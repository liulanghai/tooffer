//#include "common.h"
/*
题目描述
输入一个字符串,按字典序打印出该字符串中字符的所有排列。
例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
输入描述:
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
*/
/*问题 B : 有重复元素的排列问题
时间限制：1 秒内存限制：128 兆特殊判题： 否 提交：41解决： 8
题目描述

设R={r1, r2 ,…, rn}是要进行排列的n 个元素。其中元素 r1, r2 ,…, rn 可能相同。试设计
一个算法，列出R 的所有不同排列。

 
编程任务：
给定n 以及待排列的n 个元素。计算出这n 个元素的所有不同排列。
输入格式
输入的第1 行是元素个数n，1<=n<=500。接下来的1 行
是待排列的n 个元素。
输出
程序运行结束时，将计算出的n 个元素的所有不同排列输出。
最后1 行中的数是排列总数。
样例输入
4
aacc
样例输出
aacc
acac
acca
caac
caca
ccaa
6
*//**/
#include <stdio.h>
#include<string.h> 
int cout=0;
void swap( char * a,char * b)
{
	char temp;
	temp=*a;
	*a=*b;
	*b=temp;

}
int check(char str[],int a ,int b )
 {	
	int i;
    if(b>a)
        for( i=a;i<b;i++)
            if(str[i]==str[b])
                return 0;
    return 1;
 }
void f(char a[],int N)
{
	int length=strlen(a);
	int i;
	if(N>length-1)
	{
		printf("%s\n",a);
		cout++;
	}
	else 
		for(i=N;i<length;i++)
			if(check(a,N,i))
			{
				swap(&a[i],&a[N]);
				f(a,N+1);
				swap(&a[i],&a[N]);
			} 
}
int main()
{
	char a[100];
	int n,i;
	scanf("%d",&n);
getchar();
scanf("%s",a);
	f(a,0);
	printf("%d\n",cout);
	return 0;

}

