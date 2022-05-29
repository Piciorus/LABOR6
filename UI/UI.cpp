//
// Created by Tudor Esan on 03.05.2022.
//

#include "Ui.h"
#include <iostream>
#include "../DOMAIN/Car.h"
#include <string>

void Ui::showClientMenu() {
    std::cout<< "1. Search Car"<< std::endl;
    std::cout<< "2. Filter Car"<< std::endl;
    std::cout<< "3. Sort Cars"<< std::endl;
    std::cout<< "4. Add Favorites Cars"<< std::endl;
    std::cout<< "5. Show Favorites"<< std::endl;

}
void Ui::startClientApp() {
    int choice;
    do {
        showClientMenu();
        std::cout << "Select: ";
        std::cin >> choice;
        if (choice == 1) {
            std::string carModel, carMake;

            std::cout << "Car Model : ";
            std::cin >> carModel;
            std::cout << std::endl;

            std::cout << "Car Company : ";
            std::cin >> carMake;
            std::cout << std::endl;

            printCars(controller.search_car(carModel, carMake));
        }
        if (choice == 2) {
            int kilometrage;
            std::cout << "Kilometrage : ";
            std::cin >> kilometrage;
            printCars(controller.filter_car(kilometrage));
        }
        if (choice == 3) {
            printCars(controller.asc_sort());
        }

        if (choice == 4)
        {
            auto car = readCar();
            controller.addToFavorites(car);
        }
        if (choice == 5)
        {
            controller.showFavorites();
        }

    }
    while(choice != 0);
}

void Ui::printCar(Car car) {
    std::cout << car.getId() <<" "<< car.getCarModel() << " " << car.getCarMake() << " " << car.getRegistrationYear() << " " << car.getPrice() << " " << car.getKilometrage() << " " <<car.getChargeTimeMinutes() << " " <<car.getRange() << " " <<std::endl;
}

void Ui::printCars(std::vector<Car> cars) {
    for (auto car: cars) {
        printCar(car);
    }
}

Car Ui::readCar() {
    std::string carModel, carMake, registrationYear;
    int price, chargeTimeMinutes, range, kilometrage;

    std::cout << "Car Model : ";
    std::cin.ignore();
    getline(std::cin,carModel);
    std::cout << std::endl;

    std::cout << "Car Company : ";
    std::cin.ignore();
    getline(std::cin,carMake);
    std::cout << std::endl;

    std::cout << "Registration Year: ";
    std::cin >> registrationYear;
    std::cout << std::endl;

    std::cout << "Price : ";
    std::cin >> price;
    std::cout << std::endl;

    std::cout << "Charge Time in minutes : ";
    std::cin >> chargeTimeMinutes;
    std::cout << std::endl;

    std::cout << "Range : ";
    std::cin >> range;
    std::cout << std::endl;

    std::cout << "Kilometrage? :) : ";
    std::cin >> kilometrage;
    std::cout << std::endl;
    return {carModel, carMake, registrationYear, kilometrage, price, chargeTimeMinutes, range};
}

void Ui::showManagerMenu() {
    std::cout<< "1. Add Car" << std::endl;
    std::cout<< "2. Delete Car" << std::endl;
    std::cout<< "3. Update Car"<< std::endl;
    std::cout<< "4. Filter Car"<< std::endl;
    std::cout<< "5. Sort Car"<< std::endl;
}

void Ui::startManagerApp() {
    int choice;
    do {
        showManagerMenu();
        std::cout << "Select: ";
        std::cin >> choice;

        if (choice == 1) {
            auto car = readCar();
            controller.add_car(car);
        }
        if (choice == 2) {
            auto car = readCar();
            controller.delete_car(car);
        }
        if (choice == 3) {
            std::cout << "OLD CAR" << std::endl;
            auto oldCar = readCar();
            std::cout << "OLD CAR" << std::endl;
            auto newCar = readCar();
            controller.update_car(oldCar, newCar);
        }
        if (choice == 4) {
            int kilometrage;
            std::cout << "Kilometrage : ";
            std::cin >> kilometrage;
            printCars(controller.filter_car(kilometrage));
        }
        if (choice == 5) {
            printCars(controller.asc_sort());
        }
    }
    while(choice != 0);
}


void Ui::start() {
    std::cout << "Select type / Manager 0 / Client 1 ";
    bool type;
    std::cin >> type;
    if (type == MANAGER) {
        startManagerApp();
    }
    if (type == CLIENT) {
        startClientApp();
    }
    testAll();
}

Ui::Ui(Car_Controller controller) : controller(controller){
}

void Ui::testAll() {
    shared_ptr<CrudRepository<Car>> rep;
    rep = std::make_shared<Car_Repository>();
    Car_Controller ct(rep);
    //test test(ct);
    //test.testAll();
}
