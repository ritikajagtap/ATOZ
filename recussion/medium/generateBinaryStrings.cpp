#include <bits/stdc++.h>
using namespace std;

void solve(int num, int i, string s);
void generateBinaryStrings(int &num);

int main()
{
    int num = 3;
    generateBinaryStrings(num);
    cout << num << endl;
}

void solve(int num, int i, string s)
{
    if (i == num)
    {
        cout << s << " ";
        return;
    }
    solve(num, i + 1, s + '0');
    if (s.size() == 0 || s[s.size() - 1] != '1')
    {
        solve(num, i + 1, s + '1');
    }
}
void generateBinaryStrings(int &num)
{
    // Write your code
    solve(num, 0, "");
}