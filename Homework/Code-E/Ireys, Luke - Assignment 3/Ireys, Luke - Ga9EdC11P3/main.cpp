/* 
 * File:   
 * Author: 
 * Created on 
 * Purpose:  
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

struct CompDiv
{
    float frstQtr;
    float scndQtr;
    float thrdQtr;
    float frthQtr;
};

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

void getData(CompDiv &);
float ttl(CompDiv &);
void avrg(CompDiv &, const float);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    
    //Declare Variable Data Types and Constants
    struct CompDiv North,
                   West,
                   East,
                   South;
    
    //Initialize Variables
    float total;
    float average;
    
    //Process or map Inputs to Outputs
    cout << "North" << endl;
    getData(North);
    total = ttl(North);
    avrg(North, total);
    cout << endl;
    cout << "West" << endl;
    getData(West);
    total = ttl(West);
    avrg(West, total);
    cout << endl;
    cout << "East" << endl;
    getData(East);
    total = ttl(East);
    avrg(East, total);
    cout << endl;
    cout << "South" << endl;
    getData(South);
    total = ttl(South);
    avrg(South, total);
    
    
    //Display Outputs
    
    
    
    
    
    
    
    
    

    //Exit stage right!
    return 0;
}

void getData(CompDiv &div)
{
    cout << "Enter first-quarter sales:";
    cin >> div.frstQtr;
    cout << endl;
    cout << "Enter second-quarter sales:" ;
    cin >> div.scndQtr;
    cout << endl;
    cout << "Enter third-quarter sales:" ;
    cin >> div.thrdQtr;
    cout << endl;
    cout << "Enter fourth-quarter sales:" ;
    cin >> div.frthQtr;
    cout << endl;
}

float ttl(CompDiv &div)
{
    float total = div.frstQtr + div.scndQtr + div.thrdQtr + div.frthQtr;
    cout << "Total Annual sales:$" << fixed << setprecision(2) << total << endl;
    
    return total;
}

void avrg(CompDiv &div, const float total)
{
    float avrg = total / 4;
    cout << "Average Quarterly Sales:$" << fixed << setprecision(2) << avrg;
    
}