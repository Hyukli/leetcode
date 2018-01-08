#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        map<int,int> m;
        for(int i=0;i<B.size();i++)
        {
            m[B[i]]=i;
        }
        vector<int> ans;
        for(int i=0;i<A.size();i++)
        {
            ans.push_back(m[A[i]]);
        }
        return ans;
    }

};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<int> v1(n),v2(n),ans;
    for(int i=0;i<n;i++)
    {
        cin>>v1[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>v2[i];
    }
    ans=s.anagramMappings(v1,v2);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
