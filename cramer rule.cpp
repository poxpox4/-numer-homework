#include<stdio.h>
#include<math.h>
int main(){
	int detA,detA1,detA2,detA3;
	int x1,x2,x3; 
	int matrixA[3][3] = {{-2,3,1},
						{3,4,-5},
						{1,-2,1}};
	int matrixB[3][1]={9,0,-4};
	printf("Matrix A|B 3x3:\n");
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			printf("%d ",matrixA[i][j]);
		}
		for(int j=0;j<1;j++){
			printf("| %d\n",matrixB[i][j]);
		}
	}
	detA = matrixA[0][0]*matrixA[1][1]*matrixA[2][2] + matrixA[0][1]*matrixA[1][2]*matrixA[2][0] + matrixA[0][2]*matrixA[1][0]*matrixA[2][1]
			-(matrixA[2][0]*matrixA[1][1]*matrixA[0][2] + matrixA[2][1]*matrixA[1][2]*matrixA[0][0] + matrixA[2][2]*matrixA[1][0]*matrixA[0][1]);
	printf("detA = %d\n",detA);
	
	detA1 = matrixB[0][0]*matrixA[1][1]*matrixA[2][2] + matrixA[0][1]*matrixA[1][2]*matrixB[2][0] + matrixA[0][2]*matrixB[1][0]*matrixA[2][1]
			-(matrixB[2][0]*matrixA[1][1]*matrixA[0][2] + matrixA[2][1]*matrixA[1][2]*matrixB[0][0] + matrixA[2][2]*matrixB[1][0]*matrixA[0][1]);
	printf("detA1 = %d\n",detA1);
	detA2 = matrixA[0][0]*matrixB[1][0]*matrixA[2][2] + matrixB[0][0]*matrixA[1][2]*matrixA[2][0] + matrixA[0][2]*matrixA[1][0]*matrixB[2][0]
			-(matrixA[2][0]*matrixB[1][0]*matrixA[0][2] + matrixB[2][0]*matrixA[1][2]*matrixA[0][0] + matrixA[2][2]*matrixA[1][0]*matrixB[0][0]);
	printf("detA2 = %d\n",detA2);
	detA3 = matrixA[0][0]*matrixA[1][1]*matrixB[2][0] + matrixA[0][1]*matrixB[1][0]*matrixA[2][0] + matrixB[0][0]*matrixA[1][0]*matrixA[2][1]
			-(matrixA[2][0]*matrixA[1][1]*matrixB[0][0] + matrixA[2][1]*matrixB[1][0]*matrixA[0][0] + matrixB[2][0]*matrixA[1][0]*matrixA[0][1]);
	printf("detA3 = %d\n",detA3);
	
	x1 = detA1/detA;
	printf("X1 = %d\n",x1);
	x2 = detA2/detA;
	printf("X2 = %d\n",x2);
	x3 = detA3/detA;
	printf("X3 = %d\n",x3);
	printf("Substitute X1,X2,X3 back into the equation\n");
	if(-2*x1+3*x2+x3==9){
		printf("Equation 1: PASS\n");
	}
	else{
		printf("Equation 1: FAIL\n");
	}
	if(3*x1+4*x2-5*x3==0){
		printf("Equation 2: PASS\n");
	}
	else{
		printf("Equation 2: FAIL\n");
	}
	if(x1-2*x2+x3==-4){
		printf("Equation 3: PASS\n");
	}
	else{
		printf("Equation 3: FAIL\n");
	}
				
	return 0;
}
