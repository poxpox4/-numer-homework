#include<stdio.h>
#include<math.h>
double f(double x){
	return exp(x);
}
double fprime1(double x){
	return exp(x);
}
double forward(double x,double h){
	double forwardcal = (f(x+1*h)-f(x))/h;
	return forwardcal;
}
int main(){
	double x = 2,h = 0.25;
	double I_real = fprime1(x);
	double I_cal = forward(x,h);
	double error = ((I_real-I_cal)/I_real)*100;
	printf("%.6lf\n",I_cal);
	printf("%.6lf\n",error);
	return 0;
}
