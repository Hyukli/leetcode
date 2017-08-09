#include<iostream>
#include<vector>
#include<sstream>
#include<stdio.h>
#include<map>
using namespace std;

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence)
    {
        map<string, string>mpdic;
        for (auto s : dict)mpdic[s] = s;
        vector<string>word;
        stringstream ss(sentence);
        string tmp;
        while (ss >> tmp)word.push_back(tmp);
        for (auto &str : word)
        {
            for (int i = 1; i < str.length();i++)
            {
                if (mpdic.count(str.substr(0,i)))
                {
                    str = str.substr(0, i);
                    break;
                }
            }
        }
        string ret = word[0];
        for (int i = 1; i < word.size();i++)ret += " " + word[i];
        return ret;
    }
};

int main()
{
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    string s;
    getchar();
    getline(cin,s);
    Solution ss;
    cout<<ss.replaceWords(v,s)<<endl;
    return 0;
}
