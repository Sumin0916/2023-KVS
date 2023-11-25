STATIC_SRCS = static_main.c
DYNAMIC_SRCS = dynamic_main.c
LIBSRCS = open.c close.c set.c get.c do_snapshot_baseline.c 
STATIC_TARG = kvs_static
DYNAMIC_TARG = kvs_dynamic

CC = gcc
OPTS = -Wall -g
STATIC_LIBS = -L. -lkvs
DYNAMIC_LIBS = -L. -lkvs - ldl

STATIC_OBJS = $(STATIC_SRCS:.c=.o)
DYNAMIC_OBJS = $(DYNAMIC_SRCS:.c=.o)
LOBJS = $(LIBSRCS:.c=.o)
LARS = libkvs.a
LDLL = libkvs.so
LDFLAGS = -shared

all:

static: $(STATIC_TARG)

$(STATIC_TARG) : $(STATIC_OBJS) $(LARS)
	$(CC) -o $(STATIC_TARG) $(STATIC_OBJS) $(STATIC_LIBS) 

$(LARS) : $(LOBJS)
	ar rs $(LARS) $(LOBJS)


dynamic: $(DYNAMIC_TARG)

$(DYNAMIC_TARG) : $(DYNAMIC_OBJS) $(LDLL)
	$(CC) -fPIC -o $(DYNAMIC_TARG) $(DYNAMIC_SRCS)

$(LDLL) : $(LOBJS)
	$(CC) $(LDFLAGS) -fPIC -o $(LDLL) $(LIBSRCS)


%.o: %.c
	$(CC) $(OPTS) -c $< -o $@

clean:
	rm -f $(OBJS) $(LOBJS) $(LARS) $(TARG) $(LDLL) $(STATIC_OBJS) $(DYNAMIC_OBJS) $(STATIC_TARG) $(DYNAMIC_TARG)
