#pragma once
#include "../IN-MEMORY/Car_Repository.h"
#include "../CSV-FILE-REPOSITORY/CSVRepository.h"
#include <vector>

class Car_Controller {
private:
    std::shared_ptr<Car_Repository> car_repo;
    std::shared_ptr<CSVRepository> csv_car_repo;
    std::vector<Car> favorites;

public:
    explicit Car_Controller(std::shared_ptr<Car_Repository> &carRepo);
    explicit Car_Controller(std::shared_ptr<CSVRepository> &csvCarRepo);
    std::shared_ptr<Car_Repository> getCarRepo() const;
    void setCarRepo(std::shared_ptr<Car_Repository> carRepo);
    std::shared_ptr<CSVRepository> getCsvCarRepo() const;
    void setCsvCarRepo(std::shared_ptr<CSVRepository> csvCarRepo);
    void add_car(Car car);
    bool delete_car(Car car);
    bool update_car(Car old_car, Car new_car);
    std::vector<Car> search_car(std::string car_model, std::string car_make);
    std::vector<Car> filter_car(int car_km);
    std::vector<Car> asc_sort();
    void addToFavorites(Car car);
    void printCar(Car car);
    void showFavorites();

    Car_Controller();
};
