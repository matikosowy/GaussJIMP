all:
	gcc -Wall --pedantic src/*.c -o bin/gauss

test: all
	bin/gauss dane/A dane/b

test1: all
	bin/gauss dane/Atest1 dane/btest1

test2: all
	bin/gauss dane/Atest2 dane/btest2
