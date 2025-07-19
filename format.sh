find . -iname '*.h' -o -iname '*.c' -not -path "*/External/*"  | clang-format --style=file -i --files=/dev/stdin
