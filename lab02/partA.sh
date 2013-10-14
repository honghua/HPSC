#!/bin/bash

txt=parta_list.txt
touch $txt
rm $txt

printf "make intel-slow \n" >> $txt
make intel-slow >> $txt
echo -e "\n" >> $txt

printf "make intel-novec \n" >> $txt
make intel-novec >> $txt
echo -e "\n" >> $txt

printf "make intel-fast \n" >> $txt
make intel-fast >> $txt
echo -e "\n" >> $txt

printf "make gcc-slow \n" >> $txt
make gcc-slow >> $txt
echo -e "\n" >> $txt

printf "make gcc-novec \n" >> $txt
make gcc-novec >> $txt
echo -e "\n" >> $txt

printf "make gcc-fast \n" >> $txt
make gcc-fast >> $txt
echo -e "\n" >> $txt

exit
