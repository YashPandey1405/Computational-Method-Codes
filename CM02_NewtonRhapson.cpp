#include <iostream>
#include <bits/stdc++.h>
using namespace std;

double func(double x){
    return x*x*x  - 4*x - 9;
}

double funcDerv(double x){
    return 3*x*x - 4;
}

void NewtonRhapson(double x1){
    double h = func(x1)/funcDerv(x1);
    int itr=1;
    while( abs(h) >= 0.0001  ){
        h = func(x1)/funcDerv(x1);
        x1 = x1 - h;
        cout<<"Iteration-"<<itr<<" , The Value Of Root Is ::: "<<x1<<endl;
        itr++;
    }
    cout << "THE VALUE OF ROOT IS ::: " << x1;
}

int main() {
    cout<<endl;
    double Xo = -20;
    NewtonRhapson(Xo);
    cout<<endl;
    return 0;
}
