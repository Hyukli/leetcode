#include<iostream>
using namespace std;

class Solution {
public:
    int countSegments(string s) {
        int ans=0;
        int flag=1;
        for(int i=0;i<s.size();i++)
        {
            if(flag&&s[i]!=' ')
            {
                ans++;
                flag^=1;
            }
            else if(!flag&&s[i]==' ')
            {
                flag^=1;
            }
        }
        return ans;
    }
};

int main()
{
    string s;
    getline(cin,s);
    Solution ss;
    cout<<ss.countSegments(s)<<endl;
    return 0;
}
