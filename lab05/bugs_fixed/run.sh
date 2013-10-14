#!/bin/bash


icc -openmp -openmp-report2 -Ofast omp_bug1.c -o bug1.exe
icc -openmp -openmp-report2 -Ofast omp_bug2.c -o bug2.exe
icc -openmp -openmp-report2 -Ofast omp_bug3.c -o bug3.exe
icc -openmp -openmp-report2 -Ofast omp_bug4.c -o bug4.exe
