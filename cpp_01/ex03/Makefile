CXX = c++
CXXFLAGS = -Wall -Wextra -Werror 
SRCS = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp\

OBJS = $(SRCS:.cpp=.o)
NAME = weapon
all: $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re.