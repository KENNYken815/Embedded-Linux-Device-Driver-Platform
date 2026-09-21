# Embedded Linux Industrial Gateway

A portfolio-ready ARM Embedded Linux gateway reference project bridging an STM32 controller and external peripherals to Linux system software and network services.

> Scope: portable C system code, Linux interface examples, Device Tree/U-Boot/kernel documentation, Bash helpers, and host-side tests. Exact board-specific files remain integration targets because the ARM board was not specified.

## Architecture

STM32 / Sensors -> UART or SPI -> ARM Linux Board -> C Gateway -> TCP/IP / MQTT -> PC / Server

## Boot flow

Boot ROM -> U-Boot -> Linux Kernel -> Device Tree -> Root Filesystem -> systemd -> Gateway Service

## Demonstrates

- Linux system programming in C
- UART/serial communication
- file descriptors and non-blocking I/O
- POSIX signals and graceful shutdown
- TCP/IP sockets
- Device Tree concepts
- U-Boot/kernel boot-flow understanding
- Linux service deployment
- logging and diagnostics
- Bash automation
- unit testing
- malformed-packet rejection and fault handling

## Repository Structure

applications/     C gateway application
drivers/          Linux hardware-interface notes
device-tree/      example DTS overlay
bootloader/       U-Boot notes
kernel/           kernel integration notes
scripts/          build/demo/service scripts
configs/          gateway configuration
tests/             host-side tests
docs/              architecture, interfaces, boot and test documentation
hardware/          lab setup

## Build

make

## Demo

./scripts/run_demo.sh

## Tests

python3 -m unittest discover -s tests -v

## Gateway protocol

Example STM32 telemetry packet:

TEMP=42.5;RPM=1200;STATE=OK

The gateway validates, parses and normalizes the packet before logging it. The networking module provides a TCP forwarding hook.

## Production boundary

This is an educational/portfolio reference implementation, not production industrial software. Production deployment requires board-specific validation, secure boot/update, authentication, encrypted transport, privilege isolation, watchdog/recovery design, and complete system verification.

## Author

Kenny
