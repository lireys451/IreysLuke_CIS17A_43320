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
struct MonthlyBudget
{
    float hsing,
          ulty,
          exps,
          trans,
          food,
          med,
          insr,
          entr,
          clth,
          misc;
};

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

void getData(MonthlyBudget &);
void compare(MonthlyBudget &bdgt);
void ttl(MonthlyBudget &bdgt);


//Execution Begins Here
int main(int argc, char** argv) 
{
    
    struct MonthlyBudget bdgt;
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    
    //Initialize Variables
    
    //Process or map Inputs to Outputs
    getData(bdgt);
    
    //Display Outputs
    compare(bdgt);
    
    ttl(bdgt);

    //Exit stage right!
    return 0;
}

void getData(MonthlyBudget &bdgt)
{
    cout << "Enter housing cost for the month:$";
    cin >> bdgt.hsing;
    cout << endl;
    cout << "Enter utilities cost for the month:$" ;
    cin >> bdgt.ulty;
    cout << endl;
    cout << "Enter household expenses cost for the month:$" ;
    cin >> bdgt.exps;
    cout << endl;
    cout << "Enter transportation cost for the month:$" ;
    cin >> bdgt.trans;
    cout << endl;
    cout << "Enter food cost for the month:$";
    cin >> bdgt.food;
    cout << endl;
    cout << "Enter medical cost for the month:$";
    cin >> bdgt.med;
    cout << endl;
    cout << "Enter insurance cost for the month:$";
    cin >> bdgt.insr;
    cout << endl;
    cout << "Enter entertainment cost for the month:$";
    cin >> bdgt.entr;
    cout << endl;
    cout << "Enter clothing cost for the month:$";
    cin >> bdgt.clth;
    cout << endl;
    cout << "Enter miscellaneous cost for the month:$";
    cin >> bdgt.misc;
    cout << endl;
}

void compare(MonthlyBudget &bdgt)
{
    cout << "Housing ";
    if(bdgt.hsing > 500)
    cout << "Over";
    else if (bdgt.hsing < 500)
    cout << "Under";
    else
    cout << "Even";
    cout << endl;
    
    cout << "Utilities ";
    if(bdgt.ulty > 150)
    cout << "Over";
    else if (bdgt.ulty < 150)
    cout << "Under";
    else
    cout << "Even";
    cout << endl;
    
    cout << "Household Expenses ";
    if(bdgt.exps > 65)
    cout << "Over";
    else if (bdgt.exps < 65)
    cout << "Under";
    else
    cout << "Even";
    cout << endl;
    
    cout << "Transportation ";
    if(bdgt.trans > 50)
    cout << "Over";
    else if (bdgt.trans < 50)
    cout << "Under";
    else
    cout << "Even";
    cout << endl;
    
    cout << "Food ";
    if(bdgt.food > 250)
    cout << "Over";
    else if (bdgt.food < 250)
    cout << "Under";
    else
    cout << "Even";
    cout << endl;
    
    cout << "Medical ";
    if(bdgt.med > 30)
    cout << "Over";
    else if (bdgt.med < 30)
    cout << "Under";
    else
    cout << "Even";
    cout << endl;
    
    cout << "Insurance ";
    if(bdgt.insr > 100)
    cout << "Over";
    else if (bdgt.insr < 100)
    cout << "Under";
    else
    cout << "Even";
    cout << endl;
    
    cout << "Entertainment ";
    if(bdgt.entr > 150)
    cout << "Over";
    else if (bdgt.entr < 150)
    cout << "Under";
    else
    cout << "Even";
    cout << endl;
    
    cout << "Clothing ";
    if(bdgt.clth > 75)
    cout << "Over";
    else if (bdgt.clth < 75)
    cout << "Under";
    else
    cout << "Even";
    cout << endl;
    
    cout << "Miscellaneous ";
    if(bdgt.misc > 50)
    cout << "Over";
    else if (bdgt.misc < 50)
    cout << "Under";
    else
    cout << "Even";
    cout << endl;
}

void ttl(MonthlyBudget &bdgt)
{
    float total;
    
    float totalUsr = bdgt.hsing + bdgt.ulty + bdgt.exps + bdgt.trans + bdgt.food + bdgt.med + bdgt.insr + bdgt.entr + bdgt.clth + bdgt.misc;
    float totalBdgt = 500 + 150 + 65 + 50 + 250 + 30 + 100 + 150 + 75 + 50;
    
    if(totalUsr > totalBdgt)
    {
        total = totalUsr - totalBdgt;
        cout << "You were $" << fixed << setprecision(2) << total << " over budget";
    }
    
    else if(totalUsr < totalBdgt)
    {
        total = totalBdgt - totalUsr;
        cout << "You were $" << fixed << setprecision(2) << total << " under budget";
    }
    
    else
    {
        cout << "Your spending was equal to your budget";
    }
}