#include<bits/stdc++.h>
using namespace std;


bool isAnagram(string s, string t);

int main()
{
    string s = "sahil";
    string t = "lihas";
    cout<<isAnagram(s, t)<<endl;
}

bool isAnagram(string s, string t)
 {
        if(s.size() != t.size())
        {
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        bool flag = 1;
        for(int i = 0; i<s.size(); i++)
        {
            if(s[i]==t[i])
            {
                continue;
            }else{
                flag = 0;
                break;
            }
            
        }
        if(flag)
        {
            return true;
        }else{
            return false;
        }
    }