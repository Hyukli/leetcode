#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        vector<int> v;
        vector<char> c;
        while(n)
        {
            int k=n%26;
            v.push_back(k?k:26);
            n-=1;
            n/=26;
        }
        for(int i=v.size()-1;i>=0;i--)
        {
            c.push_back('A'-1+v[i]);
        }
        string s="";
        for(int i=0;i<c.size();i++)
        {
            s+=c[i];
        }
        return s;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    cout<<s.convertToTitle(n)<<endl;
    return 0;
}
