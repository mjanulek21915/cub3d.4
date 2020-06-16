FILE=$1
if [ -z "$FILE" ]
then
    FILE=main
fi
gcc -fsanitize=address -g \
main/$FILE.c src/lib/*.c src/mk_map_cub/*.c debug/*.c \
-I inc \
# -lXext -lX11 -lm -lbsd -lXrandr