//Code To Implement Runge Kutta Method Of 4th Order Using C++.....
#include<iostream>
#include<iomanip>
using namespace std;

double dydx(double x, double y){	return((x - y)/2);	}  // "dy/dx = (x - y)/2"........

double RungeKutta(double x0, double y0, double x, double h){
	int n = (int)((x - x0) / h);
	double k1, k2, k3, k4, k5;
	double y = y0;

	for (int i=1; i<=n; i++){
		k1 = h*dydx(x0, y);
		k2 = h*dydx(x0 + 0.5*h, y + 0.5*k1);
		k3 = h*dydx(x0 + 0.5*h, y + 0.5*k2);
		k4 = h*dydx(x0 + h, y + k3);
		y = y + (1.0/6.0)*(k1 + (2*k2) + (2*k3) + k4);
		x0 = x0 + h;
		cout<<i<<"\t"<<setw(8)<<x0<<"\t"<<setw(8)<<k1<<"\t"<<setw(8)<<k2<<"\t"<<setw(8)<<k3<<"\t"<<setw(8)<<k4<<"\t"<<setw(8)<<y<<endl;
	}
	return y;
}

int main(){
	cout<<endl;
	double x0 = 0, y = 1, x = 2, h = 0.2;
	cout<<"Itr\t"<<setw(8)<<"x\t\t"<<setw(8)<<"k1\t\t"<<setw(8)<<"k2\t\t"<<setw(8)<<"k3\t\t"<<setw(8)<<"k4\t    "<<setw(8)<<"y"<<endl;
	double ans=RungeKutta(x0, y, x, h);
	cout<<endl;
	cout << "The value of y at x = "<<x<<" IS ::: "<< ans<<endl;
	cout<<endl;
	return 0;
}
