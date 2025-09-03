#include<stdio.h>
#include<math.h>
int main(){
	double xl=1.5,xr=2.0,xm,xm_old;
	double f_xl,f_xm;
	double agree = 0.000001;
	while(1){
		xm = (xl+xr)/2;
		f_xm = pow(xm,4)-13;
		f_xl = pow(xl,4)-13;
		if(f_xm*f_xl>0){
			xl=xm;
		}
		else{
			xr=xm;
		}
		if(fabs((xm-xm_old)/xm)<agree){
			//printf("%.6f\n",)
			break;
		}
		xm_old = xm;
		//printf("%.6f ",xm);
	}
	printf("%.6f ",xm);

	
	return 0;
}
