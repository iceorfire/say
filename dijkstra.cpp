#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
struct CNode{
	int k;int w;
};
bool operator < (const CNode&d1,const CNode & d2){
	return d1.w>d2.w;
}
priority_queue<CNode>pq;
bool bUsed[30010]={0};
vector<vector<CNode> >v;
const unsigned  int INF=1<<29;
int main()
{
	int N,M,a,b,c;
	int i,j,k;
	CNode p;
	scanf("%d%d",&N,&M);
	v.clear();
	v.resize(N+1);
	memset(bUsed,0,sizeof(bUsed));
	for(i=1;i<=M;i++){
		scanf("%d%d%d",&a,&b,&c);
		p.k=b;
		p.w=c;
		v[a].push_back(p);
	}
	p.k=1;
	p.w=1;
	pq.push(p);
	while(!pq.empty()){
		p=pq.top();
		pq.pop();
		if(bUsed[p.k]) continue;
		bUsed[p.k]=true;
		if(p.k==N) break;
		for(i=0,j=v[p.k].size();i<j;i++){
			CNode q;q.k=v[p.k][i].k;
			if(bUsed[q.k]) continue;
			q.w=p.w+v[p.k][i].w;
			pq.push(q);
		}
	}
	printf("%d",p.w);
	return 0;
}
