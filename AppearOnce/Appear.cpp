#include<iostream>
#include<vector>
using namespace std;

bool Isbit(int num,int count)
{
	num=num>>count;//这里 如果count是负数就会出错 
	return (num &1);
}

void appear(vector<int> ar,int *num1,int *num2)
{
	int len=ar.size();
	if(len<2)
		return ;
	int temp =0;
	int count=0;//为什么要用unsigned int
	for(int i=0;i<len;++i)
		temp=temp^ar[i];
	while(((temp&1) == 0) && (count< 8*sizeof(int)))//这个条件 注意
	{	
		temp=temp>>1;
		count++;
	}
	*num1=*num2=0;
	for(int i=0;i<len;i++)
	{
		if(Isbit(ar[i],count))
			*num1^=ar[i];
		else
			*num2^=ar[i];
	}
	return ;
}
int main()
{
	vector<int > ar;
	int num1,num2;
	num1 =num2=0;
	int a[8]={2,3,4,3,2,5,6,5};
	for(int i=0;i<8;++i)
	ar.push_back(a[i]);
	appear(ar,&num1,&num2);
	cout<< num1<<" "<<num2<<endl;
	return 0;
}
