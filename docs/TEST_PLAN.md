# Test Plan

Functional:
- Linux boot
- UART link
- valid telemetry parsing
- malformed packet rejection
- logging
- TCP forwarding
- service startup/restart

Fault injection:
- STM32 disconnect
- UART timeout
- invalid packet
- network loss
- application process failure

Debugging:
dmesg | tail
journalctl -u embedded-linux-gateway
ps aux
top
strace ./build/gateway /dev/ttyS0

Performance values should be measured on the selected target.
