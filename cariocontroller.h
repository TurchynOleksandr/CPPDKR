#ifndef CARIOCONTROLLER_H_
#define CARIOCONTROLLER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "car.h"

class CarIOController{
private:
    std::string m_FileName;
    int m_Key;
public:
    CarIOController(std::string m_FileName = "cars.txt",int m_Key = 0);
    CarIOController(const char str[] = "cars.txt",int m_Key = 0);
    void setFileName(std::string fileName);
    void setKey(int key);
    std::string getFileName();
    int getKey();
    std::vector<Car> readCars(std::istream& in,bool doDecrypt = false);
    std::vector<Car> readCars(std::string fieName,bool doDecrypt = false);
    std::vector<Car> readCars(bool doDecrypt = false);
    void writeCars(std::vector<Car>& car_array,std::ostream& out,bool doEncrypt = false);
    void writeCars(std::vector<Car>& car_array,std::string fileName,bool doEncrypt = false);
    void writeCars(std::vector<Car>& car_array,bool doEncrypt = false);
};

#endif