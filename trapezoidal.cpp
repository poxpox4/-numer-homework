#include<stdio.h>
#include<math.h>
double f(double x){
	return 4*pow(x,5)-3*pow(x,4)+pow(x,3)-6*x+2;
}
double compositetrap(double a,double b,double n){
	if(n<1){
		n=1;
	}
	double h = (b-a)/n;
	double sum = 0;
	for(int i=1;i<n;i++){
		sum += f(a + i*h);
	}
	double I = (h/2)*(f(a)+f(b)+2*sum);
	return I;
}
int main(){
	double I_real = 155930.4;
	double a = 2,b = 8;
	double error,n=1;
	double I_cal = compositetrap(a,b,n);
	error = ((I_real-I_cal)/I_real)*100;
	printf("%.6lf\n",I_cal);
	printf("%.6lf\n",error);
	return 0;
}
