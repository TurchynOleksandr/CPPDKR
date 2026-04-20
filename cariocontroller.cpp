#include "cariocontroller.h"

CarIOController::CarIOController(std::string m_FileName,int m_Key):
                                    m_FileName(m_FileName),m_Key(m_Key){}

CarIOController::CarIOController(const char str[],int m_Key):CarIOController(std::string(str),m_Key){}

void CarIOController::setFileName(std::string fileName){
    m_FileName = fileName;
}

void CarIOController::setKey(int key){
    m_Key = key;
}

std::string CarIOController::getFileName(){
    return m_FileName;
}

int CarIOController::getKey(){
    return m_Key;
}

std::vector<Car> CarIOController::readCars(std::istream& in,bool doDecrypt){
    std::vector<Car> car_array;
    Car tempCar;
    if(doDecrypt){
        std::ostringstream oss;
        oss << in.rdbuf();
        std::string str = oss.str();
        int len = str.length(); 
        for(int i = 0; i < len; ++i)
            str[i] = str[i] ^ m_Key;
        std::istringstream iss(str);
        return readCars(iss,false);
    }
    while(in >> tempCar){
        car_array.push_back(tempCar);
    }
    return car_array;
}

std::vector<Car> CarIOController::readCars(std::string fileName,bool doDecrypt){
    std::ifstream fin(fileName,std::ios::binary);
    return readCars(fin,doDecrypt);
}

std::vector<Car> CarIOController::readCars(bool doDecrypt){
    return readCars(m_FileName,doDecrypt);
}

void CarIOController::writeCars(std::vector<Car>& car_array,std::ostream& out,bool doEncrypt){
    if(doEncrypt){
        std::ostringstream os;
        writeCars(car_array,os,false);
        std::string str = os.str(); 
        int len = str.length(); 
        for(int i = 0; i < len; ++i)
            str[i] = str[i] ^ m_Key;
        out << str;
    }else{
        for(auto it = car_array.begin();it != car_array.end();++it){
            out << (*it);
        }
    }
}

void CarIOController::writeCars(std::vector<Car>& car_array,std::string fileName,bool doEncrypt){
    std::ofstream fout = std::ofstream(fileName,std::ios::binary);
    writeCars(car_array,fout,doEncrypt);
}

void CarIOController::writeCars(std::vector<Car>& car_array,bool doEncrypt){
    writeCars(car_array,m_FileName,doEncrypt);
}