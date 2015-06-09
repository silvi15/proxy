CC = gcc

LDLIBS= -lpthread -lrt

CFLAGS = -g -Wall

all: proxy

proxy: main.o hijo.o parsear.o recuperarURI.o argumentos.o funcion.o
	$(CC) -Wall -o $@ $^

clean:
	rm -fv $(TARGETS) *.o *~
