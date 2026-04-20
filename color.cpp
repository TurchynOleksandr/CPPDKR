#include "color.h"

Color::Color(unsigned char m_Red,unsigned char m_Green,unsigned char m_Blue):m_Red(m_Red),m_Blue(m_Blue),m_Green(m_Green){}

void Color::setRed(unsigned char red){
    m_Red = red;
}

void Color::setBlue(unsigned char blue){
    m_Blue = blue;
}

void Color::setGreen(unsigned char green){
    m_Green = green;
}

unsigned char Color::getRed(){
    return m_Red;
}

unsigned char Color::getGreen(){
    return m_Green;
}

unsigned char Color::getBlue(){
    return m_Blue;
}
