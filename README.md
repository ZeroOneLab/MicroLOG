# MicroLOG
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

一款轻量级、高易用性、多色彩的嵌入式串口日志打印框架，解决嵌入式系统日志无时间戳、无代码定位、无可视化区分的调试效率难题。

## 版本说明
- v1.0_20260227：完成全部核心功能，支持高精度时间戳、多等级彩色日志、代码位置定位、断言失败卡死打印等能力

## 项目介绍
MicroLOG基于标准C库+MCU HAL库轻量级封装，采用解耦设计适配任意MCU平台，可快速集成到各类嵌入式项目的串口日志调试场景。核心特性：
- 高精度时间戳输出（时:分:秒.毫秒，基于系统滴答定时器）；
- 多等级彩色日志（信息/警告/错误区分不同颜色，兼容终端可视化）；
- 自动携带代码定位信息（文件名/函数名/行号），快速定位问题；
- 内置断言宏，断言失败时打印失败表达式+代码位置并卡死；
- 多形态日志宏（基础打印/彩色打印/带时间戳/带代码定位），适配不同调试场景；
- 自动提取文件名（兼容`/`和`\`路径分隔符），日志输出更简洁。

## 移植指南
移植文档含图文实操说明，托管于语雀平台：
[轻量级嵌入式串口日志打印框架](https://www.yuque.com/u54102073/rs06a5/ky3sz2s39lm3rfsf?singleDoc#)

## 相关链接
- 源码仓库（GitHub）：[ZeroOneLab/MicroLOG](https://github.com/ZeroOneLab/MicroLOG.git)
- 源码仓库（Gitee）：[零壹实验室-ZeroOneLab/MicroLOG](https://gitee.com/Wang2869902214/MicroLOG.git)
- 移植文档：[语雀 - MicroLOG：轻量级嵌入式串口日志打印框架](https://www.yuque.com/u54102073/rs06a5/ky3sz2s39lm3rfsf?singleDoc#)

## 许可证
Copyright (c) 2026 零壹实验室-ZoreOneLab
Released under the MIT License.
