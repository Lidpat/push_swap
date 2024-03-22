#!/bin/sh

#read -p "stack size: " lst_size
lst_size=$1

ARG=$(ruby -e "puts (1..$lst_size).to_a.shuffle.join(' ')")
mv_num=$(./push_swap $ARG | wc -l)
echo $mv_num
ret=$(./push_swap $ARG | ./checker_Mac $ARG)
echo $ret

