#include<iostream>
using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a==b)
        {
            return -1;
        }
        else if(a.size()>b.size())
        {
            return a.size();
        }
        else
        {
            return b.size();
        }
    }
};

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    Solution s;
    cout<<s.findLUSlength(s1,s2)<<endl;
    return 0;
}
