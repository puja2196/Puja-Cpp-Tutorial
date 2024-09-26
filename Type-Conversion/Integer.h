class Integer {
  int *p_Int;

public:
  Integer();
  Integer(int);
  /*
      explicit Integer(int); // Just disable the type conversion using the
     constructor
  */
  Integer(const Integer &obj);
  Integer(Integer &&obj);
  Integer &operator=(const Integer &obj); // Copy Assignment
  Integer &operator=(Integer &&obj);      // Move Assignment

  operator int(); // Type conversion operator function doesnt take any argument
                  // or any return type: operator <type>()
  int get() const;
  void set(int);
  ~Integer();
};
