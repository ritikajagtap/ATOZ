#include<bits/stdc++.h>
using namespace std;


string largestOddNumber(string s);

int main()
{
    string s = "217834594083";
    cout<<largestOddNumber(s)<<endl;
}





string largestOddNumber(string num) {
        
        for(int i = num.size()-1; i>=0; i--)
        {
            if(int(num[i])%2==0){
                num.pop_back();
                continue;
            }
            break;
        }
            return num;
    }

