#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

struct Employee {
    string name;
    int hoursWorked;
    float hourlyWage;
    float salary;
};

void generateRandomData(Employee* employees, int numEmployees)
{
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

    for (int i = 0; i < numEmployees; i++)
    {
        cout << "Enter name for Employee " << i + 1 << ": ";
        cin >> employees[i].name;
        employees[i].hoursWorked = rand() % 26 + 175; // Random hours between 175 and 200
        employees[i].hourlyWage = (rand() % 126 + 75) / 10.0; // Random hourly wage between 7.5 and 20
        employees[i].salary = employees[i].hoursWorked * employees[i].hourlyWage;
    }
}

void printTable(Employee* employees, int numEmployees)
{
    cout << "------------------------------------------------------" << endl;
    cout << setw(15) << left << "Name" << setw(15) << "Hours Worked" << setw(15) << "Salary" << endl;
    cout << "------------------------------------------------------" << endl;

    for (int i = 0; i < numEmployees; i++)
    {
        cout << setw(15) << left << employees[i].name;
        cout << setw(15) << employees[i].hoursWorked;
        cout << "$" << setw(14) << fixed << setprecision(2) << employees[i].salary << endl;
    }

    cout << "------------------------------------------------------" << endl;
}

float calculateAverageSalary(Employee* employees, int numEmployees)
{
    float totalSalary = 0.0;

    for (int i = 0; i < numEmployees; i++)
    {
        totalSalary += employees[i].salary;
    }

    return totalSalary / numEmployees;
}

Employee findEmployeeWithHighestEarnings(Employee* employees, int numEmployees)
{
    Employee highestEarner = employees[0];

    for (int i = 1; i < numEmployees; i++)
    {
        if (employees[i].salary > highestEarner.salary)
        {
            highestEarner = employees[i];
        }
    }

    return highestEarner;
}

Employee findEmployeeWithMostHoursWorked(Employee* employees, int numEmployees)
{
    Employee mostHoursWorker = employees[0];

    for (int i = 1; i < numEmployees; i++)
    {
        if (employees[i].hoursWorked > mostHoursWorker.hoursWorked)
        {
            mostHoursWorker = employees[i];
        }
    }

    return mostHoursWorker;
}

int main()
{
    int numEmployees;
    cout << "Enter the number of employees: ";
    cin >> numEmployees;

    Employee* employees = new Employee[numEmployees];
    generateRandomData(employees, numEmployees);

    cout << endl;
    printTable(employees, numEmployees);

    float averageSalary = calculateAverageSalary(employees, numEmployees);
    Employee highestEarner = findEmployeeWithHighestEarnings(employees, numEmployees);
    Employee mostHoursWorker = findEmployeeWithMostHoursWorked(employees, numEmployees);

    cout << "Average Salary: $" << fixed << setprecision(2) << averageSalary << endl;
    cout << "Employee with Highest Earnings: " << highestEarner.name << endl;
    cout << "Highest Earnings: $" << highestEarner.salary << endl;
    cout << "Employee with Most Hours Worked: " << mostHoursWorker.name << endl;
    cout << "Most Hours Worked: " << mostHoursWorker.hoursWorked << " hours" << endl;

    delete[] employees; // Deallocate the dynamic array

    return 0;
}