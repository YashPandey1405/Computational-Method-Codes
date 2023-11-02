//Code To Implement Golden Section Search Method Using C++.....
#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

//Function To Calculate Function Values For (x^2 - 6x + 2)...... 
double f(double x) {
    double a= (x*x)-(6*x)+2;   //write the equation (x^2 - 6x + 2) whose Min. Value are to be determined....
    return a;
}

int main(){
    float a,b,e,MinValue;
    float r=0.61803,x1=(-1),x2=(-1),f_x1,f_x2;

    // Statements To Input The Range And Allowed Tolerance From The User......
    cout<<"ENTER THE START VALUE FOR MIN. VALUE SEARCH ::: ";
    cin>>a;
    cout<<"ENTER THE END VALUE FOR MIN. VALUE SEARCH ::: ";
    cin>>b;
    cout<<"ENTER THE ALLOWED TOLERANCE FOR MIN. VALUE SEARCH ::: ";
    cin>>e;

    int n=1;
    cout<<"n         a           b        x1        x2          f(x1)        f(x2)    MinValue  "<<endl;

    while((b-a)>e){
        if(x1==(-1.0) && x2==(-1.0)){
            x1 = a + r*(b-a);
            x2 = b - r*(b-a);
            f_x1=f(x1) , f_x2=f(x2);
            if(f_x1<f_x2){  MinValue=f_x1;  }
            else {  MinValue=f_x2;  }
        }
        else if(MinValue==f_x1){
            a=x2;
            x2=x1;
            x1 = a + r*(b-a);
            f_x1=f(x1) , f_x2=f(x2);
            if(f_x1<f_x2){  MinValue=f_x1;  }
            else {  MinValue=f_x2;  }
        }
        else {
            b=x1;
            x1=x2;
            x2 = b - r*(b-a);
            f_x1=f(x1) , f_x2=f(x2);
            if(f_x1<f_x2){  MinValue=f_x1;  }
            else {  MinValue=f_x2;  }
        }
        cout<<n<<"  "<<setw(8)<<a<<"    "<<setw(8)<<b<<"    "<<setw(8)<<x1<<"   "<<setw(8)<<x2<<"     ";
        cout<<setw(8)<<f_x1<<"   "<<setw(8)<<f_x2<<"     "<<setw(8)<<MinValue<<endl;
        n++;
    }
    cout<<endl;
    float Min = (a+b)/2;
    cout<<"STOP ITERATION AS ::: (b-a) i.e ("<<b<<"-"<<a<<") --> "<<(b-a)<<" < "<<e<<"(Allowed Tolerance)"<<endl;
    cout<<"THE MINIMUM VALUE IN GIVEN RANGE IS ::: "<<Min<<endl;
    cout<<"THE VALUE OF f("<<Min<<") IS ::: "<<f(Min)<<endl;
    return 0;
}