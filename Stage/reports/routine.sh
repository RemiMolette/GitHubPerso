#!/bin/sh

echo "Préparation du rapport"

make
gnome-open report.pdf
