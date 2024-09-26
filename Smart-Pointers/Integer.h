class Integer {
  int *p_Int;

public:
  Integer();
  Integer(int);
  Integer(const Integer &obj);
  Integer(Integer &&obj);
  Integer &operator=(const Integer &obj); // Copy Assignment
  Integer &operator=(Integer &&obj);      // Move Assignment

  int get() const;
  void set(int);
  ~Integer();
};
