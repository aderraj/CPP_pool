#include "BitcoinExchange.hpp"

void  printErr(const std::string& info) {
  std::cerr << "Error: " << info << std::endl;
}

bool checkHeader(std::ifstream &file, const std::string& corr) {
  std::string tmp;
  std::getline(file, tmp);
  return (tmp == corr);
}

bool checkDate(std::string& date) {

  std::tm tm;
  int y, m, d;
  char del;

  if (!strptime(date.c_str(), "%Y-%m-%d", &tm))
    return false;

  std::stringstream stream(date);
  stream >> y >> del >> m >> del >> d;
  std::memset(&tm, 0, sizeof(tm));
  tm.tm_year = y - 1900;
  tm.tm_mon = m - 1;
  tm.tm_mday = d;

  std::time_t input_time = mktime(&tm);
  if (input_time == -1)
    return false;
  std::tm* validated = localtime(&input_time);

  if (validated->tm_year != y - 1900
    || validated->tm_mon != m - 1
    || validated->tm_mday != d
    || input_time > std::time(NULL))
      return false;

  return true;
}

bool checkValue(std::string &value, double& val)
{
    unsigned int dotPos;
    char        *end;
    val = std::strtod(value.c_str(), &end);

    if (end == value.c_str() || *end != '\0')
      return false;
    dotPos = value.find('.');
    if (!dotPos || dotPos == value.length() - 1
        || val < 0 || val > 1000)    
      return false;

    return true;
}

void  readDataBase(std::map<std::string, double>& data) {
  std::ifstream db("data.csv");
  std::string date, rate, line;

  if (!db.is_open())
      throw std::runtime_error("can't open database file !");
  if (db.peek() == std::ifstream::traits_type::eof())
      throw std::runtime_error("database file is empty!");
  if (!checkHeader(db, "date,exchange_rate"))
    throw std::runtime_error("invalid header inside data file !");
  while (std::getline(db, line)) {
    std::stringstream stream(line);
    if (!std::getline(stream, date, ',') || !std::getline(stream, rate, ',')
    || date.empty() || rate.empty())
      throw std::runtime_error("invalid syntax inside data file!");  
    if (!checkDate(date))
      throw std::runtime_error("bad date => " + date);
    data.insert(std::pair<std::string, double>(date, std::strtod(rate.c_str(), NULL)));
  }
}

void  readInput(const std::string& line, std::map<std::string, double>& data) {
  std::stringstream str(line);
  std::string date, value;
  double val;

  if (!std::getline(str, date, '|') || !std::getline(str, value, '|')){
    printErr("bad input => " + line); return ;}
  date = date.substr(date.find_first_not_of(" \t\r\b"), date.length());
  date = date.erase(date.find_last_not_of(" \t\r\b") + 1);
  if (!checkDate(date))
    printErr("bad input => " + date);
  else if (!checkValue(value, val))
    printErr("invalid value => " + value);
  else {
    std::map<std::string, double>::iterator it;
    it = data.find(date);
    if (it == data.end()) {
      it = data.lower_bound(date);
      if (it != data.begin())
        it--;
    }
    std::cout << date << " => " << val << " = " << val * it->second << std::endl;
  }
}

void  btcExg(const char* filename) {

  std::map<std::string, double> data;

  try { readDataBase(data); }
  catch (std::exception &e) { std::cout << e.what() << std::endl; return ; }

  std::ifstream input(filename);
  if (!input.is_open())
    { printErr("cannot open input file"); return ; }

  if (input.peek() == std::ifstream::traits_type::eof())
    { printErr("input file is empty"); return ; }

  std::string line;
  if (!checkHeader(input, "date | value"))
    printErr("invalid header inside input file");

  while (std::getline(input, line)) {
    if (!line.empty() && line.find_first_not_of(" \t\r\b\n") != std::string::npos)
      readInput(line, data);
  }
}