#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "car.h"
#include "cariocontroller.h"
#include "consolelogger.h"

int main(){
    ConsoleLogger logger("log.txt");

    CarIOController fController("cars.txt",5);

    std::vector<Car> car_vector; 
    car_vector = fController.readCars(true);

    //Car car1(3,"Daewoo","Lanos",2000,Color(0,255,0),100000,"AP1236AA");
    //car_vector.push_back(car1);

    logger.log("Program started");
    fController.writeCars(car_vector,std::cout,false);
    while(1){
        std::cout<<"Enter command:"<<std::endl;
        std::string command;

        std::getline(std::cin,command);
        logger.log(command);
        if(command == "stop"){
            exit(0);
        }else if(command == "list_of_mark"){
                std::cout<<"Enter car mark:"<<std::endl;
                std::string mark;
                std::getline(std::cin,mark);

                logger.log(mark);

                for(auto it = car_vector.begin(); it != car_vector.end(); ++it){
                    if( (*it).getMark() == mark) {
                        std::cout << (*it);
                    }
                }
        }else if(command == "aged_cars"){
                std::cout<<"Enter car model:"<<std::endl;
                std::string model;
                std::getline(std::cin,model);
                logger.log(model);

                std::cout<<"Enter car age:"<<std::endl;
                int age;
                std::cin >> age;
                logger.log( std::to_string(age) );

                std::string temp;
                std::getline(std::cin,temp);

                for(auto it = car_vector.begin(); it != car_vector.end(); ++it){
                    if( ( (*it).getModel() == model ) && ( 2026-(*it).getYear() > age ) ){
                        std::cout << (*it);
                    }
                }
        }if(command == "expensive_cars"){
                std::cout<<"Enter car year:"<<std::endl;
                int year;
                std::cin >> year;
                logger.log( std::to_string(year) );
                
                std::cout<<"Enter car cost:"<<std::endl;
                int cost;
                std::cin >> cost;
                logger.log( std::to_string(cost) );

                std::string temp;
                std::getline(std::cin,temp);

                for(auto it = car_vector.begin(); it != car_vector.end(); ++it){
                    if( ( (*it).getCost() >= cost ) && ( (*it).getYear() == year ) ){
                        std::cout << (*it);
                    }
                }
        }
    }

    //fController.writeCars(car_vector,std::cout,false);
}
