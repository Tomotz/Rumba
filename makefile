all: make_me

make_me: setos_server.o
	gcc -pthread setos_server.o -o setos_server
	
os_queue.o: os_queue.c
	gcc -c os_queue.c
	
setos_server.o: setos_server.c os_queue.c
	gcc -c setos_server.c
	
clean:
	rm -f os_queue.o setos_server.o setos_server