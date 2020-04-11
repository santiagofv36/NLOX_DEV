CPP 	= g++
NVD 	= nvcc

CFLAGS	= -std=c++11 -O3
LIBRARIES	= -lpthread -lquadmath
# INCLUDE = -I/home/diogenes1991/local/include

SOURCE = QuadFVec
OUT = $(SOURCE).out

all: compile run

compile: 
	$(CPP) $(CFLAGS) $(INCLUDE) $(SOURCE).cpp -o $(SOURCE) $(LIBRARIES) 
clean:
	@rm -f *.o *~ *.mod *# *.str
	
run: 
	./$(SOURCE)

open:
	@kate $(OUT) &
