#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        map<char,int> m;
        for(auto ll:letters)
        {
            if(m.find(ll)!=m.end())
            {
                m[ll]++;
            }
            else
            {
                m[ll]=1;
            }
        }
        //cout<<m['l']<<endl;
        for(int i=1;i<=26;i++)
        {
            int c=target+i;
            //cout<<c<<endl;
            if(c>'z')
            {
                c-=26;
            }
            //cout<<c<<endl;
            if(m.find(c)!=m.end())
            {
                return c;
            }
        }
    }
};

int main()
{
    Solution s;
    int n;
    char c;
    cin>>n;
    vector<char> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cin>>c;
    cout<<s.nextGreatestLetter(v,c)<<endl;
    return 0;
}
