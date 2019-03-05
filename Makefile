CC=g++
FLAGS= -std=c++11 -c -Wall -O2

all: student_hash.o complex_postfix.o
	$(CC) student_hash.o -o student
	$(CC) complex_postfix.o -o calc

student: student_hash.o
	$(CC) student_hash.o -o student

calc: complex_postfix.o
	$(CC) complex_postfix.o -o calc

student_hash.o: student_hash.cpp
	$(CC) -c student_hash.cpp -o student_hash.o $(FLAGS)

complex_postfix.o: complex_postfix.cpp
	$(CC) -c complex_postfix.cpp -o complex_postfix.o $(FLAGS)

clean:
	rm -f *.o student calc a.out