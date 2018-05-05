#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        vector<string> tmp;
        for(int i=0;i<words.size();i++)
        {
            if(canp(tmp,words[i],maxWidth))
            {
                tmp.push_back(words[i]);
            }
            else
            {
                i--;
                string s=merge(0,tmp,maxWidth);
                ans.push_back(s);
                tmp.clear();
            }
        }
         ans.push_back(merge(1,tmp,maxWidth));
        return ans;
    }
private:
    bool canp(vector<string> v,string s,int maxWidth)
    {
        int ans=0;
        for(int i=0;i<v.size();i++)
        {
            ans+=v[i].size();
            ans++;
        }
        ans+=s.size();
        return maxWidth>=ans;
    }

    string merge(bool flag,vector<string> tmp,int w)
    {
        string ans="";
        if(flag==1)
        {
            for(int i=0;i<tmp.size()-1;i++)
            {
                ans+=tmp[i];
                ans+=" ";
            }
            ans+=tmp[tmp.size()-1];
            while(ans.size()<w)
            {
                ans+=" ";
            }
        }
        else
        {
            if(tmp.size()==1)
            {
                ans+=tmp[0];
                while(ans.size()<w)
                {
                    ans+=" ";
                }
            }
            else
            {
                int ws=0;
                for(int i=0;i<tmp.size();i++)
                {
                    ws+=tmp[i].size();
                }
                int basew=(w-ws)/(tmp.size()-1);
                int ex=(w-ws)%(tmp.size()-1);
                for(int i=0;i<tmp.size()-1;i++)
                {
                    ans+=tmp[i];
                    for(int j=0;j<basew;j++)
                    {
                        ans+=" ";
                    }
                    if(i<ex)
                    {
                        ans+=" ";
                    }
                }
                ans+=tmp[tmp.size()-1];
            }

        }
        return ans;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int m;
    cin>>m;
    vector<string> ans=s.fullJustify(v,m);
    for(int i=0;i<ans.size();i++)
    {

        cout<<ans[i]<<endl;
    }
    return 0;
}
