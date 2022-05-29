#pragma once
#include "../REPOSITORY/CRUD-Repository.h"
#include "../DOMAIN/Car.h"
#include <vector>

class Car_Repository : public CrudRepository<Car> {
private:
    std::vector<Car> storage;

public:
    Car_Repository();
    Car_Repository(const std::vector<Car> &storage);
    void addToEnd(Car car);
    bool remove(Car car);
    std::vector<Car> &getStorage();
    int findId();
    void setStorage(const std::vector<Car> &storage);
};


