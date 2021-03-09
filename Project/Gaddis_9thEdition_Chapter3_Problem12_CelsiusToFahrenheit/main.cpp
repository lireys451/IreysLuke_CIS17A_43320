
#include <iostream>
#include <iomanip>
using namespace std;

float conversion (float);

int main(float newTemp) 
{
    cout << "Input Celsius to convert to Fahrenheit" << endl;
    float oldTemp;
    cin >> oldTemp;
    newTemp = conversion(oldTemp);
    cout << fixed << "Temperature in Fahrenheit: " << setprecision(0) << newTemp << endl;
    return 0;
    
}

float conversion(float oldTemp)
{
    float newTemp;
    newTemp = (1.8 * oldTemp) + 32;
    return newTemp;
}
