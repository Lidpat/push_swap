#!/bin/sh

read -p "stack size: " lst_size

ARG=$(ruby -e "puts (1..$lst_size).to_a.shuffle.join(' ')")
#ret=$(./push_swap $ARG | wc -l)
#outmsg=$(./push_swap $ARG | tail -n 1)
#echo $outmsg
#echo $ret

ret=$(./push_swap $ARG | ./checker_Mac $ARG)
echo $ret
