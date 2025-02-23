NAME = pipex
CC = gcc
CFLAGS = #-Wall -Wextra -Werror
SRC = ./src/pipex.c ./src/check_cmd.c ./src/handle_error.c ./utils/handle_error.c ./utils/ft_split.c ./utils/ft_strlen.c  ./utils/ft_strncmp.c ./utils/ft_strjoin.c
OBJ = $(SRC:.c=.o)

GREEN       := \033[32m
YELLOW      := \033[33m
CYAN        := \033[36m
RESET       := \033[0m
OK_SIGN     := ✅
ERROR_SIGN  := ❌
INFO_SIGN   := ℹ️
WORKING     := 🔧

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(OK_SIGN) $(GREEN)Build successful: $(NAME)$(RESET)"


%.o: %.c ./include/pipex.h
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(WORKING) $(CYAN)Compiling: $<$(RESET)"

clean:
	@echo "$(INFO_SIGN) $(YELLOW)Cleaning object files...$(RESET)"
	@rm -f $(OBJ)
	@echo "$(OK_SIGN) $(GREEN)Object files cleaned!$(RESET)"

fclean: clean
	@echo "$(INFO_SIGN) $(YELLOW)Removing executables: $(NAME) and $(RESET)"
	@rm -f $(NAME) 
	@echo "$(OK_SIGN) $(GREEN)Executables removed!$(RESET)"

re: fclean all
