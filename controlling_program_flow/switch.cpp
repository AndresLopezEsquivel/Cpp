#include <iostream>

using namespace std;

int main()
{
  enum Color
  {
    red,
    green,
    blue
  };

  Color color{green};

  switch (color)
  {
    case red:
      cout << "Selected color red " << endl;
      break;

    case green:
      cout << "Selected color green" << endl;
      break;

    case blue:
      cout << "Selected color blue" << endl;
      break;

    default:
      cout << "This won't be executed" << endl;
      break;
  }

  char vowel {'a'};

  switch (vowel)
  {
    case 'a':
    case 'A':
      cout << "Selected the vowel a/A" << endl;
      break;
    case 'e':
    case 'E':
      cout << "Selected the vowel e/E" << endl;
      break;
    case 'i':
    case 'I':
      cout << "Selected the vowel i/I" << endl;
      break;
    case 'o':
    case 'O':
      cout << "Selected the vowel o/O" << endl;
      break;
    case 'u':
    case 'U':
      cout << "Selected the vowel u/U" << endl;
      break;
    default:
      cout << "You didn't select a vowel" << endl;
  }

  return 0;
}
