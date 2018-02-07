#include<iostream>
using namespace std;
long long m,n;
long long ksp(long long n,long long p)
{
	long long ans=1;
	while(p)
	{
		if(p&1) ans=ans*n%100003;
		n=n*n%100003;
		p>>=1;
	}
	return ans;
}
int main()
{
	int m,n;
	cin>>m>>n;
	cout<<(ksp(m,n)-m*ksp(m-1,n-1)%100003)<<endl;
}
