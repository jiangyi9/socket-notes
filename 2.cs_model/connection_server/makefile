CONNECT-SERVER-OBJ = connection_oriented_server.o
CC = gcc

server: $(CONNECT-SERVER-OBJ)
	$(CC) -o server $(CONNECT-SERVER-OBJ)

connection_oriented_server.o: connection_oriented_server.c
	$(CC) -c connection_oriented_server.c

#clean
.PHONY : clean
clean:
	rm server *.o