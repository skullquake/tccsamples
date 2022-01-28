SRC=./src/a.c
BIN=./bin/a.out
CC=gcc
CXX=g++
CFLAGS+=-I../tcc-0.9.27/
LDFLAGS+=-L../tcc-0.9.27/
LDFLAGS+=-ltcc
LDFLAGS+=-ldl
$(BIN):$(SRC)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(SRC) $(LDFLAGS) -o $(BIN)
run:$(BIN)
	$(BIN)
.phony:clean
clean:
	rm $(BIN)
