# 示例

此目录包含适用于 Waveshare ESP32-P4 平台板的 ESP-IDF 项目和 Arduino 草图。

## ESP-IDF

[esp-idf](esp-idf/) 下的每个目录都是一个独立的 ESP-IDF 项目。除非示例的 README 另有说明，否则请在所选示例目录内运行 ESP-IDF 命令。

```bash
cd examples/esp-idf/00_board_check
idf.py set-target esp32p4
idf.py build
idf.py -p PORT flash monitor
```

ESP32-P4 量产 v3.x 芯片及更早的 v3 前工程样品需要不同的 ESP-IDF 构建配置。示例将版本选择保留在 [../config](../config/) 下的共享覆盖层中。在不同芯片版本系列之间烧录之前，请参阅 [../docs/ESP32P4_REVISION_CONFIG.md](../docs/ESP32P4_REVISION_CONFIG.md)。

| 目录 | 用途 | 说明 |
| --- | --- | --- |
| [00_board_check](esp-idf/00_board_check/) | 首次运行板卡和工具链检查 | 无需外部硬件 |
| [01_HowToCreateProject](esp-idf/01_HowToCreateProject/) | 最小项目模板 | 创建新示例的良好起点 |
| [02_HelloWorld](esp-idf/02_HelloWorld/) | 基础应用和日志 | 快速环境检查 |
| [03_nvs_counter](esp-idf/03_nvs_counter/) | 使用 NVS 的持久化设置 | 无需外部硬件 |
| [04_freertos_tasks](esp-idf/04_freertos_tasks/) | FreeRTOS 任务和队列 | 无需外部硬件 |
| [05_gpio_io](esp-idf/05_gpio_io/) | GPIO 输入/输出 | 可选跳线或 LED |
| [06_gpio_interrupt](esp-idf/06_gpio_interrupt/) | GPIO 中断和消抖 | 建议使用按钮或跳线 |
| [07_uart_loopback](esp-idf/07_uart_loopback/) | UART 回环 | 建议使用跳线 |
| [08_i2c_tools](esp-idf/08_i2c_tools/) | I2C 工具 | 包含命令处理程序 |
| [09_sdmmc](esp-idf/09_sdmmc/) | SD 卡 | 需要 SD 卡接线/插槽支持 |
| [10_wifistation](esp-idf/10_wifistation/) | Wi-Fi 站点 | 需要支持 Wi-Fi 的板卡或已配置的 Wi-Fi 支持 |
| [11_ethernetbasic](esp-idf/11_ethernetbasic/) | 以太网 | 在 menuconfig 中检查 PHY 设置 |
| [12_I2SCodec](esp-idf/12_I2SCodec/) | I2S 音频编解码器 | 包含音频采样数据 |
| [13_Displaycolorbar](esp-idf/13_Displaycolorbar/) | 显示彩条 | 适用于 LCD 调试 |
| [14_lvgl_demo_v9](esp-idf/14_lvgl_demo_v9/) | LVGL v9 | 使用托管的 LVGL/BSP 组件 |
| [15_eth2ap](esp-idf/15_eth2ap/) | 以太网转 AP | 需要两种网络路径 |
| [16_video_lcd_display](esp-idf/16_video_lcd_display/) | 摄像头视频到显示屏 | 请先阅读示例 README |
| [17_simple_video_server](esp-idf/17_simple_video_server/) | HTTP 视频服务器 | 包含前端资源 |
| [18_esp_brookesia_phone](esp-idf/18_esp_brookesia_phone/) | ESP-Brookesia UI | 包含英文和中文 README 文件 |
| [19_system_monitor](esp-idf/19_system_monitor/) | 串口诊断和运行时监控 | 无需外部硬件 |

## Arduino

Arduino 示例位于 [arduino/examples](arduino/examples/)。[arduino/README.md](arduino/README.md) 文件记录了推荐的 Arduino-ESP32 核心和捆绑库。

| 目录 | 用途 |
| --- | --- |
| [AsciiTable](arduino/examples/AsciiTable/) | 串口输出示例 |
| [Drawing_board](arduino/examples/Drawing_board/) | 显示/触摸绘图示例 |
| [GFX_ESPWiFiAnalyzer](arduino/examples/GFX_ESPWiFiAnalyzer/) | Wi-Fi 分析器 UI |
| [HelloWorld](arduino/examples/HelloWorld/) | 最小 Arduino 草图 |
| [LVGLV9_Arduino](arduino/examples/LVGLV9_Arduino/) | LVGL v9 Arduino 示例 |

[arduino/libraries](arduino/libraries/) 目录包含这些草图使用的捆绑库。在单独重新分发每个库之前，请检查其自身的元数据和许可证。

## 添加新示例

保持新示例小巧且专注：

- 为新的独立 ESP-IDF 示例使用带编号的目录。
- 在适用时包含 `README.md`、`CMakeLists.txt`、`main/` 和 `sdkconfig.defaults`。
- 记录所需的硬件、menuconfig 选项和预期的串口输出。
- 除非有意策划，否则不要将生成的构建产物、`sdkconfig`、`managed_components` 和依赖锁定文件加入 git。

有关学习路径，请参阅 [../docs/EXAMPLES_GUIDE.md](../docs/EXAMPLES_GUIDE.md)；有关建议的未来示例，请参阅 [../docs/EXAMPLE_ROADMAP.md](../docs/EXAMPLE_ROADMAP.md)。
