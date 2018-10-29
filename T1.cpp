// Task 1
// Cecilia Battinelli & Sakina Huseynzade 2018


#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


// Functions declaration

double sinTaylor(int N,double x);
double cosTaylor(int N,double x);



int main()
{
    int Ng [5] = {1,5,10,20};  // Number of terms
    double xg [6] = {-1,1,2,3,5,10}; // Values of x


    for (int n=0; n < 4; n++) {
        int N;
        N = Ng[n];
        for (int y=0; y < 6; y++){
            double x;
            x = xg[y];
            double realcos = cos(x);
            double realsin = sin(x);
            cout << "The current N value is: " << N << endl;
            cout << "The current x value is: " << x << endl;
            cout << "The approximated sine value is: " << sinTaylor(N,x) << endl;
            cout << "The mathematical sine real value is: " << realsin << endl;
            cout << "The approximated cosine value is: " << cosTaylor(N,x) << endl;
            cout << "The mathematical cosine real value is: " << realcos << endl;
            double sinbound = abs(sinTaylor(N+1,x) - sinTaylor(N,x));
            double cosbound = abs(cosTaylor(N+1,x) - cosTaylor(N,x));

            cout << "The error for the sine is: " << abs(realsin - sinTaylor(N,x)) << endl;
            cout << "The abs of N+1 term for the sine is: " << sinbound << endl;
            cout << "The error for the cosine is: " << abs(realcos - cosTaylor(N,x)) << endl;
            cout << "The abs of N+1 term for the cosine is: " << cosbound << endl;


            if (abs(realsin - sinTaylor(N,x)) < abs(sinbound)) {
                cout << "The error for the sine is bounded " << endl;
            };
            if (abs(realcos - cosTaylor(N,x)) < abs(cosbound)) {
                cout << "The error for the cosine is bounded " << endl;
            };

            cout << "                             " << endl;

        }
    }


    return 0;

}

// Functions definition using Horner's scheme for polynomial evaluation

double sinTaylor(int N,double x){

int i;
double summ = 1;

for (i = N ; i > 0; i--) {

    summ = 1 - x*x*summ/(double)(2*i*(2*i+1));

    }

    summ = x*summ;
return summ;
}


double cosTaylor(int N,double x){

int i;
double summ = 1;


for (i = N ; i > 0; i--) {

        summ = 1 - x*x*summ/(double)((2*i)*(2*i - 1));
    }
return summ;
}


