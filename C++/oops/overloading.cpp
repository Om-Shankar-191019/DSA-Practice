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

int main()
{

    Addition a1;

    cout << a1.add(2, 3) << endl;
    cout << a1.add(2, 3, 9) << endl;
    cout << a1.add(2.4f, 3.5f) << endl;
    cout << a1.add("maa", " ji") << endl;
    return 0;
}