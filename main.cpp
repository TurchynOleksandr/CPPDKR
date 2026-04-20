#include <iostream>
#include <fstream>
#include <list>
#include "car.h"

int main(){
    /*std::ofstream fout("cars.txt");
    Car car1;
    Car car2(1,"Renault","Scenic",2007,Color(0,0,0),320000,"AP1235AA");
    Car car3(2,"Land rover","Range rover",2020,Color(0,0,0),2600000,"AP1236AA");
    fout<<car1<<car2<<car3;*/
    std::ifstream fin("cars.txt");
    Car car1,car2,car3;
    fin >> car1 >> car2 >> car3;
    std::cout << car1 << car2 << car3;
}
