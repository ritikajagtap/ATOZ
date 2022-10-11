/* Jai Shree Krishna */
/* Ritika Jagtap */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pb push_back
#define db pop_back
#define f first
#define s second
#define rep(i, a, b) for (ll i = a; i < b; ++i)
#define repi(i, b, a) for (ll i = b - 1; i >= a; --i)
#define all(a) (a).begin(), (a).end()
int maxSubArray(int A[], int n1);
void solve();
long long gcd(long long int a, long long int b);
long long lcm(int a, int b);
const int N = 200001;

int main()
{
    int x;
    cin>>x;
    cout<<solve(x)<<endl;
}
int solve(int x)
{
    long long n = x;
    long long rev = 0;
    long long temp;
    while (n != 0)
    {
        temp = n % 10;
        rev = rev * 10 + temp;
        n = n / 10;
    }
    int res = rev;
    if (res > -pow(2, 31) && res < pow(2, 31) - 1)
        return res;
    return 0;
}
long long gcd(long long int a, long long int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}