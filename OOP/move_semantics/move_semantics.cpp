#include <iostream>
#include <vector>

using namespace std;

class Move
{
  private:
  int *data;

  public:
  void set_data(int d);
  int get_data() const;
  Move(int d);
  Move(const Move &source); // copy constructor -- deep copy
  Move(Move &&source); // move constructor
  ~Move();
};

int main()
{
  vector<Move> vec;

  vec.push_back(Move(10));
  vec.push_back(Move(20));

  /*
  Without move constructor:

  Move(int d) called with d = 10 <- Object Move(10) is created
  Deep copy Move(const Move &source) called for data = 10 <- vec.push_back(Move(10)) calls copy constructor <- Makes a copy of Move(10)
  ~Move called for data = 10 <- The copy made by vec.push_back(Move(10)) is freed
  Move(int d) called with d = 20 <- Object Move(20) is created
  Deep copy Move(const Move &source) called for data = 20 <- vec.push_back(Move(20)) calls copy constructor <- Makes a copy of Move(20)
  Deep copy Move(const Move &source) called for data = 10 <- When the vector size increases, all previous elements are copied
  ~Move called for data = 10 <- Free memory allocated for the copy of Move(10)
  ~Move called for data = 20 <- Free memory allocated for the copy of Move(20)
  ~Move called for data = 20 <- Free memory allocated for Move(20)
  ~Move called for data = 10 <- Free memory allocated for Move(10)
  */

 /*
  With move constructor:
  Move(int d) called with d = 10
  Move constructor called for data = 10
  ~Move called for nullptr
  Move(int d) called with d = 20
  Move constructor called for data = 20
  Deep copy Move(const Move &source) called for data = 10
  ~Move called for data = 10
  ~Move called for nullptr
  ~Move called for data = 20
  ~Move called for data = 10
 */

  return 0;
}

void Move::set_data(int d) { *data = d; }

int Move::get_data() const { return *data; }

Move::Move(int d) : data(new int(d))
{
  cout << "Move(int d) called with d = " << d << endl;
}

Move::Move(const Move &source) : data(new int(*source.data))
{
  cout << "Deep copy Move(const Move &source) called for data = " << *source.data << endl;
}

// Move constructor
Move::Move(Move &&source) : data(source.data) // reuse the data pointer from the source object
{
  cout << "Move constructor called for data = " << *source.data << endl;
  source.data = nullptr; // set the data pointer of the source object to null
  // This is important because the source object is a temporary object that will be destroyed soon
  // Different from a shallow copy, the source object does not need to keep the data pointer
}

Move::~Move()
{
  // cout << "~Move called for data = " << *data << endl; <- produces segmentation fault
  // https://stackoverflow.com/questions/2346806/what-is-a-segmentation-fault
  // I was trying to dereference a pointer that was already made null by the move constructor
  if (data != nullptr)
    cout << "~Move called for data = " << *data << endl;
  else
    cout << "~Move called for nullptr" << endl;
  delete data;
}
