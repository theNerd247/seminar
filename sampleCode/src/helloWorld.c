#include <stdio.h>

void printResults(double rmax, double dmax)
{
	printf("rmax: %lf \n",rmax);
	printf("dmax: %lf \n",dmax);
}

double calculateRMax(double v0y, double g)
{
	double result;

	result = (v0y*v0y)/(2*g);

	return result;
}

void getInputs(double* theta, double* v0)
{
	printf("Give me theta: ");
	scanf("%lf",theta);

	printf("Give me v0: ");
	scanf("%lf",v0);
}

int main(int argc, char** argv)
{
	double theta;
	double v0;

	double hmax;
	double dmax;

	getInputs(&theta,&v0);
	hmax = calculateRMax(v0/2, 9.81);
	printResults(hmax,dmax);

  return 0;
}
