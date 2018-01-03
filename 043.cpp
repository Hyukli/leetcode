#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int f(vector<int> v)
    {
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
        return 0;
    }
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0")
        {
            return "0";
        }
        vector<int> v1,v2;
        for(int i=0;i<num1.size();i++)
        {
            v1.push_back(num1[i]-'0');
        }
        for(int i=0;i<num2.size();i++)
        {
            v2.push_back(num2[i]-'0');
        }
        reverse(v1.begin(),v1.end());
        reverse(v2.begin(),v2.end());
        vector<int> v(v1.size()+v2.size(),0);
        for(int i=0;i<v1.size();i++)
        {
            for(int j=0;j<v2.size();j++)
            {
                int t=v1[i]*v2[j];
                v[i+j]+=t;
                if(v[i+j]>9)
                {
                    v[i+j+1]+=v[i+j]/10;
                    v[i+j]%=10;
                }
            }
        }
        reverse(v.begin(),v.end());
        while(v[0]==0)
        {
            v.erase(v.begin());
        }
        string s;
        for(int i=0;i<v.size();i++)
        {
            s+=(v[i]+'0');
        }
        return s;
    }
};

int main()
{
    Solution s;
    string s1,s2;
    cin>>s1>>s2;
    cout<<s.multiply(s1,s2)<<endl;
    return 0;
}
