#pragma once
#include "../IN-MEMORY/Car_Repository.h"
#include "../CSV-FILE-REPOSITORY/CSVRepository.h"
#include <vector>

class Car_Controller {
private:
    std::shared_ptr<CrudRepository<Car>> repo;
    std::vector<Car> favorites;

public:
    explicit Car_Controller(std::shared_ptr<CrudRepository<Car>> &carRepo);
    void add_car(Car car);
    bool delete_car(Car car);
    bool update_car(Car old_car, Car new_car);
    std::vector<Car> get_data() const;
    std::vector<Car> search_car(std::string car_model, std::string car_make);
    std::vector<Car> filter_car(int car_km);
    std::vector<Car> asc_sort();
    void addToFavorites(Car car);
    void printCar(Car car);
    void showFavorites();

    Car_Controller();
};
