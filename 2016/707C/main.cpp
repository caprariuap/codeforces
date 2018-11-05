#include <iostream>
#include <cmath>

using namespace std;

long long a;

int main()
{
    cin>>a;
    if (a<=2)
        cout<<"-1";
    else
    {
        if (a%2)
        {
            a/=2;
            cout<<2*a*(a+1)<<' '<<2*a*a+2*a+1;
        }
        else
        {
            a/=2;
            cout<<a*a-1<<' '<<a*a+1;
        }
    }
}
//int x=a/2;
//a^2+b^2=c^2
//(m^2-n^2)^2+(2mn)^2=(m^2+n^2)^2
//a par => a=2mn => x=mn n=1,m=x
//x^2-1+x^2=x^2+1
//a impar=> a=m^2-n^2=x*2+1
//(m-n)(m+n)=x*2+1
//m-n=1; m+n=2n+1
//2n+1=2x+1
//x=n m=x+1
//b=2*x*(x+1)
//c=2x^2+2x+1
