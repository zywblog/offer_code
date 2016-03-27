#include<iostream>
#include<vector>
using namespace std;

int count=0;
int Binsort(vector<int> ar,int left,int right,int k)
{
	while(left<=right)
	{
		int mid=left+(right-left)/2;
		if(ar[mid]>k)
			right=mid-1;
		if(ar[mid]<k)
			left=mid+1;
		if(ar[mid]==k)
			return mid;
	}
	return -1;
}

int GetCount(vector<int> ar,int left,int right,int k)
{
	if(left>right)
		return 0;
	int mid=Binsort(ar,left,right,k);
	if(mid!=-1)
	{
		count++;
		GetCount(ar,left,mid-1,k);
		GetCount(ar,mid+1,right,k);
		return count;
	}
	return 0;
}
int main()
{
	vector<int > ar;
	int b[8]={3,3,3,3,3,3,3,3};
	for(int i=0;i<8;++i)
	ar.push_back(b[i]);
	int a=GetCount(ar,0,7,3);
	cout<< a <<endl;
	return 0;
}
