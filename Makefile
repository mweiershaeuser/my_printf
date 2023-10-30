##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile 1
##

SRC	=	lib/my/helpers.c	\
		lib/my/my_compute_power_rec.c	\
		lib/my/my_compute_square_root.c	\
		lib/my/my_find_prime_sup.c	\
		lib/my/my_getint_base.c 	\
		lib/my/my_getint_base_len.c         \
		lib/my/my_getnbr.c	\
		lib/my/my_get_nbr_len.c	\
		lib/my/my_isneg.c	\
		lib/my/my_is_prime.c	\
		lib/my/my_putchar.c	\
		lib/my/my_put_ll.c      \
		lib/my/my_put_nbr.c	\
		lib/my/my_putfloat.c	\
		lib/my/my_putstr.c	\
		lib/my/my_revstr.c	\
		lib/my/my_showmem.c	\
		lib/my/my_showstr.c	\
		lib/my/my_show_word_array.c	\
		lib/my/my_sort_int_array.c	\
		lib/my/my_strcapitalize.c	\
		lib/my/my_strcat.c	\
		lib/my/my_strcmp.c	\
		lib/my/my_strcpy.c	\
		lib/my/my_str_isalpha.c	\
		lib/my/my_str_islower.c	\
		lib/my/my_str_isnum.c	\
		lib/my/my_str_isprintable.c	\
		lib/my/my_str_isupper.c	\
		lib/my/my_strlen.c	\
		lib/my/my_strlowcase.c	\
		lib/my/my_strncat.c	\
		lib/my/my_strncmp.c	\
		lib/my/my_strncpy.c	\
		lib/my/my_strstr.c	\
		lib/my/my_str_to_word_array.c	\
		lib/my/my_strupcase.c	\
		lib/my/my_swap.c	\
		my_printf.c		\
		basic_flags.c		\
		handle_int.c		\
		change_base.c		\
		p_flag.c		\
		e_flag.c		\
		handle_c.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

TESTS	=	unit_tests

.PHONY: all clean_emacs clean_tests clean fclean re tests_run tests_run_cov

all: $(NAME)

$(NAME):	$(OBJ)
	ar rc -o $(NAME) $(OBJ)

clean_emacs:
	find . \( -name "*~" -or -name "#*#" \) -delete

clean_tests:
	rm -f $(TESTS)
	rm -rf coverage

clean: clean_emacs
	rm -f $(OBJ)

fclean:		clean clean_tests
	rm -f $(NAME)

re: fclean all

$(TESTS): re
	mkdir -p coverage
	cd coverage && \
	gcc -o $(TESTS) ../tests/*.c -L ../ -lmy --coverage -lcriterion

tests_run: $(TESTS)
	cd coverage && ./$(TESTS)

tests_run_cov: $(TESTS)
	mkdir -p coverage
	cd coverage && \
	gcc -o $(TESTS) ../*.c ../tests/*.c -L ../ -lmy --coverage -lcriterion
	cd coverage && ./$(TESTS)
	gcovr --exclude tests
	gcovr --exclude tests --branches
