/**
 * @file main.cpp
 * @brief Raspberry Pi Pico 用のverilaterシミュレーションデバッグ表示サンプルコード
 * @author tommie.jp (https://tommie.jp/)
 * @version 1.0 
 * 
 * target: Raspberry Pi pico 2
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include <time.h>
#include <string.h>  // strncmp 用
#include <memory>  // unique_ptr用（オプション）
#include <malloc.h>
#include "pico/time.h"  // 時間計測用
#include "hardware/regs/m33.h"  // m33_hwアクセス用

#include "stub_mutex.h"
#include "VTD4.h"
#include "verilated.h"

#include "pico/stdlib.h"

#define DEBUG
#include "debug.h"

// グローバル変数としてインスタンスを作成
// static VTD4 vtd4_1;  
// static VerilatedContext context_1;

// ヒープの総バイト数を取得
uint32_t get_total_heap() {
    extern char __StackLimit, __bss_end__;  // リンクシンボル（SDKのmemmap_default.ld）
    return (uint32_t)(&__StackLimit - &__bss_end__);  // 総ヒープバイト
}
// ヒープの空きバイト数を取得
uint32_t get_free_heap() {
    struct mallinfo m = mallinfo();
    return get_total_heap() - m.uordblks;  // 空き = 総 - 使用中
}

// ２進数を出力（改行しないので注意）
void print_bin( uint p_uint) {

    for (int i = 7; i >= 0; --i) {
        if(i==3) {
            printf("_"); // 4ビットごとにアンダースコアを挿入
        }
        printf("%d", (p_uint >> i) & 1);  // 各ビットを抽出して出力
    }
    printf("B"); // 2進数表記の接尾辞
}

// ヒープ使用状況を表示
void memory_info( void)
{
    struct mallinfo m = mallinfo();
    uint32_t total = get_total_heap();
    uint32_t used = m.uordblks;
    uint32_t free = get_free_heap();
    float usage_percent = (float)used / total * 100.0f;
    float free_percent = (float)free / total * 100.0f;
    _DEBUG("RAM Total: %03d,%03d bytes (%d KB)\n", total/1000, total%1000, total / 1024);
    _DEBUG("RAM Used:  %03d,%03d bytes (%4.1f%%)\n", 
        used/1000, used%1000, usage_percent);
    _DEBUG("RAM Free:  %03d,%03d bytes (%4.1f%%)\n", 
        free/1000, free%1000, free_percent);    
}    

// Cortex-M33のDWT_CYCCNTを使って時間計測の初期化
// DWT CYCCNT初期化（コア0で一度実行）
void init_time_culc( void)
{
    // Cortex-M33のDWT_CYCCNTを使って時間計測
    // DWT CYCCNT初期化（コア0で一度実行）
    m33_hw->demcr |= 0x01000000u;  // TRCENA有効化
    m33_hw->dwt_cyccnt = 0;        // リセット
    m33_hw->dwt_ctrl |= 1u;        // CYCCNTENA有効化
}   

// ロジックを実行評価
// Cortex-M33のDWT_CYCCNTを使って時間計測
void eval(VTD4* top) {
    // 時間計測 開始
    
    uint32_t start_cycles = m33_hw->dwt_cyccnt;
    top->eval();  // 評価
    uint32_t end_cycles = m33_hw->dwt_cyccnt;
    uint32_t elapsed_cycles = end_cycles - start_cycles;

    // 経過時間を計算して表示
    // pico2のクロックは150MHz
    // サイクルをnsに変換（150MHz = 150000000 cycles/s → 1 cycle ≈ 6.6667 ns）
    double elapsed_ns = (double)elapsed_cycles * (1000000000.0 / 150000000.0);
    double per_sec = 1000000000.0 / (elapsed_ns*2); // 1秒あたりのサイクル数
    double per_sec_khz = per_sec / 1000.0; // kHz単位
    _DEBUG("elapsed-time:top->eval() %6u cycles, %6.3f us, clock=%8.3f kHz\n",
        elapsed_cycles, elapsed_ns/1000.0, per_sec_khz);
}

int main() {
    const uint LED_PIN = 25;  // Pico 2の組み込みLEDピン（PICO_DEFAULT_LED_PINでも可）

    stdio_init_all();

    // Cortex-M33のDWT_CYCCNTを使って時間計測の初期化
    init_time_culc();

    // GPIO初期化
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);  // 出力モード

    // LED設定
    // GPIOピンを出力モードに設定
    int pins[4] = {2, 3, 4, 5};  // GP2~GP5 (GP2=ビット3(MSB), GP5=ビット0(LSB))
    for (int i = 0; i < 4; i++) {
        gpio_init(pins[i]);
        gpio_set_dir(pins[i], GPIO_OUT);
        gpio_put(pins[i], 0);  // 初期状態: OFF (LOW)
    }

    // DIPスイッチ設定
    // GPIOピンを入力モード + 内部プルアップに設定
    int pins_dip[4] = {10, 11, 12, 13};  // GP10~GP13
    for (int i = 0; i < 4; i++) {
        gpio_init( pins_dip[i]);
        gpio_set_dir(pins_dip[i], GPIO_IN);
        gpio_pull_up(pins_dip[i]);  // 内部プルアップ有効 (OFF=1, ON=0)
    }


    // 初期遅延: シリアルモニターが接続されるまで待機
    sleep_ms(4000);  // 2秒推奨 (1-3秒で調整)

    init_date(); // AONタイマーをコンパイル日時で初期化
    _DEBUG( "**************************\n" );
    _DEBUG( "--- start\n" );
    _DEBUG( "file=%s\n", __FILE__);
    char compile_date[20];
    convert_date( compile_date, __DATE__, __TIME__ );
    _DEBUG( "compile_date=%s\n", compile_date);
    _DEBUG( "**************************\n" );
    
    // Verilated::commandArgs(0, (char**)nullptr); // 組み込み用: argc, argv不要
    // コンテキスト初期化: --threads 1 をダミー引数で指定 (モデル一致)
    const char* my_argv[3] = {"sim", "--threads", "1"};
    Verilated::commandArgs(3, my_argv);
    _DEBUG( "after commandArgs()\n" );

    // コンテキスト作成（unique_ptrで自動クリーンアップ）
    // 組み込みでnewはしたくないが、コンテキストを渡すには仕方ない
    const std::unique_ptr<VerilatedContext> contextp{new VerilatedContext};
    contextp->commandArgs(3, my_argv);  // コンテキスト経由で引数設定

    // トップモジュール作成（コンテキストを渡す）
    // 組み込みでnewはしたくないが、コンテキストを渡すには仕方ない
    const std::unique_ptr<VTD4> top{new VTD4{contextp.get()}};

    // Vcounter* top = new Vcounter;
    // _DEBUG( "after new Vconter\n" );
    // VTD4* top = &vtd4_1;

    int half_count = 0; // クロックの半周期カウンタ
    int clock_count = 0; // クロック周期カウンタ

    top->clock = 0;   // クロック初期化
    top->reset_n = 1;   // リセットオフ 0:オン 1:オフ
    top->in_port = 0;   // 入力初期化
    top->pc_out = 0;  // 出力初期化
    top->op = 0;
    top->out_port = 0;
    top->alu_data = 0;

    while (true) {

        _DEBUG( "--------------------------- verilator-TD4 #1\n" );
        _DEBUG( "compile_date=%s\n", compile_date);
        _DEBUG( "clock_count=%d\n", clock_count );  
        // _DEBUG( "half_count =%d\n", half_count );  
        // _DEBUG( "file=%s\n", __FILE__ );
        // _DEBUG( "compile_date=%s\n", g_compile_date);
        // print_date();
        // _DEBUG("Hello, world!\n");
        // _DEBUG( "DBG_DEBUG: test\n");

        // DIPスイッチの値を読み取り
        // 各ピンの値を読み取り、ON=1に反転
        int sw[4];
        for (int i = 0; i < 4; i++) {
            sw[i] = !gpio_get(pins_dip[i]);  // 反転: LOW(ON)=1, HIGH(OFF)=0
        }

        // 4bit値を合成 (GP10=ビット3(MSB), GP13=ビット0(LSB))
        uint8_t switch_value = (sw[0] << 3) | (sw[1] << 2) | (sw[2] << 1) | sw[3];

        // シリアル出力 (例: Thonnyやscreenで確認)
        _DEBUG("DIP SW value: 0x%02X (%d in decimal)\n", switch_value, switch_value);
        top->in_port = switch_value;  // 入力にセット

        // クロック立ち上がりのときにクロックカウンタに応じて入力を変更する
        if ( top->clock == 1) {
            switch (clock_count ) {
                case 0:
                    break;
                case 1:
                    _DEBUG( "=== reset ON\n");
                    top->reset_n = 0;  // リセットオン
                    break;
                case 2:
                    _DEBUG( "=== reset OFF\n");
                    top->reset_n = 1;  // リセットオフ
                    break;
                // case 10:
                //     _DEBUG( "=== reset ON\n");
                //     top->rst = 1;  // リセットオン
                //     break;
                // case 11:
                //     _DEBUG( "=== reset OFF\n");
                //     top->rst = 0;
                //     break;
                default:
                    break;
            }   
        } 
        contextp->timeInc(1);  // 時間を進める(1単位)

        eval(top.get());  // 評価（時間計測）

        _DEBUG("top->clock=%d\n", top->clock);
        _DEBUG("top->reset_n=%d,%s\n", top->reset_n, (top->reset_n==0)?"reset":"run");
        _DEBUG("top->in_port=%d\n", top->in_port);
        _DEBUG("top->pc_out=%02XH,", top->pc_out);
        print_bin(top->pc_out);
        printf("\n");
        _DEBUG("top->op=%02XH,", top->op);
        print_bin(top->op);
        printf("\n");
        _DEBUG("top->out_port=%02XH,", top->out_port);
        print_bin(top->out_port);
        printf("\n");
        _DEBUG("top->alu_data=%d\n", top->alu_data);
        gpio_put(LED_PIN, top->clock);  

        memory_info();

        // LED表示
        // out_portの下位4ビットを各GPIOに設定
        gpio_put(pins[0], (top->out_port >> 3) & 1);  // GP2: ビット3
        gpio_put(pins[1], (top->out_port >> 2) & 1);  // GP3: ビット2
        gpio_put(pins[2], (top->out_port >> 1) & 1);  // GP4: ビット1
        gpio_put(pins[3], top->out_port & 1);         // GP5: ビット0 (LSB)

        half_count++;
        // クロック立ち上がりのとき、クロックカウンターをインクリメント
        if ( (top->clock == 0) && ( !top->clock == 1) ) {
            clock_count++;
        }
        top->clock = !top->clock;  // クロックトグル
        sleep_ms(100);
    }

    // delete top;

}
