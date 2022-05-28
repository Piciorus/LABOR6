#include "Car.h"

const std::string &Car::getCarModel() const {
    return car_model;
}

const std::string &Car::getCarMake() const {
    return car_make;
}

const std::string &Car::getRegistrationYear() const {
    return registration_year;
}

int Car::getKilometrage() const {
    return kilometrage;
}

int Car::getPrice() const {
    return price;
}

int Car::getChargeTimeMinutes() const {
    return charge_time_minutes;
}

int Car::getRange() const {
    return range;
}

void Car::setCarModel(const std::string &carModel) {
    car_model = carModel;
}

void Car::setCarMake(const std::string &carMake) {
    car_make = carMake;
}

void Car::setRegistrationYear(const std::string &registrationYear) {
    registration_year = registrationYear;
}

void Car::setKilometrage(int kilometrage) {
    Car::kilometrage = kilometrage;
}

void Car::setPrice(int price) {
    Car::price = price;
}

void Car::setChargeTimeMinutes(int chargeTimeMinutes) {
    charge_time_minutes = chargeTimeMinutes;
}

void Car::setRange(int range) {
    Car::range = range;
}

int Car::getId() const {
    return ID;
}

void Car::setId(int id) {
    ID = id;
}

Car::Car(int id,const std::string &carModel, const std::string &carMake, const std::string &registrationYear, int kilometrage,
         int price, int chargeTimeMinutes, int range) : ID(id),car_model(carModel), car_make(carMake),
                                                        registration_year(registrationYear), kilometrage(kilometrage),
                                                        price(price), charge_time_minutes(chargeTimeMinutes),
                                                        range(range) {}
Car::Car(const std::string &carModel, const std::string &carMake, const std::string &registrationYear, int kilometrage,
         int price, int chargeTimeMinutes, int range) :car_model(carModel), car_make(carMake),
                                                       registration_year(registrationYear), kilometrage(kilometrage),
                                                       price(price), charge_time_minutes(chargeTimeMinutes),
                                                       range(range) {}





