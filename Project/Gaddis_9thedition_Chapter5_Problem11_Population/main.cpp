
#include <iostream>
#include <iomanip>
using namespace std;


int main() {
    float starting_number_of_organisms;
    float average_daily_population_increase;
    float size_of_daily_population;
    
    int number_of_days_to_multiply;
    
    cout << "Enter the starting population number: ";
    
   while (!(cin >> starting_number_of_organisms) || 
                    starting_number_of_organisms < 2)
    {
        cout << "The starting population must be greater than 2." << endl;
        cout << "Enter the starting population number: ";
        cin.clear();
        cin.ignore(123, '/n');
    }
    cout << "Enter average daily population increase (%): ";

    while (!(cin >> average_daily_population_increase) || 
                    average_daily_population_increase < 0)
        {
        cout << "Oops. Average daily population increase\n"
             << " must be greater than 0. Enter average\n"  
             << " daily population increase (%): ";
        cin.clear();
        cin.ignore(123, '\n');
    }
    
    average_daily_population_increase *= .01;
    
    cout << "Enter the total number of days the population will multiply: ";
    
    while(!(cin >> number_of_days_to_multiply) ||
            number_of_days_to_multiply < 1)
    {
        cout << "Number of days can not be less/n"
                << "than 1. Reenter another number of/n"
                << "day to multiply: ";
        cin.clear();
        cin.ignore(123, '/n');
    }
    
    for(int i = 0; i < number_of_days_to_multiply; i++)
    {
        cout << fixed << setprecision(0) << "Population size for day " << (i + 1);
        cout << ": " << starting_number_of_organisms << endl;
        
        starting_number_of_organisms +=
                (starting_number_of_organisms * 
                average_daily_population_increase);
    }
    
    return 0;
}

