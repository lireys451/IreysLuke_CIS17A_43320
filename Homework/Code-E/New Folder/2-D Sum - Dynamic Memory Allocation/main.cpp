#include <iostream>

using namespace std;


int **getData(int &, int &);
void prntData(const int * const *, int, int);
void destroy(int **, int, int);
int sum(const int * const*, int, int);


int main(){
    
    int row, col;
    int **ary;
    int total;

    ary = getData(row, col);
    
    total = sum(ary, row, col);
    
    prntData(ary, row, col);
    
    cout << total;
    
    destroy(ary, row, col);
    
	return 0;
}

int **getData(int &row, int &col)
{
    cin >> row >> col;
    
    int** ary = new int*[row];

    for(int r = 0; r < row; r++) 
    {
        *(ary + r) = new int [col];
    }
    
    for(int r = 0; r < row; r++)
    {
        for(int c = 0; c < col; c++)
        {
            cin >> ary[r][c];
        }
    }
    

    
    return ary;
}

int sum(const int * const *ary, int row, int col)
{
    int sum = 0;
    
    for(int r = 0; r < row; r++)
    {
        for(int c = 0; c < col; c++)
        {
            sum += ary[r][c];
        }
    }
    
    return sum;
}

void prntData(const int * const *ary, int row, int col)
{
    for(int r = 0; r < row; r++)
    {
        for(int c = 0; c < (col - 1); c++)
        {
            cout << ary[r][c] << " ";//2 digit numbers
        }
        
        cout << ary[r][(col - 1)];
        cout << endl;
    }
    
    
}

void destroy(int **ary, int row, int col)
{
    for (int i = 0; i < row; i++) 
    {
        delete [] ary[i];
    }
    
    delete [] ary;
    ary = 0;
}