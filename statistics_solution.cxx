#include <random>
#include <iostream>
#include <cmath>

using namespace std;

int main(int, char**)
{
    
    random_device rd; 
    mt19937 gen(rd()); 

    double mu = 0;
    double sigma = 1;
    normal_distribution<double> d(mu, sigma); 

    int i;

    const int Nsample = 100;
    double sample[Nsample];

    for(i = 0; i < Nsample; ++i)
        sample[i] = d(gen); 
    
    // From here on, we forget, that we know the distribution paramters mu and sigma

    double m = 0;
    double s = 0;
    
    for(int i = 0; i < Nsample; i++)
        m += sample[i];
    m /= Nsample;    

    for(int i=0; i<Nsample; i++)
        s += (sample[i] - m) * (sample[i] - m);
    s /= (Nsample-1);
    s = sqrt(s);


    // optimal bin size a la D.W.Scott (https://doi.org/10.1093/biomet/66.3.605)
    double dx = 3.49 * s / pow(Nsample, 1.0/3.0);

    const double xmin = -10;
    const double xmax =  10;

    // Since L= xmax - xmin is not a perfect multiple of dx,
    // we determine the number of bins such, that we are close to
    // the suggested bin width, but still have L = Nbins*dx;
    const int Nbins = int((xmax-xmin)/dx + 0.5);
    dx = (xmax - xmin)/Nbins;
    int h[Nbins];

    for(int i=0; i<Nbins; i++) h[i] = 0;

    for(int i=0; i<Nsample; i++){
        int j = int( (sample[i] - xmin) / dx );
        h[j]++;
    }

    for(int i=0; i<Nbins; i++){
        cout << i*dx + xmin << "\t" << h[i]  << endl;
    }

    cout << "# m = " << m << ", s = " << s << endl;
    cout << "# Nbins = " << Nbins << endl;

    return 0;
}