#include<stdio.h>
#include<math.h>
int main(){
	double x0=2.0,x1=3,fx_x0,fx_x1,x2;
	double error,agree=0.000001;
	int iteration=0,i=0;
	printf("Initial: I=%d X0=%lf X1=%lf\n",i,x0,x1);
	do{
		fx_x0=pow(x0,2)-7;
		fx_x1=pow(x1,2)-7;
		x2=x1-(fx_x1*(x1-x0))/(fx_x1-fx_x0);
		iteration++;
		i++;
		printf("Iteration %d : X%d = %lf\n",iteration,i+1,x2);
		error=fabs((x2-x1)/x2);
		printf("Error = %.6lf\n",error);
		x0=x1;
		x1=x2;
		
	}
	while(error>agree);
	printf("Result of sqrt7 = %.6lf\n",x2);
	return 0;
}
