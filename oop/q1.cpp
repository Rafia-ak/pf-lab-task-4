#include <iostream>
#include <string>
using namespace std;

class Person{
private:
	string name;
	int age;
	string address;
	
public:
	Person(string n, int a, string addr) : name(n), age(a), address(addr) {}

	void displayDetails() {
		cout << "Name: " << name << endl;
		cout << "Age: " << age << " years"<< endl;
		cout << "Address: " << address << endl;
	}
};

class Student: public Person{
private:
	int studentID;
	char grade;

public:
	Student(string n, int a, string addr, int id) : Person(n, a, addr), studentID(id), grade('F') {}

	void calculateGPA(){
		double gpa = 0;
        if (grade == 'A') gpa = 4.0;
        else if (grade == 'B') gpa = 3.0;
        else if (grade == 'C') gpa = 2.0;
        else if (grade == 'D') gpa = 1.0;
        else if (grade == 'F') gpa = 0.0;

        cout << "GPA: " << gpa << endl;
    }
    
    void assignGrade(char g) {
        grade = g;
    }
};

class Payable {
public:
    virtual void calculateSalary() = 0;
};

class Teacher: public Person, public Payable {
private:
	int teacherID;
	string subject;
	
public:
	Teacher(string n, int a, string addr, int id, string sub) : Person(n, a, addr), teacherID(id), subject(sub) {}
	
	void assignGrade(Student &student, char grade) {
        student.assignGrade(grade);
    }

    void calculateSalary() override {
        double salary = 5000.0;
        cout << "Teacher's Salary: $" << salary << endl;
    }
    
    void displayDetails() {
        Person::displayDetails();
        cout << "Teacher ID: " << teacherID << endl;
        cout << "Subject: " << subject << endl;
    }
};

int main(){
	Teacher teacher1("Mr. Rahim", 40, "123 Main St", 101, "Physics");
    Student student1("Rafia", 19, "456 Elm St", 201);
    Student student2("Amna", 18, "789 Oak St", 202);

    teacher1.assignGrade(student1, 'A');
    teacher1.assignGrade(student2, 'B');

    cout << "Teacher Details:" << endl;
    teacher1.displayDetails();

    teacher1.calculateSalary();

    cout << "\nStudent 1 Details:" << endl;
    student1.displayDetails();
    student1.calculateGPA();

    cout << "\nStudent 2 Details:" << endl;
    student2.displayDetails();
    student2.calculateGPA();

    return 0;
}

























