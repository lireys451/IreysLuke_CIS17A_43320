#include <iostream>

using namespace std;

int *getData(int &);
int *augment(const int *, int);
void prntAry(const int *, int);

int main(){
	
	int SIZE;
	int *ary;
	int *newAry;
	
	ary = getData(SIZE);
	
	newAry = augment(ary, SIZE);
	
	prntAry(ary, SIZE);
	cout << endl;
	prntAry(newAry, (SIZE + 1));
	
	delete []ary;
	delete []newAry;
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
int *augment(const int *ary, int SIZE)
{
    int *newAry=new int[SIZE];
    
    *(newAry + 0) = 0;
   
    for(int i = 0; i < SIZE; i++)
    {
        *(newAry + (i + 1)) = *(ary + i);
    }
    
    return newAry;
}
void prntAry(const int *ary, int SIZE)
{
    for(int i = 0; i < (SIZE - 1); i++)
    {
        cout << *(ary + i) << " ";
    }
    
    cout << *(ary + (SIZE - 1));
}