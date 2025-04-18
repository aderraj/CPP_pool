#ifndef DATA_HPP
#define DATA_HPP

class Data {

  private:
    char c;

  public:
    Data();
    Data(const Data& other);
    Data& operator=(const Data& other);
    ~Data();

};
#endif