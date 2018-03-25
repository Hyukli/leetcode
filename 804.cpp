#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        map<int,int> m;
        int aa=0;
        vector<string> v={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(int i=0;i<words.size();i++)
        {
            string s="";
            for(int j=0;j<words[i].size();j++)
            {
                s+=v[words[i][j]-'a'];
            }
            int ans=0;
            for(int k=0;k<s.size();k++)
            {
                ans*=2;
                ans+=(s[k]=='.'?1:0);
            }
            if(m.find(ans)==m.end())
            {
                m[ans]=1;
                aa++;
            }
        }
        return aa;
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
    cout<<s.uniqueMorseRepresentations(v)<<endl;
    return 0;
}
