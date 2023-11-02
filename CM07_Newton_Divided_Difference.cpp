#include<iostream>
using namespace std;

int main(){
	cout<<endl;
	cout<<endl;
	 float x[100], y[100], xp, yp=0, p;
	 int i,j,n;

	// Input Section For Input Of Variables.....
    cout<<"ENTER THE NUMBER OF DATA ::: ";
	cin>>n;
	cout<<"ENTER THE VALUES OF DATA FOR CALCULATION"<< endl;
	for(i = 1 ; i <= n ; i++) {
	  cout<<"x["<<i<<"] = ";
	  cin>>x[i];
	  cout<<"y["<<i<<"] = ";
	  cin>>y[i];
	}
	cout<<"ENTER THE INTERPOLATING POINTS ::: ";
	cin>>xp;
	/* Implementing Lagrange Interpolation */
	for(i = 1 ; i <= n ; i++) {
	    p=1;
	    for(j=1;j<=n;j++) {
		   if(i!=j){
		    	p = p* (xp - x[j])/(x[i] - x[j]);
		   }
	  }
	  yp = yp + p * y[i];
	}
	cout<<endl;
    cout<<"INTERPOLATED VALUE AT "<<xp<<" IS ::: "<<yp<<endl;
	return 0;
}

