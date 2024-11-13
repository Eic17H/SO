#!/bin/bash
cut -d' ' -f1 rubrica.txt | sort | uniq -c
echo I seguenti elementi non sono ricercatori:
grep "^[^(Ricercatore)].*$" rubrica.txt
grep "^.*\.it$" rubrica.txt > italia.txt
