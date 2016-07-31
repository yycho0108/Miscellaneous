
CXXFLAGS = -O3 -Wall -std=c++11 -I/usr/local/cuda/include/

NVCCFLAGS = -O3 -arch sm_20 -c
#NVCCFLAGS = -O3 -gencode arch=compute_20,code=sm_20 -c
NVCCFLAGS += -D_FORCE_INLINES -ccbin=$(CXX) -Xcompiler -fPIC $(COMMON_FLAGS) --std=c++11

all : program

program : Matrix.o Size.o RandManager.o Utility.o main.cpp
	g++ -o program $(CXXFLAGS) main.cpp Matrix.o Size.o RandManager.o Utility.o -L/usr/local/cuda/lib64 -lcuda -lcudart -lcurand 

Matrix.o: Size.o RandManager.o Utility.o Matrix.cu
	nvcc -lib Matrix.o $(NVCCFLAGS) Matrix.cu Size.o RandManager.o Utility.o

Size.o : Size.cpp
	g++ -o Size.o $(CXXFLAGS) Size.cpp -c

RandManager.o : RandManager.cu
	nvcc -o RandManager.o $(NVCCFLAGS) RandManager.cu

Utility.o : Utility.cu
	nvcc -o Utility.o $(NVCCFLAGS) Utility.cu

clean :
	rm -rf *.o program
