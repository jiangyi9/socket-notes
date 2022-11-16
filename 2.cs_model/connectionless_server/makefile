CONNECTLESS-SERVER-OBJ = connectionless_oriented_server.o
CC = gcc

server: $(CONNECTLESS-SERVER-OBJ)
	$(CC) -o server $(CONNECTLESS-SERVER-OBJ)

connectionless_oriented_server.o: connectionless_oriented_server.c
	$(CC) -c connectionless_oriented_server.c

#clean
.PHONY : clean
clean:
	rm server *.o