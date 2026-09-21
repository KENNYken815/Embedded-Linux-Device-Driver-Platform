# Architecture

Portable gateway logic is separated from board-specific Linux integration.

STM32 -> UART/SPI -> Linux device interface -> C gateway
                                   |-> logging
                                   |-> TCP/MQTT integration

Standard Linux tools can be used for diagnosis while the application remains small and modular.
