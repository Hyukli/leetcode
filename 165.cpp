#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1,v2;
        version1+=".";
        version2+=".";
        stringstream s1(version1),s2(version2);
        while(s1)
        {
            int t;
            char c;
            s1>>t>>c;
            v1.push_back(t);
        }
        v1.pop_back();
        while(s2)
        {
            int t;
            char c;
            s2>>t>>c;
            v2.push_back(t);
        }
        v2.pop_back();
        for(int i=v1.size()-1;i>=0;i--)
        {
            if(v1[i])
            {
                break;
            }
            else
            {
                v1.pop_back();
            }
        }
        for(int i=v2.size()-1;i>=0;i--)
        {
            if(v2[i])
            {
                break;
            }
            else
            {
                v2.pop_back();
            }
        }
        for(int i=0;i<v1.size()&&i<v2.size();i++)
        {
            if(v1[i]<v2[i])
            {
                return -1;
            }
            else if(v1[i]>v2[i])
            {
                return 1;
            }
        }
        if(v1.size()>v2.size()) return 1;
        if(v1.size()<v2.size()) return -1;
        return 0;
    }
};

int main()
{
    Solution s;
    string s1,s2;
    cin>>s1>>s2;
    cout<<s.compareVersion(s1,s2)<<endl;
    return 0;
}
