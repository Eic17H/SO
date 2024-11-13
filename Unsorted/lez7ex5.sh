#!/bin/bash
# converte un file da minuscolo a maiuscolo e non vice versa
if test $# -lt 1; then
	echo "Inserisci il nome di un file"
else
	# controlla che esista il file
	if [ ! -e "$1" ]; then
		echo Inserisci il nome di un file esistente
	else
		cat ${1} | tr a-z A-Z > maiusc_${1}
fi fi
