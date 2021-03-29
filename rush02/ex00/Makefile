CC=gcc
CFLAGS=-Wall -Werror -Wextra
EXEC=rush-02
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
all: $(EXEC)
$(EXEC): $(OBJ)
	$(CC) -o $@ $^
%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)
clean:
	rm -f *.o
fclean: clean 
	rm $(EXEC)
