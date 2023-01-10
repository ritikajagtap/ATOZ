#include<bits/stdc++.h>
using namespace std;


bool isIsomorphic(string s, string t);

int main()
{
    string s = "egg";
    string t = "add";
    cout<<isIsomorphic(s, t)<<endl;
}


bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()){return false;}
        unordered_map<char, char> m1, m2;
        for(int i=0; i<s.size(); i++)
        {
            if(m1[s[i]] && m1[s[i]]!=t[i]){return false;}
            if(m2[t[i]] && m2[t[i]]!=s[i]){return false;}
            m1[s[i]]=t[i];
            m2[t[i]] = s[i];

        }
        return true;
    }