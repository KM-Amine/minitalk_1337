NAME = client-server
CC = gcc
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror -I .
RM = rm -rf
HEADER  = minitalk.h
CLIENT = client
SERVER = server

COBJ = client.o
SOBJ = server.o

BCLIENT = client_bonus
BSERVER = server_bonus

BCOBJ = client_bonus.o
BSOBJ = server_bonus.o

all: $(NAME)

$(NAME): $(CLIENT) $(SERVER)

$(CLIENT):$(COBJ)
	$(CC) $(CFLAGS) $(COBJ) -o $(CLIENT)
$(SERVER):$(SOBJ)
	$(CC) $(CFLAGS) $(SOBJ) -o $(SERVER)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< 

bonus: $(BCLIENT) $(BSERVER) 

$(BCLIENT):$(BCOBJ)
	$(CC) $(CFLAGS) $(BCOBJ) -o $(BCLIENT)
$(BSERVER):$(BSOBJ)
	$(CC) $(CFLAGS) $(BSOBJ) -o $(BSERVER)

clean:
	$(RM) $(COBJ) $(SOBJ) $(BCOBJ) $(BSOBJ)
fclean: clean
	$(RM) $(CLIENT) $(SERVER) $(BSERVER) $(BCLIENT)
re: fclean all

.PHONY: all clean fclean re bonus