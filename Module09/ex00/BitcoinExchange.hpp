#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <fstream>
#include <sstream>

class bitcoin {

    private:
      std::multimap<std::string, float> data;
      std::multimap<std::string, float> output;
      bool  parseLine(const std::string& line);
      bool  parseInput(const std::string& line);
      bitcoin();

    public:
      bitcoin(const char* name);
      bitcoin(const bitcoin& other);
      bitcoin& operator=(const bitcoin& other);
      ~bitcoin();

};

void  printErr(const char* info);
#endif