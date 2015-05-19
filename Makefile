CC = gcc

LDLIBS= -lpthread -lrt

CFLAGS = -g -Wall

all: proxy

proxy: main.c hijo.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

clean:
	rm -fv proxy
