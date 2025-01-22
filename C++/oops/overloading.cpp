#include <iostream>
using namespace std;

class Addition
{

public:
    int add(int a, int b)
    {
        return a + b;
    }

    int add(int a, int b, int c)
    {
        return a + b + c;
    }

    float add(float a, float b)
    {
        return a + b;
    }
    string add(string a, string b)
    {
        return a + b;
    }
};

// constructor overloading --
#include <iostream>
using namespace std;

class Rectangle
{
private:
    int length;
    int width;

public:
    // Default constructor
    Rectangle()
    {
        length = 0;
        width = 0;
    }

    // Parameterized constructor for square
    Rectangle(int side)
    {
        length = side;
        width = side;
    }

    // Parameterized constructor for rectangle
    Rectangle(int l, int w)
    {
        length = l;
        width = w;
    }

    // Copy constructor
    Rectangle(const Rectangle &rect)
    {
        length = rect.length;
        width = rect.width;
    }

    // Method to display the dimensions
    void display()
    {
        cout << "Length: " << length << ", Width: " << width << endl;
    }

    // Method to calculate area
    int area()
    {
        return length * width;
    }
};

int main()
{

    Rectangle rect1;         // Calls default constructor
    Rectangle square(5);     // Calls single-parameter constructor
    Rectangle rect2(10, 20); // Calls two-parameter constructor
    Rectangle rect3 = rect2; // Calls copy constructor

    cout << "Rectangle 1: ";
    rect1.display();
    cout << "Area: " << rect1.area() << endl;

    cout << "\nSquare: ";
    square.display();
    cout << "Area: " << square.area() << endl;

    cout << "\nRectangle 2: ";
    rect2.display();
    cout << "Area: " << rect2.area() << endl;

    cout << "\nRectangle 3 (copy of Rectangle 2): ";
    rect3.display();
    cout << "Area: " << rect3.area() << endl;
    // Addition a1;

    // cout << a1.add(2, 3) << endl;
    // cout << a1.add(2, 3, 9) << endl;
    // cout << a1.add(2.4f, 3.5f) << endl;
    // cout << a1.add("maa", " ji") << endl;
    return 0;
}