// C++ program for Implementation of Lagrange's Interpolation......
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

// Class To represent a data point corresponding to 'x' and y = f(x)......
class Data{
    public:
	    int x, y;
};

// Function to Interpolate the given data points using Lagrange's formula
// 'xi' which corresponds to the new data point whose value is to be obtained
// 'n' represents the number of known data points........

double Interpolate(Data f[], int xi, int n){ 
	double result = 0; // Initialize result.....
	for (int i = 0 ; i < n ; i++) {
		double term = f[i].y;  // To Compute individual terms of above formula.....
		for (int j = 0 ; j < n ; j++){
			if (j != i){
				term = term * (xi - f[j].x) / double(f[i].x - f[j].x);   //Type Casting....
            }
		}
		result += term;  // Add current term to result
	}
	return result;
}

void Display(Data*);  //Function Defination Of Function Display().......

int main(){
	cout<<endl;
	Data f[] = {{1,2}, {2,4}, {3,8}, {4,16}, {7,128}};  //Array Of Objects.....
	Display(f);
	// Using the Interpolate function to obtain a data point corresponding to x=5.....
	cout << "Value of f(5) is : " << Interpolate(f, 5, 5);
	cout<<endl;
	cout<<endl;
	return 0;
}

void Display(Data arr[]){
	cout<<"THE VALUE OF 'X' ARE   ::: ";
	for(int i=0;i<5;i++){
		cout<<arr[i].x<<" ";
	}
	cout<<endl;
	cout<<"THE VALUE OF 'f(x)' IS ::: ";
	for(int i=0;i<5;i++){
		cout<<arr[i].y<<" ";
	}
	cout<<endl;
}

// Theory --> https://youtu.be/2h0R0Uka1HI?si=CzwXPHCtjrV8n97z
