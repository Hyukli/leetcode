#include<iostream>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int ss=s.size();
        if(ss!=0)
        {
            for(int i=1;i<ss;i++)
            {
                if(ss%i==0)
                {
                    string str=nextStr(s,i);
                    if(s==str)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
private:
    string nextStr(string &s,int l)
    {
        string lef=s.substr(0,l);
        string rig=s.substr(l);
        rig+=lef;
        return rig;
    }
};

int main()
{
    Solution s;
    string ss;
    cin>>ss;
    cout<<(s.repeatedSubstringPattern(ss)?"Yes":"No")<<endl;
    return 0;
}
