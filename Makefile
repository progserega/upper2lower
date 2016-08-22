upper2lower: upper2lower.o
	gcc upper2lower.o -o upper2lower -lxml2

upper2lower.o: upper2lower.c
	#gcc -g3 -DDEBUG -c -I/usr/include/libxml2 upper2lower.c -o upper2lower.o
	gcc -O3 -c -I/usr/include/libxml2 upper2lower.c -o upper2lower.o

clean:
	rm upper2lower upper2lower.o

install:
	install -o root -g root -m 755 upper2lower /usr/local/bin/upper2lower
