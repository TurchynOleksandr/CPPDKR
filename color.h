#ifndef COLOR_H_
#define COLOR_H_

class Color{
protected:
    unsigned char m_Red;
    unsigned char m_Green;
    unsigned char m_Blue;
public:
    Color(unsigned char m_Red = 0,unsigned char m_Green = 0,unsigned char m_Blue = 0);
    void setRed(unsigned char red);
    void setBlue(unsigned char blue);
    void setGreen(unsigned char green);
    unsigned char getRed();
    unsigned char getGreen();
    unsigned char getBlue();
};

#endif