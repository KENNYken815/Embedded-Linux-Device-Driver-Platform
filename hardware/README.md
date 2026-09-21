# Hardware Reference

Suggested setup:

- ARM Linux development board
- STM32 development board
- USB-UART adapter or direct UART
- optional I2C/SPI sensor
- Ethernet or Wi-Fi
- SWD/JTAG debugger

Data path:

STM32 -> UART/SPI -> ARM Linux -> TCP/MQTT -> PC/server

Match UART voltage levels and connect a common ground.
