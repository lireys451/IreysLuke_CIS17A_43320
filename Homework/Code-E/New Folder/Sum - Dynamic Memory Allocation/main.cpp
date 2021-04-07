#include <iostream>

using namespace std;


int *getData(int &);
int *sumAry(const int *, int);
void prntAry(int *,int);

int main(){
    
    int SIZE;
    int *ary;
    int *sum;

    ary = getData(SIZE);
    
    sum = sumAry(ary, SIZE);
    
    prntAry(ary, SIZE);
    
    cout << endl;
    
    prntAry(sum, SIZE);
    
    delete []sum;
    delete []ary;
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

int *sumAry(const int *ary, int SIZE)
{

    int *sum = new int[SIZE];
    
    *(sum + 0) = 0;
    
    for(int i = 0; i < SIZE; i++)
    {
        *(sum + i) = *(sum + (i - 1)) + *(ary + i);
    }
    
    return sum;
    
}

void prntAry(int *ary, int SIZE)
{
    for(int i = 0; i < (SIZE - 1); i++)
    {
        cout << *(ary + i) << " ";
    }
    
    cout << *(ary + (SIZE - 1));
}