#!/bin/bash
output=`uname -$1 2> /dev/null`
empty=""
if [ "${output}" != "${empty}" ];
then echo ${output};
else echo Questa non e\' un\'opzione;
fi
