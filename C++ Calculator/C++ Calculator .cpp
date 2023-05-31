#include <iostream>
using namespace std;

void enter(float& a, float& b)
{
    cout << "Enter 2 numbers to calculate" << endl;
    cin >> a >> b;
}

char choice_of_operation()
{
    char choice;
    do
    {
        cout << "Enter a character: ";
        cin >> choice;
        if (choice != '+' && choice != '-' && choice != '*' && choice != '/')
        {
            cout << "Enter choice again" << endl;
        }
    } while (choice != '+' && choice != '-' && choice != '*' && choice != '/');

    return choice;
}

float operation(float a, float b, char choice)
{
    float result = 0.0  ;
    if (choice == '+')
    {
        result = a + b;
    }
    else if (choice == '-')
    {
        result = a - b;
    }
    else if (choice == '*')
    {
        result = a * b;
    }
    else if (choice == '/')
    {
        result = a / b;
    }
    return result;
}

int main()
{
    float a, b;
    enter(a, b);
    char choice = choice_of_operation();
    cout << "Result is: " << operation(a, b, choice) << endl;

    return 0;
}