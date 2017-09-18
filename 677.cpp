#include<iostream>
#include<map>
#include<vector>
using namespace std;

class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
    }

    void insert(string key, int val) {
        string s;
        if(h.find(key)==h.end())
        {
            for(int i=1;i<=key.size();i++)
            {
                s=key.substr(0,i);
                //cout<<s<<endl;
                m[s]+=val;
            }
        }
        else
        {
            int t=m[key];
            for(int i=1;i<=key.size();i++)
            {
                s=key.substr(0,i);
                m[s]-=t;
                m[s]+=val;
            }
        }
        h[key]=1;
    }

    int sum(string prefix) {
        return m[prefix];
    }
private:
    map<string,int> m;
    map<string,int> h;
};

int main()
{
    MapSum obj;
    string key,s;
    int val;
    cin>>key>>s>>val;
    obj.insert(key,val);
    cout<<obj.sum(s)<<endl;
    return 0;
}
