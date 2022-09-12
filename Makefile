CC := gcc
CFLAGS := -Wall -g

SRC := $(wildcard *.c)
OBJS := $(SRC:%.c=%.o)
OUTBIN := psx

.PHONY: install clean

install: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(OUTBIN)


%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@


clean:
	rm $(OUTBIN) $(OBJS)
