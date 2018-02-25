//更新一个dinnic网络流的模版
#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f
struct node
{
    int from,to,cap,flow;
};
vector<node>edges;
vector<int>load[1000005];
int n,m,s,t;
int cur[1000005];
int d[1000005];
void add(int u,int v,int w)
{
    edges.push_back((node){u,v,w,0});
    edges.push_back((node){v,u,0,0});
    int x=edges.size();
    load[u].push_back(x-2);
    load[v].push_back(x-1);
}
bool bfs()
{
    memset(d,0,sizeof(d));
    queue<int>q;
    q.push(s);
    d[s]=1;
    while(!q.empty())
    {
        int u=q.front();q.pop();
        int x=load[u].size();
        for(int i=0;i<x;i++)
        {
            node &v=edges[load[u][i]];
            if(!d[v.to]&&v.cap>v.flow)
            {
                d[v.to]=d[u]+1;
                q.push(v.to);
            }
        }
    }
    return d[t]!=0?1:0;
}
int dfs(int u,int mini)
{
    if(mini==0||u==t)
    return mini;
    int x=load[u].size();
    int flow=0;
    for(int &i=cur[u];i<x;i++)
    {
        node& v=edges[load[u][i]];
        int f;
        if(d[v.to]==d[u]+1&&(f=dfs(v.to,min(mini,v.cap-v.flow)))>0)
        {
            v.flow+=f;
            edges[load[u][i]^1].flow-=f;
            flow+=f;
            mini-=f;
            if(mini==0)break;
        }
    }
    return flow;
}
void dinic()
{
    int ans=0;
    while(bfs())
    {
        memset(cur,0,sizeof(cur));
        ans+=dfs(s,INF);
    }
    printf("%d",ans);
}
int n1,n2,n3,m1,m2,m3;
int main()
{
    s=0;
    scanf("%d %d %d",&n1,&n2,&n3);
    scanf("%d",&m1);
    for(int i=1;i<=m1;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        add(y,x+n2,1);
    }
    scanf("%d",&m2);
    for(int i=1;i<=m2;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        add(x+n2+n1,2*n1+n2+y,1);
    }
    for(int i=1;i<=n2;i++)
    {
        add(0,i,1);
    }
    for(int i=1;i<=n1;i++)
    {
        add(n2+i,n2+n1+i,1);
    }
    int end=n1+n2*2+n3+1;
    t=end;
    for(int i=1;i<=n1;i++)
    {
        add(n2+2*n1+i,end,1);
    }
    dinic();
}
