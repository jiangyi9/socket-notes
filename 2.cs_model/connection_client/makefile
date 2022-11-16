CONNECT-CLIENT-OBJ = connection_oriented_client.o
CC = gcc

client: $(CONNECT-CLIENT-OBJ)
	$(CC) -o client $(CONNECT-CLIENT-OBJ)

connection_oriented_client.o: connection_oriented_client.c
	$(CC) -c connection_oriented_client.c

#clean
.PHONY : clean
clean:
	rm client *.o