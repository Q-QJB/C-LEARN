#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>


//void my_strcpy(char* dest,char* src)
//{
//	if (dest != NULL && src != NULL)
//	{
//		while(*dest++ = *src++/**src != '\0'*/)
//		{
//			//*dest++ = *src++;
//			//src++;
//			//dest++;
//		}
//		//*dest = *src;//\0
//	}
//}
#include <assert.h>
char* my_strcpy(char* dest,const char* src)
{
	char* ret = dest;
	assert(dest != NULL);//����
	assert(src != NULL);//����
	//��srcָ����ַ���������destָ��Ŀռ䣬����'\0'
	while(*dest++ = *src++/**src != '\0'*/)
	{
			//*dest++ = *src++;
			//src++;
			//dest++;
	}
		//*dest = *src;//\0
	return ret;
}
int main()
{
	//strcpy
	//�ַ�������
	char arr1[] = "############";
	char arr2[] = "bit";
	printf("%s\n",my_strcpy(arr1,arr2));
	return 0;
}