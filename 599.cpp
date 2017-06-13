#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int s1=list1.size();
        int s2=list2.size();
        vector<int> v;
        vector<string> s;
        for(int i=0;i<s1;i++)
        {
            v.push_back(3000);
            for(int j=0;j<s2;j++)
            {
                if(list1[i]==list2[j])
                {
                    v[i]=i+j;
                }
            }
        }
        int min=3000;
        for(int i=0;i<s1;i++)
        {
            if(v[i]<min)
            {
                min=v[i];
            }
        }
        for(int i=0;i<s1;i++)
        {
            if(v[i]==min)
            {
                s.push_back(list1[i]);
            }
        }
        return s;
    }
};

int main()
{
    int n,m;
    cout<<"please input the num of two lists:";
    cin>>n>>m;
    cout<<"please input restaurants of list1";
    vector<string> s1,s2,s;
    string t;
    while(n--)
    {
        cin>>t;
        s1.push_back(t);
    }
    cout<<"please input restaurants of list2";
    while(m--)
    {
        cin>>t;
        s2.push_back(t);
    }
    Solution ss;
    s=ss.findRestaurant(s1,s2);
    for(int i=0;i<s.size();i++)
    {
        cout<<s[i]<<" ";
    }
    cout<<endl;
    return 0;
}
