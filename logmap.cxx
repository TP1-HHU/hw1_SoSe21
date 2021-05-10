#include <iostream>
#include <fstream>

using namespace std;

int main(){
	double x0 = 0.5;
	double x;
	int Nskip = 100; //Number of iterations to skip
	int Nend  = 200; //Number of total iterations

	double xa[Nend-Nskip];

	ofstream out("data.txt");
	for(double r=0; r <= 4; r += 0.001){
	   x=x0;
	   for(int i=1; i <= Nskip; i++)
		   x *= r*(1-x);
	   

	   xa[0] = x;
	   for(int i=1; i < Nend-Nskip; i++)
	   		   xa[i] = xa[i-1]*r*(1-xa[i-1]);
  	   
	   for(int i=0; i < Nend-Nskip; i++)
		    out << r << "\t" << xa[i] << endl;
	}

	out.close();


	return 0;
}