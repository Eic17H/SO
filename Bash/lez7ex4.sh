#!/bin/bash
# prende in input due numeri, dice se la somma è più grande di 10
if test $# -eq 2; then
	if test $(($1+$2)) -gt 10; then
		echo "grande"; else
		echo "piccolo"; fi
elif test $# -eq 0; then
	echo "Inserisci due parametri"
elif test $# -eq 1; then
	echo "Inserisci un altro parametro"
else
	echo "Inserisci due parametri"
fi
