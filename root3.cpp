#include<stdio.h>
#include<math.h>
int main(){
	double xl=0,xr=1000000,xm,xm_old,x,n;
	double f_xl,f_xm;
	double agree = 0.000001;
	scanf("%lf %lf",&x,&n);
	if(2>n||n>2000000||n>x||2>x||x>2000000){
		printf("Error\n");
	}
	else{
		while(1){
			xm = (xl+xr)/2;
			f_xm = pow(xm,n)-x;
			f_xl = pow(xl,n)-x;
			if(f_xm*f_xl>0){
				xl=xm;
			}
			else{
				xr=xm;
			}2
			if(fabs((xm-xm_old)/xm)<agree){
				
				break;
			}
			xm_old = xm;
			//printf("%.6f ",xm);
			}
		printf("%.4f ",xm);
	}
	
	return 0;
}
