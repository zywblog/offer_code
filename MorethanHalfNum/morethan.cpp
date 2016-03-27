#include<iostream>
#include<vector>
using namespace std;
int morethan(vector<int> ar)
{
	int i;
	int len=ar.size();
	int temp=ar[0];
	int count=1;
	for(i=1;i<len;++i)
	{
		if(count==0)
		{
			temp=ar[i];
			count=1;
		}
		else if(temp==ar[i])
			count++;
		else
			count--;
	}
	return temp;
}


int main()
{
	vector<int > ar;
	int a[]={1,2,3,2,2,2,5,4,2};
	for(int i=0;i<9;++i)
		ar.push_back(a[i]);
	int res=morethan(ar);
	cout<< res<<endl;
	return 0;
}
