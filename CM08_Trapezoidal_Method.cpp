#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

#define f(x)  (1/(1+pow(x,2)))

int main(){
     cout << endl;
     float lower, upper, integration = 0.0, stepSize, k;
     int i, subInterval;

     /* Input */
     cout<< "Enter lower limit of integration -> ";
     cin >> lower;
     cout << "Enter upper limit of integration -> ";
     cin >> upper;
     cout << "Enter number of sub intervals    -> ";
     cin >> subInterval;

     /* Finding step size */
     stepSize = (upper - lower) / subInterval;
     cout << endl;
     cout<< "value of h -> " << setprecision(7) << stepSize << endl; // Set precision to 7 decimal places
     cout<< endl;

     // Print column headers
     cout << setw(6) << "x" << setw(17) << "f(x)" << endl;
     cout << fixed << setprecision(7); // Set precision to 7 decimal places

     /* Finding Integration Value */
     integration = f(lower) + f(upper);
     cout << setw(10) << lower << setw(15) << f(lower) << endl;
     for (i = 1; i <= subInterval - 1; i++) {
          k = lower + i * stepSize;
          cout << setw(10) << k << setw(15) << f(k) << endl;
          integration = integration + 2 * (f(k));
     }
     cout << setw(10) << upper << setw(15) << f(upper) << endl;
     integration = integration * stepSize / 2;
     cout<< "Required value of integration is: " << integration << endl;
     cout << endl;
     return 0;
}
