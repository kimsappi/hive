#/bin/bash

make clean
echo
echo
echo
echo
echo
echo


gcc -Wall -Wextra -Werror test.c -lft -L.
./a.out
