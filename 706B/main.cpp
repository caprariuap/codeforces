#include <iostream>

using namespace std;

int n,m,i,j,fr[100010];

int main()
{
    cin>>n;
    for (i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        fr[x]++;
    }
    for (i=1; i<=100000; i++)
        fr[i]+=fr[i-1];
    cin>>m;
    for (i=1; i<=m; i++)
    {
        int x;
        cin>>x;
        if (x<100000)
        cout<<fr[x]<<'\n';
        else cout<<fr[100000]<<'\n';
    }
    return 0;
}
