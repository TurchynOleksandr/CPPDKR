#ifndef CAR_H_
#define CAR_H_

#include <iostream>
#include <string>
#include "color.h"

class Car{
protected:
    unsigned long m_ID;
    std::string m_Mark;
    std::string m_Model;
    unsigned short m_Year;
    Color m_Color;
    unsigned long m_Cost;
    std::string m_RegistrationNumber;
public:
    Car(unsigned long m_ID = 0,
        std::string m_Mark = "ZAZ",
        std::string m_Model = "ZAZ-966",
        unsigned short m_Year = 1967,
        Color m_Color = Color(255,255,255),
        unsigned long m_Cost = 7000,
        std::string m_RegistrationNumber = "AP1234AA");
    std::string toString();

    void setID(unsigned long ID);
    void setMark(std::string mark);
    void setModel(std::string model);
    void setYear(unsigned short year);
    void setColor(Color color);
    void setCost(unsigned long cost);
    void setRegistrationNumber(std::string registrationNumber);

    unsigned long getID();
    std::string getMark();
    std::string getModel();
    unsigned short getYear();
    Color getColor();
    unsigned long getCost();
    std::string getRegistrationNumber();
};

std::ostream& operator <<(std::ostream& out,Car& car);

std::istream& operator >>(std::istream& fin,Color& color);

std::istream& operator >>(std::istream& in, Car& car);

#endif