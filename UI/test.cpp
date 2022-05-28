#include "test.h"


void test::testAdd() {

    auto c1=Car(1,"Tesla Model S", "Tesla", "22.02.2022", 700, 250, 22, 11);
    auto c2=Car(2,"Tesla Model 3", "Tesla", "21.02.2022", 150, 250, 22, 11);
    auto c3=Car(3,"Tesla Model Y", "Tesla", "20.02.2022", 1000, 250, 22, 11);
    control.add_car(c1);
    control.add_car(c2);
    control.add_car(c3);
    assert(control.getCarRepo()->getStorage().size()==3);
}

void test::testDelete() {
    auto c4=Car(4,"Tesla Model S", "Tesla", "22.02.2022", 700, 250, 22, 11);
    auto c5=Car(5,"Tesla Model 3", "Tesla", "21.02.2022", 150, 250, 22, 11);
    auto c6=Car(6,"Tesla Model Y", "Tesla", "20.02.2022", 1000, 250, 22, 11);
    control.add_car(c4);
    control.add_car(c5);
    control.add_car(c6);
    control.delete_car(c4);
    control.delete_car(c5);
    control.delete_car(c6);
    assert(control.getCarRepo()->getStorage().size()==3);
}

void test::testFilter() {
    control.filter_car(702);
    assert(control.filter_car(702).size()==2);
}

void test::testSearch() {
    auto c1=Car(1,"Tesla Model S", "Tesla", "22.02.2022", 700, 250, 22, 11);
    auto c2=Car(2,"Tesla Model 3", "Tesla", "21.02.2022", 150, 150, 22, 11);
    control.add_car(c1);
    assert(control.search_car("Tesla Model 3","Tesla").size()==1);

}

void test::testFilterPreis() {
    auto c1=Car(1,"Tesla Model S", "Tesla", "22.02.2022", 700, 250, 22, 11);
    auto c2=Car(2,"Tesla Model 3", "Tesla", "21.02.2022", 150, 150, 22, 11);
    control.add_car(c1);
    control.add_car(c2);
    assert(control.asc_sort()[0].getCarModel()=="Tesla Model 3" && control.asc_sort()[1].getCarModel()=="Tesla Model S");

}


void test::testUpdateCar() {
    auto c1=Car(1,"Tesla Model S", "Tesla", "22.02.2022", 700, 250, 22, 11);
    auto c2=Car(2,"Tesla Model 3", "Tesla", "21.02.2022", 150, 150, 22, 11);
    assert(control.update_car(c1,c2)== true);

}

void test::testAll() {
    testAdd();
    testDelete();
    testFilter();
    testSearch();
    testFilterPreis();
    testUpdateCar();
}

test::test(Car_Controller controller):control(controller){}




