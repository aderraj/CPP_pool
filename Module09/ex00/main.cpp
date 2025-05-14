#include "BitcoinExchange.hpp"

int main (int ac, char **av) {
  if (ac != 2)
    return (printErr("invalid args"), 0);
  btcExg(av[1]);
}