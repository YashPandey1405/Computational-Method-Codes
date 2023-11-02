//Code To Implement Simpson-(3/8)-Rule Using C++.....
#include<iostream>
#include <math.h>
#include <iomanip>
using namespace std;

#define f(x)  (1/(1+pow(x,2)))  // Function Expression......
#define I(x)  atan(x)           // Integrated Function......
float Y[7];

int main(){
    cout<<endl;
    float a,b,h;

    // Statements To Input The Range From The User......
    cout<<"ENTER THE START VALUE FOR INTEGRATION ::: ";
    cin>>a;
    cout<<"ENTER THE END VALUE FOR INTEGRATION ::: ";
    cin>>b;
    cout<<endl;
    h=(b-a)/6;

    float  temp=a;
    for(int i=0;i<=6;i++){
        Y[i]=f(temp);  temp += h;
    }

    // Approx Value Calculated By Simpson-(3/8)-Rule......
    float Approx_f_x=(3*h/8)*((Y[0]+Y[6]) + 3*(Y[1]+Y[2]+Y[4]+Y[5]) + 2*(Y[3]));

    // Actual Value Calculated By Integration......
    float Actual_f_x=I(b)-I(a);

    cout<<"APPROX VALUE OF INTEGRATION IS ::: "<<setw(8)<<Approx_f_x<<endl;
    cout<<"ACTUAL VALUE OF INTEGRATION IS ::: "<<setw(8)<<Actual_f_x<<endl;
    
    float Error= (Actual_f_x>Approx_f_x) ? (Actual_f_x-Approx_f_x) : (Approx_f_x-Actual_f_x);
    cout<<"THE ERROR IN THE APPROX VALUE IS ::: |Actual-Approx| i.e "<<Error<<endl;

    return 0;
}