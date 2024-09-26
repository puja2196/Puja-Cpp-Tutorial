class Car {
private:
  float fuel;
  float speed;
  int passengers;

public:
  Car();      // default constructor
  Car(float); // parameterized constructor
  Car(float, int);
  ~Car(); // Destructor
  void FillFuel(float amount);
  void Accelerate();
  void Brake();
  void AddPassengers(int count);
  void Dashboard();
};
