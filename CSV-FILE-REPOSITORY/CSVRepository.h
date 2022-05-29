#pragma once
#include <fstream>
#include "../REPOSITORY/CRUD-Repository.h"
#include "../DOMAIN/Car.h"

class CSVRepository : public CrudRepository<Car>{
private:
    string file;
    int id;
public:
    CSVRepository();
    void addToEnd(Car car);
    bool remove(int ID);
    int findId();
    vector<Car> getStorage();
    void setStorage(const vector<Car> &elems);
};


