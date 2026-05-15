#include <iostream>
#include <string>
using namespace std;


// A vehicle rental company manages different types of vehicles. Construct a management system
// --- STEP 1: The Base Class ---
class Vehicle {
protected:
    string vehicleID;
    string brand;
    double baseRate;

public:
    Vehicle(string id, string b, double rate) 
        : vehicleID(id), brand(b), baseRate(rate) {}

    // Pure virtual function makes this an Abstract Class
    virtual double calculateRent(int days) = 0;

    virtual ~Vehicle() {} // Virtual destructor for safe polymorphism
};

// --- STEP 2: Virtual Inheritance to solve Diamond Structure ---
class Car : virtual public Vehicle {
protected:
    int passengerCapacity;
public:
    Car(string id, string b, double rate, int cap) 
        : Vehicle(id, b, rate), passengerCapacity(cap) {}

    double calculateRent(int days) override {
        double rent = baseRate * days;
        if (passengerCapacity > 4) rent += 50;
        return rent;
    }
};

class Truck : virtual public Vehicle {
protected:
    double payloadCapacity;
public:
    Truck(string id, string b, double rate, double payload) 
        : Vehicle(id, b, rate), payloadCapacity(payload) {}

    double calculateRent(int days) override {
        return (baseRate * days) + (payloadCapacity * 10);
    }
};

// --- STEP 3: Multiple Inheritance and Manual Resolution ---
class PickupTruck : public Car, public Truck {
public:
    PickupTruck(string id, string b, double rate, int cap, double payload)
        : Vehicle(id, b, rate), Car(id, b, rate, cap), Truck(id, b, rate, payload) {}

    // We MUST override this to tell the compiler which logic to use
    double calculateRent(int days) override {
        cout << "(Calculating Pickup rate using combined Car and Truck logic...)" << endl;
        
        // Resolving the ambiguity by calling specific parent methods
        double carPart = Car::calculateRent(days);
        double truckPart = Truck::calculateRent(days);
        
        return (carPart + truckPart) / 2; // Averaged rate
    }
};

// --- STEP 4: Main function showing Polymorphism ---
int main() {
    // Array of base class pointers
    Vehicle* fleet[3];

    fleet[0] = new Car("C-001", "Toyota", 50, 5);
    fleet[1] = new Truck("T-99", "Hino", 100, 15.5);
    fleet[2] = new PickupTruck("P-50", "Ford Raptor", 80, 4, 10.0);

    cout << "--- Vehicle Rental System ---" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Vehicle ID: " << (i+1) 
             << " | Rent for 3 days: $" << fleet[i]->calculateRent(3) << endl;
    }

    // Cleanup memory
    for (int i = 0; i < 3; i++) {
        delete fleet[i];
    }

    return 0;
}