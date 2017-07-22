#include<iostream>
#include<map>
#include<stdio.h>
#include<vector>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char,string> m;
        map<string,char> n;
        vector<string> vs;
        string s="";
        for(int i=0;i<str.size();i++)
        {
            if(str[i]!=' ')
            {
                s+=str[i];
            }
            else
            {
                vs.push_back(s);
                s="";
            }
        }
        vs.push_back(s);
        if(vs.size()!=pattern.size())
        {
            return false;
        }
        for(int i=0;i<vs.size();i++)
        {
            if(m.find(pattern[i])==m.end())
            {
                m[pattern[i]]=vs[i];
            }
            else
            {
                if(m[pattern[i]]!=vs[i])
                {
                    return false;
                }
            }
        }
        for(int i=0;i<vs.size();i++)
        {
            if(n.find(vs[i])==n.end())
            {
                n[vs[i]]=pattern[i];
            }
            else
            {
                if(n[vs[i]]!=pattern[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution ss;
    string pa,st;
    cout<<"please input the pattern:"<<endl;
    cin>>pa;
    getchar();
    cout<<"please input the str:"<<endl;
    getline(cin,st);
    cout<<(ss.wordPattern(pa,st)?"Yes":"No")<<endl;
    return 0;
}
