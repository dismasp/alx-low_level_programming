#!/bin/bash
gcc -Wall -pedantic -Werror -Wexra -c *.c
ar -rc liball.a *.o
ranlib liball.a
