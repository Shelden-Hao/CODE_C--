#include <iostream>
using namespace std;
#include <string>
class Teacher {
  public:
    Teacher(string name, int age);
    void display();
  protected: 
    string name;
    int age;
};
Teacher::Teacher(string name, int age) : name(name), age(age) {}
void Teacher::display() {
  cout << "Name: " << name << endl;
  cout << "Age: " << age << endl;
}
class Cadre {
  public:
    Cadre(string name, int age);
    void display();
  protected:
    string name;
    int age;
};
Cadre::Cadre(string name, int age) : name(name), age(age) {
}
void Cadre::display() {
  cout << "Name: " << name << endl;
  cout << "Age: " << age << endl;
}
class Student : public Teacher, public Cadre {
  public:
    Student(string name, int age, string teacherName, int teacherAge, string cadreName, int cadreAge);
    void display();
  private:
    string teacherName;
    int teacherAge;
    string cadreName;
    int cadreAge;
};
Student::Student(string name, int age, string teacherName, int teacherAge, string cadreName, int cadreAge) : Teacher(name, age), Cadre(name, age), teacherName(teacherName), teacherAge(teacherAge), cadreName(cadreName), cadreAge(cadreAge) {}
void Student::display() {
    cout << "Name: " << Teacher::name << endl;
    cout << "Age: " << Teacher::age << endl;
    cout << "Teacher Name: " << teacherName << endl;
    cout << "Teacher Age: " << teacherAge << endl;
    cout << "Cadre Name: " << cadreName << endl;
    cout << "Cadre Age: " << cadreAge << endl;
}

int main() {
  Student student("John", 18, "Mary", 25, "Joe", 30);
  student.display();
  return 0;

}