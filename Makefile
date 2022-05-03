compile: atv5.c
	gcc atv5.c -o atv5 -lpthread

run:
	./atv5

clean:
	rm -rf *.o atv5
