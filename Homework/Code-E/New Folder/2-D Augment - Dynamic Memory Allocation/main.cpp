#include <iostream>

using namespace std;


int **getData(int &, int &);
void prntData(const int * const *, int, int);
int **augment(const int * const*, int, int);
void destroy(int **, int, int);


int main(){
    
    int row, col;
    int **ary;
    int **newAry;

    ary = getData(row, col);
    
    newAry = augment(ary, row, col);
    
    prntData(ary, row, col);
    
    cout << endl;
    
    prntData(newAry, (row + 1), (col + 1));
    
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

int **augment(const int * const *ary, int row, int col)
{
    
    int** newAry = new int*[row + 1];

    for(int r = 0; r < row + 1; r++) 
    {
        *(newAry + r) = new int [col + 1];
    }
    
    for(int i = 0; i < row + 1; i++)
    {
        for(int j = 0; j < col + 1; j++)
        newAry[i][j] = 0;
    }
   
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {

            newAry[i + 1][j + 1] = ary[i][j];
        }
    }
    
    return newAry;
}

void prntData(const int * const *ary, int row, int col)
{
    for(int r = 0; r < row; r++)
    {
        for(int c = 0; c < (col - 1); c++)
        {
            cout << ary[r][c] << " ";
        }
        
        cout << ary[r][(col - 1)];
        
        if(r < row - 1)
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