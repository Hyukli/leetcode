#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int tmp=0;
        int l=1;
        for(int i=0;i<S.size();i++)
        {
            int t=widths[S[i]-'a'];
            if(tmp+t<=100)
            {
                tmp+=t;
            }
            else
            {
                l++;
                tmp=t;
            }
        }
        vector<int> ans;
        ans.push_back(l);
        ans.push_back(tmp);
        return ans;
    }
};

int main()
{
    Solution s;
    string ss;
    vector<int> v(26);
    for(int i=0;i<26;i++)
    {
        cin>>v[i];
    }
    cin>>ss;
    vector<int> ans=s.numberOfLines(v,ss);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}
