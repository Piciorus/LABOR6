#pragma once
#include <string>
#include <iostream>
#include <memory>
class Car {

private:
    std::string car_model;
    std::string car_make;
    std::string registration_year;
    int kilometrage;
    int price;
    int charge_time_minutes;
    int range;
    int ID;

public:
    const std::string &getCarModel() const;

    const std::string &getCarMake() const;

    const std::string &getRegistrationYear() const;

    void setId(int id);

    int getId() const;

    int getRegistrationYearAsNum() const;

    int getKilometrage() const;

    int getPrice() const;

    int getChargeTimeMinutes() const;

    int getRange() const;

    void setCarModel(const std::string &carModel);

    void setCarMake(const std::string &carMake);

    void setRegistrationYear(const std::string &registrationYear);

    void setKilometrage(int kilometrage);

    void setPrice(int price);

    void setChargeTimeMinutes(int chargeTimeMinutes);

    void setRange(int range);

    Car(int id,const std::string &carModel, const std::string &carMake, const std::string &registrationYear, int kilometrage,
        int price, int chargeTimeMinutes, int range);

    Car(const std::string &carModel, const std::string &carMake, const std::string &registrationYear, int kilometrage,
        int price, int chargeTimeMinutes, int range);
};


