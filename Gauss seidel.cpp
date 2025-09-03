#include<stdio.h>
#include<math.h>
int main(){
	double xk0[4] = {0,0,0,0};
	double xk1[4],xold[4];
	double agree=0.00001,iter=0,er[4];
	do{
		for(int k=0;k<4;k++){
			xold[k] = xk0[k];
		}
		xk1[0] = (12-2*xk0[1])/5;
		xk0[0] = xk1[0];
		xk1[1] = (17-2*xk0[0]-2*xk0[2])/5;
		xk0[1] = xk1[1];
		xk1[2] = (14-2*xk0[1]-2*xk0[3])/5;
		xk0[2] = xk1[2];
		xk1[3] = (7-2*xk0[2])/5;
		xk0[3] = xk1[3];
		for(int k=0;k<4;k++){
			er[k] = fabs((xk1[k]-xold[k])/xk1[k]);
		}
		iter++;
	}while(er[0]>agree||er[1]>agree||er[2]>agree||er[3]>agree);
	printf("%lf\n",iter);
	printf("x1=%lf x2=%lf x3=%lf x4=%lf",xk1[0],xk1[1],xk1[2],xk1[3]);
	return 0;
}
