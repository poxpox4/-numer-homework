#include<stdio.h>
int main(){
	double i,r,y;
	for(i=0;i<=10;i++){
		r = 43*i-180;
		if(r>0){
			y = i-1;
			break;
		}
		else{
			y = i;
		
		}
	}
	for(i=y;i<=y+1;i=i+0.0000001){
		r = 43*i-180;
		if(-0.000001<r&&r<0.000001){
			printf("%f\n",i);
			break;
		}
	}
	
	return 0;
}
