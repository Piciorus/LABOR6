#pragma once
#include "../CONTROLLER/Car_Controller.h"
#include "../UI/UI.h"
#include <vector>
#include "../DOMAIN/Car.h"
#include <QApplication>
#include <QTableView>
#include <QAbstractTableModel>
#include <string>

class MyModel : public QAbstractTableModel {

private:
    Car_Controller controller;

public:
    MyModel(Car_Controller controller, QObject *parent);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
};


