#include "../CONTROLLER/Car_Controller.h"
#include <bits/stdc++.h>
#include <utility>

Car_Controller::Car_Controller(std::shared_ptr<Car_Repository> &carRepo) : car_repo(carRepo), csv_car_repo(nullptr) {}

Car_Controller::Car_Controller(shared_ptr<CSVRepository> &csvCarRepo) : csv_car_repo(csvCarRepo), car_repo(nullptr) {}

std::shared_ptr<Car_Repository> Car_Controller::getCarRepo() const {
    return car_repo;
}

void Car_Controller::setCarRepo(std::shared_ptr<Car_Repository> carRepo) {
    car_repo = carRepo;
}

std::shared_ptr<CSVRepository> Car_Controller::getCsvCarRepo() const {
    return csv_car_repo;
}

void Car_Controller::setCsvCarRepo(std::shared_ptr<CSVRepository> csvCarRepo) {
    csv_car_repo = csvCarRepo;
}

void Car_Controller::add_car(Car car) {
    if (car_repo) {
        car_repo->addToEnd(car);
        setCarRepo(car_repo);
    }
    else {
        csv_car_repo->addToEnd(car);
        setCsvCarRepo(csv_car_repo);
    }
}

bool Car_Controller::delete_car(Car car) {
    if (car_repo) {
        if (car_repo->remove(car))
            return true;
        return false;
    }
    else {
        if (csv_car_repo->remove(car))
            return true;
        return false;
    }

}

bool Car_Controller::update_car(Car old_car, Car new_car) {
    if (car_repo) {
        for (Car &car: car_repo->getStorage())
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
    } else {
        for (Car &car: csv_car_repo->getStorage())
            if (car.getCarModel() == old_car.getCarModel() && car.getCarMake() == old_car.getCarMake()) {
                car.setCarModel(new_car.getCarModel());
                car.setCarMake(new_car.getCarModel());
                car.setRegistrationYear(new_car.getRegistrationYear());
                car.setPrice(new_car.getPrice());
                car.setKilometrage(new_car.getKilometrage());
                car.setRange(new_car.getRange());
                car.setChargeTimeMinutes(new_car.getChargeTimeMinutes());
                return true;
            }
        return false;
    }
}

std::vector<Car> Car_Controller::search_car(std::string car_model, std::string car_make) {
    std::vector<Car> cars;
    if (car_repo) {
        for (const auto & i : car_repo->getStorage())
            if (i.getCarModel() == car_model &&
                i.getCarMake() == car_make)
                cars.push_back(i);
        return cars;
    } else {
        for (const auto & i : csv_car_repo->getStorage())
            if (i.getCarModel() == car_model &&
                i.getCarMake() == car_make)
                cars.push_back(i);
        return cars;
    }
}

std::vector<Car> Car_Controller::filter_car(int car_km) {
    std::vector<Car> cars;
    if (car_repo) {
        for (const auto &i: car_repo->getStorage())
            if (i.getKilometrage() <= car_km)
                cars.push_back(i);
        return cars;
    }
    else {
        for(const auto & i : csv_car_repo->getStorage())
            if(i.getKilometrage()<=car_km)
                cars.push_back(i);
        return cars;
    }
}

static bool bypreis(const Car& c1, const Car& c2 ) { return c1.getPrice() < c2.getPrice(); }

std::vector<Car> Car_Controller::asc_sort() {
    std::vector<Car> cars;
    if (car_repo) {
        for (const auto &i: car_repo->getStorage()) {
            cars.push_back(i);
        }
        sort(cars.begin(), cars.end(), bypreis);
        return cars;
    } else {
        if (!csv_car_repo->getStorage().empty()) {
            for (const auto &i: csv_car_repo->getStorage()) {
                cars.push_back(i);
            }
            sort(cars.begin(), cars.end(), bypreis);
            return cars;
        }
    }
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





