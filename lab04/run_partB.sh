#!/bin/bash

files="10 100 500 1000 2000 5000 10000"
result=result_partB.txt

make

for i in $files
do
    python generate_matrix.py -m $i -n $i -f matrix.A.h5 -t h5
    python generate_matrix.py -m $i -n $i -f matrix.B.h5 -t h5
    psrun  ./matrix_multiply matrix.A.h5 matrix.B.h5 matrix.C.h5
    psrun  ./naive matrix.A.h5 matrix.B.h5 matrix.C.h5

    rm matrix.*.h5
done 

# process the data
generate_list()
{
    ls *.xml
}

touch $result
rm -f $result

for i in $(generate_list)
do
    psprocess $i > ${i}.result
    printf "$i\n" >> $result
    grep 'Wall' ${i}.result >> $result
    grep 'Level 2 cache misses' ${i}.result >> $result
    grep 'Level 3 cache misses' ${i}.result >> $result
    echo -e "\n" >> $result
    rm ${i}.result
done 

exit 0

