
all: test_pet.exe

test_pet.exe: test_pet.cpp pet.o dog.o
	g++ -g test_pet.cpp pet.o dog.o -o test_pet.exe

pet.o: pet.h pet.cpp
	g++ -c pet.cpp

dog.o: dog.h dog.cpp
	g++ -c dog.cpp

clean: 
	del test_pet.exe dog.o pet.o

run: test_pet.exe
	./test_pet.exe