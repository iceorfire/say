//check is a answer or not in a star8
//将矩阵元素排成一排，忽略空格，当且仅当逆序数个数为偶数时，问题有解
#include<iostream>
#include<queue>
#include<string>
using namespace std;


int main()
{
	string state;
	cin>>state;
	int num=0;
	for(int i=0;i<state.size();i++)
	{
		for(int j=i+1;j<state.size();j++)
		{
			if((state[i]-'0')>(state[j]-'0')) num++;
		}
	}
	if(num%2==0) cout<<"有解"<<endl;
	else cout<<"无解"<<endl;
	return 0;
}
