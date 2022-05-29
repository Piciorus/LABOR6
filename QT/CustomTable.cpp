#include "CustomTable.h"

    MyModel::MyModel(Car_Controller controller, QObject *parent = nullptr): controller(controller), QAbstractTableModel(parent) {
    }

    int MyModel::rowCount(const QModelIndex &parent ) const  {
        return controller.get_data().size();
    }

    int MyModel::columnCount(const QModelIndex &parent ) const  {
        return 8;
    }

    QVariant MyModel::data(const QModelIndex &index, int role) const {
        char buffer[256];
        auto car = controller.get_data()[index.row()];
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

    bool MyModel::setData(const QModelIndex &index, const QVariant &value, int role)
    {
        if (role == Qt::EditRole) {
            auto car = controller.get_data()[index.row()];
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

    Qt::ItemFlags MyModel::flags(const QModelIndex &index) const
    {
        return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
    }

    QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const
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
