#include <iostream>
#include <cstring>

using namespace std;

char a[100100],b[100100];
int la,lb,i,ans;

int main()
{
    cin >> a >> b;
    if (strcmp(a,b)==0)
    {
        cout << "-1\n";
        return 0;
    }
    la=strlen(a);
    lb=strlen(b);
    cout << max(la,lb) << '\n';
    return 0;
    int minim=min(la,lb);
    for (i=0; i<minim; i++)
        if (a[i]!=b[i])
            ans++;
    ans=ans+max(la-lb,lb-la);
    cout << ans << '\n';
}
