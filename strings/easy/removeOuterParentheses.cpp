#include<bits/stdc++.h>
using namespace std;


string removeOuterParentheses(string s);

int main()
{
    string s = "(((())))";
    cout<<removeOuterParentheses(s)<<endl;
}
string removeOuterParentheses(string s) 
{
        string res = "";
        int cnt1 = 0;
        for(int i = 0; i<s.size(); i++)
        {
            if(s[i]=='('){cnt1++;}
            else if(s[i]==')'){
                cnt1--;
            }
            if(s[i]=='(' && cnt1!=1){
                res += s[i];
            }else if(s[i]==')' && cnt1!=0){
                res+=s[i];
            }
        }
        return res;
}