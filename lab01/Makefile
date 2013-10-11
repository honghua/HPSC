# modified makefile for lab-01
#
# purpose: Benchmark test for Janus suprcomputer performance
# author: Honghua Yang
# ref: http://www.gnu.org/software/make/manual/make.html#toc_Makefiles

# original Makefile
	# CC = icc
	# FC = ifort
	# OPT = -O2
	# 
	# build: timing.o dummy.o triad.f90
	# 	$(FC) $(OPT) timing.o dummy.o triad.f90 -o triad  
	# 
	# timing.o: timing.c
	# 	$(CC) $(OPT) -c timing.c
	# 
	# dummy.o: dummy.c
	# 	$(CC) $(OPT) -c dummy.c
	# 
	# clean:
	# 	rm -f *.o triad
	# 
	# check: 
	# 	/curc/tools/grading/scripts/check

# define variables: following _Monte Lunacek_'s notation
CC = icc
FC = ifort
OPT = -O2
EXE = triad
OBJ = triad.o dummy.o timing.o


all: $(EXE)

$(EXE): $(OBJ)
	$(FC) $(OPT) $(OBJ) -o $(EXE)

# Pattern rules: http://www.gnu.org/software/make/manual/make.html#Pattern-Rules
%.o: %.f90
	$(FC) $(OPT) -c $<

# Automatic variables: http://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html\
	$@: The file name of the target of the rule.\
	$<: The name of the first prerequisite.
%.o: %.c
	$(CC) $(OPT) -c $< -o $@

timing.o: timing.h

# generate data to scaling.csv
run: scaling.py
	rm -f scaling.csv
	touch scaling.csv
	/usr/bin/python scaling.py

# automatic check result
check:
	/curc/tools/grading/scripts/check

clean:
	rm -f *.o triad
