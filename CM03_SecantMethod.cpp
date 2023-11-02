//Secant Method(Chord Method) for finding the roots of an equation...
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

double f(double x);    //declare the function for the given equation......

double f(double x) {    //define the function here, ie give the equation......
    double a=pow(x,3)-(5*x)+1.0;    //write the equation whose roots are to be determined......
    return a;
}

int main() {
    cout.precision(4);
    cout.setf(ios::fixed);        //set the precision of the output......
    
    int itr=1;
    double a,b,c,fa,fb,e;
    cout<<"ENTER THE INITIAL No OF GUESSES ::: ";
    cin>>b;        //take an intial guess.....
    cout<<"ENTER THE INITIAL No OF GUESSES ::: ";                
    cin>>c;        //take an intial guess.....
    cout<<"ENTER THE DEGREE OF ACCURACY ::: ";
    cin>>e;              //take the desired accuracy.........
    
    do{    
        a=b; b=c;                //make b equal to the last calculated value of c....
        fa=f(a) ; fb=f(b);
        c =( (a*fb) - (b*fa) ) / (fb - fa);    //calculate c......
        // c=b-(b-a) / ( (f(b)-f(a)) * f(b) );    //calculate c......
        cout<<"IN ITERATION-"<<itr<<" , THE VALUE OF c = "<<c<<" & f(c) = "<<f(c)<<endl;
        itr++;

        if (f(c)==0){
            cout<<endl;
            cout<<"THE ROOT OF THE EQUATION '(x^3) - (5x) + 1' IS ::: "<<c<<"   &   f("<<c<<") = "<<f(c)<<endl;    //print the root......
            return 0;
        }

    }while(fabs(c-b)>=e);            //check if the error is greater than the desired accuracy......

    cout<<endl;
    cout<<"THE ROOT OF THE EQUATION '(x^3) - (5x) + 1' IS ::: "<<c<<"   &   f("<<c<<") = "<<f(c)<<endl;    //print the root......
    return 0;
}

// Theory --> https://youtu.be/Eud16189QRA?si=20JX79hFT3wfll1A
// Code --> https://youtu.be/TRFtrYdugdY?si=iRg5Rm8lwvKaGK4m