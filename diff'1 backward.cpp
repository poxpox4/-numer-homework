#include<stdio.h>
#include<math.h>
double f(double x){
	return exp(x);
}
double fprime1(double x){
	return exp(x);
}
double backward(double x,double h){
	double backwardcal = (f(x-0*h)-f(x-1*h))/h;
	return backwardcal;
}
int main(){
	double x = 2,h = 0.25;
	double I_real = fprime1(x);
	double I_cal = backward(x,h);
	double error = ((I_real-I_cal)/I_real)*100;
	printf("%.6lf\n",I_cal);
	printf("%.6lf\n",error);
	return 0;
}
