//Code To Implement Bisection Method Using C++.....
#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<cmath>
using namespace std;

// double f(double x);    //Function Prototype......

//Defined the Function To Calculate Function Values For(cos(x)-x*exp(x))........
double f(double x) {
    double a=cos(x)-x*exp(x);   //write the equation(cos(x)-x*exp(x)) whose roots are to be determined....
    return a;
}

int main() {  
    cout<<endl;
    int iter=1;  
    double a,b,c,e,fa,fb,fc;    //declare some needed variables.....
    cout<<setprecision(6)<<fixed;  //Set The Precision Of Our Output...
    e=0.00001;
    cout<<"ENTER THE START VALUE OF GUESS ::: ";
    cin>>a;
    cout<<"ENTER THE END VALUE OF GUESS ::: ";
    cin>>b;
    cout<<endl;
    fa=f(a),fb=f(b);
    if(fa*fb>0.0){
        cout<<"YOU ENTERED INCORRECT GUESSES"<<endl;
    }
    else{
        do{
            c=(a+b)/2;
            fc=f(c);
            cout<<"Iteration-"<<iter<<"\tx = "<<setw(10)<<c<<"   And   f(x) = "<<setw(10)<<fc<<endl;
            if(fa*fc<0){    b=c;    }
            else{   a=c;    }
            iter++;
        }while (fabs(fc)>e);
        cout<<endl<<"Root For The Equation '(cos(x) - x*exp(x))' IS ::: "<<c<<endl;
        cout<<endl;
        cout<<endl;
    }
    return 0;    
}

//For Theory --> https://youtu.be/3j0c_FhOt5U?si=UzIIOqoyqbvocvJG
//For Code  ---> https://youtu.be/H1i0o04Ou3c?si=S7LuXOLW8-N2n6Vs   