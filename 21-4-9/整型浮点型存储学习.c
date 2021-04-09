#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>



int main()
	//9.0
	//1001.0
	//(-1)^0 * 1.001 * 2^3
	//(-1)^S * M * 2^E
	//S-0,M-1.001,E-3
{
	int n = 9;
	//00000000 0000000 00000000 00001001
	float* pFloat = (float*)&n;
	printf("n的值为:%d\n",n);//9
	printf("pFloat的值为:%f\n",*pFloat);//0.000000
	//(-1)^0 * 0.0000000000000000001001 * 2^-126

	*pFloat = 9.0;
	//1001
	//(-1)^0 * 1.001 * 2^3
	//0 10000010 00100000000000000000000-原码
	printf("num的值为:%d\n",n);//1091567671
	printf("pFloat的值为:%f\n",*pFloat);//9.000000
}