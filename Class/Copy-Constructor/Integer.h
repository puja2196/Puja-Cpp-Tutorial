class Integer {
  int *p_Int;

public:
  Integer();
  Integer(int);
  Integer(const Integer &obj);
  void get() const;
  void set(int);
  ~Integer();
};
