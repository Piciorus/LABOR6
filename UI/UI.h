#pragma once
#define CLIENT 1
#define MANAGER 0
#include "../CONTROLLER/Car_Controller.h"
#include "../DOMAIN/Car.h"
#include "../UI/test.h"
#include <vector>


class Ui {
    Car_Controller controller;

public:
    void start();
    void showClientMenu();
    void showManagerMenu();
    void startClientApp();
    void startManagerApp();
    Car readCar();
    void printCar(Car car);
    void printCars(std::vector<Car> cars);
    void testAll();

    Ui(Car_Controller controller);
};


