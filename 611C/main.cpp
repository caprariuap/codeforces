#include <iostream>

using namespace std;

int i,j,r[510][510],d[510][510],rd[510][510];
int a[510][510];
int n,m;
int r1,c1,r2,c2;
int q;

int main()
{cin>>n>>m;
for (i=1; i<=n; i++)
    for (j=1; j<=m; j++)
{char c;
cin>>c;
if (c=='.')
    a[i][j]=1;
}
for (i=1; i<=m; i++)
{if (a[1][i-1]==1&&a[1][i]==1)
r[1][i]=1;
r[1][i]+=r[1][i-1];
}
for (i=2; i<=n; i++)
{r[i][1]=r[i-1][1];
for (j=2; j<=m; j++)
{if (a[i][j-1]==1&&a[i][j]==1)
r[i][j]++;
r[i][j]+=r[i-1][j]+r[i][j-1]-r[i-1][j-1];
}
}
for (i=2; i<=n; i++)
{d[i][1]=d[i-1][1];
if (a[i][1]==1&&a[i-1][1]==1)
    d[i][1]++;
for (j=2; j<=m; j++)
{if (a[i][j]==1&&a[i-1][j]==1)
d[i][j]++;
d[i][j]+=d[i-1][j]+d[i][j-1]-d[i-1][j-1];
}
}
for (i=1; i<=n; i++)
    for (j=1; j<=m; j++)
{rd[i][j]=r[i][j]+d[i][j];
}
cin>>q;
for (i=1; i<=q; i++)
{cin>>r1>>c1>>r2>>c2;
int sum=rd[r2][c2]-r[r2][c1]-d[r2][c1-1]-r[r1-1][c2]-d[r1][c2]+r[r1-1][c1]+d[r1][c1-1];

cout<<sum<<'\n';
}
}
//r[r2][c2-1]+d[r2-1][c2]-r[r2][c1-1]-r[r1-1][c1]+r[r1-1][r2-1]-d[r1-1][c2]-d[r1][c1-1]+d[r1-1][c1-1];
