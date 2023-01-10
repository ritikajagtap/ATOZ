#include<bits/stdc++.h>
using namespace std;


bool rotateString(string s, string goal);

int main()
{
    string s = "egg";
    string t = "egg";
    cout<<rotateString(s, t)<<endl;
}


bool rotateString(string s, string goal) 
{
        if(s.size()!=goal.size()){
            return false;
        }
        s = s+s;
        size_t found = s.find(goal);
        if(found!=std::string::npos){return true;}
        return false;
    }