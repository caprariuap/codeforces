#include <vector>
#include <cstdio>

using namespace std;

int n,m,q,i,j,r[100010],op[100010][3];
int a[1010][1010],inv[1010];
vector <int> v[100010];

void dfs(int x,int rasp)
{
    r[x]=rasp;
//    printf("%dDADA",x);
//    for (int z=0; z<v[x].size();z++)
//        printf("%d ",v[x][z]);
//    printf("\n");
    if (op[x][0]==1)
    {
        if (!inv[op[x][1]])
        {
            if (!a[op[x][1]][op[x][2]])
            {
                a[op[x][1]][op[x][2]]=1;
                a[op[x][1]][0]++;
                r[x]++;
                for (int z=0; z<v[x].size(); z++)
                    dfs(v[x][z],r[x]);
                a[op[x][1]][op[x][2]]=0;
                a[op[x][1]][0]--;
            }
            else
                for (int z=0; z<v[x].size(); z++)
                    dfs(v[x][z],r[x]);
        }
        else
        {
            if (a[op[x][1]][op[x][2]])
            {
                a[op[x][1]][op[x][2]]=1;
                a[op[x][1]][0]++;
                r[x]++;
                for (int z=0; z<v[x].size(); z++)
                    dfs(v[x][z],r[x]);
                a[op[x][1]][op[x][2]]=0;
                a[op[x][1]][0]--;
            }
            else
                for (int z=0; z<v[x].size(); z++)
                    dfs(v[x][z],r[x]);
        }
        return;
    }
    if (op[x][0]==2)
    {
        if (!inv[op[x][1]])
        {
            if (a[op[x][1]][op[x][2]])
            {
                a[op[x][1]][op[x][2]]=0;
                a[op[x][1]][0]--;
                r[x]--;
                for (int z=0; z<v[x].size(); z++)
                    dfs(v[x][z],r[x]);
                a[op[x][1]][op[x][2]]=1;
                a[op[x][1]][0]++;
            }
            else
                for (int z=0; z<v[x].size(); z++)
                    dfs(v[x][z],r[x]);
        }
        else
        {
            if (!a[op[x][1]][op[x][2]])
            {
                a[op[x][1]][op[x][2]]=1;
                a[op[x][1]][0]--;
                r[x]--;
                for (int z=0; z<v[x].size(); z++)
                    dfs(v[x][z],r[x]);
                a[op[x][1]][op[x][2]]=0;
                a[op[x][1]][0]++;
            }
            else
                for (int z=0; z<v[x].size(); z++)
                    dfs(v[x][z],r[x]);
        }
        return;
    }
    if (op[x][0]==3)
    {
        int aux2=a[op[x][1]][0];
        r[x]=r[x]-a[op[x][1]][0];
        inv[op[x][1]]=1-inv[op[x][1]];
        a[op[x][1]][0]=m-a[op[x][1]][0];
        r[x]+=a[op[x][1]][0];
        for (int z=0; z<v[x].size(); z++)
            dfs(v[x][z],r[x]);
        inv[op[x][1]]=1-inv[op[x][1]];
        a[op[x][1]][0]=aux2;
        return;
    }
    for (int z=0; z<v[x].size(); z++)
        dfs(v[x][z],r[x]);
}

int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for (i=1; i<=q; i++)
    {
        scanf("%d%d",&op[i][0],&op[i][1]);
        if (op[i][0]<3)
            scanf("%d",&op[i][2]);
        if (op[i][0]==4)
            v[op[i][1]].push_back(i);
        else
            v[i-1].push_back(i);
    }
    dfs(0,0);
    for (i=1; i<=q; i++)
        printf("%d\n",r[i]);
}
