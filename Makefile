
CC=gcc
CFLAGS=-lpulse-simple -lpulse
OBJ = paimpersonate.o

paimpersonate: $(OBJ)
	$(CC)  $(CFLAGS) -o $@ $^

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm $(OBJ) paimpersonate
