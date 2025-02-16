#include <iostream>

void	str_toupper(char *str)
{
	for (int i = 0; str[i]; i++) {
		str[i] = std::toupper(str[i]);
	}
}

int main(int ac, char **av)
{
	if (ac < 2)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n", 1);
	for (int i = 1; av[i]; i++)
		str_toupper(av[i]);
	std::cout << std::endl;
	return (0);
}