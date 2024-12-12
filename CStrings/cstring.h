#ifndef CSTRING_H
#define CSTRING_H

class CString
{
  private:
  char *str;

  public:
  CString();
  CString(const char *str);
  CString(const CString &source);
  ~CString();
  void print() const;
  const char *getString() const;
};

#endif
