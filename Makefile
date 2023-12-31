##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Build organized
##

CC = gcc
CFLAGS = -Wall -Wextra -I. -I./src/ -L . -lmy -MMD -MP
SHELLFLAGS = -lshell
LDFLAGS = -L . -lmy $(SHELLFLAGS)
RM = rm -f

MAIN_SRC = ./src/main.c
SRC = ./src/organized.c \
	./src/args.c \
	./src/display.c \
	./src/sort.c \
	./src/compare.c
SRC_TEST = ./tests/test_organized.c
OBJS = $(MAIN_SRC:.c=.o) $(SRC:.c=.o)
TEST_OBJS = $(SRC:.c=.o) $(SRC_TEST:.c=.o)

LIB_PATH = ./lib/my

NAME_TEST = unit_tests
NAME = organized

RUN_ARGS =

.PHONY: all build_lib clean_lib fclean_lib clean fclean re tests_run \
	valgrind tests_clean

all: $(NAME)

$(NAME): build_lib $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

$(NAME_TEST): build_lib $(TEST_OBJS)
	$(CC) $(TEST_OBJS) -o $(NAME_TEST) $(LDFLAGS) --coverage -lcriterion

# Rule for building object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

build_lib:
	make -C $(LIB_PATH)

clean_lib:
	make clean -C $(LIB_PATH)

fclean_lib:
	make fclean -C $(LIB_PATH)

clean: clean_lib
	find . -type f \( -name '*.o' -o -name '*.d' \) -delete

fclean: clean fclean_lib tests_clean
	$(RM) $(NAME)

re: fclean all

tests_run: $(NAME_TEST)
	./$(NAME_TEST)

tests_clean:
	$(RM) $(NAME_TEST)
	$(RM) *.gcno *.gcda

run: $(NAME)
	./$(NAME) $(RUN_ARGS)

# Include the dependency files generated by GCC
-include $(OBJS:.o=.d) $(TEST_OBJS:.o=.d)
