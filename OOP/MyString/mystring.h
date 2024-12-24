#ifndef MYSTRING_H
#define MYSTRING_H

class MyString
{
  private:
  char *str;

  public:
  MyString();
  MyString(const char *str);
  ~MyString();
  char *get_str() const;

};

#endif
