#include "CONTROLLER/Car_Controller.h"
#include "UI/UI.h"
#include <vector>
#include "DOMAIN/Car.h"
#include <string>
#include <iostream>
#include "QT/CustomTable.h"


int main(int argc, char *argv[])
{
    auto cars = std::vector<Car>{
            Car(1,"Tesla Model S", "Tesla", "22.02.2022", 700, 250, 22, 11),
            Car(2,"Tesla Model 3", "Tesla", "21.02.2022", 150, 250, 22, 11),
            Car(3,"Tesla Model Y", "Tesla", "20.02.2022", 1000, 250, 22, 11),
            Car(4,"Prius", "Toyota", "23.02.2022", 1223, 250, 22, 11),
            Car(5,"Dacia Spring", "Dacia", "24.02.2022", 1, 1, 0, 100),
            Car(6,"E-Tron", "Audi", "25.02.2022", 150, 250, 22, 11)};

    shared_ptr<CrudRepository<Car>> repo;
    repo = std::make_shared<Car_Repository>(cars);
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