// 3. Design a base class Vehicle with basic attributes like brand,
// model, and year. Derive:
// Car (add attribute fuelType)
// Bike (add attribute engineCapacity)
// ElectricCar (inherits from Car, add attribute batteryLife)
// Implement:
// a) Constructor and Destructor to manage object lifecycle
// b) Function Overriding of a displayInfo() method
// c) Multilevel and Hierarchical Inheritance


#include <iostream>
using namespace std;

class Vehicle{
protected:
    string brand;
    string model;
    int year;

public:
    Vehicle(string b , string m , int y){
        brand = b;
        model = m;
        year = y;
    }

    virtual void displayInfo(){
        cout<<brand<<endl;
        cout<<model<<endl;
        cout<<year<<endl;
    }

    virtual ~Vehicle(){
        cout<<"Destructor called"<<endl;
    }

};

class Car : public Vehicle{
protected:
    string engineCapacity;

public:
    Car(string b , string m , int y , string f): Vehicle(b,m,y), engineCapacity(f){}

    void displayInfo() override{
    Vehicle::displayInfo();
        cout<<engineCapacity<<endl;
    
}
    virtual ~Car(){
        cout<<"Destructor called"<<endl;
    }
};




class Bike : public Vehicle{
protected:
    string fueltype;

public:
    Bike(string b , string m , int y , string f): Vehicle(b,m,y), fueltype(f){}

void displayInfo() override{
    Vehicle::displayInfo();
        cout<<fueltype<<endl;
    
}
    virtual ~Bike(){
        cout<<"Destructor called"<<endl;
    }
};


class ElectricCar : public Car{
protected:
    string batteryLife;

public:
    ElectricCar(string b , string m , int y , string f,string ba): Car(b,m,y,f), batteryLife(ba){}
void displayInfo() override{
    Car::displayInfo();
        cout<<batteryLife<<endl;
    
}
    virtual ~ElectricCar(){
        cout<<"Destructor called"<<endl;
    }
};



int main() {
    cout << "=== Vehicle Demo ===" << endl;

    Car c("Toyota", "Fortuner", 2021, "Diesel");
    Bike b("Yamaha", "R15", 2022, "155cc");
    ElectricCar e("Tesla", "Model 3", 2024, "Electric", "ok");

    cout << "\n--- Car Info ---" << endl;
    c.displayInfo();

    cout << "\n--- Bike Info ---" << endl;
    b.displayInfo();

    cout << "\n--- Electric Car Info ---" << endl;
    e.displayInfo();

    cout << "\n--- Destructors ---" << endl;
    return 0;
}