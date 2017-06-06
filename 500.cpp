#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> v;
        string s1="qwertyuiop";
        string s2="asdfghjkl";
        string s3="zxcvbnm";
        for(int i=0;i<words.size();i++)
        {
            int as,bs,cs;
            as=bs=cs=0;
            //cout<<"!!!!!"<<endl;
            for(int j=0;j<words[i].length();j++)
            {
                if(s1.find(words[i][j])!=string::npos)
                {
                    as++;
                }
                else if(s2.find(words[i][j])!=string::npos)
                {
                    bs++;
                }
                else if(s3.find(words[i][j])!=string::npos)
                {
                    cs++;
                }
            }
            if(as*bs+as*cs+bs*cs)
            {
                ;
            }
            else
            {
                v.push_back(words[i]);
            }
        }
        return v;
    }
};

int main()
{
    Solution s;
    vector<string> v;
    string ss;
    int n;
    cin>>n;
    while(n--)
    {
        cin>>ss;
        v.push_back(ss);
    }
    vector<string> k=s.findWords(v);
    for(int i=0;i<k.size();i++)
    {
        cout<<k[i]<<" ";
    }
    return 0;
}
