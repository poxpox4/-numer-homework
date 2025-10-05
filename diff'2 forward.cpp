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
double forward(double x,double h){
	double xi[4]={0};
	for(int i=0;i<4;i++){
		if(i==0){
			xi[i] = x;
		}
		else{
			xi[i] = x+i*h;
		}
	}
	double fxi[4]={0};
	for(int i=0;i<4;i++){
		fxi[i] = f(xi[i]);
	}
	double forwardcal = (-fxi[3]+4*fxi[2]-5*fxi[1]+2*fxi[0])/pow(h,2);
	return forwardcal;
}
int main(){
	double x = -2.5,h = 0.1;
	double I_real = fprime2(x);
	double I_cal = forward(x,h);
	double error = ((I_real-I_cal)/I_real)*100;
	printf("%.6lf\n",I_cal);
	printf("%.6lf\n",error);
	return 0;
}
