#include<iostream>
#include<vector>
using namespace std;

int swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
	return 0;
}

int partition(vector<int> &ar,int start, int end)
{
	int i;
	int j;
	j=start;
	i=start+1;
	int temp=ar[i];
	for(;i<end;i++)
	{
		if(ar[i]<temp)
		{
			j++;
			if(i!=j)
				swap(ar[i],ar[j]);
		}
	}
	swap(ar[j],ar[start]);
	return j;
}

int getmix_k(vector<int> &ar,int k)
{
	int start=0;
	int end=ar.size()-1;
	if(k>end || k<=0)
		return 0;
	int par=partition(ar,start,end);//返回的是下标
	while(par!=k-1)
	{
		if(par<k-1)
		{
			start=par+1;
			par=partition(ar,start,end);
		}
		else
		{
			//end=par-1;
			//par=partition(ar,start,end);	
			break;
		}
	}
	for(int i=0;i<k;++i)
	{
		cout<< ar[i]<<endl;
	}
	return 0;
}
int main()//O(n)
{
	vector<int> ar;
	int a[]={4,5,1,6,2,7,3,8};
	int k=3;
	for(int i=0;i<8;++i)
		ar.push_back(a[i]);
	getmix_k(ar,k);
	//cout<< "hello"<<endl;	
	return 0;
}
