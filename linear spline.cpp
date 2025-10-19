#include<stdio.h>
double mlinear(double x1,double y1,double x2,double y2){
	return (y2-y1)/(x2-x1);
}
double linear(double x1,double y1,double m,double x){
	return y1+m*(x-x1);
}
int main(){
	double x[] = {2,4,6,8,10},y[] = {9.5,8.0,10.5,39.5,72.5};
	double X = 4.5;
	if(x[0]<=X&&X<=x[1]){
		double fx = linear(x[0],y[0],mlinear(x[0],y[0],x[1],y[1]),X);
		printf("%.6lf\n",fx);
	}
	else if(x[1]<=X&&X<=x[2]){
		double fx = linear(x[1],y[1],mlinear(x[1],y[1],x[2],y[2]),X);
		printf("%.6lf\n",fx);
	}
	else if(x[2]<=X&&X<=x[3]){
		double fx = linear(x[2],y[2],mlinear(x[2],y[2],x[3],y[3]),X);
		printf("%.6lf\n",fx);
	}
	else if(x[3]<=X&&X<=x[4]){
		double fx = linear(x[3],y[3],mlinear(x[3],y[3],x[4],y[4]),X);
		printf("%.6lf\n",fx);
	}
	return 0;
}
