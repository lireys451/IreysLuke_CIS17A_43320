#include <iostream>
#include <iomanip>

using namespace std;

int *getData(int &);
void prntData(int *,int);
float *median(int *, int);
void prntMed(float *, int);

int main(){
	
	int SIZE;
	int *ary;
	float *medianAry;
	
	ary = getData(SIZE);
	
	prntData(ary, SIZE);
	
	medianAry = median(ary, SIZE);
	
	cout << (SIZE + 2) << " ";
	
	prntMed(medianAry, SIZE);
	
	delete []ary;
	delete medianAry;
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

void prntData(int *ary, int SIZE)
{
    for(int i = 0; i < (SIZE - 1); i++)
    {
        cout << *(ary + i) << " ";
    }
    
    cout << *(ary + (SIZE - 1));
    
    cout << endl;
}
float *median(int *ary, int SIZE)
{
    float *medianAry = new float[SIZE];
    
    for(int i = 0; i < SIZE; i++)
    {
        *(medianAry + i) = *(ary +i);
    }
    
    return medianAry;
}
void prntMed(float *medianAry, int SIZE)
{
    float sum;
    float fSIZE = 0;
    
    for(int i = 0; i < SIZE; i++)
    {
        sum += *(medianAry + i);
        fSIZE++;
    }
    
    float median = (sum/fSIZE);
    
    cout << fixed << setprecision(2) << median << " ";
    
    for(int i = 0; i < (SIZE - 1); i++)
    {
        cout << *(medianAry + i) << " ";
    }
    
    cout << *(medianAry + (SIZE - 1));
}