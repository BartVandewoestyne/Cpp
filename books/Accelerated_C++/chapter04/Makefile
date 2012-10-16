CXX = g++
CC = g++

all:		main

Student_info.o:	Student_info.cpp Student_info.h

grade.o:	grade.cpp grade.h median.h Student_info.h

main.o:	main.cpp grade.h median.h Student_info.h

median.o:	median.cpp median.h

main:		main.o grade.o median.o Student_info.o

test:		all
	./main <../data/grades

clean:
	rm -f *.o *.exe core main
