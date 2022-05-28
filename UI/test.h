#pragma once
#include "../CONTROLLER/Car_Controller.h"
#include <cassert>


class test {
private:
    Car_Controller control;
public:
    test(Car_Controller controller);
    void testAdd();
    void testDelete();
    void testFilter();
    void testSearch();
    void testFilterPreis();
    void testUpdateCar();
    void testAll();



};


