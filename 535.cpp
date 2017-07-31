#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    string dict="0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int id=0;
    map<string,string> m;
    map<int,string> n;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(m.find(longUrl)!=m.end())
        {
            return m[longUrl];
        }
        id++;
        int count=id;
        string res="";
        while(count>0)
        {
            res=dict[count%62]+res;
            count/=62;
        }
        while(res.size()<6)
        {
            res="0"+res;
        }
        m[longUrl]=res;
        n[id]=longUrl;
        return res;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int k=0;
        int i=0;
        while(i<shortUrl.size())
        {
            k=k*62+dict.find(shortUrl[i]);
            i++;
        }
        if(n.find(k)!=n.end())
        {
            return n[k];
        }
        return "";
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

int main()
{
    string s;
    cin>>s;
    Solution ss;
    cout<<ss.encode(s)<<endl;
    cout<<ss.decode(ss.encode(s))<<endl;
    return 0;
}
