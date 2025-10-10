
// Created by Qumrixon on 10/10/2025.

#ifndef ELECTRICCAR_H
#define ELECTRICCAR_H

#include "Car.h"

class ElectricCar : public Car {
private:
    int batteryRange;

public:
    ElectricCar(string b, int y, int d, int br)
            : Car(b, y, d), batteryRange(br) {}

    void displayInfo() override {
        Car::displayInfo();
        cout << "Battery Range: " << batteryRange << " km" << endl;
    }

    ~ElectricCar() override {
        cout << "Electric car is destroyed" << endl;
    }
};

#endif