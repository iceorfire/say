#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 100010
using namespace std;
long long a[maxn];
struct segment_tree{
    long long sum[maxn<<2+1];long long add[maxn<<2+1];
    #define lson o<<1
    #define rson o<<1|1
    inline void push_down(int o,int l,int r){
        if(!add[o]) 
            return;
        add[lson] += add[o];
        add[rson] += add[o];
        int mid = (l+r) >> 1;
        sum[lson] += add[o]*(mid - l + 1);
        sum[rson] += add[o]*(r - mid);
        add[o] = 0;
    }
    inline void push_up(int o){ 
        sum[o] = sum[lson] + sum[rson];
    }
    inline void build(int o,int l,int r){
        add[o] = 0; 
        if(l == r){
            sum[o] = a[l];
            return;
        }
        int mid = (l+r) >> 1;
        build(lson,l,mid);
        build(rson,mid+1,r);
        push_up(o);
    }
    inline long long calc_sum(int o,int l,int r,int ql,int qr){
        if(ql <= l && qr >= r) 
            return sum[o];
        int mid = (l+r) >> 1;
        push_down(o,l,r);
        long long ans = 0;
        if(ql <= mid) 
            ans += calc_sum(lson,l,mid,ql,qr);
        if(qr > mid) 
            ans += calc_sum(rson,mid+1,r,ql,qr);
        return ans;
    }
    inline void update(int o,int l,int r,int ql,int qr,int v){
        if(ql <= l && qr >= r){
            add[o] += v;
            sum[o] += v*(r - l + 1);
            return;
        }
        int mid = (l+r) >> 1;
        push_down(o,l,r);
        if(ql <= mid) 
            update(lson,l,mid,ql,qr,v);
        if(qr > mid) 
            update(rson,mid+1,r,ql,qr,v);
        push_down(o,l,r);
        push_up(o);
    }
};
int n,m;
segment_tree tree;
inline int read(){
    int num = 0;
    char c;
    bool flag = false;
    while ((c = getchar()) == ' ' || c == '\n' || c == '\r');
    if (c == '-')
        flag = true;
    else
        num = c - '0';
    while (isdigit(c = getchar()))
        num = num * 10 + c - '0';
    return (flag ? -1 : 1) * num;
} 
int main(){
    n = read();m = read();
    for(int i=1;i<=n;i++) 
      a[i] = 1ll*read();
    tree.build(1,1,n);
    for(int i=1;i<=m;i++){
        int opt,x,y;
        long long k;
        opt = read();
        if(opt == 2){
            x = read();y = read();
            long long int s = tree.calc_sum(1,1,n,x,y);
            printf("%lld\n",s);
        }
        if(opt == 1){
            x = read();y = read();k = read();
            tree.update(1,1,n,x,y,k);
        }
    }
    return 0;
}
