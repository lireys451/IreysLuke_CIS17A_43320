#include <iostream>
#include <iomanip>

using namespace std;

struct Drinks
{
  string name;
  float cost;
  int stock;
};

void fillData(Drinks *);
void prntData(Drinks *);
void usrInput(Drinks *);

int main(){
	
	struct Drinks drnk[4];
	
	fillData(drnk);
	
	prntData(drnk);
	
	usrInput(drnk);
	
	delete []drnk;
	return 0;
}

void fillData(Drinks *drnk)
{
    Drinks *drnks = new Drinks;
    
    drnk[0].name = "Cola";
    drnk[0].cost = 0.75;
    drnk[0].stock = 20;
    
    drnk[1].name = "Root Beer";
    drnk[1].cost = 0.75;
    drnk[1].stock = 20;
    
    drnk[2].name = "Lemon-Lime";
    drnk[2].cost = 0.75;
    drnk[2].stock = 20;
    
    drnk[3].name = "Grape Soda";
    drnk[3].cost = 0.80;
    drnk[3].stock = 20;
    
    drnk[4].name = "Cream Soda";
    drnk[4].cost = 0.80;
    drnk[4].stock = 20;
}

void prntData(Drinks *drnk)
{
    for(int i = 0; i < 5; i++)
    {
        cout << left << setw (11) << drnk[i].name << setw(4) << (drnk[i].cost * 100) << drnk[i].stock << endl;
    }
    
    cout << setw(4) << "Quit" << endl;
}

void usrInput(Drinks *drnk)
{
    string usrName;
    int usrCost;
    int change;
    
    do
    {
        cin >> usrName;
        cin >> usrCost;
        
        if(usrName == "Cola") 
        change = usrCost - (drnk[0].cost * 100);
        
        else if(usrName == "Root Beer") 
        change = usrCost - (drnk[1].cost * 100);
        
        else if(usrName == "Lemon-Lime") 
        change = usrCost - (drnk[2].cost * 100);
        
        else if(usrName == "Grape Soda") 
        change = usrCost - (drnk[3].cost * 100);
        
        else if(usrName == "Cream Soda") 
        change = usrCost - (drnk[4].cost * 100);
        
        else
        cout << "Incorrect input. Try again: ";
    }
    while(usrName != "Quit");
    
    cout << change << endl;
    
}