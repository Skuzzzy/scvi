.PHONY: all util clean

all: util

util:
	mkdir -p bin
	find util -iname "*.c" | sed -e "s/\.c//" -e "s/util\///" | xargs -i sh -c "gcc util/{}.c -o bin/{}"

clean:
	rm -f bin/*
