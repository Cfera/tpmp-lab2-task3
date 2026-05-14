
all:
	mkdir -p bin
	gcc -Iinclude src/*.c -o bin/lab2_task3

clean:
	rm -rf bin
