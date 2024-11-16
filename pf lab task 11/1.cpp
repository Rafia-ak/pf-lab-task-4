#include <iostream>
#include <string>
using namespace std;

class Animal {
private:
    string name;
    int age;

public:
    void setName(string animalName) {
        name = animalName;
    }

    string getName() {
        return name;
    }

    void setAge(int animalAge) {
        age = animalAge;
    }

    int getAge() {
        return age;
    }

    void displayInfo() {
        cout << "Animal Name: " << name << endl;
        cout << "Animal Age: " << age << " years" << endl;
    }
};

class Mammal : public Animal {
public:
    void feedBaby() {
        cout << "Feeding baby mammal." << endl;
    }
};

class Bird : public Animal {
public:
    void layEgg() {
        cout << "Laying an egg." << endl;
    }
};

class Reptile : public Animal {
public:
    void shedSkin() {
        cout << "Shedding skin." << endl;
    }
};

int main() {
    Mammal mammal;
    Bird bird;
    Reptile reptile;

    mammal.setName("Lion");
    mammal.setAge(5);
    mammal.displayInfo();
    mammal.feedBaby();
    cout << endl;

    bird.setName("Parrot");
    bird.setAge(2);
    bird.displayInfo();
    bird.layEgg();
    cout << endl;

    reptile.setName("Snake");
    reptile.setAge(3);
    reptile.displayInfo();
    reptile.shedSkin();
    cout << endl;

    return 0;
}
