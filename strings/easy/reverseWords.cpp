#include<bits/stdc++.h>
using namespace std;


string reverseWords(string s);

int main()
{
    string s = "the sky is blue";
    cout<<reverseWords(s)<<endl;
}
 string reverseWords(string s) {
        string tmp = "";
        string res = "";
        for(int i = 0; i<s.size(); i++)
        {
            if(s[i]!=' '){
                tmp+=s[i];
            }
            if(s[i]==' '){
                if(res.size()==0){
                    res=tmp;
                }else if(s[i-1]!=' '){
                    res = tmp + ' ' + res;
                }
                    tmp = "";
            }
            
        } 
        if(tmp.size()!=0){
            if(res.size()==0){
                res=tmp;
                return res;
            }
            res = tmp + ' ' +res;
        }
        return res;
        
    }