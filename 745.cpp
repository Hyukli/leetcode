#include<iostream>
#include<vector>
#include<map>
using namespace std;

class WordFilter {
public:
    map<string, int> S;
    WordFilter(vector<string> words) {
        int n = words.size();
        for(int i = 0; i < n; ++i)
        {
            string &s = words[i];
            int m = s.length();
            for(int p = 0; p <= m; ++p)
            {
                string pre = s.substr(0, p);
                for(int su = 0; su <= m; ++su)
                {
                    string suf = s.substr(m - su, su);
                    int &v = S[pre + "#" + suf];
                    v = max(v, i + 1);
                }
            }
        }
    }

    int f(string prefix, string suffix) {
        return S[prefix + "#" + suffix] - 1;
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
    WordFilter w=WordFilter(v);
    string s1,s2;
    cin>>s1>>s2;
    cout<<w.f(s1,s2)<<endl;
    return 0;
}
