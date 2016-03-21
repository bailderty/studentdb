CC = g++

all: Student.o Database.o P2.o
	$(CC) -o test $?

Student.o: Student.cpp
	$(CC) -c $?

Database.o: Database.cpp
	$(CC) -c $?

P2.o: P2.cpp
	$(CC) -c $?

clean:
	rm -f *.o test