#include<stdio.h>
#include<math.h>
int main(){
	double x1,f_x1,x1_old,xl,xr,f_xl,f_xr,agree = 0.000001;
	double x,n,i,error;
	scanf("%lf %lf",&x,&n);
	scanf("%lf %lf",&xl,&xr);
	if(2>n||n>x||2>x||x>2000000){
			printf("Error\n");
			return 0;38
		}
	else{
		do{
			f_xl = pow(xl,n)-x;
			f_xr = pow(xr,n)-x;
			x1 = ((xl*f_xr)-(xr*f_xl))/(f_xr-f_xl);
			f_x1 = pow(x1,n)-x;
			if(f_x1*f_xl<0){
				xr=x1;
			}
			else{
				xl=x1;
			}
			error = fabs((x1-x1_old)/x1);
			x1_old=x1;
		}while(error>agree);
		printf("X = %.4f\n",x1);
		return 0;
	}
}
