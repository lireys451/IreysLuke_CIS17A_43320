
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() 
{
    char june[30];
    char july[30];
    char august[30];
    
    ifstream file;
    file.open("RainOrShine.txt");
    
    if(file.is_open())
    {
        int i = 0;
        
        while(i < 30)
        {
            file >> june[i];
            i++;
        }
        
        while(i > 30, i < 60)
        {
            file >> july[i];
            i++;
        }
                        
                       
        file.close();
    }
    

    for(int j = 0; j < 30; j++)
    {
        cout << june[j];
    }

    
    
    return 0;
}

