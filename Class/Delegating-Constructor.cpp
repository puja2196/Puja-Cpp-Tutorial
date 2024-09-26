#include "Delegating-Constructor.h"
#include <iostream>

using namespace std;

/* Default constructor defined by programmer */
/*
Car::Car() {
    fuel = 0.0f;
    speed = 0.0f;
    passengers = 0;
}
*/
Car::Car() : Car(0) {}

/* Parameterized Constructor */
/*
Car::Car(float amount) {
    fuel = amount;
    speed = 0.0f;
    passengers = 0;
}
*/
Car::Car(float amount) : Car(amount, 0) {}

Car::Car(float amount, int pass) {
  fuel = amount;
  speed = 0.0f;
  passengers = pass;
}

/* All the 3 functions share common code, so we can use the last function for
 * defining the 1st 2 functions */

/* Destructor defined by programmer*/
Car::~Car() { cout << "Destructor called\n"; }

void Car::FillFuel(float amount) { fuel = amount; }

void Car::Accelerate() {
  speed++;
  fuel -= 0.5f;
}

void Car::Brake() { speed = 0; }

void Car::AddPassengers(int count) { passengers = count; }

void Car::Dashboard() {
  cout << "fuel = " << fuel << endl;
  cout << "speed = " << speed << endl;
  cout << "passengers = " << passengers << endl;
}
