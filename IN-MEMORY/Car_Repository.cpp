#include "Car_Repository.h"

Car_Repository::Car_Repository(const std::vector<Car> &storage) : storage(storage) {}


std::vector<Car> Car_Repository::getStorage() {
    return storage;
}

void Car_Repository::setStorage(const std::vector<Car> &storage) {
    Car_Repository::storage = storage;
}

void Car_Repository::addToEnd(Car car) {
    car.setId(findId());
    storage.push_back(car);
}

bool Car_Repository::remove(int ID) {
    for(int i=0;i<storage.size();i++)
        if(storage[i].getId()==ID)
        {
            storage.erase(storage.begin()+i);
            return true;
        }
    return false;
}

int Car_Repository::findId() {
    int max=0;
    for(auto & i : storage)
        if(i.getId()>max)
            max=i.getId();
    return max+1;
}

Car_Repository::Car_Repository() {

}




