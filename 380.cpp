#include<iostream>
#include<stdlib.h>
#include<vector>
#include<math.h>
#include<map>
using namespace std;

class RandomizedSet
{
public:
    /** Initialize your data structure here. */
    RandomizedSet()
    {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if(m.find(val)!=m.end())
        {
            return false;
        }
        v.push_back(val);
        m[val]=v.size()-1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        if(m.find(val)==m.end())
        {
            return false;
        }
        int t=m[val];
        m[v[v.size()-1]]=t;
        v[t]=v[v.size()-1];
        v.pop_back();
        m.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        if(v.size()==0)
        {
            cout<<"there is no val in the set!"<<endl;
            return -1;
        }
        return v[rand()%v.size()];
    }
private:
    vector<int> v;
    map<int,int> m;
};

int main()
{
    int val;
    RandomizedSet obj = RandomizedSet();
    cout<<"please insert a val:"<<endl;
    cin>>val;
    obj.insert(val);
    cout<<"insert "<<val<<" success!!"<<endl;
    cout<<"please insert another val:"<<endl;
    cin>>val;
    bool param_1 = obj.insert(val);
    if(param_1)
    {
        cout<<"insert "<<val<<" success!!"<<endl;
    }
    else
    {
        cout<<"insert "<<val<<" failure,its already in the set!"<<endl;
    }
    cout<<"please delete a val:"<<endl;
    cin>>val;
    bool param_2 = obj.remove(val);
    if(param_2)
    {
        cout<<"delete "<<val<<" success!!"<<endl;
    }
    else
    {
        cout<<"delete "<<val<<" failure,there is no "<<val<<" in the set!"<<endl;
    }
    int param_3 = obj.getRandom();
    cout<<"get a random val in the set: "<<param_3<<endl;
    return 0;
}
