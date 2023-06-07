##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC     =	lib/my/my_compute_power_rec.c 	\
			lib/my/my_find_prime_sup.c 	\
			lib/my/my_is_prime_it.c 	\
			lib/my/my_is_prime.c 	\
			lib/my/my_isneg.c 	\
			lib/my/my_pow.c 	\
			lib/my/my_put_nbr.c 	\
			lib/my/my_putchar.c 	\
			lib/my/my_putstr.c 	\
			lib/my/my_revstr.c 	\
			lib/my/my_show_word_array.c 	\
			lib/my/my_str_isalpha.c 	\
			lib/my/my_str_islower.c 	\
			lib/my/my_str_isnum.c 	\
			lib/my/my_str_isprintable.c 	\
			lib/my/my_str_isupper.c 	\
			lib/my/my_strcapitalize.c 	\
			lib/my/my_strcat.c 	\
			lib/my/my_strcpy.c 	\
			lib/my/my_strdup.c 	\
			lib/my/my_strlen.c 	\
			lib/my/my_strlowcase.c 	\
			lib/my/my_strncat.c 	\
			lib/my/my_strncmp.c 	\
			lib/my/my_strncpy.c 	\
			lib/my/my_strstr.c 	\
			lib/my/my_strupcase.c 	\
			lib/my/my_swap.c 	\
			lib/my/rev_char.c	\
			lib/my/my_getnbr.c 	\
			lib/my/my_strcmp.c 	\
			lib/my/my_strchr.c 	\
			src/menu_test.c 	\

OBJ =   $(SRC:.c=.o)

CFLAGS = -W -Wall -Wextra -Wshadow

NAME =  mypaint

all:    $(NAME)

$(NAME):    $(OBJ)
		gcc -o $(NAME) $(CFLAGS) $(OBJ) -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window
tests_run:
	gcc -o unit_tests $(SRC) tests/test.c --coverage -lcriterion
	./unit_tests && gcovr && gcovr --exclude tests/ --branches
clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)
		rm -f unit_tests
		rm -f *.gcda
		rm -f *.gcno

re: fclean all
