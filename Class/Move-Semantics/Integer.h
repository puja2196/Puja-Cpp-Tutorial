class Integer {
  int *p_Int;

public:
  Integer();
  Integer(int);
  Integer(const Integer &obj);
  Integer(Integer &&obj);
  int get() const;
  void set(int);
  ~Integer();
};
