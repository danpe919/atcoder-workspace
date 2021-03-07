# Script to initialize submit codes

set -eu
files=(a b c d e f)

read -p "Do you want to overwrite submit codes? (y/N): " yn; case "$yn" in [yY]*) ;; *) exit 1;; esac

cd $(dirname $0)
cd ..

template_file=templates/main.cpp
echo "creating files from $template_file..."
for file in ${files[@]}; do
    cp $template_file $file.cpp
    echo "created $file.cpp"
done
