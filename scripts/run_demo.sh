#!/usr/bin/env bash
set -euo pipefail
[[ -x build/gateway ]] || make
./build/gateway /dev/nonexistent
