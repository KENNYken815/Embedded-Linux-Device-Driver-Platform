# Interfaces

| Interface | Typical Linux representation | Purpose |
|---|---|---|
| UART | /dev/tty* | STM32 link |
| GPIO | /dev/gpiochip* | status/control |
| I2C | /dev/i2c-* | digital sensor |
| SPI | /dev/spidev* | peripheral |
| TCP | POSIX sockets | remote telemetry |
| MQTT | client library | pub/sub telemetry |
