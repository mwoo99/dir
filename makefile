dir: dir.c
	gcc dir.c -o dir

run: dir
	./dir

clean:
	-rm *~
	-rm dir