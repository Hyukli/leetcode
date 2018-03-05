#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        map<char,vector<int>> m;
        int ans=0;
        for(int i=0;i<S.size();i++)
        {
            m[S[i]].push_back(i);
        }
        int tmp;
        for(int i=0;i<words.size();i++)
        {
            tmp=-1;
            for(int j=0;j<words[i].size();j++)
            {
                int flag=0;
                for(auto k:m[words[i][j]])
                {
                    if(k>tmp)
                    {
                        tmp=k;
                        flag++;
                        break;
                    }
                }
                if(flag==0)
                {
                    break;
                }
                if(j==words[i].size()-1)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    string ss;
    cin>>ss;
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<s.numMatchingSubseq(ss,v)<<endl;
    return 0;
}
