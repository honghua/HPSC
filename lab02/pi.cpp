#include <iostream>
#include <stdlib.h>
#include <sys/time.h>

using namespace std;
 
void get_walltime(double* wcTime);

int main()
{
	const double CPU = 2800.0;
	// time stamp
	double S, E, WT;
	double MFLOPS, latency;

	// start timing
	get_walltime(&S);

	// integrate to get the value Pi
	const int SLICES = 1e9;
	double x = 0;
	double sum = 0;
	double delta_x = 1.0/SLICES;

	for ( int i = 0; i < SLICES; i++)
	{
		sum += 4/(1 + x*x);
		x = x + delta_x; 
	}
	double pi = sum*delta_x;

	// end timing
	get_walltime(&E);
	WT = E - S;

	// calculate MFLOPS
	MFLOPS = SLICES/(WT*1e6);
	latency = CPU/MFLOPS;

	// print result
	cout << "pi      = " << pi << endl;
	cout << "time    = " << WT << endl;
	cout << "MFLOPS  = "  << MFLOPS << endl;
	cout << "latency = "  << latency << endl;
}


void get_walltime_(double* wcTime) {
  struct timeval tp;
  gettimeofday(&tp, NULL);
  *wcTime = (double)(tp.tv_sec + tp.tv_usec/1000000.0);
}

void get_walltime(double* wcTime) {
  get_walltime_(wcTime);
}
