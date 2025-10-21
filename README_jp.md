# Soft-FPGA-TD4

![soft-fpga-logo](./images/soft_fpga_logo-70x50.png)

- 2025/10/21 __まだ編集中です__


- Verilogで実装したシンプルな4bit CPU TD4をverilatorでC++ソースへ変換し、`Raspberry Pi Pico2` 上で動作するようにしました。
- __FPGAは不要__ です。pico2のみで動きます。
- ハードウェアFPGAなしでverilogソースが動く！だから __`soft-FPGA`__ です。
- `soft-FPGA`は`Software Defined FPGA`の略です。

![pico2-01](./images/pico2-01.jpg)

---

## 開発環境、インストール手順

- Windows11
- VSCode
  - `pico SDK`ではVSCodeが標準開発環境です。
- `pico SDK` VSCode拡張インストール
  - Raspberry Pi 公式の拡張機能 (Raspberry Pi Pico)
  - [Raspberry Pi Pico Visual Studio Code extension](https://github.com/raspberrypi/pico-vscode)
    - この拡張をVSCodeにインストールすると`pico SDK`がインストールされます。
    - [公式 Raspberry Pi Pico SDK](https://github.com/raspberrypi/pico-sdk)

- verilatorインストール

  - WSL2 (Windows Subsystem for Linux)上verilatorを使用（最も簡単で推奨）
  - Windows 10/11でWSL2を有効化
  - Microsoft StoreからUbuntuインストール
  - 以下のwsl2 ubuntu24でテストしました。

    ```bash
    $ lsb_release  -a
    No LSB modules are available.
    Distributor ID: Ubuntu
    Description:    Ubuntu 24.04.3 LTS
    Release:        24.04
    Codename:       noble
    ```

  - Ubuntuパッケージのverilatorをインストール
    - WSL内で以下を実行

    ```bash
    $ sudo apt update && sudo apt install verilator
    $ verilator --version
    Verilator 5.020 2024-01-01 rev (Debian 5.020-1)
    ```

  - 最新版のインストール

    - 既にパッケージをインストールしてある場合はアンイストールします。

    ```bash
    $ sudo apt remove verilator
    ```

    - インストール手順
      - [公式：how to install Verilator.](https://verilator.org/guide/latest/install.html)

    - インストール後の確認

    ```bash
    $ which verilator
    /usr/local/bin/verilator
    $ verilator --version
    Verilator 5.040 2025-08-30 rev v5.040
    ```

  - `soft-FPGA`はverilator 5.xxxであれば最新版でなくても動くと思います。
  - 余力があれば最新版をインストールして下さい。
  
---

## 解説

- [verilatorマニュアル](https://veripool.org/guide/latest/)
  - verilatorで変換したC++ソースはLinux向けになっています。
  - そのままではpico2 SDK C++ではコンパイルエラーがでます。
  - エラーがでないように修正し、pico2で実行できました。

- verilogソース: [TD4.v](./verilator-TD4/TD4.v)

- [main.cpp](./verilator-TD4/main.cpp)
  - top: verilatorが出力したTD4.vのモデルインスタンス
    - verilogシミュレーション用のインスタンス
  - 以下を繰り返す
    - DIPスイッチをINレジスタへ設定する
      - 4bit DIPスイッチの状態をpico2のGPIOから読む
      - 読んだ値を top->in_port(INレジスタ)へ設定する
    - top->eval(): 評価：TD4.vの状態を更新する
    - LEDへOUTレジスタを設定する
      - top->out_port(OUTレジスタ)の値をpico2のGIPOでLEDへ出力する 
    - top->clock = !top->clock: クロックを反転する
    - sleep: 時間まち
  - top->eval()の処理時間は6μ秒ぐらいなので、最大クロック周波数は50kHzぐらいの見込み。
    - デバッグ文を出力すると遅くなる
    - GPIOで遅くなる。

---

## FAQ

### Q: verilator出力のC++ソースを毎回修正する必要あるか？

- A: __ありません。__
- verilatorはLinux向けビルドを想定しているので、出力C++ソースではpthread mutexを使っています。
- pico SDKはpthread mutexをサポートしていないので、そのままではコンパイルエラーになります。(verilatorのフラグオプションで thread 1に指定してもmutexを使う)

- 何もしないダミーmutexクラスをヘッダーファイル`stub_mutex.h`で定義することにより、pico SDK C++でビルドできるようにしています。
- 通常であれば、`stub_mutex.h`をverilator出力のCPPソースの先頭に`#include "stub_mutex.h"`と書けばコンパイルできるようになります。
- しかしながら、verilator変換は何度も実行するので、その度に毎回出力ソースファイルを修正するのは手間がかかります。
- そこで、ヘッダーファイル`stub_mutex.h`を読み込むようにg++フラグオプションで指定します。

  ```bash
  g++ -include stub_mutex.h -o output source.cpp
  ```

- '-include` オプション
  - 特定のヘッダーファイルを強制的にインクルードします。ソースコードに `#include` を書かなくても、指定したヘッダーファイルが自動的にインクルードされます。
- 実際は`CMakeLists.txt`に書かれています。
  - [CMakeLists.txt](./verilator-TD4/CMakeLists.txt)

  ```text
      # dir_obj/*.cppに -include stub_mutex.h を適用
      set_source_files_properties(${VERILATOR_SOURCES} PROPERTIES COMPILE_FLAGS "-include stub_mutex.h")
  ```

- 結論
  - verilatorを実行しても出力C++ソースを修正する必要はありません。

---

## メモ

- `Raspberry Pi 5`で`soft-FPGA`できるかも？
  - `Raspberry Pi OS`はLinuxなので、pthread mutexに対応している。
  - verilator出力のC++ソースがそのまま動く見込み。
    - pico2のようにmutexを無効化する必要がないと思われる。（未検証）
  - ラズパイ5の`soft-FPGA`でLチカ
  - 簡単なので試す価値あり。
- `Raspberry Pi OS`
  - Linuxなのでリアルタイム処理が弱い。
    - リアルタイム処理にはPREEMPT_RTパッチを適用したカーネルが推奨
    - リアルタイム向けのOS設定
- `Raspberry Pi 5`で`FreeRTOS`
  - 高度なリアルタイム要件（マイクロ秒単位の制御）なら、FreeRTOSを検討。
    - ただし、Pi 5のフル機能は制限される場合あり。
  - `Raspberry Pi 5`向けの`FreeRTOS`公式サポートはない。
- しかし、もともと`soft-FPGA`は遅いので、リアルタイム性を追求する意味はあまりないかも？実験としてラズパイ5で十分である。
- リアルタイム性が高まると実験できる範囲が広がる。
  - DSP処理など。
- pico2の方が`soft-FPGA`向きなので依然として`pico2`で動く意味はある。
  - pico2の方がGPIOが速い。
  - GPIO低レイテンシと高い応答性
  - pico2の方が安価
  - pico2にはADC(アナログデジタル変換)がある。ADCを用いた`soft-FPGA`実験ができる。ラズパイ5にはない。
- pico2のADCを使った`soft-FPGA`実験
    - FIRフィルター実験(リアルタイムDSP処理)
      - `Grok`に聞いてみた。verilogソースあり。
        - [01-FIR-filter-verilog.pdf](./etc/01-FIR-filter-verilog.pdf)
      - pico2のADCで音声帯域の信号をアナログ入力
      - verilogでFIRフィルターを記述
        - まずはLPF(低周波フィルター）
        - 他にはHPF(高周波フィルター）、BPF（バンドパスフィルター）など。
      - pico2 `soft-FPGA`実行
      - pico2 PWMでデジタルアナログ変換
        - PWM出力ピンにLPF(低周波フィルター）回路を追加
      - LPF出力をオシロスコープなどで確認
- pico2 `FreeRTOS`
  - 公式サポートあり。pico SDKが使える。
  - 対話的なプログラムを開発しやすい？
    - 自作CPU用の機械語モニタ
  - `FreeRTOS`の学習に。
  
- verilogでオセロ作れるか？
  - 調査した範囲では作れそうだ。
  - `Grok`に聞いてみた。verilogソースあり（未検証）     
    - [02-othello-verilog.pdf](./etc/02-othello-verilog.pdf)
  - UI(盤面の表示、指し手の位置指定など)をpico SDK C++で書き、`soft FGPA`でverilogオセロ部分を実行する。
  - 実は、オセロマシンを作る妄想を昔からしていた。
    - 最初は`74シリーズTTL`で作る妄想をしていた。
    - 次は`FPGA`で作る妄想をしていた。
    - C言語で簡単なオセロ対戦ゲームを作ったことはある。
    - `自作CPUを語る会`でオセロ対戦の話がでてきて __びっくり__ した！
    - 忘れかけていた青春の妄想が今よみがえる！
    - `soft-FPGA`で作る __妄想が始まってしまった！__
    - 作るでしょ！今なら`soft-FPGA`でオセロ作るしかない！

- `soft-FPGA`の哲学的解釈
  - 速度の違いはあるものの、pico2を隠せば、見た目だけでは`soft-FPGA`とハードウェアFPGAは区別ができない。人間に区別できないものは、人間にとって同じということである。
  - [不可知論](https://ja.wikipedia.org/wiki/%E4%B8%8D%E5%8F%AF%E7%9F%A5%E8%AB%96) によってハードウェアFPGAと同一とみなせる。

    ```text
    不可知論（ふかちろん、agnosticism）は、
    神や超自然的な存在の有無について、
    知識として確定的な結論を下すことができないとする立場です。
    「知ることができない」という意味です。
    ```

---
## 以下はfork元からの引用です。

# simpleTD4 
Verilogで実装したシンプルな4bit CPU TD4の実装です。 
[Sipeed Tang Nano] (https://tangnano.sipeed.com/en/) でも動作します。
[TD4\_details\_jp.md](TD4_details_jp.md) でコードの解説をしています。

## ライセンス
  ```
Copyright (c) 2020 asfdrwe <asfdrwe@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy 
of this software and associated documentation files (the "Software"), to deal 
in the Software without restriction, including without limitation the rights 
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell 
copies of the Software, and to permit persons to whom the Software is 
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in 
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL 
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS 
IN THE SOFTWARE.
  ```

## ファイル取得
```
git clone https://github.com/asfdrwe/simpleTD4.git
```

## 必要なもの
### PCでシミュレーションする場合
- [iverlog](http://iverilog.icarus.com/)
	- [iverlog Windows版](http://bleyer.org/icarus/)
- [gtkwave](http://gtkwave.sourceforge.net/) (なくてもいい)  

Linuxで動作確認しています。iverlogもgtkwaveもLinuxなら大抵のディストリビューションでバイナリが用意されていると思います。


### FPGAを使う場合
- [Sipeed Tang Nano] (https://tangnano.sipeed.com/en/)  
(以下なくてもいい)
	- [ブレッドボード] (https://akizukidenshi.com/catalog/g/gP-05294/)
	- [抵抗内蔵５ｍｍ赤色ＬＥＤ] (https://akizukidenshi.com/catalog/g/gI-06245/) 4個
	- [タクトスイッチ] (https://akizukidenshi.com/catalog/g/gP-03647/) 4個
	- [圧電スピーカー] (https://akizukidenshi.com/catalog/g/gP-04118/) 1個
	- [スルホール用テストワイヤ] (https://akizukidenshi.com/catalog/g/gC-09830/) 10本
	- [ジャンプワイヤ] (https://akizukidenshi.com/catalog/g/gC-05371/) 5本  
	ハンダ付けなしでも動作確認できるようにスルホール用テストワイヤを活用しています。もちろん普通にピンヘッダをハンダ付けしても動きます。

## PCでのシミュレーション
### 論理合成
   ```
iverlog -o TD4 TD4.v TD4_test.v
   ```

### シミュレーション実行
   ```
./TD4
   ```

gtkwaveで信号状態の確認もできます。./TD4実行後に
   ```
gtkwave TD4.vcd
   ```

### ROM.binの書き方
ROM.binを差し替えることで動作が変わります。
1行8bitの2進数で記述してください。\_は区切りで無視されます。 // 以下はコメントです。 ROMLED.bin、ROMRAMEM.bin、ROMINOUT.binを参考にしてください。

## Tang Nanoでの実行
[Sipeed Tang Nanoで遊んでみる (Linux版)] (https://qiita.com/ciniml/items/bb9723673c91d8374b63) や
 [SiPeed Tang Nanoの環境構築(Windows編)] (https://qiita.com/tomorrow56/items/7e3508ef43d3d11fefab) 
 を参考に環境設定を行ってTang Nanoの動作確認をしてください。nano\_simpleならば
Open Projectからnano\_simple/TD4_nano1.gprjを開き、
Processから Synthesize => Place & Route => Program Deviceで書き込みしてください。
Synthesizeできない場合はTD4.vを開いて適当に改行を入れて保存してからSynthesizeしてください。

### ROM.binの書き方
Tang Nano向けでは、\_や//　があるとうまく動かない可能性があるので1行8bitの2進数だけで記述してください。

## ファイル
- TD4.v  
iverilog用のVerilogで実装したTD4本体です。
- TD4_test.v  
iverilog用のTD4のテストベンチです。

- ROM.bin
TD4が読み込むプログラムです。
ROMLED.bin、ROMRAMEM.bin、ROMINOUT.binのファイル名を変えるか自作のコードをROM.binにしてください。
- ROMLED.bin  
TD4のLED点滅プログラム(外部出力)です。  
0011, 0110, 1100, 1000, 1000, 1100, 0110, 0011, 0001の順に繰り返します。
- ROMRAMEM.bin  
TD4のラーメンタイマープログラムです。  
0111のあと少し経つと0110になりそのあと0000と0100を繰り返し最後1000になります。
1サイクル1秒にすれば3分後1000になるはずです。
- ROMINOUT.bin  
TD4の入力と出力のテストプログラムです。
入力内容をBレジスタに入れBレジスタの内容を出力します。

- README\_jp.md  
この文書です。
- TD4\_details\_jp.md  
simpleTD4の実装の解説です。
- README.md
英語版の文書です。

- TD4withComment.v  
コメント付きのsimpleTD4の実装です。


### FPGA用
- nano\_simple  
Tang Nanoのみで動作します。USB端子を右とした場合、上のボタンがリセット、
TD4の出力ポートのうち下位3bitをTang Nano内蔵LEDの青、緑、赤に割り振り、
TD4の入力ポートの最下位ビットが下のボタンです。
それ以外は、出力ポートの最上位は38番(左下)、入力ポートの残りは下位から40番41番42番(左下の3番目から5番目)です。

	Tang Nanoのピンアサインは [Tang Nano](https://tangnano.sipeed.com/en/) の 
[Pinout Diagram](https://tangnano.sipeed.com/assets/tang_nano_pinout_v1.0.0_w5676_h4000_large.png) を参照してください。

- nano\_breadboard  
ブレッドボードと組み合わせて動作します。USB端子を右とした場合、上のボタンがリセット、
TD4の出力ポートが上位から38番39番40番41番(左下1番目から4番目)、最上位ビットの
ブザー出力が23番(右上のスイッチから5番目)、TDの入力ポートが上位から
20番21番22番24番(右上のスイッチから10番目から7番目)です。  
![雑な配線例](images/tangnano.png) 。

- nano\_uart
PCにUSB UART経由でTD4の内部状態を出力しながら動作します。
ピンアサインはnano\_simpleと同じです。
出力形式は  
pc opcode reg_a,reg_b,reg_out,reg_in cflag|load_a,load_b,load_out,load_pc|nextcflag|alu_out  

Tang NanoはUARTの信号線と書き込み用の信号線が重複しています。  
Linuxではftdi\_sioが動いていると書き込みができず、ftdi\_sioが動いていないとUARTでの通信ができないので、rmmodとmodprobeをうまく使ってください。cuコマンドを使う場合/dev/ttyUSB0としてTang Nanoが認識されているなら

```
cu -l /dev/ttyUSB0 -s 57600
```

Windowsの場合は
[Tang NanoでuartのIPコアを動かした件](https://qiita.com/yoshiki9636/items/cabcd0c62ea97472b51c)
が参考になると思います。なおこのページのコードをnano_uartの実装の参考にしています。
