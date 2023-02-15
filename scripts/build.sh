#!/bin/bash

ROOT=$(git rev-parse --show-toplevel)

cd "$ROOT/build"
cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=1
cp compile_commands.json ..
make
