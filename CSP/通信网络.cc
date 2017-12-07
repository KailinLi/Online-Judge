#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

const int MAXN = 1010;
const int MAXM = 10100;
struct Edge
{
    int to,next;
} edge[MAXM];
int head[MAXN],tot;
int Low[MAXN],DFN[MAXN],Stack[MAXN],Belong[MAXN];
int degree[MAXN];
int Index,top;
int scc;
bool Instack[MAXN];
int num[MAXN];

void addedge(int u, int v)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}


void Tarjan(int u)
{
    int v;
    Low[u] = DFN[u] = ++Index;
    Stack[top++] = u;
    Instack[u] = true;
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        v = edge[i].to;
        if(!DFN[v])
        {
            Tarjan(v);
            if(Low[u] > Low[v])
                Low[u] = Low[v];
        }
        else if(Instack[v] && Low[u] > DFN[v])
            Low[u] = DFN[v];
    }
    if(Low[u] == DFN[u])
    {
        scc++;
        do
        {
            v = Stack[--top];
            Instack[v] = false;
            Belong[v] = scc;
            num[scc]++;
        }
        while(v != u);
    }
}

void init()
{
    memset(degree,0,sizeof(degree));
    memset(DFN,0,sizeof(DFN));
    memset(Instack,false,sizeof(Instack));
    memset(num,0,sizeof(num));
    Index = scc = top = 0;
}

void solve(int n)
{
    init();
    for(int i = 1; i <= n; ++i)
        if(!DFN[i])
            Tarjan(i);
}

vector<int> G1[MAXN],G2[MAXN];
bool vis1[MAXN],vis2[MAXN];
int cnt;

void dfs1(int u)
{
    cnt++;
    for(int i = 0; i < G1[u].size(); ++i)
    {
        int v = G1[u][i];
        if(vis1[v]) continue;
        vis1[v] = true;
        dfs1(v);
    }
}

void dfs2(int u)
{
    cnt++;
    for(int i = 0; i < G2[u].size(); ++i)
    {
        int v = G2[u][i];
        if(vis2[v]) continue;
        vis2[v] = true;
        dfs2(v);
    }
}
int res;
void rebuild(int n)
{
    int u,v;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = head[i]; j != -1; j = edge[j].next)
        {
            u = Belong[i];
            v = Belong[edge[j].to];
            if(u != v)
            {
                G1[u].push_back(v);
                G2[v].push_back(u);
            }
        }
    }
    res = 0;

    for(int i = 1; i <= scc; ++i)
    {
        memset(vis1,0,sizeof(vis1));
        memset(vis2,0,sizeof(vis2));
        cnt = 0;
        vis1[i] = vis2[i] = true;
        dfs1(i);
        dfs2(i);
        if(cnt == scc+1)
            res += num[i];
    }
}

int n,m;
int main()
{
    scanf("%d %d",&n,&m);
    int u,v;
    tot = 0;
    memset(head,-1,sizeof(head));
    for(int i = 0; i < m; ++i)
    {
        scanf("%d %d",&u,&v);
        addedge(u,v);
    }
    solve(n);
    rebuild(n);
    printf("%d\n",res);
    return 0;
}