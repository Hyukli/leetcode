#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> ret;
        string cur = "";
        int f1 = 0, f2 = 0;
        for (auto str : source) {
            f1 = 0;
            for (int i = 0; i < str.size(); i++) {
                if (f1) break;
                if (f2) {
                    if (str[i] == '*') {
                        if (i + 1 < str.size() && str[i+1] == '/') {
                            f2 = 0; i++;
                        }
                    }
                    continue;
                }
                if (str[i] == '/' && i + 1 < str.size()) {
                    if (str[i+1] == '/') {f1 = 1; i++; continue;}
                    if (str[i+1] == '*') {f2 = 1; i++; continue;}
                }
                cur.push_back(str[i]);
            }
            if (!f1 && !f2) {if (cur != "") ret.push_back(cur); cur = "";}
            if (f1 && cur != "") {ret.push_back(cur); cur = "";}
        }
        return ret;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<string> v(n+1);
    for(int i=0;i<=n;i++)
    {
        string s;
        getline(cin,s);
        v[i]=s;
    }
    v=s.removeComments(v);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }
    return 0;
}
