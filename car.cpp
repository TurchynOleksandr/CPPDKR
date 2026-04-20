#include "car.h"
#include <string>

Car::Car(unsigned long m_ID,
    std::string m_Mark,
    std::string m_Model,
    unsigned short m_Year,
    Color m_Color,
    unsigned long m_Cost,
    std::string m_RegistrationNumber):m_ID(m_ID),
                                      m_Mark(m_Mark),
                                      m_Model(m_Model),
                                      m_Year(m_Year),
                                      m_Color(m_Color),
                                      m_Cost(m_Cost),
                                      m_RegistrationNumber(m_RegistrationNumber){
    }

std::string Car::toString(){
    return std::to_string(m_ID)+std::string("\n")+
            m_Mark+std::string("\n")+
            m_Model+std::string("\n")+
            std::to_string(m_Year)+std::string("\n")+
            m_Color.toString()+std::string("\n")+
            std::to_string(m_Cost)+std::string("\n")+
            m_RegistrationNumber+std::string("\n");
}


void Car::setID(unsigned long ID){
    m_ID = ID;
}

void Car::setMark(std::string mark){
    m_Mark = mark;
}
void Car::setModel(std::string model){
    m_Model = model;
}

void Car::setYear(unsigned short year){
    m_Year = year;
}

void Car::setColor(Color color){
    m_Color = color;
}

void Car::setCost(unsigned long cost){
    m_Cost = cost;
}

void Car::setRegistrationNumber(std::string registrationNumber){
    m_RegistrationNumber = registrationNumber;
}

unsigned long Car::getID(){
    return m_ID;
}
std::string Car::getMark(){
    return m_Mark;  
}

std::string Car::getModel(){
    return m_Model;
}

unsigned short Car::getYear(){
    return m_Year;
}

Color Car::getColor(){
    return m_Color;
}

unsigned long Car::getCost(){
    return m_Cost;
}

std::string Car::getRegistrationNumber(){
    return m_RegistrationNumber;
}

std::istream& operator >>(std::istream& fin, Car& car){
    unsigned long id, cost;
    unsigned short year;
    std::string mark,model,regNum;
    Color color;
    std::string temp;

    fin >> id;
    std::getline(fin,temp);

    std::getline(fin,mark);
    if (!mark.empty() && mark.back() == '\r') mark.pop_back();

    std::getline(fin,model);
    if (!model.empty() && model.back() == '\r') model.pop_back();

    fin >> year;
    fin >> color;
    fin >> cost;

    std::getline(fin,temp);
    std::getline(fin,regNum);

    car.setID(id);
    car.setMark(mark);
    car.setModel(model);
    car.setYear(year);
    car.setColor(color);
    car.setCost(cost);
    car.setRegistrationNumber(regNum);

    return fin;
}

std::ostream& operator <<(std::ostream& out,Car& car){
    out<<car.toString();
    return out;
}
