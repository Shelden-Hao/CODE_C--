#include <iostream>
using namespace std;
const double PI = 3.14;
class Student
{
public:
  Student()
  {
    cout << "Student()" << endl;
  }
  Student(string name, int age)
  {
    this->name = name;
    this->age = age;
    cout << "Student(string,int)" << endl;
  }
  ~Student()
  {
    cout << "~Student()" << endl;
  }
  void setAge(int age)
  {
    this->age = age;
  }
  void setName(string name)
  {
    this->name = name;
  }
  string getName()
  {
    return name;
  }
  int getAge()
  {
    return age;
  }
private:
  void print();
private:
  string name;
  int age;
};
void Student::print()
{
  cout << "name: " << name << endl;
}
int main()
{
  Student s1;
  // 1. 通过对象名和成员运算符访问对象中的成员
  s1.setName("John");
  // 2. 通过指向对象的指针访问对象的成员
  Student *p = &s1;
  p->setName("Mary");
  // 3. 通过对象的引用访问对象中的成员
  Student &r = s1;
  r.setName("Lucy");
  cout << s1.getName() << endl;
  return 0;
}