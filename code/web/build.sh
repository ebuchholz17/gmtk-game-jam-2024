#!/usr/bin/env bash

# Create directories if they don't exist
mkdir -p ../../build/web

# Run TypeScript compiler
tsc

# Change directory
pushd ../../build/web

# Compile C code to WebAssembly
clang-15 --target=wasm32 -nostdlib -fvisibility=hidden -Wl,--no-entry -Wl,--strip-all -Wl,--export-dynamic -Wl,--import-memory -Wl,--allow-undefined-file=../../code/web/wasm.syms ../../code/web/web_platform.c -o gng.wasm

# Copy index.html
cp -r ../../code/web/index.html* .

# Copy Assets
rm -rf ./assets
cp -r ../../assets .

# Return to original directory
popd
