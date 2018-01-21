#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string reorganizeString(string S) {
        int n=S.size();
        vector<int> v(26,0);
        int m=0;
        for(int i=0;i<n;i++)
        {
            v[S[i]-'a']++;
            if(v[S[i]-'a']>m)
            {
                m=v[S[i]-'a'];
            }
        }
        if(m>(S.size()+1)/2)
        {
            return "";
        }
        string s="";
        int k=0;
        for(int i=0;i<S.size();i++)
        {
            int t=0;
            m=0;
            for(int j=0;j<26;j++)
            {
                if(i==0&&v[j]>m)
                {
                    t=j;
                    m=v[j];
                }
                if(i!=0&&v[j]>m&&j!=k)
                {
                    t=j;
                    m=v[j];
                }
            }
            char c='a'+t;
            s+=c;
            v[t]--;
            k=t;
        }
        return s;
    }
};

int main()
{
    Solution s;
    string ss;
    cin>>ss;
    cout<<s.reorganizeString(ss)<<endl;
    return 0;
}
