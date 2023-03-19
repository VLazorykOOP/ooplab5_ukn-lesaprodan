# ooplab5_ukn-lesaprodan
ooplab5_ukn-lesaprodan created by GitHub Classroom
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

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

    return 0;
}
