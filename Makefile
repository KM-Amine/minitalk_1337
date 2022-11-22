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

all: $(NAME)
bonus: $(NAME)
$(NAME): $(CLIENT) $(SERVER)

$(CLIENT):$(COBJ)
	$(CC) $(CFLAGS) $(COBJ) -o $(CLIENT)
$(SERVER):$(SOBJ)
	$(CC) $(CFLAGS) $(SOBJ) -o $(SERVER)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< 

clean:
	$(RM) $(OBJ) $(COBJ) $(SOBJ)
fclean: clean
	$(RM) $(CLIENT) $(SERVER)
re: fclean all

.PHONY: all clean fclean re bonus