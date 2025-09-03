#include<stdio.h>
int main(){
	int x1,x2,x3; 
	printf("Matrix A|B 3x3:\n");
	float matrixAB[3][4] = {{-2,3,1,9},
					{3,4,-5,0},
					{1,-2,1,-4}};
	float matrixB[3] = {9,0,-4};
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%.2f ",matrixAB[i][j]);
		}
		printf("| %.2f\n",matrixAB[i][3]);
	}
	float cal1,cal2,cal3; 
	cal1 = matrixAB[1][0]/matrixAB[0][0];
	for(j=0;j<4;j++){
		matrixAB[1][j] = matrixAB[1][j]-cal1*matrixAB[0][j];
	}
	cal2 = matrixAB[2][0]/matrixAB[0][0];
	for(j=0;j<4;j++){
		matrixAB[2][j] = matrixAB[2][j]-cal2*matrixAB[0][j];
	}
	cal3 = matrixAB[2][1]/matrixAB[1][1];
	for(j=0;j<4;j++){
		matrixAB[2][j] = matrixAB[2][j]-cal3*matrixAB[1][j];
	}
	
	printf("After Gauss Elimination\n");
	for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%.2f ", matrixAB[i][j]);
        }
        printf("| %.2f\n", matrixAB[i][3]);
    }
    
    x3 = matrixAB[2][3]/matrixAB[2][2];
	x2 = (matrixAB[1][3]-matrixAB[1][2]*x3)/matrixAB[1][1];
	x1 = (matrixAB[0][3]-matrixAB[0][1]*x2-matrixAB[0][2]*x3)/matrixAB[0][0];
	printf("X1 = %d\n",x1);
	printf("X2 = %d\n",x2);
	printf("X3 = %d\n",x3);
	if(-2*x1+3*x2+x3==matrixB[0]){
		printf("Equation 1: PASS\n");
	}
	else{
		printf("Equation 1: FAIL\n");
	}
	if(3*x1+4*x2-5*x3==matrixB[1]){
		printf("Equation 2: PASS\n");
	}
	else{
		printf("Equation 2: FAIL\n");
	}
	if(x1-2*x2+x3==matrixB[2]){
		printf("Equation 3: PASS\n");
	}
	else{
		printf("Equation 3: FAIL\n");
	}
	return 0;
}
