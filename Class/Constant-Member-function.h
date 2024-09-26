class Car {
private:
  float fuel;
  float speed;
  int passengers;

public:
  Car();      // default constructor
  Car(float); // parameterized constructor
  ~Car();     // Destructor
  void FillFuel(float amount);
  void Accelerate();
  void Brake();
  void AddPassengers(int count);
  /* Here all the functions are changing the data members except "Dashboard".
   * you can make "Dashboard" as constant function */
  void Dashboard() const;
};
