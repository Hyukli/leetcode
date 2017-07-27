#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.empty() && needle.empty())
            return 0;
        if (needle.size() == 0)
            return 0;
        if (haystack.size() < needle.size())
            return -1;

        return KMP(haystack,needle);
    }
    vector<int> getNext(string tmp) {
        int i = tmp.size();
        int j = 0;
        int k = -1;
        vector<int> ans(i);
        ans[0] = -1;
        while (j < i-1) {
            if (k == -1 || tmp[j] == tmp[k]) {
                k++;
                j++;
                ans[j] = k;
            } else {
                k = ans[k];
            }
        }
        return ans;
    }
    int KMP(string s, string sub) {
        int i = 0;
        vector<int> next = getNext(sub);
        int j = 0;
        while (i < s.size()) {
            if (j == -1 || s[i] == sub[j]) {
                i++;
                j++;
            } else {
                j = next[j];
            }
            if (j == sub.size())
                return i-j;
        }
        return -1;
    }
};

class Solution2
{
public:
    int strStr(string haystack, string needle)
    {
        if (haystack.empty() && needle.empty())
            return 0;
        if (needle.size() == 0)
            return 0;
        if (haystack.size() < needle.size())
            return -1;

        return KMP(haystack,needle);
    }

    vector<int> getNext(string tmp)
    {
        vector<int> v;
        int st=tmp.size();
        int k=0;
        v.push_back(-1);
        for(int i=1; i<st; i++)
        {
            if(i==1)
            {
                v.push_back(0);
            }
            else
            {
                if(tmp[k]==tmp[i-1])
                {
                    k++;
                    v.push_back(k);
                }
                else
                {
                    k=0;
                    v.push_back(k);
                }
            }
        }

        for(int i=0;i<st;i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
        return v;
    }

    int KMP(string s, string sub)
    {
        int i = 0;
        vector<int> next = getNext(sub);
        int j = 0;
        while (i < s.size())
        {
            if (j == -1 || s[i] == sub[j])
            {
                i++;
                j++;
            }
            else
            {
                j = next[j];
            }
            if (j == sub.size())
                return i-j;
        }
        return -1;
    }
};

int main()
{
    Solution s;
    string s1,s2;
    cin>>s1>>s2;
    cout<<s.strStr(s1,s2)<<endl;
    return 0;
}
