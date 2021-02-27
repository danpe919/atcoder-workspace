# Script to initialize submit codes

set -eu
files=(a b c d e f)

read -p "Do you want to overwrite submit codes? (y/N): " yn; case "$yn" in [yY]*) ;; *) exit 1;; esac

cd $(dirname $0)
cd ..

for f in ${files[@]}; do
    cp templates/main.cpp $f.cpp
done
