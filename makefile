CC = gcc
LD = gcc
CFLAGS = -g -I.
LDFLAGS =

src = $(wildcard *.c)
obj = $(src:.c=.o)
out = $(src:.c=)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(out): % : %.o test/test.o
	$(LD) $(LDFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm -f test/test.o $(obj) $(out)
