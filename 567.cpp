#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        vector<int> v1(26,0);
        vector<int> v2(26,0);
        if(n1>n2)
        {
            return false;
        }
        for(int i=0;i<n1;i++)
        {
            v1[s1[i]-'a']++;
            v2[s2[i]-'a']++;
        }
        if(v1==v2)
        {
            return true;
        }
        for(int i=1;i+n1<=n2;i++)
        {
            v2[s2[i+n1-1]-'a']++;
            v2[s2[i-1]-'a']--;
            if(v1==v2)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    string s1,s2;
    cin>>s1>>s2;
    cout<<(s.checkInclusion(s1,s2)?"Yes":"No")<<endl;
    return 0;
}
