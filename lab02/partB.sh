#!/bin/bash

txt=partb1.txt
br=############################################

in10=matrix.10x10
in100=matrix.100x100
in500=matrix.500x500
in1000=matrix.1000x1000

out10=result.10x10
out100=result.100x100
out500=result.500x500
out1000=result.1000x1000

touch $txt
rm $txt

sh partB_gen_matrix.sh

echo -e "$br" >> $txt
printf "10X10 starting ...\n\n" >> $txt
make matrix-multiply VA=$in10 VB=$in10 VC=$out10 >> $txt
printf "result stored in \'$out10\'" >> $txt
echo -e "\n" >> $txt

echo -e "$br" >> $txt
printf "100X100 starting ...\n\n" >> $txt
make matrix-multiply VA=$in100 VB=$in100 VC=$out100 >> $txt
printf "result stored in \'$out100\'" >> $txt
echo -e "\n" >> $txt

echo -e "$br" >> $txt
printf "500X500 starting ...\n\n" >> $txt
make matrix-multiply VA=$in500 VB=$in500 VC=$out500 >> $txt
printf "result stored in \'$out500\'" >> $txt
echo -e "\n" >> $txt

echo -e "$br" >> $txt
printf "1000X1000 starting ...\n\n" >> $txt
make matrix-multiply VA=$in1000 VB=$in1000 VC=$out1000 >> $txt
printf "result stored in \'$out1000\'" >> $txt
echo -e "\n" >> $txt

exit
