#include<iostream>
#include<vector>
using namespace std;

int GetFirst(vector<int> ar,int left,int right,int k)
{
	if(left>right)
		return -1;
	int mid=left+(right-left)/2;
	int temp=ar[mid];
	if(ar[mid]== k)
	{
		if((mid>0 && ar[mid-1]!=k) || mid==0)//这个条件一样 要注意边界值
			return mid;
		else
			right=mid-1;
	}
	else if(ar[mid]>k)
		right=mid-1;
	else
		left=mid+1;
	return GetFirst(ar,left,right,k);
		
}
int GetLast(vector<int> ar,int left,int right, int k)
{
	if(left>right)
		return -1;
	int size=ar.size();
	int mid=left+(right-left)/2;
	if(ar[mid]==k)
	{
		if((mid+1<size && ar[mid+1]!=k) || mid==size-1)//这个条件很容易就忘了 mid有可能是最后一个数 那就返回mid
			return mid;
		else
			left=mid+1;
	}
	else if(ar[mid]<k)
		left=mid+1;
	else
		right=mid-1;
	return GetLast(ar,left,right,k);
}

int GetNumberOfK(vector<int> data ,int k)
{
	int left=0;
	int right=data.size()-1;
	int first=GetFirst(data,left,right,k);
	int last=GetLast(data,left,right,k);
	if(first >-1 && last>-1)
	return last-first+1;
	return 0;
}
int main()
{
	vector<int > ar;
	//int a[8]={1,2,3,3,3,3,4,5};
	int a[8]={3,3,3,3,3,3,3,3};
	for(int i=0;i<8;i++)
	ar.push_back(a[i]);
	int count= GetNumberOfK(ar,3);
	cout<< count <<endl;
	return 0;
}
