#include "CSVRepository.h"

CSVRepository::CSVRepository() {
    file = "carlist.csv";
    id = 0;
}

void CSVRepository::addToEnd(Car car) {
    ofstream f(file.c_str(), ios::app);
    if (f.is_open()) {
        f << findId() << ",";
        f << car.getCarModel() << ",";
        f << car.getCarMake() << ",";
        f << car.getRegistrationYear() << ",";
        f << car.getKilometrage() << ",";
        f << car.getPrice() << ",";
        f << car.getChargeTimeMinutes() << ",";
        f << car.getRange() << "\n";
        f.close();
    } else {
        perror("File not opened!");
    }
}

bool CSVRepository::remove(int ID) {
    return false;
}

int CSVRepository::findId() {
    int old_id = id;
    id++;
    return old_id;
}

vector<Car> CSVRepository::getStorage() {
    vector<Car> storage;
    ifstream fin(file.c_str());
    if (fin.is_open()) {
        while (!fin.eof()) {
            string car_model, car_make, registration_year, kilometrage, price, charge_t, range, ID;
            getline(fin, ID,',');
            getline(fin, car_model,',');
            getline(fin, car_make,',');
            getline(fin, registration_year,',');
            getline(fin, kilometrage,',');
            getline(fin, price,',');
            getline(fin, charge_t,',');
            getline(fin, range,'\n');
            if (!ID.empty())
                storage.push_back(Car(stoi(ID), car_model, car_make, registration_year, stoi(kilometrage), stoi(price),
                                      stoi(charge_t),
                                      stoi(range)));
        }
    }

    return storage;
}

void CSVRepository::setStorage(const vector<Car> &elems) {
    ofstream f(file.c_str());
    if (f.is_open()) {
        for (auto car: elems) {
            f << car.getId() << ",";
            f << car.getCarModel() << ",";
            f << car.getCarMake() << ",";
            f << car.getRegistrationYear() << ",";
            f << car.getKilometrage() << ",";
            f << car.getPrice() << ",";
            f << car.getChargeTimeMinutes() << ",";
            f << car.getRange() << "\n";
        }
        f.close();
    } else {
        perror("File not opened!");
    }
}

