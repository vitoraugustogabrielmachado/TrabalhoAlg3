CC = gcc
CFLAGS = -Wall
TARGET = inicio
SRC = inicio.c arvore.c heap.c util.c
OBJ = inicio.o arvore.o heap.o util.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET) $(LIBS)

inicio.o: inicio.c arvore.h heap.h util.h
	$(CC) $(CFLAGS) -c inicio.c -o inicio.o $(LIBS)

arvore.o: arvore.c arvore.h
	$(CC) $(CFLAGS) -c arvore.c -o arvore.o $(LIBS)

heap.o: heap.c heap.h
	$(CC) $(CFLAGS) -c heap.c -o heap.o $(LIBS)

util.o: util.c util.h
	$(CC) $(CFLAGS) -c util.c -o util.o $(LIBS)

clean:
	rm -f $(TARGET) $(OBJ)
