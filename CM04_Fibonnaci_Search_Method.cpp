//Code To Implement Fibonnaci Search Method Using C++.....
#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

// 1-D Array To Store Fibonnaci Series......
int Fib[11]={1,1,2,3,5,8,13,21,34,55,89};

//Function To Calculate Function Values For (x^2 - 6x + 2)...... 
double f(double x) {
    double a= (x*x)-(6*x)+2;   //write the equation (x^2 - 6x + 2) whose Min. Value are to be determined....
    return a;
}

int Get_Value_n(float Key){
    for(int i=0;i<11;i++){
        if(Fib[i]>=Key){  return i;  }
    }
    return (-1);
}

int main(){
    int k ;
    float a,b,l,MinValue,Delta;
    float x1=(-1.0),x2=(-1.0),f_x1,f_x2,e;

    // Statements To Input The Range And Allowed Tolerance From The User......
    cout<<"ENTER THE START VALUE FOR MIN. VALUE SEARCH ::: ";
    cin>>a;
    cout<<"ENTER THE END VALUE FOR MIN. VALUE SEARCH ::: ";
    cin>>b;
    cout<<"ENTER THE ALLOWED TOLERANCE FOR MIN. VALUE SEARCH ::: ";
    cin>>e;
    l=(b-a);

    // Statements To Get Value Of n......
    float temp = (b-a)/(2*e);
    k=Get_Value_n(temp);
    cout<<"k         a           b        x1        x2          f(x1)        f(x2)    MinValue  "<<endl;

    while(k>2){
        Delta=Fib[k-2]/(float)Fib[k];
        if(x1==(-1.0) && x2==(-1.0)){
            x1 = a + (Delta*l);
            x2 = b - (Delta*l);
            f_x1=f(x1) , f_x2=f(x2);
            if(f_x1<f_x2){  MinValue=f_x1;  }
            else {  MinValue=f_x2;  }
        }
        else if(MinValue==f_x1){
            b=x2;
            x2=x1;
            l=(b-a);
            x1 = a + (Delta*l);
            f_x1=f(x1) , f_x2=f(x2);
            if(f_x1<f_x2){  MinValue=f_x1;  }
            else {  MinValue=f_x2;  }
        }
        else {
            a=x1;
            x1=x2;
            l=(b-a);
            x2 = b - (Delta*l);
            f_x1=f(x1) , f_x2=f(x2);
            if(f_x1<f_x2){  MinValue=f_x1;  }
            else {  MinValue=f_x2;  }
        }
        cout<<k<<"  "<<setw(8)<<a<<"    "<<setw(8)<<b<<"    "<<setw(8)<<x1<<"   "<<setw(8)<<x2<<"     ";
        cout<<setw(8)<<f_x1<<"   "<<setw(8)<<f_x2<<"     "<<setw(8)<<MinValue<<endl;
        k--;
    }

    // Statement For (k=2) Case Only......
    float dell = e - (e*0.2);
    if(MinValue==f_x1){
        b=x2; x2=x1;
        x1 = ((a+b)/2)-dell;
        f_x1=f(x1) , f_x2=f(x2);
        if(f_x1<f_x2){  MinValue=f_x1;  }
        else {  MinValue=f_x2;  }
    }
    else {
        a=x1; x1=x2;
        x2 = ((a+b)/2)+dell;
        f_x1=f(x1) , f_x2=f(x2);
        if(f_x1<f_x2){  MinValue=f_x1;  }
        else {  MinValue=f_x2;  }
    }

    cout<<k<<"  "<<setw(8)<<a<<"    "<<setw(8)<<b<<"    "<<setw(8)<<x1<<"   "<<setw(8)<<x2<<"     ";
    cout<<setw(8)<<f_x1<<"   "<<setw(8)<<f_x2<<"     "<<setw(8)<<MinValue<<endl;

    cout<<endl;
    if(MinValue=f_x1){
        float Min = (a+x2)/2;
        cout<<"THE MINIMUM VALUE IN GIVEN RANGE IS ::: "<<Min<<endl;
        cout<<"THE VALUE OF f("<<Min<<") IS ::: "<<f(Min)<<endl;
    }
    else {
        float Min = (x1+b)/2;
        cout<<"THE MINIMUM VALUE IN GIVEN RANGE IS ::: "<<Min<<endl;
        cout<<"THE VALUE OF f("<<Min<<") IS ::: "<<f(Min)<<endl;
    }
    return 0;
}