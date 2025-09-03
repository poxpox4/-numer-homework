#include<stdio.h>
#include<math.h>
int main(){
	double x1,f_x1,x1_old,xl = 1.5,xr=2.0,f_xl,f_xr,agree = 0.000001;
	double n,i,error;
	do{
		f_xl = pow(xl,4)-13;
		f_xr = pow(xr,4)-13;
		x1 = ((xl*f_xr)-(xr*f_xl))/(f_xr-f_xl);
		f_x1 = pow(x1,4)-13;
		if(f_x1*f_xl<0){
			xr=x1;
		}
		else{
			xl=x1;
		}
		error = fabs((x1-x1_old)/x1);
//		if(fabs((x1-x1_old)/x1)<agree){
//			break;
//		}

		x1_old=x1;
	}while(error>agree);
	printf("X = %.6f\n",x1);
	return 0;
}
