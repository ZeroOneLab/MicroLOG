#include "micro_log.h"
#include "usart.h"

static char log_time_str[16];

int fputc(int ch, FILE *f)
{
  HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xFFFF);
  return ch;
}

/**
 * @brief   获取当前时间
 * @param   无
 * @retval  无
 */
char *log_get_time(void)
{
    uint32_t log_time = log_get_tick();
    uint16_t msec = log_time % 1000;
    log_time /= 1000;
    uint8_t sec = log_time % 60;
    log_time /= 60;
    uint8_t min = log_time % 60;
    log_time /= 60;
    uint8_t hour = log_time;

    snprintf(log_time_str, sizeof(log_time_str), "%02d:%02d:%02d.%03d", hour, min, sec, msec);
    return log_time_str;
}

/**
 * @brief   从路径中提取文件名
 * @param   path 文件路径
 * @retval  文件名指针
 */
const char *log_get_filename(const char *path)
{
    const char *p = strrchr(path, '/');
    if (p)
        return p + 1;

    p = strrchr(path, '\\');
    if (p)
        return p + 1;

    return path;
}
