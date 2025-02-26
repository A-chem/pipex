NAME = pipex
CC = cc
CFLAGS = #-Wall -Wextra -Werror
SRC = ./Mandatory/src/pipex.c ./Mandatory/utils/ft_split.c ./Mandatory/utils/ft_putstr.c ./Mandatory/utils/ft_strjoin.c ./Mandatory/utils/ft_strlen.c ./Mandatory/utils/ft_strncmp.c  ./Mandatory/utils/fonction_utils.c ./Mandatory/src/check_exec_cmd.c   ./Mandatory/src/handle_error1.c ./Mandatory/src/handle_error2.c 
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


%.o: %.c ./Mandatory/include/pipex.h
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