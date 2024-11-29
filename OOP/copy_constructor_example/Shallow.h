#ifndef SHALLOW_H
#define SHALLOW_H

class Shallow
{
  private:
  int *data;

  public:
  Shallow(int value);
  Shallow(const Shallow &sourceObject) = default; // Member wise shallow copy
  ~Shallow();
  int getData() const;
  void setData(int newValue);
};

#endif
