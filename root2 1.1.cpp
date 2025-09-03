#include<stdio.h>
#include<math.h>
int main(){
	double x0=1,x1,sqrt7; 
	double error,agree=0.000001;
	int iteration=0,i=0;
	printf("Initial X0 = %lf\n",x0);
	do{
		sqrt7 = sqrt(7);
		x1 = 0.5*(x0+(7/x0));
		iteration++;
		i++;
		printf("Iteration %d : X%d = %lf\n",iteration,i,x1);
		
		error=fabs((x1-sqrt7)/x1);
		printf("Error = %.6lf\n",error);
		x0=x1; 
	}while(error>agree);
	printf("Sqrt 7 = %.6lf\n",x1);
	return 0;
}
