GXX = g++
OBJ_PATH = ./obj/
SRC_PATH = ./src/
TARGET = program.out

build:
	$(GXX) -fPIC -c $(SRC_PATH)main.cpp -o $(OBJ_PATH)main.o 
	$(GXX) -fPIC -c $(SRC_PATH)pow.cpp -o $(OBJ_PATH)pow.o
	$(GXX) -shared -fPIC -o libpow.so $(OBJ_PATH)pow.o
	$(GXX) $(SRC_PATH)main.cpp -o $(TARGET) -L. -lpow
	export LD_LIBRARY_PATH=./

debug:
	$(GXX) -g -fPIC -c $(SRC_PATH)main.cpp -o $(OBJ_PATH)main.o 
	$(GXX) -g -fPIC -c $(SRC_PATH)pow.cpp -o $(OBJ_PATH)pow.o
	$(GXX) -g -shared -fPIC -o libpow.so $(OBJ_PATH)pow.o
	$(GXX) -g $(SRC_PATH)main.cpp  -o deb$(TARGET) -L. -lpow
	export LD_LIBRARY_PATH=./

clean:
	rm $(OBJ_PATH)*.o 