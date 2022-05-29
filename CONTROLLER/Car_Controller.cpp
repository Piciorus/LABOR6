#include "../CONTROLLER/Car_Controller.h"
#include <bits/stdc++.h>
#include <utility>

Car_Controller::Car_Controller(std::shared_ptr<CrudRepository<Car>> &carRepo) : repo(carRepo) {}

void Car_Controller::add_car(Car car) {
        repo->addToEnd(car);
        //setCarRepo(repo);
}

bool Car_Controller::delete_car(Car car) {
        if (repo->remove(car))
            return true;
        return false;
}

bool Car_Controller::update_car(Car old_car, Car new_car) {
        for (Car &car: repo->getStorage())
            if (car.getCarModel() == old_car.getCarModel() && car.getCarMake() == old_car.getCarMake()) {
                car.setCarModel(new_car.getCarModel());
                car.setCarMake(new_car.getCarMake());
                car.setRegistrationYear(new_car.getRegistrationYear());
                car.setPrice(new_car.getPrice());
                car.setKilometrage(new_car.getKilometrage());
                car.setRange(new_car.getRange());
                car.setChargeTimeMinutes(new_car.getChargeTimeMinutes());
                return true;
            }
        return false;
}

std::vector<Car> Car_Controller::search_car(std::string car_model, std::string car_make) {
    std::vector<Car> cars;
        for (const auto & i : repo->getStorage())
            if (i.getCarModel() == car_model &&
                i.getCarMake() == car_make)
                cars.push_back(i);
        return cars;

}

std::vector<Car> Car_Controller::filter_car(int car_km) {
    std::vector<Car> cars;
        for (const auto &i: repo->getStorage())
            if (i.getKilometrage() <= car_km)
                cars.push_back(i);
        return cars;
}

static bool bypreis(const Car& c1, const Car& c2 ) { return c1.getPrice() < c2.getPrice(); }

std::vector<Car> Car_Controller::asc_sort() {
    std::vector<Car> cars;
        for (const auto &i: repo->getStorage()) {
            cars.push_back(i);
        }
        sort(cars.begin(), cars.end(), bypreis);
        return cars;
}

void Car_Controller::addToFavorites(Car car) {
    favorites.push_back(car);
}

void Car_Controller::showFavorites() {
    for (auto &car: favorites)
        printCar(car);
}

void Car_Controller::printCar(Car car) {
    std::cout << car.getId() << car.getCarModel() << " " << car.getCarMake() << " " << car.getRegistrationYear() << " " << car.getPrice() << " " << car.getChargeTimeMinutes() << " " <<car.getKilometrage() << " " <<car.getRange() << " " <<std::endl;
}

std::vector<Car> Car_Controller::get_data() const{
    std::vector<Car> data;
    for (auto &car : repo->getStorage())
        data.push_back(car);
    return data;
}





