#include "BitcoinExchange.hpp"

bool  bitcoin::parseLine(const std::string& line) {
  std::istringstream s(line);
  std::string date, rate;

  if (std::getline(s, date, ',') && std::getline(s, rate, ',')) {
    data.insert(std::make_pair(date, std::atof(rate.c_str())));
    return true;
  }
  return (false);
}

bitcoin::bitcoin() {
  std::ifstream db("data.csv");
  if (db.fail()) {
    std::cerr << "Error: cannot open database file!" << std::endl;
    return ; }
  for (std::string line ; std::getline(db, line); ) {
      if (!parseLine(line)) {
        std::cerr << "Error: invalid syntax in databasefile!" << std::endl;
        return ;
      }
  }
}