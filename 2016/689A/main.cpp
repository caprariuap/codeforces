#include <iostream>

using namespace std;

int n;
char s[15];

bool stanga()
{
    for (int i=0; i<n; i++)
        if (s[i]=='1'||s[i]=='4'||s[i]=='7'||s[i]=='0')
            return 0;
    return 1;
}

bool jos()
{
    for (int i=0; i<n; i++)
        if (s[i]=='7'||s[i]=='0'||s[i]=='9')
            return 0;
    return 1;
}

bool dreapta()
{
    for (int i=0; i<n; i++)
        if (s[i]=='3'||s[i]=='6'||s[i]=='9'||s[i]=='0')
            return 0;
    return 1;
}

bool sus()
{
    for (int i=0; i<n; i++)
        if (s[i]=='1'||s[i]=='2'||s[i]=='3')
            return 0;
    return 1;
}

int main()
{
    cin>>n;
    cin>>s;
    if (stanga()||jos()||dreapta()||sus())
        cout<<"NO";
    else cout<<"YES";
    cout<<'\n';
}
