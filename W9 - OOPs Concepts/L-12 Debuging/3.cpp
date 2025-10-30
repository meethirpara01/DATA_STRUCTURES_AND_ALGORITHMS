#include <iostream>
using namespace std;

class Shape
{
public:
    Shape(int s) : sides(s) {}
    virtual void draw() { cout << "Drawing a shape with " << sides << " sides." << endl; }

private:
    int sides;
};

class Circle : public Shape
{
public:
    Circle(int r) : Shape(0), radius(r) {} // Call the base class constructor
    // No need to redefine draw() here
private:
    int radius;
};

int main()
{
    Shape *s = new Circle(5);
    s->draw(); // Output: "Drawing a shape with 0 sides."
    delete s;
    return 0;
}