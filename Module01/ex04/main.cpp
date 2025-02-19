#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
# define RED "\x1b[31m"
# define RESET "\x1b[0m"
# define BOLD "\x1b[1m"
# define YELLOW "\x1b[33m"

void SearchOccurences( std::ofstream *out, std::string* buffer, char **args ) {

	size_t pos = 0;
	size_t last_pos = 0;
	size_t s1_len = strlen(args[0]);

	while (true) {
			pos = buffer->find(args[0], pos);
			if (pos == std::string::npos)
					break;

			out->write(buffer->c_str() + last_pos, pos - last_pos);
			out->write(args[1], strlen(args[1]));
			
			pos += s1_len;
			last_pos = pos;
	}

	if (last_pos < buffer->length())
		out->write(buffer->c_str() + last_pos, buffer->length() - last_pos);

}

void	SedForLoosers(std::ifstream* in, std::ofstream* out, char **args) {

	std::string buffer;

	while (std::getline(*in, buffer).fail() == false)
	{
		SearchOccurences(out, &buffer, args);
	}
}

int main( int ac, char **av ) {

	if (ac < 4)
	{
		std::cout << BOLD RED "Error: " RESET << "Invalid arguments\n"\
		<< BOLD YELLOW "Usage: " RESET <<  "./SedForLoosers "\
		<< "[filename] [s1] [s2]" << std::endl;
		return (1);
	}

	std::ifstream in(av[1]);
	if (in.fail())
		return (std::cout << BOLD RED "Error: can't open file" RESET << std::endl, 1);

	std::ofstream out((std::string(av[1]) + ".replace").c_str());
	if (out.fail())
		return (in.close(), std::cout << BOLD RED "Error: can't create file"  RESET << std::endl, 1);

	SedForLoosers(&in, &out, &av[2]);
	in.close();
	out.close();
	return (0);
}