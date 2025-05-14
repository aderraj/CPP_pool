#include "BitcoinExchange.hpp"

void  printErr(const char* info, const char* extra) {
  std::cout << "Error: " << info
            << (extra ? extra : "!") << std::endl;
}

bool checkDate(std::string& date) {
  std::tm tm = {};
  if (!strptime(date.c_str(), "%Y-%m-%d", &tm))
    return false;
  std::time_t input_time = mktime(&tm);
  if (input_time == -1)
    return false;

  std::tm* validated = localtime(&input_time);

  if (validated->tm_year != tm.tm_year
    || validated->tm_mon != tm.tm_mon
    || validated->tm_mday != tm.tm_mday)
    return false;

  if (input_time > std::time(NULL))
    return false;

  return true;
}

void  readDataBase(std::map<std::string, double>& data) {
  std::ifstream db("data.csv");
  std::string date, rate;

  if (!db.is_open())
      throw std::runtime_error("can't open database file !");
  std::getline(db, );
  while (std::getline(db, date, ',') && std::getline(db, rate, ',')) {
    if (date.empty() || rate.empty())
      throw std::runtime_error("invalid syntax inside data file!");
    else if (!checkDate(date))
      throw std::runtime_error("bad date => " + date);
    data.insert(std::make_pair(date, std::strtod(rate.c_str(), NULL)));
  }
}

void  btcExg(const char* filename) {

  (void)filename;
  std::map<std::string, double> data;

  try { readDataBase(data); }
  catch (std::exception &e) { std::cout << e.what() << std::endl; return ; }

  for (std::map<std::string, double>::iterator it = data.begin();
    it != data.end(); it++)
      std::cout << it->first << "," << it->second << std::endl;
}