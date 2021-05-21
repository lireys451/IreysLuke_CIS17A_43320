
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cstring>
using namespace std;



int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();

int main() {

    int inN;
        do{
         inN=getN();
         switch(inN){
          case 1:    problem1();break;
          case 2:    problem2();break;
          case 3:    problem3();break;
          case 4:    problem4();break;
          case 5:    problem5();break;
          case 6:    problem6();break;
          case 7:    problem7();break;
          default:   def(inN);}
        }while(inN<8);
        
    return 0;
}

int getN()
{
    int inN;
    cout << "Input Problem Number: ";
    cin >> inN;

    
    return inN;
}

void def(int inN)
{
    cout << "Incorrect Input. Try Again :";
    cin >> inN;
            
}

struct AccountBalance
{
    string name,
           adrs,
           acntNum;
    float blnc,
          *wthdrw,
          *dpst;
};

void getData(AccountBalance &, float &, float &);
void displayData(AccountBalance &, float, float);
void calculate(AccountBalance &, float, float);

void problem1()
{
        struct AccountBalance acnt;
    
    float dpstTotal = 0;
    float wthdrwTotal = 0;
    
    getData(acnt, wthdrwTotal, dpstTotal);
    displayData(acnt, wthdrwTotal, dpstTotal);
    calculate(acnt, wthdrwTotal, dpstTotal);
    
    
    delete[] acnt.wthdrw;
    delete[] acnt.dpst;
}

void getData(AccountBalance &acnt, float &wthdrwTotal, float &dpstTotal)
{
    int chks;
    int dpsts;
    acnt.wthdrw = new float[chks];
    acnt.dpst = new float[dpsts];
    
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, acnt.name);
    cout << "Enter Address: ";
    getline(cin, acnt.adrs);
    cout << "Enter 5 Digit Account Number: ";
    getline(cin, acnt.acntNum);
    while(acnt.acntNum.length() != 5)
    {
        cout << "Account number must be 5 digits. Please try again: ";
        getline(cin, acnt.acntNum);
    }
    cout << "Enter Balance at the Beginning of the Month: ";
    cin >> acnt.blnc;
    cout << "Enter Total Checks Written: ";
    cin >> chks;
    cout << "Enter Amount Withdrawn Per Check: ";
    for(int i = 0; i < chks; i++) 
    {
        cin >> *(acnt.wthdrw + i);
        wthdrwTotal += *(acnt.wthdrw + i);
    } 
    cout << "Enter Total Checks Deposited: ";
    cin >> dpsts;
    cout << "Enter Amount Deposited Per Check: ";
    for(int j = 0; j < dpsts; j++) 
    {
        cin >> *(acnt.dpst + j);
        dpstTotal += *(acnt.dpst + j);
    }
}

void displayData(AccountBalance &acnt, float wthdrwTotal, float dpstTotal)
{
    cout << endl << "Name: ";
    cout << acnt.name << endl;
    cout << "Address: ";
    cout << acnt.adrs << endl;
    cout << "Account Number: ";
    cout << acnt.acntNum << endl;
    cout << "Balance at the Beginning of the Month: $";
    cout << acnt.blnc << endl;
    cout << "Amount Withdrawn: $";
    cout << wthdrwTotal << endl;
    cout << "Amount Deposited: $";  
    cout << dpstTotal << endl;
}

void calculate(AccountBalance &acnt, float wthdrwTotal, float dpstTotal)
{
    float balance = acnt.blnc;
    
    float ttl = balance + dpstTotal - wthdrwTotal;
    
    if (ttl >= 0)
    {
        cout << endl << "Account Balance: $" << ttl << endl << endl;
    }
    
    else
    {
        cout << endl << "Account Balance: $" << ttl;
        ttl -= 20;
        cout << endl << "Your account is overdrawn. You will be charged an additional $20 fee."
             << endl << "New Balance: $" << ttl << endl << endl;
    }
}

struct EmployeeInfo
{
    string comp,
           adrs,
           name,
           amntEng,
           sign;
    float amntNum,
          rate,
          hrs;
};

void getData(EmployeeInfo *, int &);
void calcData(EmployeeInfo *, int);
void displayData(EmployeeInfo *, int);

void problem2()
{
    struct EmployeeInfo *info;
    
    int emplys;
    cout << "Enter Number of Employees: ";
    cin >> emplys;
    cout << endl;
    
    info = new EmployeeInfo[emplys];
    
    getData(info, emplys);
    calcData(info, emplys);
    displayData(info, emplys);
    
    cout << endl;
    
    delete []info;
}

void getData(EmployeeInfo *info, int &emplys)
{
    
    
    
    for(int i = 0; i < emplys; i++)
    {
        cout << "Enter Company Name: ";
        cin.ignore();
        getline(cin, info[i].comp);
        cout << "Enter Address: ";
        getline(cin, info[i].adrs);
        cout << "Enter Recipient: ";
        getline(cin, info[i].name);
        cout << "Enter Digital Signature: ";
        getline(cin,info[i].sign);
        cout << "Enter Pay Rate Per Hour: ";
        cin >> info[i].rate;
        cout << "Enter Hours Worked: ";
        cin >> info[i].hrs;
        cout << endl;
    }
}

void calcData(EmployeeInfo *info, int emplys)
{
    for(int i = 0; i < emplys; i++){
        
    float ttl;
    float nrmlPay = 40 * info[i].rate;
    float dblPay = (10 * info[i].rate) * 2;
    
    if (info[i].hrs <= 40)
    ttl = info[i].rate * info[i].hrs;
    
    else if(info[i].hrs > 40 && info[i].hrs <=50)
    ttl = nrmlPay + ((info[i].hrs - 40) * info[i].rate) * 2;
    
    else
    ttl = nrmlPay + dblPay + ((info[i].hrs - 50) * info[i].rate) * 3;
     
    info[i].amntNum = ttl;
    
    unsigned char n1000s,n100s,n10s,n1s;
        int newttl = static_cast<int>(ttl);
        n1000s=newttl/1000;
        n100s=newttl%1000/100;
        n10s=newttl%100/10;
        n1s=newttl%10;

    info[i].amntEng += (n1000s==9?"Nine Thousand ":
                    n1000s==8?"Eight Thousand ":
                    n1000s==7?"Seven Thousand ":
                    n1000s==6?"Six Thousand ":
                    n1000s==5?"Five Thousand ":
                    n1000s==4?"Four Thousand ":
                    n1000s==3?"Three Thousand ":
                    n1000s==2?"Two Thousand ":
                    n1000s==1?"One Thousand ": "");
               
    info[i].amntEng += (n100s==9?"Nine Hundred ":
                    n100s==8?"Eight Hundred ":
                    n100s==7?"Seven Hundred ":
                    n100s==6?"Six Hundred ":
                    n100s==5?"Five Hundred ":
                    n100s==4?"Four Hundred ":
                    n100s==3?"Three Hundred ":
                    n100s==2?"Two Hundred ":
                    n100s==1?"One Hundred ": "");
               
    info[i].amntEng += (n10s==9?"Ninety ":
                    n10s==8?"Eighty ":
                    n10s==7?"Seventy ":
                    n10s==6?"Sixty ":
                    n10s==5?"Fifty ":
                    n10s==4?"Forty ":
                    n10s==3?"Thirty ":
                    n10s==2?"Twenty ": "");
               
    info[i].amntEng += ((n10s==1 && n1s == 9)?"Nineteen":
                    (n10s==1 && n1s == 8)?"Eighteen":
                    (n10s==1 && n1s == 7)?"Seventeen":
                    (n10s==1 && n1s == 6)?"Sixteen":
                    (n10s==1 && n1s == 5)?"Fifteen":
                    (n10s==1 && n1s == 4)?"Fourteen":
                    (n10s==1 && n1s == 3)?"Thirteen":
                    (n10s==1 && n1s == 2)?"Twelve":
                    (n10s==1 && n1s == 1)?"Eleven":
                    (n10s==1 && n1s == 0)?"Ten":
               
                    (n10s!=1 && n1s == 9)?"Nine":
                    (n10s!=1 && n1s == 8)?"Eight":
                    (n10s!=1 && n1s == 7)?"Seven":
                    (n10s!=1 && n1s == 6)?"Six":
                    (n10s!=1 && n1s == 5)?"Five":
                    (n10s!=1 && n1s == 4)?"Four":
                    (n10s!=1 && n1s == 3)?"Three":
                    (n10s!=1 && n1s == 2)?"Two":
                    (n10s!=1 && n1s == 1)?"One": "");
    
    }

}

void displayData(EmployeeInfo *info, int emplys)
{
    for (int i = 0; i < emplys; i++){
        
    cout << info[i].comp << endl;
    cout << info[i].adrs << endl;
    cout << "Name: " << info[i].name << "          "; 
    cout << "Amount: $" << fixed << setprecision(2) << info[i].amntNum << endl;
    cout << "Amount: " << info[i].amntEng << " Dollars" << endl;
    cout << "Signature Line: " << info[i].sign << endl <<endl;
    }
    
}

struct Array{
    int size; //Size of the Array
    int *data;//Values contained in the array
};

struct Stats{
    Array *mode;  //Array ADT contains number of modes and the modes themselves
    int modFreq;  //Mode Frequency
    float median; //Median of the array
    float avg;    //Average of the Array
};

Array *fillAry(int,int);        //Fill an array and put into a structure
void prntAry(const Array *,int);//Print the array 
int *copy(const int *,int);     //Copy the array
void mrkSort(int *,int);        //Sort an array
void prtStat(const Stats *);    //Print the structure
void rcvrMem(Array *);          //Recover memory from the Array Structure
void rcvrMem(Stats *);          //Recover memory from Statistics Structure

Stats *stat(const Array *);     //Find & store mean, median, & modes in structure


void problem3()
{
    //Declare variables
    int arySize;//Array Size
    int modNum; //Number to control the modes (digits 0 to 9 allowed)
    Array *array;
    
    //Input the size and mod number
    cout<<"This program develops an array to be analyzed"<<endl;
    cout<<"Array size from mod number to 100"<<endl;
    cout<<"Mod number from 2 to 10"<<endl;
    cout<<"Input the Array Size and the mod number to be used."<<endl;
    cin>>arySize>>modNum;
    cout<<endl<<endl;
    
    //Fill the array
    array=fillAry(arySize,modNum);
    
    //Print the initial array
    cout<<"Original Array before sorting"<<endl;
    prntAry(array,10);
    
    //Sort the array
    mrkSort(array->data,array->size);
    cout<<"Sorted Array to be utilize for the stat function"<<endl;
    prntAry(array,10);
    
    //Calculate some of the statistics
        Stats *stats=stat(array);
    
    //Print the statistics
    prtStat(stats);
    
    //Recover allocated memory
    rcvrMem(array);
    rcvrMem(stats);
    
}

int *copy(const int *a,int n){
    //Declare and allocate an array
    //that is a c
    int *b=new int[n];
    //Fill
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}

void prtStat(const Stats *ary){
    cout<<endl;
    cout<<"The average of the array = "<<ary->avg<<endl;
    cout<<"The median of the array  = "<<ary->median<<endl;
    cout<<"The number of modes      = "<<
            ary->mode->size<<endl;
    cout<<"The max Frequency        = "<<
            ary->modFreq<<endl;
    if(ary->mode->size==0){
        cout<<"The mode set             = {null}"<<endl;
        return;
    }
    cout<<"The mode set             = {";
    for(int i=0;i<ary->mode->size-1;i++){
        cout<<ary->mode->data[i]<<",";
    }
    cout<<ary->mode->data[ary->mode->size-1]<<"}"<<endl;
}

void mrkSort(int *array,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(array[j]<array[i]){
                int temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
}

void rcvrMem(Stats *stats){
    rcvrMem(stats->mode);
    delete stats;
}

void rcvrMem(Array *array){
    delete []array->data;
    delete array;
}

void prntAry(const Array *array,int perLine){
    //Output the array
    for(int i=0;i<array->size;i++){
        cout<<array->data[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

Array *fillAry(int n, int modNum){
    //Allocate memory
    Array *array=new Array;
    array->size=n;
    array->data=new int[array->size];

    //Fill the array with mod numbers
    for(int i=0;i<n;i++){
        array->data[i]=i%modNum;
    }
    
    //Exit function
    return array;
}

Stats *stat(const Array *array){
    
    cout<<endl<<"Stat function to be completed by the student"<<endl;
    Stats *stats=new Stats;
    stats->mode=new Array;
    stats->mode->size=0;
    
    
    
    
    //Median Calculations
    int mid = (array->size)/2;
    if (array->size % 2 == 1)
    stats->median= array->data[mid];
    float midtotal = static_cast<float>(array->data[mid] + array->data[mid - 1]);
    if (array->size % 2 == 0)
    stats->median =  midtotal / 2;
    
    //Average Calculations
    float ttl = 0;
    for (int i = 0; i < array->size; i++)
    {
        float temp = array->data[i];
        ttl +=temp;
    }
    ttl = ttl / array->size;
    stats->avg = ttl;
    
    
    //Median Calculations
    unsigned short max = 1;
    unsigned short temp = 1;
    unsigned short nmodes = 0;
    unsigned short modePos = 0;
    

    //Find the max Frequency
    for(int i = 1; i < array->size; i++)
    {
        if(*(array->data + i) != *(array->data + (i - 1)))
        {
            if(temp > max && temp >= 2)
            {
                max = temp;
            }
            temp = 1;
        }
        else temp++;
    }
    if(temp > max && temp >= 2)
    {
        max = temp;
    }
    
    stats->modFreq=max;
    
    //Find the number of modes
    temp = 1;
    for(unsigned char i = 1; i < array->size; i++)
    {
        if(*(array->data + i) != *(array->data + (i - 1)))
        {
            if(temp == max && temp >= 2)
            {
                nmodes++;
            }
            temp = 1;
        }
        else temp++;
    }
    
    if(temp == max && temp >= 2)
    {
        nmodes++;
    }
    
    stats->mode->size = nmodes;
    int nModes= nmodes;
    if(nModes!=0)
    {
        stats->mode->data=new int[nModes];
        //Fill Mode Array
    temp = 1;
    for(unsigned char i = 1; i < array->size; i++)
    {
        if(*(array->data + i) != *(array->data + (i - 1)))
        {
            if(temp == max)
            {
                *(stats->mode->data + modePos) = *(array->data + (i - 1));
                modePos++;
            }
            temp = 1;
        }
        else temp++;
    }
    
    if(temp == max)
    {
        *(stats->mode->data + modePos) = *(array->data + (array->size - 1));
    }
    }
    
    
    return stats;
}

void getData();
void encrypt(char [], const int);
void decrypt(char [], const int);

void problem4()
{
    getData();
}

void getData()
{
    const int SIZE = 4;
    char code[SIZE];
    bool path;
    
    cout << "Enter 4-Digit Code Using Only 0-7: ";
    
    cin >> code;
    
    if(strlen(code) != 4)
    {
        cout << "Invalid input. Code must be 4-Digits. Please try again: ";
        cin >> code;
               
    }
    
 
    while (code[0] > '7' || code[0] < '0' || code[1] > '7' || code[1] < '0' || code[2] > '7' || code[2] < '0' || code[3] > '7' || code[3] < '0')
    {
        cout << "Invalid input. Code must only use numbers between 0-7. Please try again: ";
        cin >> code;
    }
 
    cout << "Encrypt (0) or Decrypt (1): ";
    cin >> path; 
    if(path == false)
        encrypt(code, SIZE);
    else if(path == true)
        decrypt(code, SIZE);
            
    
}

void encrypt(char code[], const int SIZE)
{
    
    for (int i = 0; i < SIZE; i ++)
    {
        unsigned char temp1 = code[i];
        int temp2 = temp1 - '0';
        temp2 += 5;
        temp2 = temp2 % 8;
        temp1 = '0' + temp2;
        code[i] = temp1;
    }
    
    char swap1;
    swap1 = code[0];
    code[0] = code[2];
    code[2] = swap1;
    
    char swap2;
    swap2 = code[1];
    code[1] = code[3];
    code[3] = swap2;

    
    cout << "New Code: " << code << endl ;
}

void decrypt(char code[], const int SIZE)
{
    char swap1;
    swap1 = code[0];
    code[0] = code[2];
    code[2] = swap1;
    
    char swap2;
    swap2 = code[1];
    code[1] = code[3];
    code[3] = swap2;
    
    for (int i = 0; i < SIZE; i ++)
    {
        unsigned char temp1 = code[i];
        int temp2 = temp1 - '0';
        if (temp2 < 5)
        {
            temp2 += 8;
        }
        temp2 -= 5;
        temp1 = '0' + temp2;
        code[i] = temp1;
    }
    
    cout << "New Code: " << code << endl;
}

void problem5()
{
    cout << "Integer overflows when n = 13" << endl;
    cout << "Unsigned integer overflows when n = 13" << endl;
    cout << "Character overflows when n = 4" << endl;
    cout << "Unsigned Character overflows when n = 4" << endl;
    cout << "Short overflows when n = 8" << endl;
    cout << "Unsigned short overflows when n = 9" << endl;
    cout << "Float overflows when n = 35" << endl;
    cout << "Double overflows when n = 171" << endl << endl;
}
void problem6()
{
    cout << "Part A:" << endl << endl
         << "Base 10: 2.875" << endl 
         << "Base 16: 2.E" << endl
         << "Base 2: 10.111" << endl
         << "Base 8: 2.7" << endl
         << "Float Representation: 5C000002" << endl << endl;
    
    cout << "Base 10: 0.1796875" << endl
         << "Base 16: 0.2E" << endl
         << "Base 2: 0.0010111" << endl
         << "Base 8: 0.134" << endl
         << "Float Representation: 5C0000FE" <<endl
         << "-------------------------------" << endl;
    
    cout << "Part B:" << endl << endl
         << "Base 10: -2.875" << endl 
         << "Base 16: D.2" << endl
         << "Base 2: 1110.001" << endl
         << "Base 8: 16.1" << endl
         << "Float Representation: 71000004" << endl << endl;
    
    cout << "Base 10: -0.1796875" << endl
         << "Base 16: 0.E2" << endl
         << "Base 2: 0.1110001" << endl
         << "Base 8: 0.704" << endl
         << "Float Representation: 71000000" <<endl
         << "-------------------------------" << endl;
    
    cout << "Part C:" << endl << endl
         << "Float Representation: 59999901" << endl
         << "Base 2: 1.011001" << endl
         << "Base 10: 1.39063" << endl << endl;
    
    cout << "Float Representation: 59999902" << endl
         << "Base 2: 10.11001" << endl
         << "Base 10: 2.78125" << endl << endl;
    
    cout << "Float Representation: A66667FE" << endl
         << "Base 2: 0.0101001100110011001100111" << endl
         << "Base 10: 0.32500001788139343262" << endl << endl;
}

struct Prime{
    unsigned short prime;
    unsigned char power;
};

struct Primes{
    unsigned char nPrimes;
    Prime *prime;
};

Primes *factor(int);
void prntPrm(Primes *);

void problem7()
{
    int n;
  do{
    cout << "Input a number between 2 and 10,000: ";
    cin >> n;
    cout << endl;
  }while(n < 2 || n > 10000);

  Primes *primes = factor(n);
  cout << n;
  prntPrm(primes);
}

Primes *factor(int n){
  Prime *p = new Prime[5];
  int count = 0;
  unsigned char nPrimes = 0;
  unsigned char power = 0;

  while(n % 2 == 0){
    cout << "(" << n << "/" << 2 << ") " << n/2 << endl;
    n /= 2;
    power++;
    p[0] = {2, power};
  }

  if(p[0].prime == 2){
    count++;
  }

  for(unsigned short i = 3; i <= n; i = i+2){
    power = 0;
    while(n % i == 0){
      n /= i;
      power++;
    }
    if(power != 0){
      p[count] = {i, power};
      count++;
      nPrimes++;
    }
  }

  Primes *primes = new Primes{nPrimes, p};
  return primes;
}

void prntPrm(Primes *p){

  cout << " = ";
  for(int i = 0; i <= p->nPrimes; i++){
    cout << int(p->prime[i].prime) << "^" << int(p->prime[i].power);
    if(i != p->nPrimes){
      cout << " * ";
    }
  }
  cout << "\n";
}
