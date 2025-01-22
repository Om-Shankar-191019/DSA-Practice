#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// display inheritance concept --

class Car
{
protected:
    string brand;
    string model;
    int maxSpeed;
    string fuelType;

public:
    Car(string brand, string model, int maxSpeed, string fuelType)
    {
        this->brand = brand;
        this->model = model;
        this->maxSpeed = maxSpeed;
        this->fuelType = fuelType;
    }

    void carBrandWithFuel()
    {
        cout << "Brand : " << this->brand << " fuelType : " << this->fuelType;
        cout << endl;
    }
};

class Mahindra : public Car
{
private:
    string carType;
    string carBody;

public:
    Mahindra(string brand, string model, int maxSpeed, string fuelType, string carType, string carBody) : Car(brand, model, maxSpeed, fuelType)
    {
        this->carType = carType;
        this->carBody = carBody;
    }

    void showDetails()
    {
        cout << "Brand : " << this->brand << " Model : " << this->model << " carBody: " << this->carBody << endl;
    }
};

int main()
{
    Mahindra xuv("Mahindra", "xuv300", 200, "petrol", "electric", "suv");
    Mahindra bolero("Mahindra", "bolero25", 130, "desiel", "fuel", "sedan");
    Mahindra marazo("Mahindra", "marazzoLL34", 150, "diesel", "fuel", "hatchback");
    xuv.carBrandWithFuel();
    bolero.carBrandWithFuel();
    bolero.showDetails();
    marazo.showDetails();

    return 0;
}