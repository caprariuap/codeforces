#include <iostream>

using namespace std;

int n,m,i,j,ok,nr,maxim,a[510],b[510],s[510],sb[510],pozi,poz,cn,NR,ind[510],sbb[510];
bool op[510];

int main()
{
    cin >> n;
    for (i=1; i<=n; i++)
    {
        cin >> a[i];
        s[i]=s[i-1]+a[i];
    }
    cin >> m;
    for (i=1; i<=m; i++)
    {
        cin >> b[i];
        sb[i]=sb[i-1]+b[i];
    }
    int nr=1;
    ok=1;
    poz=1;
    while (nr<=m)
    {
        cn=sbb[nr-1]-nr+1;
        pozi=poz;
        while (b[nr]>s[poz]-sb[nr-1])
            poz++;
        if (b[nr]<s[poz]-sb[nr-1])
        {
            cout << "NO" << '\n';
            return 0;
        }
        sbb[nr]=sbb[nr-1]+poz-pozi+1;
        maxim=0;
        for (i=pozi; i<=poz; i++)
            if (a[i]>a[maxim])
                maxim=i;
        int pozz=maxim;
        while (a[pozz]==a[pozz+1]&&pozz<poz) pozz++;
        if (pozz==poz)
        {
            while (a[pozz]==a[pozz-1]&&pozz>pozi) pozz--;
            if (pozz==pozi&&pozi!=poz)
            {
                cout << "NO" << '\n';
                return 0;
            }
        }
        maxim=pozz;
        int left=maxim;
        int right=maxim;
        if (maxim==pozi||(a[maxim]==a[maxim-1]&&maxim>pozi))
        {
            while (right<poz)
                ind[++NR]=maxim-cn,op[NR]=0,right++;
        }
        else
        {
            while (left>pozi)
                ind[++NR]=maxim-cn,op[NR]=1,cn++,left--;
        }
        while (right<poz)
            ind[++NR]=maxim-cn,op[NR]=0,right++;
        while (left>pozi)
            ind[++NR]=maxim-cn,op[NR]=1,cn++,left--;
        if (poz<n&&nr==m)
        {
            cout << "NO" <<'\n';
            return 0;
        }
        poz++;
        nr++;
    }
    if (ok==0)
        cout << "NO";
    else
    {
        cout << "YES" << '\n';
        for (i=1; i<=NR; i++)
        {
            cout << ind[i] << ' ';
            if (op[i]==1)
                cout << 'L';
            else
                cout << 'R';
            cout << '\n';
        }
    }
}
