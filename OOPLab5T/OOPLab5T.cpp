// OOPLab5T.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <cstdlib>
#include <ctime>

// Ваші файли загловки 
//
#include "Lab5Exmaple.h"
int main()
{
    std::cout << " Lab #5  !\n";
   // Завлання 1
    class Point {
private:
    double x, y;
public:
    Point() {
        x = y = 0;
    }

    Point(double xCoord, double yCoord) {
        x = xCoord;
        y = yCoord;
    }

    ~Point() {}

    void print() {
        cout << "Point coordinates: (" << x << ", " << y << ")" << endl;
    }

    void setX(double xCoord) {
        x = xCoord;
    }

    void setY(double yCoord) {
        y = yCoord;
    }

    double getX() {
        return x;
    }

    double getY() {
        return y;
    }
};

class ColorPoint : public Point {
private:
    int red, green, blue;
public:
    ColorPoint() : Point() {
        red = green = blue = 0;
    }

    ColorPoint(double xCoord, double yCoord, int r, int g, int b) : Point(xCoord, yCoord) {
        red = r;
        green = g;
        blue = b;
    }

    ~ColorPoint() {}

    void print() {
        cout << "Color point coordinates: (" << getX() << ", " << getY() << ")" << endl;
        cout << "Color: RGB(" << red << ", " << green << ", " << blue << ")" << endl;
    }

    void setColor(int r, int g, int b) {
        red = r;
        green = g;
        blue = b;
    }

    void setCoords(double xCoord, double yCoord) {
        setX(xCoord);
        setY(yCoord);
    }
};

int main() {
    srand(time(0)); // Initialize random seed

    // Create a point object with default constructor
    Point p1;
    p1.print();

    // Create a point object with 2 parameters
    Point p2(3.5, 2.0);
    p2.print();

    // Create a color point object with default constructor
    ColorPoint cp1;
    cp1.print();

    // Create a color point object with 5 parameters
    ColorPoint cp2(1.0, 1.5, 255, 0, 0);
    cp2.print();

    // Set random coordinates and color for cp1
    double x = ((double)rand() / RAND_MAX) * 10;
    double y = ((double)rand() / RAND_MAX) * 10;
    int r = rand() % 256;
    int g = rand() % 256;
    int b = rand() % 256;
    cp1.setCoords(x, y);
    cp1.setColor(r, g, b);
    cp1.print();
// Завдання 2

using namespace std;

class Processor {
private:
    int power; // Потужність процесора в МГц
public:
    Processor(int p) {
        power = p;
    }
    int getPower() {
        return power;
    }
};

class Computer {
private:
    char* brand; // Марка комп'ютера
    int price; // Ціна комп'ютера
    Processor* processor; // Об'єкт класу процесор
public:
    Computer(char* b, int p, Processor* pr) {
        brand = new char[strlen(b) + 1];
        strcpy(brand, b);
        price = p;
        processor = pr;
    }
    ~Computer() {
        delete[] brand;
        delete processor;
    }
    char* getBrand() {
        return brand;
    }
    int getPrice() {
        return price;
    }
    Processor* getProcessor() {
        return processor;
    }
};

class Desktop : public Computer {
private:
    int monitorSize; // Розмір монітора в дюймах
public:
    Desktop(char* b, int p, Processor* pr, int m) : Computer(b, p, pr) {
        monitorSize = m;
    }
    ~Desktop() {
        cout << "Desktop destroyed" << endl;
    }
    void printInfo() {
        cout << "Brand: " << getBrand() << endl;
        cout << "Price: " << getPrice() << endl;
        cout << "Processor Power: " << getProcessor()->getPower() << " MHz" << endl;
        cout << "Monitor Size: " << monitorSize << " inches" << endl;
    }
};

int main() {
    Processor* i5 = new Processor(3200); // Створюємо об'єкт процесора
    Desktop* pc = new Desktop("HP", 500, i5, 22); // Створюємо об'єкт комп'ютера з монітором
    pc->printInfo(); // Друкуємо інформацію про комп'ютер
    delete pc; // Видаляємо об'єкт комп'ютера
    delete i5; // Видаляємо об'єкт процесора
    
    // Завдання 3
    class Person {
protected:
    std::string name;
    int age;
public:
    Person() : name(""), age(0) {}
    Person(std::string n, int a) : name(n), age(a) {}
    virtual ~Person() {}
    virtual void print(std::ostream& os) const {
        os << "Name: " << name << ", Age: " << age << std::endl;
    }
    virtual void read(std::istream& is) {
        is >> name >> age;
    }
    Person(const Person& p) : name(p.name), age(p.age) {}
    Person& operator=(const Person& p) {
        if (this != &p) {
            name = p.name;
            age = p.age;
        }
        return *this;
    }
};

class Employee : public Person {
private:
    std::string position;
    double salary;
public:
    Employee() : Person(), position(""), salary(0.0) {}
    Employee(std::string n, int a, std::string pos, double sal)
        : Person(n, a), position(pos), salary(sal) {}
    ~Employee() {}
    void print(std::ostream& os) const override {
        Person::print(os);
        os << "Position: " << position << ", Salary: " << salary << std::endl;
    }
    void read(std::istream& is) override {
        Person::read(is);
        is >> position >> salary;
    }
    Employee(const Employee& e) : Person(e), position(e.position), salary(e.salary) {}
    Employee& operator=(const Employee& e) {
        if (this != &e) {
            Person::operator=(e);
            position = e.position;
            salary = e.salary;
        }
        return *this;
    }
};

int main() {
    Person p1("John", 25);
    Employee e1("Jane", 30, "Manager", 50000.0);
    std::cout << "Person p1: " << std::endl;
    p1.print(std::cout);
    std::cout << "Employee e1: " << std::endl;
    e1.print(std::cout);

    Person p2 = p1;
    Employee e2 = e1;
    std::cout << "Person p2: " << std::endl;
    p2.print(std::cout);
    std::cout << "Employee e2: " << std::endl;
    e2.print(std::cout);

    return 0;
}

