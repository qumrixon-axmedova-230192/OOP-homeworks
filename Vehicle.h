//OOP 1st homework
// Created by Qumrixon on 09/10/2025.


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
    Vehicle(string b, int y) : brand(b), year(y) {
        totalVehicles++;
    }
    virtual void displayInfo() {
        cout << "Brand: " << brand << endl;
        cout << "Year: " << year << endl;
    }

    static int getTotal() {
        return totalVehicles;
    }


    virtual ~Vehicle() {
        cout << "Vehicle is destroyed" << endl;
    }
};

int Vehicle::totalVehicles = 0;

#endif
