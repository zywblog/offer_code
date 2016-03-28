#include<iostream>
#include<vector>
#include<set>
using namespace std;
int getmix_k(vector<int> ar,int k)
{
	multiset<int,greater<int> > myset;//set 是begin 最大 即从大到小顺序输出
	multiset<int,greater<int> >::iterator it;//如果没有greater<int> begin 是最小 从小到大
	int i=0;
	vector<int>::iterator iter=ar.begin();
	for(;iter!=ar.end();++iter)
	{	
		if(myset.size()<k)
			myset.insert(*iter);
		else
		{
			it=myset.begin();//得到最大值
			if(*it >*iter)
			{
				myset.erase(it);
				myset.insert(*iter);
			}
		}
	}
	for(it=myset.begin();it!=myset.end();++it)
		cout<<*it<<endl;
	return 0;
}
int main()//O(nlgk)
{
	int a[]={4,5,1,6,2,7,3,8};
	vector<int > ar;
	for(int i=0;i<8;++i)
		ar.push_back(a[i]);
	int k=6;
	getmix_k(ar,k);
	return 0;
}
