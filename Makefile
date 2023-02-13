##
## EPITECH PROJECT, 2023
## B-ASM-400-NAN-4-1-bsasmminilibc-alexandre.franquet
## File description:
## Makefile
##

SRC_SHARED_LIB	=	src/strlen.asm		\
					src/strchr.asm		\
					src/strrchr.asm		\
					src/memset.asm		\
					src/memcpy.asm		\
					src/strcmp.asm		\
					src/memmove.asm		\
					src/strncmp.asm		\
					src/strcasecmp.asm	\
					src/strstr.asm		\

SRC_TESTS		=	tests/tests.c

TEST_FLAGS		=	-lcriterion

TEST_NAME		=	unit_tests

NASM			=	nasm

CC				=	gcc

OBJ				=	$(SRC_SHARED_LIB:%.asm=%.o)

ASM_FLAGS		=	-f elf64 -DPIC

INCLUDE			=	-I./include

LD 				=	ld

LD_FLAGS		=	-shared

NAME			=	libasm.so

RM				=	rm -rf

all:		$(NAME)

%.o:		%.asm
			$(NASM) $(ASM_FLAGS) $< -o $@

$(NAME):	$(OBJ)
			$(LD) $(LD_FLAGS) -o $(NAME) $(OBJ)

tests_run:	fclean $(NAME)
			$(CC) $(SRC_TESTS) $(TEST_FLAGS) $(INCLUDE) -o $(TEST_NAME) -ldl
			./$(TEST_NAME)

clean:
			$(RM) $(OBJ)
			$(RM) $(TEST_NAME)
			$(RM) *.gc*

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

debug:		CFLAGS += -g
debug:		re

.PHONY:		all clean fclean re tclean debug tests_run $(NAME) %.asm