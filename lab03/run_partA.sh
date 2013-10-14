#!/bin/bash
# partA.sh: file IO speed compare

br=################################################
result=partA_result.txt

files="10 100 500 1000 5000 10000 15000"

touch $result
rm -f $result
rm -f matrix.*

# generate matrix
for i in $files
do
    python generate_matrix.py -m $i -n $i -f matrix.${i}x${i}.h5 -t h5
    python generate_matrix.py -m $i -n $i -f matrix.${i}x${i}.txt -t txt
done

# matrix input/output
for i in $files
do
    echo -e "\n$br" >> $result
    printf "matrix.${i}x${i} starting ... \n" >> $result

    printf "\ntxt file reading time: " >> $result
    (time ./io_text matrix.${i}x${i}.txt) >> $result 2>&1

    printf "\nhdf file reading time: " >> $result
    (time ./io_hdf matrix.${i}x${i}.h5) >> $result 2>&1
done

exit 0
