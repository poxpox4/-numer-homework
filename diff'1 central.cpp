#include<stdio.h>
#include<math.h>
double f(double x){
	return exp(x);
}
double fprime1(double x){
	return exp(x);
}
double central(double x,double h){
	double xip[2]={0};
	double xin[2]={0};
	for(int i=0;i<2;i++){
		if(i==0){
			xip[i] = x;
			xin[i] = x;
		}
		else{
			xip[i] = x+h;
			xin[i] = x-h;
		}
	}
	double fxip[2]={0};
	double fxin[2]={0};
	for(int i=0;i<2;i++){
		fxip[i] = f(xip[i]);
		fxin[i] = f(xin[i]);
	}
	double central = (fxip[1]-fxin[1])/(2*h);
	return central;
}
int main(){
	double x = 2,h = 0.25;
	double I_real = fprime1(x);
	double I_cal = central(x,h);
	double error = ((I_real-I_cal)/I_real)*100;
	printf("%.6lf\n",I_cal);
	printf("%.6lf\n",error);
	return 0;
}
