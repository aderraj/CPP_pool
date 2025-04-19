#ifndef DATA_HPP
#define DATA_HPP

class Data {

  private:
    int x;

  public:
    Data();
    Data(const Data& other);
    Data& operator=(const Data& other);
    ~Data();

};
#endif