
#include <iostream>
#include <iomanip>
using namespace std;

float YEN_PER_DOLLAR(float);
float EUROS_PER_DOLLAR(float);

int main() {
    cout << "Enter U.S. dollar amount: ";
    float dollar;
    cin >> dollar;
    float yen = YEN_PER_DOLLAR(dollar);
    cout << fixed << setprecision(0) << yen << " Yen" << endl;
    float euros = EUROS_PER_DOLLAR(dollar);
    cout << fixed << setprecision(0) << euros << " Euros";        
    return 0;
}

float YEN_PER_DOLLAR(float dollar)
{
    return (dollar * 108.94);
}

float EUROS_PER_DOLLAR(float dollar)
{
    return (dollar * 0.84);
}