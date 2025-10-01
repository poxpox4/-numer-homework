#include<stdio.h>
#include<math.h>
#define N 9
#define A 3
void gausseliminate(double arr[A][A+1],double resultarr[A]){
	int i,j,k;
	for(i=0;i<A;i++){
		double forward = arr[i][i];
		for(j=i;j<=A;j++){
			arr[i][j] /= forward;
		}
		for(k=i+1;k<A;k++){
			double down = arr[k][i];
			for(j=i;j<=A;j++){
				arr[k][j] -= down*arr[i][j];
			}
		}
	}
	for(i=A-1;i>=0;i--){
		resultarr[i] = arr[i][A];
		for(j=i+1;j<A;j++){
			resultarr[i] -= arr[i][j]*resultarr[j];
		}	
	}
}
int main(){
	double x[N][2] = {{10,5},
					{15,9},
					{20,15},
					{30,18},
					{40,22},
					{50,30},
					{60,35},
					{70,38},
					{80,43}};
	 double X[N][A];
    double Y[N];

    for (int i=0; i<N; i++) {
		X[i][0] = 1;              
        X[i][1] = x[i][0];
		X[i][2] = x[i][0]*x[i][0]; 
        Y[i] = x[i][1];            
    }
    
	
	double sumx[A]={0};
	double sumy=0;
	double sumxx[A][A]={0},sumxy[A]={0};
	for(int i=0;i<N;i++){
		sumy += Y[i];
		for(int j=0;j<A;j++){
			sumx[j] += X[i][j];
			sumxy[j] += X[i][j]*Y[i];
			for(int k=0;k<A;k++){
				sumxx[j][k] += X[i][j]*X[i][k];
			}
		}
		
	}
	
	double arr[A][A+1] = {0}; 
	for(int i=0;i<A;i++){
		for(int j=0;j<A;j++){
			if(i==0&&j==0){
				arr[i][j] = N;
			}
			else if(i==0&&j==1){
				arr[i][j] = sumx[j];
			}
			else if(j>=i){
				arr[i][j] = sumxx[i][j];
			}
			else{
				arr[i][j] = arr[j][i];
			}
		}
		 if(i==0){
		 	arr[i][A] = sumy;
		 }
		 else{
		 	arr[i][A] = sumxy[i];
		 }
	}
	for(int i=0;i<A;i++){
		for(int j=0;j<A+1;j++){
			printf("%.2lf ",arr[i][j]);
		}
		printf("\n");
	}
	double resultofa[A];
	gausseliminate(arr,resultofa);
	double Xcal = 65;
	double fx = resultofa[0] + resultofa[1]*Xcal + resultofa[2]*pow(Xcal,2);
	printf("f(X) = %.5lf + %.5lfX1 + %.5lfX2^2\n",resultofa[0],resultofa[1],resultofa[2]);
	printf("f(%.2lf) = %.6lf\n",Xcal,fx);
	return 0;
}
