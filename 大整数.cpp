#include<iostream>
using namespace std;
struct BigInterger {
	static const int BASE = 100000000;
	static const int WEDTH =8;
	vector<int>s;
	BigInterger(long long num =0){*this=num;}
	BigInteger operator = (long long num){
		s.clear();
		do{
			s.push_back(num%BASE);
			num/=BASE;
		}while(num>0);
		return *this;
	}
	BigInteger operator = ( sonst string &str){
		s.clear();
		int x,len=(str.length()-1)/WIDTH +1;
		for(int i=0;i<len;i++){
			int end=str.length()-i*WIDTH;
			int start=max(0,end-WIDTH);
			ssacnf(str.substr(start,end-start).c_str(),"%d",&x);
			s.push_back(x);
		}
		return *this;
	}
};
int main()
{

