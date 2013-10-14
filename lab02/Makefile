
GCC = g++
ICC = icc
PI = pi.cpp
PIEXE = pi
MEXE = matrix_multiply

VA = matrixA
VB = matrixB
VC = matrixC

intel-slow: $(PI)
	$(ICC)  -O0 -no-vec $(PI) -o $(PIEXE)
	./$(PIEXE)

intel-novec: $(PI)
	$(ICC) -O2 -no-vec $(PI) -o $(PIEXE)
	./$(PIEXE)

intel-fast: $(PI)
	$(ICC) -Ofast $(PI) -o $(PIEXE)
	./$(PIEXE)

gcc-slow: $(PI)
	$(GCC) -O0 $(PI) -o $(PIEXE)
	./$(PIEXE)

gcc-novec: $(PI)
	$(GCC) -O2 $(PI) -o $(PIEXE)
	./$(PIEXE)	

gcc-fast: $(PI)
	$(GCC) -O3 $(PI) -o $(PIEXE)
	./$(PIEXE)

matrix-multiply: matrix_multiply.cpp
	$(GCC)  matrix_multiply.cpp -o $(MEXE)
	./$(MEXE) $(VA) $(VB) $(VC)

cpuinfo:
	cat /proc/cpuinfo | grep 'cpu MHz'

clean:
	rm -f $(PIEXE) $(MEXE)

check:
	/curc/tools/grading/scripts/check
