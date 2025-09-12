#!/bin/bash

    NDIR=$(find / -name "n.txt" 2>/dev/null | head -n 1)
    EDIR=$(find / -name "e.txt" 2>/dev/null | head -n 1)
    mv "$NDIR" /home/iulia/Documents/PlatformIO/Projects/ananas/data/
    mv "$EDIR" /home/iulia/Documents/PlatformIO/Projects/ananas/data/

    cd /home/iulia/Documents/PlatformIO/Projects/ananas/

    if  [ "$(ls -A data)" ]; then
        echo "data"
        if platformio run --target uploadfs --environment nodemcuv2; then
            echo "upload successful removing folder"
            rm -rf data
            mkdir data
            echo "finished the thing"
        else
            $(ls -A $DIR)echo "Upload failed! Keeping existing data directory."
            exit 1
        fi
    else
        echo "no"
        exit 1
    fi

