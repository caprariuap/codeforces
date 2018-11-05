#include <iostream>

using namespace std;

int n[15],m[15],i,j,n1,m1,nt;
int nn,nm;
int usen[7];
int usem[7];
int bn[15],bm[15];

int bc(int x[],int &nr,int y)
{nr=0;
while (y)
{x[++nr]=y%7;
y/=7;
}
if (nr==0) nr++;
for (int i=1; i<=nr/2; i++)
    swap(x[i],x[nr-i+1]);
}

int compare(int a[],int b[],int nr)
{if (a[i]==0&&b[i]!=0) return -1;
if (a[i]!=0&&b[i]==0) return 1;
int i=1;
while (a[i]==b[i]&&i<nr) i++;
if (a[i]>b[i]) return 1;
else if (a[i]<b[i]) return -1;
return 0;
}

void bktm(int k)
{if (k>nm)
{if (compare(m,bm,nm)>=0)
{nt++;
}
}
else
{for (int i=0; i<=6; i++)
if (!usen[i]&&!usem[i])
{usem[i]=1;
bm[k]=i;
bktm(k+1);
usem[i]=0;
}
}
}

void bktn(int k)
{if (k>nn)
{if (compare(n,bn,nn)>=0)
bktm(1);
}
else
{for (int i=0; i<=6; i++)
if (!usen[i])
{usen[i]=1;
bn[k]=i;
bktn(k+1);
usen[i]=0;
}
}
}

int main()
{cin>>n1>>m1;
n1--;
m1--;
bc(n,nn,n1);
bc(m,nm,m1);
if (nn+nm>7) cout<<'0';
else
{bktn(1);
cout<<nt;
}
}
