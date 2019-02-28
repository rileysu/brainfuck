src = $(wildcard src/*.c)
headers = $(wildcard src/*.h)
out = bin/brainfuck.out

CFLAGS = -O2 

all: $(out)

$(out):
	$(CC) $(CFLAGS) $(src) -Isrc -o $@

clean:
	rm -f $(out)
