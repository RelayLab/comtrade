SRC=$(wildcard *.c)
NAME =comtrade2csv

all: $(SRC)
	gcc $(SRC) -g -o $(NAME)
	
clean:
	-rm $(NAME)
