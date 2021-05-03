#include <random>

using namespace std;

int main()
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
    
   
}