#include<stdio.h>
#include<math.h>
double f(double x){
	return exp(x/3.0)+pow(x,2);
}
double fprime1(double x){
	return (1.0/3.0)*exp(x/3)+2*x;
}
double fprime2(double x){
	return (1.0/9.0)*exp(x/3)+2;
}
double central(double x,double h){
	double xip[4]={0};
	double xin[4]={0};
	for(int i=0;i<4;i++){
		if(i==0){
			xip[i] = x;
			xin[i] = x;
		}
		else{
			xip[i] = x+i*h;
			xin[i] = x-i*h;
		}
	}
	double fxip[4]={0};
	double fxin[4]={0};
	for(int i=0;i<4;i++){
		fxip[i] = f(xip[i]);
		fxin[i] = f(xin[i]);
	}
	double centralcal = (-fxip[2]+16*fxip[1]-30*fxip[0]+16*fxin[1]-fxin[2])/(12*pow(h,2));
	return centralcal;
}
int main(){
	double x = -2.5,h = 0.1;
	double I_real = fprime2(x);
	double I_cal = central(x,h);
	double error = ((I_real-I_cal)/I_real)*100;
	printf("%.6lf\n",I_cal);
	printf("%.6lf\n",error);
	return 0;
}
