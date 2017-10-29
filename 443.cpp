#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> char2;
        int c=chars[0];
        int tmp=1;
        for(int i=1;i<chars.size();i++)
        {
            if(chars[i]==chars[i-1])
            {
                tmp++;
            }
            else
            {
                char2.push_back(c);
                pb(char2,tmp);
                c=chars[i];
                tmp=1;
            }
        }
        char2.push_back(c);
        pb(char2,tmp);
        chars=char2;
        return char2.size();
    }
private:
    int pb(vector<char> &v,int t)
    {
        if(t==1)
        {
            return 0;
        }
        int k=v.size();
        while(t)
        {
            v.insert(v.begin()+k,t%10+'0');
            t/=10;
        }
        return 0;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<char> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<s.compress(v)<<endl;
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}
