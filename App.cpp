#include "CONTROLLER/Car_Controller.h"
#include "UI/Ui.h"
#include <vector>
#include "DOMAIN/Car.h"
#include <QApplication>
#include <QPushButton>
#include <QApplication>
#include <QTableView>
#include <QMainWindow>
#include <QAbstractTableModel>
#include <string>
#include <iostream>

class MyModel : public QAbstractTableModel
{
    Car_Controller controller;

public:
    MyModel(Car_Controller controller, QObject *parent = nullptr): controller(controller), QAbstractTableModel(parent) {
    }
    int rowCount(const QModelIndex &parent = QModelIndex()) const override {
        return controller.getCarRepo()->getStorage().size();
    }
    int columnCount(const QModelIndex &parent = QModelIndex()) const override {
        return 8;
    }
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override{
        char buffer[256];
        auto car = controller.getCarRepo()->getStorage()[index.row()];
        if (index.column() == 0) {
            std::string tmp = std::to_string(car.getId());
            strcpy(buffer, tmp.c_str());
        }

        if(index.column() == 1){
            strcpy(buffer,car.getCarModel().c_str());
        }
        if (index.column() == 2) {
            strcpy(buffer,car.getCarMake().c_str());

        }
        if (index.column() == 3) {
            strcpy(buffer,car.getRegistrationYear().c_str());

        }
        if (index.column() == 4) {
            std::string tmp = std::to_string(car.getKilometrage());
            strcpy(buffer,tmp.c_str());

        }
        if (index.column() == 5) {
            std::string tmp = std::to_string(car.getPrice());
            strcpy(buffer, tmp.c_str());

        }
        if (index.column() == 6) {
            std::string tmp = std::to_string(car.getChargeTimeMinutes());
            strcpy(buffer,tmp.c_str());

        }
        if (index.column() == 7) {
            std::string tmp = std::to_string(car.getRange());
            strcpy(buffer,tmp.c_str());
        }

        if (role == Qt::DisplayRole) {
            return QString("%1").arg(buffer);
        }
        return QVariant();
    }
    bool setData(const QModelIndex &index, const QVariant &value, int role)
    {
        if (role == Qt::EditRole) {
            auto car = controller.getCarRepo()->getStorage()[index.row()];
            if (index.column() == 1) {
                auto car2 = car;
                car2.setCarModel(value.toString().toStdString());
                controller.update_car(car, car2);
                emit dataChanged(index, index, {role});
                return true;
            }
            if (index.column() == 2) {
                auto car2 = car;
                car2.setCarMake(value.toString().toStdString());
                controller.update_car(car, car2);
                emit dataChanged(index, index, {role});
                return true;
            }
            if (index.column() == 3) {
                auto car2 = car;
                car2.setRegistrationYear(value.toString().toStdString());
                controller.update_car(car, car2);
                emit dataChanged(index, index, {role});
                return true;
            }
            if (index.column() == 4) {
                auto car2 = car;
                car2.setKilometrage(value.toInt());
                controller.update_car(car, car2);
                emit dataChanged(index, index, {role});
                return true;
            }
            if (index.column() == 5) {
                auto car2 = car;
                car2.setPrice(value.toInt());
                controller.update_car(car, car2);
                emit dataChanged(index, index, {role});
                return true;
            }
            if (index.column() == 6) {
                auto car2 = car;
                car2.setChargeTimeMinutes(value.toInt());
                controller.update_car(car, car2);
                emit dataChanged(index, index, {role});
                return true;
            }
            if (index.column() == 7) {
                auto car2 = car;
                car2.setRange(value.toInt());
                controller.update_car(car, car2);
                emit dataChanged(index, index, {role});
                return true;
            }
        }
        return false;
    }
    Qt::ItemFlags flags(const QModelIndex &index) const
    {
        return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
    }


    QVariant headerData(int section, Qt::Orientation orientation, int role) const
    {
        if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
            switch (section) {
                case 0:
                    return QString("Id");
                case 1:
                    return QString("Car Model");
                case 2:
                    return QString("Car Make");
                case 3:
                    return QString("Registration Year");
                case 4:
                    return QString("Kilometrage");
                case 5:
                    return QString("Price");
                case 6:
                    return QString("Charge Time");
                case 7:
                    return QString("Range");

            }
        }
        return QVariant();
    }
};



int main(int argc, char *argv[])
{
    auto cars = std::vector<Car>{
            Car(1,"Tesla Model S", "Tesla", "22.02.2022", 700, 250, 22, 11),
            Car(2,"Tesla Model 3", "Tesla", "21.02.2022", 150, 250, 22, 11),
            Car(3,"Tesla Model Y", "Tesla", "20.02.2022", 1000, 250, 22, 11),
            Car(4,"Prius", "Toyota", "23.02.2022", 1223, 250, 22, 11),
            Car(5,"Dacia Spring", "Dacia", "24.02.2022", 1, 1, 0, 100),
            Car(6,"E-Tron", "Audi", "25.02.2022", 150, 250, 22, 11)};
    std::shared_ptr<Car_Repository> repo = std::make_shared<Car_Repository>(cars);
    Car_Controller controller(repo);
    QApplication a(argc, argv);
    QTableView table;
    MyModel model( controller, nullptr);
    table.setSortingEnabled(true);
    table.sortByColumn(5, Qt::AscendingOrder);
    table.setModel(&model);
    table.show();
    return a.exec();
}





//
//    std::cout << "Select type / persistent 0 / in-memory 1 ";
//    bool type;
//    std::cin >> type;
//    if (type == 0) {
//        std::shared_ptr<CSVRepository> repo1 = std::make_shared<CSVRepository>();
//        auto controller = Car_Controller(repo1);
//        auto ui = Ui(controller);
//        ui.start();
//    }
//    if (type == 1) {
//        std::shared_ptr<Car_Repository> repo1 = std::make_shared<Car_Repository>(cars);
//        auto controller = Car_Controller(repo1);
//        auto ui = Ui(controller);
//        ui.start();
//    }


//    QApplication a(argc, argv);
//    QPushButton button("Hello world!", nullptr);
//    button.resize(200, 100);
//    button.show();
//    return QApplication::exec();