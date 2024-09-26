#include <iostream>

using namespace std;

class Distance {
  long double in_km;

public:
  Distance(long double km) : in_km{km} {}
  long double GetKm() const { return in_km; }
  void SetKm(long double km) { in_km = km; }
};

// Operator Literals to convert 32_mi to Km and create the instance with Km
Distance operator"" _mi(long double val) {
  return Distance{val * 1.6}; // 1 mile = 1.6 Km
}

Distance operator"" _meters(long double val) {
  return Distance{val / 1000}; // 1 Km = 0.001 m
}

int main() {
  Distance d1{32};

  Distance d2{23.0_mi};

  Distance d3{2300.00_meters};

  cout << "d2 is " << d2.GetKm() << "km\n";

  cout << "d3 is " << d3.GetKm() << "km\n";
  return 0;
}
