#ifndef MYSTRING_H
#define MYSTRING_H

class MyString
{
  private:
  char *str;

  public:
  MyString();
  MyString(const char *str);
  MyString(const MyString &source);
  MyString(MyString &&source);
  ~MyString();
  const char *get_str() const;
};

#endif
