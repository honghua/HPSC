#!/bin/bash

in10=matrix.10x10
python generate_matrix.py -m 10 -n 10 -f $in10

in100=matrix.100x100
python generate_matrix.py -m 100 -n 100 -f $in100

in500=matrix.500x500
python generate_matrix.py -m 500 -n 500 -f $in500

in1000=matrix.1000x1000
python generate_matrix.py -m 1000 -n 1000 -f $in1000
