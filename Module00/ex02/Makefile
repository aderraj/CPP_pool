ERASE		:=  \033[2K\r
BLUE		:=	\033[34m
YELLOW		:=	\033[33m
GREEN		:=	\033[32m
MAGENTA		:=	\033[35m
CYAN		:=	\033[36m
BOLD		:=	\033[1m
END			:=	\033[0m

CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = account
SRCS = Account.cpp tests.cpp
OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(CXXFLAGS) -o $@
	@printf "$(ERASE)$(GREEN)--> $@ made <--$(END)\n"

$(OBJS_DIR)/%.o: %.cpp Makefile Account.hpp
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CXXFLAGS) -c $< -o $@
	@printf "$(BLUE) > Compilation :$(END) $<\r"
	@sleep 0.2

clean:
	@printf "$(MAGENTA)-->	$(OBJS_DIR) removed$(END)\n"
	@rm -rdf $(OBJS_DIR)

fclean: clean
	@printf "$(MAGENTA)-->	$(NAME) removed$(END)\n"
	@rm -f $(NAME)

re: fclean all

.PHONY:		all libft clean fclean re