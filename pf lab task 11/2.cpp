#include <iostream>
#include <string>
using namespace std;

class Person {
private:
	string name;
	int age;
	
public:
	void setName(const string& n){
		name = n;
	}
	
	void setAge(int a){
		age = a;
	}
	
	string getName(){
		return name;
	}
	
	int getAge(){
		return age;
	}
	
	virtual void displayInfo(){
		cout << "Name: " << name << endl;
        cout << "Age: " << age << " years" << endl;
	}	
};

class Employee: public Person{
private:
	int employeeID;
		
public:
    void setEmployeeID(int id) {
        employeeID = id;
    }

    int getEmployeeID() {
        return employeeID;
    }

    void displayInfo() override {
        Person::displayInfo();
        cout << "Employee ID: " << employeeID << endl;
    }
};

class Student: public Person{
private:
	int studentID;

public:
    void setStudentID(int id) {
        studentID = id;
    }

    int getStudentID() {
        return studentID;
    }

    void displayInfo() override {
        Person::displayInfo();
        cout << "Student ID: " << studentID << endl;
    }
};

int main(){
	Person person;
    Employee employee;
    Student student;
    
    person.setName("Rafia Abdul Karim");
    person.setAge(19);
    cout << "Person Information:" << endl;
    person.displayInfo();
    cout << endl;

    employee.setName("Fariha Danish");
    employee.setAge(30);
    employee.setEmployeeID(1001);
    cout << "Employee Information:" << endl;
    employee.displayInfo();
    cout << endl;

    student.setName("Ghania Tabish");
    student.setAge(28);
    student.setStudentID(2001);
    cout << "Student Information:" << endl;
    student.displayInfo();
    cout << endl;

    return 0;
}
