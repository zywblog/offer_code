#include<iostream>
#include<vector>
using namespace std;

bool g_InvalidInput=false;
int GreastSum(vector<int> ar)
{
	int len=ar.size();
	if(len<=0)
	{
		g_InvalidInput=true;
		return 0;
	}
	int maxSum=0;
	int temSum=0;
	for(int i=0;i<len;++i)
	{
		if(temSum<=0)
			temSum=ar[i];
		else
			temSum+=ar[i];
		if(temSum>maxSum)
			maxSum=temSum;
	}
	return maxSum;
}

int main()
{
	int a[]={1,-2,3,10,-4,-7,-2,3,-5};
	vector<int> ar;
	for(int i=0;i<9;++i)
		ar.push_back(a[i]);
	int res=GreastSum(ar);
	cout<<res<<endl;
	return 0;
}
