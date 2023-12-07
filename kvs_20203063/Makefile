SRCS = echoclient.c echoserver.c
OBJS = $(SRCS:.c=.o)
LIBSRCS = open.c close.c get.c set.c
LOBJS = $(LIBSRCS:.c=.o)
CC = gcc
OPTS = -Wall -g
LIBS = -L. -lkvs
LARS = libkvs.a


all: client server

client : echoclient.o $(LARS)
	$(CC) -o client $(O) echoclient.o $(LIBS)

server : echoserver.o $(LARS)
	$(CC) -o server $(O) echoserver.o $(LIBS)

$(LARS) : $(LOBJS)
	ar rs $(LARS) $(LOBJS)

%.o: %.c
	$(CC) $(OPTS) -c $< -o $@

clean:
	rm server client answer.dat $(LOBJS) $(OBJS) $(LARS)
