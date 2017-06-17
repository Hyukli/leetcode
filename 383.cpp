#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> v1,v2;
        for(int i=0;i<ransomNote.size();i++)
        {
            v1.push_back(ransomNote[i]-'a');
        }
        for(int i=0;i<magazine.size();i++)
        {
            v2.push_back(magazine[i]-'a');
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        int i,j;
        for(i=0,j=0;i<v1.size()&&j<v2.size();)
        {
            if(v1[i]==v2[j])
            {
                i++;
                j++;
            }
            else if(v1[i]<v2[j])
            {
                return false;
            }
            else if(v1[i]>v2[j])
            {
                j++;
            }
        }
        if(i==v1.size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    Solution s;
    if(s.canConstruct(s1,s2))
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
    return 0;
}
