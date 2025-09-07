#include <stdio.h>
#define N 3
double cal(int i, double x[], double y[], int n, double X, int j){
	if (j == 0) {
        return y[i];   
    }
    return (cal(i+1,x,y,n,X,j-1) - cal(i,x,y,n,X,j-1)) / (x[i+j] - x[i]);
}
double recurInter(double x[], double y[], int n, double X, int i){
	if(i == n){
		return 0.0;
	}
	double temp = 1.0;
	for(int k = 0 ; k < i ; k++){
		temp *= (X-x[k]);
	}
	return cal(0, x , y , n, X, i) * temp + recurInter(x,y,n,X,i+1);
}
int main(){
	double x[N] = {0,40000,80000};
    double y[N] = {9.81,9.6879,9.5682};
    double X = 42235;
    double result = recurInter(x,y,N,X,0);
    printf("%f",result);
}
