// File Name: 11367.cpp
// Author: Zlbing
// Created Time: 2013/4/18 10:30:28

#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<set>
#include<map>
#include<vector>
#include<cstring>
#include<stack>
#include<cmath>
#include<queue>
using namespace std;
#define CL(x,v); memset(x,v,sizeof(x));
#define INF 0x3f3f3f3f
#define LL long long
#define REP(i,r,n) for(int i=r;i<=n;i++)
#define RREP(i,n,r) for(int i=n;i>=r;i--)
const int MAXN=1e3+10;

int P[MAXN];
int n,m;
struct Edge{
    int u,v,cost;
};
vector<Edge> edges;
vector<int> G[MAXN];
struct node{
    int u,fuel,cost;
    bool operator <(const node& rhs)const{
        return cost>rhs.cost;
    }
};
int V[MAXN][105];
int dijkstra(int st,int en,int cap)
{
    memset(V,-1,sizeof(V));
    priority_queue<node> Q;
    V[st][0]=0;
    node t,tt;
    t.u=st;t.fuel=0;t.cost=0;
    Q.push(t);
    //printf("==============\n");
    while(!Q.empty())
    {
        t=Q.top();
        Q.pop();
        if(t.u==en)return t.cost;
        for(int i=0;i<G[t.u].size();i++)
        {
            Edge e=edges[G[t.u][i]];
            if(t.fuel>=e.cost)
            {
                int fuel=t.fuel-e.cost;
                if(V[e.v][fuel]==-1||V[e.v][fuel]>t.cost)
                {
                    tt.u=e.v;
                    tt.cost=t.cost;
                    tt.fuel=fuel;
                    V[tt.u][tt.fuel]=tt.cost;
                //    printf("tt.u %d cost %d fuel %d\n",tt.u,tt.fuel,tt.cost);
                    Q.push(tt);
                }
            }
            if(t.fuel<cap)
            {
                if(V[e.u][t.fuel+1]==-1||V[e.u][t.fuel+1]>t.cost+P[e.u])
                {
                    tt.u=e.u;
                    tt.fuel=t.fuel+1;
                    tt.cost=t.cost+P[e.u];
                    V[tt.u][tt.fuel]=tt.cost;
                //    printf("tt.u %d cost %d fuel %d\n",tt.u,tt.fuel,tt.cost);
                    Q.push(tt);
                }
            }
        }
    }
    return -1;
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        REP(i,0,n-1)
            scanf("%d",&P[i]);
        REP(i,0,n-1)
            G[i].clear();
        edges.clear();
        int a,b,c;
        REP(i,1,m)
        {
            scanf("%d%d%d",&a,&b,&c);
            edges.push_back((Edge){a,b,c});
            edges.push_back((Edge){b,a,c});
            int m=edges.size();
            G[a].push_back(m-2);
            G[b].push_back(m-1);
        }
        int k;
        scanf("%d",&k);
        REP(i,1,k)
        {
            scanf("%d%d%d",&a,&b,&c);
            int ans=dijkstra(b,c,a);
            if(ans==-1)
                printf("impossible\n");
            else printf("%d\n",ans);
        }
    }
    return 0;
}
