#!/bin/bash

gcc source1.c -o code1
gcc source2.c -o code2
echo 
echo cmp sorgente:
cmp source1.c source2.c
echo 
echo cmp eseguibile:
cmp code1 code2
echo 
echo diff sorgente:
diff source1.c source2.c
echo 
echo diff eseguibile:
diff code1 code2
echo 
echo Descrivi il risultato di tali operazioni