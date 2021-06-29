#!/bin/sh

dpkg -s python3-venv >/dev/null

cd "$(dirname "$(readlink -f "$0")")"

test ! -d .venv && \
  python3 -m venv --system-site-packages .venv && \
  . .venv/bin/activate && \
  pip install -U pip && \
  pip install pyserial || \
  . .venv/bin/activate

exec python -m serial.tools.miniterm --exit-char 3 /dev/ttyUSB0 9600
