#!/bin/sh

read -p "stack size: " lst_size

ARG=$(ruby -e "puts (1..$lst_size).to_a.shuffle.join(' ')")
ret=$(./push_swap $ARG | wc -l)
echo $ret
