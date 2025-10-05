#include<stdio.h>
#include<math.h>
double f(double x){
	return exp(x);
}
double fprime1(double x){
	return exp(x);
}
double backward(double x,double h){
	double xi[2]={0};
	for(int i=0;i<2;i++){
		if(i==0){
			xi[i] = x;
		}
		else{
			xi[i] = x-h;
		}
	}
	double fxi[2]={0};
	for(int i=0;i<2;i++){
		fxi[i] = f(xi[i]);
	}
	double backwardcal = (fxi[0]-fxi[1])/h;
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
