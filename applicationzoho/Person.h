#include <string>

class Person
{
public:
  std::string name;
  int age;

  Person(std::string username, int userage)
  {
    this->name = username;
    this->age = userage;
  }
};