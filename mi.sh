#!/bin/bash

echo "works"

if platformio run --target uploadfs --environment nodemcuv2; then
    echo "upload successful removing folder"
    rm -rf data
    mkdir data
    echo "finished the thing"
else
    echo "Upload failed! Keeping existing data directory."
    exit 1
fi
