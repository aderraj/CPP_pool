ERASE		:=  \033[2K\r
BLUE		:=	\033[34m
YELLOW	:=	\033[33m
GREEN		:=	\033[32m
MAGENTA	:=	\033[35m
BOLD		:=	\033[1m
END			:=	\033[0m

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -g
NAME = Interface
SRCS = AMateria.cpp ICharacter.cpp Character.cpp Cure.cpp Ice.cpp\
			IMateriaSource.cpp MateriaSource.cpp main.cpp
INCLUDES = AMateria.hpp ICharacter.hpp Character.hpp Cure.hpp Ice.hpp\
			IMateriaSource.hpp MateriaSource.hpp Colors.hpp
OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(CPPFLAGS) -o $@
	@printf "$(ERASE)$(GREEN)--> $@ made <--$(END)\n"

$(OBJS_DIR)/%.o: %.cpp Makefile $(INCLUDES)
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CPPFLAGS) -c $< -o $@
	@printf "$(BLUE) > Compilation :$(END) $<\r"

clean:
	@printf "$(MAGENTA)-->	$(OBJS_DIR) removed$(END)\n"
	@rm -rdf $(OBJS_DIR)

fclean: clean
	@printf "$(MAGENTA)-->	$(NAME) removed$(END)\n"
	@rm -f $(NAME)

re: fclean all

.PHONY:		all clean fclean re