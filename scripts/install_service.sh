#!/usr/bin/env bash
set -euo pipefail
sudo mkdir -p /opt/embedded-linux-gateway
sudo install -m 0755 build/gateway /opt/embedded-linux-gateway/gateway
cat <<'EOF' | sudo tee /etc/systemd/system/embedded-linux-gateway.service >/dev/null
[Unit]
Description=Embedded Linux Industrial Gateway
After=network.target

[Service]
ExecStart=/opt/embedded-linux-gateway/gateway /dev/ttyS0
Restart=on-failure
RestartSec=2

[Install]
WantedBy=multi-user.target
EOF
sudo systemctl daemon-reload
sudo systemctl enable --now embedded-linux-gateway.service
