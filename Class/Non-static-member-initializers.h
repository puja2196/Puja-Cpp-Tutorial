class Car {
private:
  float fuel{8.7f};
  float speed = 4.6f;
  int passengers{0};
  int arr[5] = {1, 2, 3};
  char *p{};
  /* non-static data member declared with placeholder ‘auto’ */
  // auto i; // Error
public:
  Car();      // default constructor
  Car(float); // parameterized constructor
  ~Car();     // Destructor
  void FillFuel(float amount);
  void Accelerate();
  void Brake();
  void AddPassengers(int count);
  void Dashboard();
};
