CONNECTLESS-CLIENT-OBJ = connectionless_oriented_client.o
CC = gcc

client: $(CONNECTLESS-CLIENT-OBJ)
	$(CC) -o client $(CONNECTLESS-CLIENT-OBJ)

connectionless_oriented_client.o: connectionless_oriented_client.c
	$(CC) -c connectionless_oriented_client.c

#clean
.PHONY : clean
clean:
	rm client *.o