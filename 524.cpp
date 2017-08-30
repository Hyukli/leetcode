#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string ans="";
        int max=0;
        int i,j,k;
        for(i=0;i<d.size();i++)
        {
            for(j=0,k=0;j<d[i].size()&&k<s.size();)
            {
                if(s[k]==d[i][j])
                {
                    j++;
                }
                k++;
            }
            if(j==d[i].size())
            {
                if(j>max||(j==max&&fr(d[i],ans)))
                {
                    max=j;
                    ans=d[i];
                }
            }
        }
        return ans;
    }
private:
    bool fr(string a,string b)
    {
        for(int i=0;i<a.size();i++)
        {
            if(a[i]<b[i])
            {
                return true;
            }
            else if(a[i]>b[i])
            {
                return false;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    string ss;
    int n;
    cout<<"please input the dictionary :"<<endl;
    cin>>ss;
    cout<<"please input the num of strings you wanan input: "<<endl;
    cin>>n;
    vector<string> v(n);
    cout<<"please input strings onr by one: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<s.findLongestWord(ss,v)<<endl;
    return 0;
}
