#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>
using namespace std;

class Vehicle {
private:
    string brand;
    int year;
    static int totalVehicles;

public:
    Vehicle(string b, int y) {
        brand = b;
        year = y;
        totalVehicles++;
    }

    void displayInfo() {
        cout << "Brand: " << brand << endl;
        cout << "Year: " << year << endl;
    }

    static int getTotal() {
        return totalVehicles;
    }

    ~Vehicle() {
        cout << "Vehicle is destroyed" << endl;
    }
};

#endif

