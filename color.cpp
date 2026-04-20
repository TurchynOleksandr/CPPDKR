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

std::string Color::toString(){
    return std::string("[")+
           std::to_string(m_Red)+
           std::string(" ")+
           std::to_string(m_Green)+
           std::string(" ")+
           std::to_string(m_Blue)+
           std::string("]");
}

std::istream& operator >>(std::istream& fin,Color& color){
    char bracket1,bracket2;
    unsigned int red,green,blue;
    fin >> bracket1 >> red >> green >> blue >> bracket2;
    if( bracket1 == '[' && bracket2 == ']' ){
        color.setRed(red);
        color.setGreen(green);
        color.setBlue(blue);
    }
    return fin;
}

std::ostream& operator <<(std::ostream& out,Color& color){
    out<<color.toString();
    return out;
}