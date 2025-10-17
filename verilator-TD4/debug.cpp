/**
 * デバッグ文の出力テスト用プロジェクト
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include <time.h>
#include <string.h>  // strncmp 用
#include "pico/stdlib.h"
#include "pico/aon_timer.h"
#include <time.h>
#include "debug.h"

static log_level_t current_level = LOG_LEVEL_DEBUG;  // デフォルト: すべて出力

// デバッグメッセージを出力
void _debug(const char* p_msg) {
    char fake_date[20];
    get_fake_date( fake_date );
    printf( "%s %s", fake_date, p_msg );
    // printf( " %s", p_msg );
}

void log_set_level(log_level_t level) {
    current_level = level;
}

// __FILE__ からファイル名抽出（関数版）
// picoライブラリにはbasename()がないため自前実装
static const char *get_basename(const char *file) {
    const char *last_slash = strrchr(file, '/');
    return last_slash ? last_slash + 1 : file;
}

void _dbg(log_level_t level, const char *file, int line, const char *func, const char *fmt, ...) {
    if (level > current_level) return;

    const char *base = get_basename(file);

    va_list args;
    va_start(args, fmt);
    char buffer[256];
    // sprintf( buffer, "%15s,%d:%8s", file, line, func);
    sprintf( buffer, "%15s %03d:%12s: ", base, line, func);
    _debug(buffer);
    vprintf(fmt, args);
    va_end(args);
}

// コンパイル日時を2025-10-10 12:34:56形式に変換
void convert_date( char* p_date_out, const char* p_date, const char* p_time,
    struct tm* p_tm) 
{
    // 文字列を解析
    struct tm initial_tm = {0};
    *p_tm = initial_tm; // 初期化
    int year, day, hour, min, sec;
    char mon_str[4];

    // 日付解析: %3s (月略称) %d (日) %d (年)
    sscanf(p_date, "%3s %d %d", mon_str, &day, &year);

    // 月の略称を数字 (1-12) に変換
    const char *months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                            "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    int month = 0;
    for (int i = 0; i < 12; i++) {
        if (strncmp(months[i], mon_str, 3) == 0) {
            month = i + 1;
            break;
        }
    }
    if (month == 0) {
        printf("月解析エラー\n");
        return;
    }

    // 時刻解析: %d:%d:%d
    sscanf(p_time, "%d:%d:%d", &hour, &min, &sec);

    sprintf( p_date_out, "%04d-%02d-%02d %02d:%02d:%02d",
        year, month, day, hour, min, sec);

    if ( p_tm == NULL ) {
        return;
    }
    // struct tm にセット
    p_tm->tm_year = year - 1900;  // 1900年からの相対値
    p_tm->tm_mon = month - 1;     // 0-11
    p_tm->tm_mday = day;
    p_tm->tm_hour = hour;
    p_tm->tm_min = min;
    p_tm->tm_sec = sec;
    p_tm->tm_isdst = -1;          // DST 不明

}

void init_date() {
    // コンパイル時の日時文字列を取得

    struct tm tm;
    char date[20];
    convert_date( date, __DATE__, __TIME__, &tm );

    _DEBUG( "%s\n", date);

    // AON タイマーを初期時間で開始
    if (!aon_timer_start_calendar(&tm)) {
        printf("AON タイマー開始失敗\n");
        return;
   }
}

// 現在fake時間をカレンダー形式で取得
void get_fake_date( char* p_fake_date) {
    struct tm current_tm;
    if ( !aon_timer_get_time_calendar(&current_tm)) {
        // 失敗時はゼロクリア
        sprintf( p_fake_date, "%04d-%02d-%02d %02d:%02d:%02d", 0,0,0,0,0,0);
    }
    // sprintf( p_fake_date, 
    //     "%04d-%02d-%02d %02d:%02d:%02d",
    //     current_tm.tm_year + 1900,
    //     current_tm.tm_mon + 1,
    //     current_tm.tm_mday,
    //     current_tm.tm_hour,
    //     current_tm.tm_min,
    //     current_tm.tm_sec);
    sprintf( p_fake_date, 
        "%02d:%02d:%02d",
        current_tm.tm_hour,
        current_tm.tm_min,
        current_tm.tm_sec);
}



