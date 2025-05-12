#include "BitcoinExchange.hpp"

void  printErr(const char* info) {
  std::cerr << "Error: " << info << "!" << std::endl;
}

bool  bitcoin::parseLine(const std::string& line) {
  std::istringstream s(line);
  std::string date, rate;

  if (std::getline(s, date, ',') && std::getline(s, rate, ',')) {
    data.insert(std::make_pair(date, std::atof(rate.c_str())));
    return true;
  }
  return (false);
}

#include <regex.h>
bool  validateInput(const std::string& input, const char* pattern) {
  regex_t regex;

  int result = regcomp(&regex, pattern, REG_EXTENDED);
  if (result != 0)
    return (printErr("failed to compile regex pattern"), false);
  result = regexec(&regex, input.c_str(), 0, NULL, 0);
  regfree(&regex);

  return (result == 0);
}

bool  bitcoin::parseInput(const std::string& line) {
  std::istringstream str(line);
  std::string date, value;

  if (std::getline(str, date, '|') && std::getline(str, value, '|')) {
    date = date.substr(0, date.length() - 1);
    value = value.substr(1, value.length() - 1);
    std::cout << date << "$" << value << std::endl;
    if (!validateInput(date, "^\\d{4}-\\d{2}-\\d{2}\\s")
      || !validateInput(value, "^\\s(1000|[0-9]{1,3}(\\.[0-9]+)?)$"))
      return (std::cout << line << std::endl, printErr("invalid syntax inside input file"), false);
    else
      output.insert(std::make_pair(date, std::atof(value.c_str())));
  }
  else
    return (printErr("invalid syntax inside input file"), false);

  return true;
}

bitcoin::bitcoin(const char* name) {

  std::ifstream db("data.csv");
  if (db.fail()) { printErr("cannot open database file"); return; }
  bool flag = true;
  for (std::string line ; std::getline(db, line); ) {
      if (flag) { flag = false; continue; }
      if (!parseLine(line)) { printErr("invalid syntax in databasefile"); return; }
  }

  std::ifstream input(name);
  if (input.fail()) { printErr("cannot open input file"); return; }
  for (std::string line ; std::getline(input, line); )
    if (!parseInput(line))
      return ;

  for (std::multimap<std::string, float>::iterator it = output.begin(); it != output.end(); it++)
    std::cout << it->first << " # " << it->second << std::endl;
}

bitcoin::~bitcoin() {}