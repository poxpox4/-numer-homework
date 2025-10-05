#include<stdio.h>
#include<math.h>
double f(double x){
	return pow(x,7)+2*pow(x,3)-1;
}
double simpson(double a,double b,double n){
	if(n<1){
		n=1;
	}
	double h = (b-a)/(2*n);
	double sum1=0;
	double sum2=0;
	for(int i=1;i<2*n;i++){
		if(i%2==0){
			sum1 += f(a+i*h);
		}
		else{
			sum2 += f(a+i*h);
		}
	}
	double I = (h/3)*(f(a)+f(b)+4*sum2+2*sum1);
	return I;
}
int main(){
	double I_real = 36.375;
	double a=-1,b=2;
	double error,n=1;
	double I_cal = simpson(a,b,n);
	error = ((I_real-I_cal)/I_real)*100;
	printf("%.6lf\n",I_cal);
	printf("%.6lf\n",error);
	return 0;
}
