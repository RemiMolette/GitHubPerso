#!/bin/sh

echo "Update Git du rapport"

make

git add -A
git commit -m "Auto update.sh"
git push
