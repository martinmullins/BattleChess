#!/usr/bin/env bash
# setup.sh - Install the Battle Chess build toolchain
# Run once on a fresh system before using `make`
set -euo pipefail

WATCOM_INSTALL=/opt/watcom
OW_URL="https://github.com/open-watcom/open-watcom-v2/releases/download/Current-build/ow-snapshot.tar.xz"

echo "=== Battle Chess Build Toolchain Setup ==="

# ── 1. NASM ──────────────────────────────────────────────────────────────────
if command -v nasm &>/dev/null; then
    echo "[OK] NASM already installed: $(nasm --version | head -1)"
else
    echo "[..] Installing NASM..."
    sudo apt-get install -y nasm
    echo "[OK] NASM installed."
fi

# ── 2. Open Watcom V2 ─────────────────────────────────────────────────────────
if [ -f "$WATCOM_INSTALL/binl64/wcc" ]; then
    echo "[OK] Open Watcom already installed at $WATCOM_INSTALL"
else
    echo "[..] Downloading Open Watcom V2 snapshot (~144 MB)..."
    TMP=$(mktemp -d)
    curl -L -o "$TMP/ow-snapshot.tar.xz" "$OW_URL"
    echo "[..] Extracting to $WATCOM_INSTALL..."
    sudo mkdir -p "$WATCOM_INSTALL"
    sudo tar -xf "$TMP/ow-snapshot.tar.xz" -C "$WATCOM_INSTALL"
    rm -rf "$TMP"
    echo "[OK] Open Watcom installed at $WATCOM_INSTALL"
fi

# ── 3. Environment ────────────────────────────────────────────────────────────
PROFILE_SNIPPET='
# Open Watcom V2 (Battle Chess build toolchain)
export WATCOM=/opt/watcom
export PATH=$WATCOM/binl64:$PATH
export INCLUDE=$WATCOM/h
'

if ! grep -q "WATCOM=" ~/.bashrc 2>/dev/null; then
    echo "$PROFILE_SNIPPET" >> ~/.bashrc
    echo "[OK] Added WATCOM env vars to ~/.bashrc"
else
    echo "[OK] WATCOM env vars already in ~/.bashrc"
fi

export WATCOM=/opt/watcom
export PATH=$WATCOM/binl64:$PATH
export INCLUDE=$WATCOM/h

echo ""
echo "=== Toolchain ready ==="
echo "  wcc  (16-bit C compiler): $(wcc --version 2>&1 | head -1)"
echo "  wlink (linker):           $(wlink --version 2>&1 | head -1)"
echo "  nasm (assembler):         $(nasm --version)"
echo ""
echo "Run 'make' to build CHESS.EXE"
