#include <iostream>
#include <fstream>
#include <vector>
#include "car.h"
#include "cariocontroller.h"

int main(){
    CarIOController fController("cars.txt",5);
    std::vector<Car> car_vector;    
    car_vector = fController.readCars(true);

    //Car car1(3,"Daewoo","Lanos",2000,Color(0,255,0),100000,"AP1236AA");
    //car_vector.push_back(car1); 

    //fController.writeCars(car_vector,true);
    //car_vector = fController.readCars(true);
    //fController.writeCars(car_vector);

    fController.writeCars(car_vector,std::cout,false);
}
