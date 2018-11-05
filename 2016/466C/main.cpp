#include <iostream>

using namespace std;

long long n,i,j,a[500010],nr;
long long s,sum;
long long nr1,nr2;

int main()
{cin>>n;
for (i=1; i<=n; i++)
    cin>>a[i],sum+=a[i];
if (sum%3==0&&n>=3)
{long long poz1=sum/3;long long poz2=2*poz1;
for (i=1; i<n; i++)
{s+=a[i];
if (s==poz2)
nr+=nr1;
if (s==poz1)
    nr1++;
}
cout<<nr<<'\n';
}
else cout<<'0'<<'\n';
}
