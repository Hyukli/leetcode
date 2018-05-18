#include<iostream>
using namespace std;

class Solution {
public:
    bool canTransform(string start, string end) {
        int n=start.size();
        if(end.size()!=n)   return false;
        int i=0,j=0;
        while(i<n&&j<n)
        {
            while(i<n&&start[i]=='X')   i++;
            while(j<n&&end[j]=='X')   j++;
            if(i==n&&j==n)  return true;
            if(i==n||j==n||start[i]!=end[j])   return false;
            if(start[i]=='R'&&i>j)  return false;
            if(start[i]=='L'&&i<j)  return false;
            i++;j++;
        }
        return true;
    }
};

int main()
{
    Solution s;
    string s1,s2;
    cin>>s1>>s2;
    cout<<(s.canTransform(s1,s2)?"Yes":"No")<<endl;
    return 0;
}
