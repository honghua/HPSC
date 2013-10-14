CC = icpc
OPT = -openmp -openmp-report2 -Ofast
#OPT = -Ofast

HDF5_INCLUDE=-I/curc/tools/x_86_64/rh6/hdf5/1.8.11/szip/2.1/zlib/1.2.78/jpeglib/8d/intel/13.0.0/include
HDF5_LIB_DIR=-L/curc/tools/x_86_64/rh6/hdf5/1.8.11/szip/2.1/zlib/1.2.78/jpeglib/8d/intel/13.0.0/lib
HDF5_LIBS=-lhdf5

MKL_LINK=-Wl,--start-group  $(MKLROOT)/lib/intel64/libmkl_intel_ilp64.a $(MKLROOT)/lib/intel64/libmkl_intel_thread.a $(MKLROOT)/lib/intel64/libmkl_core.a -Wl,--end-group -lpthread -lm
MKL_INCLUDE = -openmp -DMKL_ILP64 -I$(MKLROOT)/include

INCLUDE = $(HDF5_INCLUDE) $(MKL_INCLUDE)
LINK = $(HDF5_LIB_DIR) $(HDF5_LIBS) $(MKL_LINK)

#serial
#EXES = matrix_multiply

#parallel
EXES = matrix_multiply_parallel

A = matrix.A
B = matrix.B
C = matrix.C

all: $(EXES) 

run: $(EXES)
	./$(EXES) $(A) $(B) $(C)

%: %.cpp
	$(CC) $(OPT) $< $(INCLUDE) $(LINK) -o $@

check: 
	python compare.py -a matrix.A -b matrix.B

clean:
	rm -rf $(EXES) 




