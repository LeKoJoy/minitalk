CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

all: server client

server: server.c
	$(CC) $(CFLAGS) -o server server.c
client: client.c
	$(CC) $(CFLAGS) -o client client.c
clean:
	$(RM) server.o $(RM) client.o
fclean: clean
	$(RM) client $(RM) server

re: clean all
