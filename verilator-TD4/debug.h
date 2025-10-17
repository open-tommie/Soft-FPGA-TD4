#ifndef DEBUG_H
#define DEBUG_H 

#include <cstddef>

// ログレベル定義
typedef enum {
    LOG_LEVEL_ERROR = 0,
    LOG_LEVEL_WARN  = 1,
    LOG_LEVEL_INFO  = 2,
    LOG_LEVEL_DEBUG = 3
} log_level_t;

extern void init_date( void);
extern void get_fake_date( char* p_fake_date);
extern void _dbg(log_level_t level, const char *file, int line, const char *func, const char *fmt, ...);
// コンパイル日時を2025-10-10 12:34:56形式に変換
extern void convert_date( char* p_date_out, const char* p_date, const char* p_time, struct tm* p_tm=(struct tm*)0);
extern void log_set_level(log_level_t level);


// マクロで簡易呼び出し
#define _ERROR(fmt, ...) _dbg(LOG_LEVEL_ERROR, __FILE__, __LINE__, __func__, fmt, ##__VA_ARGS__)
#define _WARN(fmt, ...)  _dbg(LOG_LEVEL_WARN,  __FILE__, __LINE__, __func__, fmt, ##__VA_ARGS__)
#define _INFO(fmt, ...)  _dbg(LOG_LEVEL_INFO,  __FILE__, __LINE__, __func__, fmt, ##__VA_ARGS__)
#define _DEBUG(fmt, ...) _dbg(LOG_LEVEL_DEBUG, __FILE__, __LINE__, __func__, fmt, ##__VA_ARGS__)


#endif // DEBUG_H


