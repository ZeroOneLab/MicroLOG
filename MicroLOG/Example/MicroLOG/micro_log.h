#ifndef _MICRO_LOG_H
#define _MICRO_LOG_H

#include <stdio.h>
#include <string.h>

#include "main.h"

char *log_get_time(void);       // 获取时间
const char *log_get_filename(const char *path); // 获取文件名

#define log_printf(fmt, ...) printf(fmt, ##__VA_ARGS__) // 核心函数打印接口
#define log_get_tick HAL_GetTick                        // 获取系统滴答计数

/* ============== 颜色定义 ============== */
#define CLR_RED         "\x1b[31m"      // 红色
#define CLR_ORANGE      "\x1b[33;1m"    // 橙色
#define CLR_YELLOW      "\x1b[33m"      // 黄色
#define CLR_GREEN       "\x1b[32m"      // 绿色
#define CLR_BLUE        "\x1b[34m"      // 蓝色
#define CLR_PURPLE      "\x1b[35m"      // 紫色
#define CLR_RESET       "\x1b[0m"       // 重置颜色


/* ============== 核心日志接口 ============== */

// 1. LOG(...) - 无时间戳printf，无颜色
#define LOG(fmt, ...) log_printf(fmt, ##__VA_ARGS__)

// 2. LOG_C(color, ...) - 无时间戳printf，带颜色
#define LOG_C(color, fmt, ...) log_printf(color fmt CLR_RESET, ##__VA_ARGS__)

// 3. LOG_T(...) - 带时间戳printf，无颜色
#define LOG_T(fmt, ...) log_printf("[%s] " fmt, log_get_time(), ##__VA_ARGS__)

// 4. LOG_TC(color, ...) - 带时间戳printf，带颜色
#define LOG_TC(color, fmt, ...) log_printf(color "[%s] " fmt CLR_RESET, log_get_time(), ##__VA_ARGS__)

/* ============== 文件位置+时间戳日志 ============== */

// LOG_I - 文件+时间信息（绿色）
#define LOG_I(fmt, ...) log_printf(CLR_GREEN "[%s][%s,%s:%d] " fmt CLR_RESET, \
                                   log_get_time(), log_get_filename(__FILE__), __FUNCTION__, __LINE__, ##__VA_ARGS__)

// LOG_W - 文件+时间警告（黄色）
#define LOG_W(fmt, ...) log_printf(CLR_YELLOW "[%s][%s,%s:%d] " fmt CLR_RESET, \
                                   log_get_time(), log_get_filename(__FILE__), __FUNCTION__, __LINE__, ##__VA_ARGS__)

// LOG_E - 文件+时间错误（红色）
#define LOG_E(fmt, ...) log_printf(CLR_RED "[%s][%s,%s:%d] " fmt CLR_RESET, \
                                   log_get_time(), log_get_filename(__FILE__), __FUNCTION__, __LINE__, ##__VA_ARGS__)

/* ============== 断言宏 ============== */
#define LOG_ASSERT(expr)                                                                              \
    do                                                                                                \
    {                                                                                                 \
        if (!(expr))                                                                                  \
        {                                                                                             \
            log_printf(CLR_RED "\r\n[ASSERT FAILED] %s\r\nFile: %s:%d\r\nFunction: %s\r\n" CLR_RESET, \
                       #expr, log_get_filename(__FILE__), __LINE__, __FUNCTION__);                    \
            while (1)                                                                                 \
                ;                                                                                     \
        }                                                                                             \
    } while (0)
    
#endif /* _MICRO_LOG_H */
