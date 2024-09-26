#include "Non-static-member-initializers.h"
#include <iostream>

using namespace std;

/* Default constructor defined by programmer */
Car::Car() {
  cout << "Default Constructor called\n";
  fuel = 0.0f;
}

/* Parameterized Constructor */
Car::Car(float amount) {
  cout << "Parameterized Constructor called\n";
  fuel = amount;
}

/* Destructor defined by programmer*/
/* If not, compiler will have its own destructor to kill all the things used by
 * obeject */
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
