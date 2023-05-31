#include <iostream>
using namespace std;

float calculateArea(float length, float width, char unit)
{
    float area = 0.0;

    if (unit == 'm')
    {
        area = length * width;
    }
    else if (unit == 'c')
    {
        area = (length * width) / 100.0; // Convert to meters
    }
    else if (unit == 'f')
    {
        area = (length * width) / 10.764; // Convert to square meters
    }

    return area;
}

int main()
{
    float length, width;
    char unit;

    cout << "Enter length: ";
    cin >> length;

    cout << "Enter width: ";
    cin >> width;

    cout << "Enter unit ('m' for meter, 'c' for centimeter, 'f' for feet): ";
    cin >> unit;

    float area = calculateArea(length, width, unit);

    cout << "Area is: " << area << " square " << unit << endl;

    return 0;
}