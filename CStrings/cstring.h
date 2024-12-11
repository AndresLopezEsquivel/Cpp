#ifndef CSTRING_H
#define CSTRING_H

class CString
{
  private:
  char *str;

  public:
  CString();
  CString(const char *str);
  ~CString();
  void print() const;
};

#endif
