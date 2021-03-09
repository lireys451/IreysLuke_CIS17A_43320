
#include <iostream>
#include <iomanip>
using namespace std;

float celsius();


int main() 
{
    cout << "Fahrenheit:         Celsius:"<< endl
         << "----------------------------"<< endl;
    celsius();
    return 0;
}

float celsius()
{
    float fahrenheit = 0;
    float newTemp;
    
    while(fahrenheit < 10)
{
    newTemp = (fahrenheit - 32) * 5/9;
    cout << fixed << setprecision(0) << fahrenheit << "                   " 
         << fixed << setprecision(3) << newTemp << endl;
    fahrenheit++;
}

    while(fahrenheit >= 10, fahrenheit < 21)
{
    newTemp = (fahrenheit - 32) * 5/9;
    cout << fixed << setprecision(0) << fahrenheit << "                  " 
         << fixed << setprecision(3) << newTemp << endl;
    fahrenheit++;
}

    return newTemp;
}
