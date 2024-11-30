CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = xa
AR = ar 
ARFLAGS = -rc

OBJECT_FILES = get_next_line.o get_next_line_utils.o


all : $(NAME)

$(NAME) : $(OBJECT_FILES)
	$(AR) $(ARFLAGS) $(NAME) $^

%.o : %.c get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJECT_FILES)

fclean : clean
	rm -f $(NAME)

re : fclean all