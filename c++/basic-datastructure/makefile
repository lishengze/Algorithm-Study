CC = g++
TARGET = a.out
OBJS = main.o Print.o sort.o test.o

$(TARGET):$(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

main.o:main.cpp test.h
	$(CC) -c main.cpp

test.o:test.cpp test.h sort.h
	$(CC) -c test.cpp

sort.o:sort.cpp sort.h
	$(CC) -c sort.cpp

Print.o: Print.cpp Print.h
	$(CC) -c Print.cpp

.PHONY : clean
clean:
	-rm -f *.o
