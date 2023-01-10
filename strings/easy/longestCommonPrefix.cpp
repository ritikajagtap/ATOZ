#include<bits/stdc++.h>
using namespace std;


string longestCommonPrefix(vector<string>& strs);

int main()
{
    vector<string> s = {"floer", "fl", "fll"};
    cout<<longestCommonPrefix(s)<<endl;
}



string longestCommonPrefix(vector<string>& strs) {
        string tmp = "";
        string comp = strs[0];
        for(int i =1; i<strs.size(); i++)
        {
            tmp="";
            string cur = strs[i];
            if(cur.size()==0){return "";}
            for(int j = 0; j<strs[i].size() && j<comp.size(); j++)
            {
               
                if((comp[j] != cur[j]))
                {
                    comp = tmp;
                    tmp="";
                    break;
                }else{
                    tmp += comp[j];
                    
                }
            }
            if(tmp.size()!=0){comp = tmp;}
          
        }
        if(tmp.size()!=0){return tmp;}
        return comp;
    }