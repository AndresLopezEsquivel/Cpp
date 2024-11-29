#ifndef DEEP_H
#define DEEP_H

class Deep
{
  private:
  int *data;

  public:
  Deep(int value);
  ~Deep();
  Deep(const Deep &sourceObject);
  int getData() const;
  void setData(int newValue);
};

#endif
