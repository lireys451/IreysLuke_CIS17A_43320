#include <iostream>
#include <iomanip>

using namespace std;

int *getData(int &);
int *sort(const int *, int);
int *reverse(const int *, int);
void prntData(int *,int);

int main(){
	
	int SIZE;
	int *ary;
	int *newAry;
	int *newAry2;
	
	ary = getData(SIZE);
	
	newAry = sort(ary, SIZE);
	
	newAry2 = reverse(ary, SIZE);
	
	prntData(newAry, SIZE);
	cout << endl;
	prntData(newAry2, SIZE);
	
	delete []ary;
	delete []newAry;
	delete []newAry2;
	return 0;
}

int *getData(int &SIZE)
{
    cin >> SIZE;
    int *ary = new int[SIZE];
    
    for(int i = 0; i < SIZE; i++)
    {
        cin >> *(ary + i);
    }
    
    return ary;
}

int *sort(const int *ary, int SIZE)
{
    
    int *newAry=new int[SIZE];
    //Fill with passed array
    for(int i = 0; i < SIZE; i++)
    {
        *(newAry + i) = *(ary + i);
    }
    
    
    for (int i = 0; i < (SIZE-1); i++)
    {
        for(int j = i + 1; j < SIZE; j++)
        {
            if (*(newAry + i) > *(newAry + j))
            {
                *(newAry + i) = *(newAry + i) ^ *(newAry + j);
                *(newAry + j) = *(newAry + i) ^ *(newAry + j);
                *(newAry + i) = *(newAry + i) ^ *(newAry + j);
            }
        }
    }
    
    
    return newAry;
}

int *reverse(const int *ary, int SIZE)
{
    int *newAry=new int[SIZE];
    //Fill with passed array
    for(int i = 0; i < SIZE; i++)
    {
        *(newAry + i) = *(ary + i);
    }
    
    
    for (int i = 0; i < (SIZE-1); i++)
    {
        for(int j = i + 1; j < SIZE; j++)
        {
            if (*(newAry + i) < *(newAry + j))
            {
                *(newAry + i) = *(newAry + i) ^ *(newAry + j);
                *(newAry + j) = *(newAry + i) ^ *(newAry + j);
                *(newAry + i) = *(newAry + i) ^ *(newAry + j);
            }
        }
    }
    
    
    return newAry;
}

void prntData(int *newAry, int SIZE)
{
    
    for(int i = 0; i < (SIZE - 1); i++)
    {
        cout << *(newAry + i) << " ";
    }
    
    cout << *(newAry + (SIZE - 1));
    
    
}