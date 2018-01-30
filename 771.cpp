#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int ans=0;
        map<char,int> m;
        for(int i=0;i<J.size();i++)
        {
            m[J[i]]++;
        }
        for(int i=0;i<S.size();i++)
        {
            if(m[S[i]]==1)
            {
                ans++;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    string s1,s2;
    cin>>s1>>s2;
    cout<<s.numJewelsInStones(s1,s2)<<endl;
    return 0;
}
