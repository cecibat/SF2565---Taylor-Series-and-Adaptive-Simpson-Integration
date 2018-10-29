//Task 2
// Cecilia Battinelli and Sakina Huseynzade 2018
#include <iostream>
#include<iomanip>
#include<cmath>

using namespace std;

// Functions declaration
double f(double x);
double midpoint(double a, double b);
double I(double a, double b, double f(double x));
double IT(double a, double b);
double ASI(double a, double b, double tol);


int main(int argc, char *argv[])
{
    double a, b, matlab;
    a = -1;
    b = 1;
    matlab = 2.500809110336167;
    double tol [3] = {1e-2, 1e-3, 1e-4};

    cout << fixed << setprecision(15);

    for (int i = 0; i < 3; i ++){
        double tolerance;
        tolerance  = tol[i];
        cout << "Current tolerance is: " << tol[i] << "       " << endl;
        cout << "Integral value with ASI is: " << ASI(a,b,tolerance) << endl;
        cout << "MATLAB integral value is: 2.500809110336167" << endl;
        cout << "Error of ASI result compared to MATLAB: " << abs(matlab - ASI(a,b,tolerance)) << endl;
        cout << endl;
    }

    return 0;
}


// Functions definition

double ASI(double a, double b, double tol){
    double I1, I2;
    I1 = I(a,b,f);
    I2 = IT(a,b);

    double errset;
    errset = abs(I1 - I2);
    if (errset < 15*tol) {return I2;}
    else {return ASI(a, midpoint(a,b), tol/2) + ASI(midpoint(a,b), b, tol/2);};

}


double I(double a, double b, double f(double x)){
    double value;
    value = (b-a)/6*(f(a) + 4*f(midpoint(a,b)) + f(b));
    return value;
}

double IT(double a, double b){
    double value2;
    double gamma;
    gamma = midpoint(a,b);
    value2 = I(a,gamma,f) + I(gamma,b,f);
    return value2;
}

double f(double x){ return (1+sin(exp(3*x)));}

double midpoint (double a, double b){
    double gamma;
    gamma = (a+b)*0.5;
    return gamma;
}
