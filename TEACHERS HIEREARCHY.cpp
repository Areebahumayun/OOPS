#include<iostream>
using namespace std;

class Teacher {
private:
    string name;
    int age;
    string institute;

public:
    void setData(string n, int a, string i){
        name = n;
        age = a;
        institute = i;
    }

    void displayTeacher(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Institute: " << institute << endl;
    }
};

class HumanitiesTeacher : public Teacher {
public:
    string department = "Humanities";
    string course;
    string designation;

    void display(){
        displayTeacher();
        cout << "Department: " << department << endl;
        cout << "Course: " << course << endl;
        cout << "Designation: " << designation << endl;
    }
};

class ScienceTeacher : public Teacher {
public:
    string department = "Science";
    string course;
    string designation;

    void display(){
        displayTeacher();
        cout << "Department: " << department << endl;
        cout << "Course: " << course << endl;
        cout << "Designation: " << designation << endl;
    }
};

class MathsTeacher : public Teacher {
public:
    string department = "Maths";
    string course;
    string designation;

    void display(){
        displayTeacher();
        cout << "Department: " << department << endl;
        cout << "Course: " << course << endl;
        cout << "Designation: " << designation << endl;
    }
};

int main(){
    HumanitiesTeacher h;
    h.setData("Areeba", 25, "ABC University");
    h.course = "History";
    h.designation = "Lecturer";
    h.display();}