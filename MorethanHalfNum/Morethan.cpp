#include<iostream>
#include<vector>
using namespace std;

bool g_bInputInvalid =false;
bool g_bHalfInvalid=false;
int swap(int &a,int &b)
{
	int tem=a;
	a=b;
	b=tem;
	return 0;
}
bool CheckHalfNum(vector<int> ar,int result)
{
	int len=ar.size();
	int count=0;
	for(int i=0;i<len;++i)
	{
		if(ar[i]==result)
			count++;	
	}
	if(count*2<len)
		g_bHalfInvalid=true;
	return g_bHalfInvalid;	
}
int partition(vector<int> ar,int start,int end)
{
	int len=ar.size();
	int right=end;
	int left=start;
	int prev=start-1;
	int cur =start;
	int temp=ar[left];
	for(;cur<=right;++cur)
	{	
		if(ar[cur]<=temp)
		{
			prev++;
			if(cur!=prev)
				swap(ar[cur],ar[prev]);
		}
	}
	swap(ar[prev],ar[left]);
	return prev;
}
int Morethan(vector<int> ar)
{
	int length=ar.size();
	if(length<=0)
	g_bInputInvalid=true;
	int start=0;
	int end=length-1;
	int mid=length>>1;
	int index=partition(ar,start,end);
	while(index!=mid)
	{
		if(index>mid)
		{
			end=index-1;
			index=partition(ar,start,end);
		}
		else
		{
			start=index+1;
			index=partition(ar,start,end);
		}
	}
	int result=ar[mid];
	if(CheckHalfNum(ar,result))
		result=0;
	return result;	
}
int main()
{
	vector<int> ar;
	int a[9]={1,2,3,2,2,2,5,4,2};
	for(int i=0;i<9;++i)
		ar.push_back(a[i]);
	int res=Morethan(ar);
	cout<<res<<endl;
	return 0;
}
