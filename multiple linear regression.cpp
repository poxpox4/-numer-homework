#include<stdio.h>
#define N 7
#define A 4
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
	double x[N][4] = {{1,0,1,4},
					{0,1,3,-5},
					{2,4,1,-6},
					{3,2,2,0},
					{4,1,5,-1},
					{2,3,3,-7},
					{1,6,4,-20}};
	 double X[N][A];
    double Y[N];

    for (int i=0; i<N; i++) {
		X[i][0] = 1;              
        X[i][1] = x[i][0];   
        X[i][2] = x[i][1];   
        X[i][3] = x[i][2];  
        Y[i] = x[i][3];            
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
//			else if(i==0&&j==A){
//				arr[i][j] = sumy;
//			}
			else if(i==0&&j>0){
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
	printf("f(X) = %.2lf + %.2lfX1 + %.2lfX2 + %.2lfX3\n",resultofa[0],resultofa[1],resultofa[2],resultofa[3],resultofa[4]);
	
	return 0;
}
