#!/bin/bash

source="main.c"
build="gtk_calculator"

echo ""
echo "-------------------------"
echo "Compiling $source..."
echo "-------------------------"
echo ""

gcc -o "$build" "$source" $(pkg-config --cflags --libs gtk4) 2>&1
status=$?

if [ $status -eq 0 ]; then
    echo "Compilation successful !"
    
    echo ""
    echo "-------------------------"
    read -p "Run? (y/n): " answer
    echo "-------------------------"
    echo ""

    if [ "$answer" == "y" ]; then
        chmod u+x "$build"
        ./"$build"
    fi
else
    echo ""
    echo "-----------------------"
    echo ""
fi
