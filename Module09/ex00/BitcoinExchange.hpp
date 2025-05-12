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
      bool  parseLine(const std::string& line);
    public:
      bitcoin();
      bitcoin(const bitcoin& other);
      bitcoin& operator=(const bitcoin& other);
      ~bitcoin();

};

#endif