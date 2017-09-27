#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double> ans;
        map<string,Node*> m;
        for(int i=0;i<equations.size();i++)
        {
            string s1=equations[i].first;
            string s2=equations[i].second;
            if(m.count(s1)==0&&m.count(s2)==0)
            {
                m[s1]=new Node();
                m[s2]=new Node();
                m[s1]->val=values[i];
                m[s2]->val=1;
                m[s1]->parent=m[s2];
            }
            else if(m.count(s2)==0)
            {
                m[s2]=new Node();
                m[s2]->val=m[s1]->val/values[i];
                m[s2]->parent=m[s1];
            }
            else if(m.count(s1)==0)
            {
                m[s1]=new Node();
                m[s1]->val=m[s2]->val*values[i];
                m[s1]->parent=m[s2];
            }
            else
            {
                unionNode(m[s1],m[s2],values[i],m);
            }
        }
        for(auto it:queries)
        {
            string s1=it.first,s2=it.second;
            if(m.count(s1)==0||m.count(s2)==0||findp(m[s1])!=findp(m[s2]))
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(m[s1]->val/m[s2]->val);
            }
        }
        return ans;
    }
private:
    struct Node
    {
        double val;
        Node *parent;
        Node()
        {
            val=0.0;
            parent=this;
        }
    };
    Node *findp(Node *node)
    {
        if(node->parent==node)
        {
            return node;
        }
        return node->parent=findp(node->parent);
    }
    int unionNode(Node *n1,Node *n2,double num,map<string,Node*> &m)
    {
        Node *p1=findp(n1),*p2=findp(n2);
        double b=n2->val*num/n1->val;
        for(auto it:m)
        {
            if(findp(it.second)==p1)
            {
                it.second->val*=b;
            }
        }
        p1->parent=p2;
        return 0;
    }
};

int main()
{
    Solution s;
    int n,m;
    cin>>n>>m;
    vector<pair<string,string>> v1(n);
    vector<double> v2(n);
    vector<pair<string,string>> v3(m);
    vector<double> ans;
    for(int i=0;i<n;i++)
    {
        cin>>v1[i].first>>v1[i].second;
    }
    for(int i=0;i<n;i++)
    {
        cin>>v2[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>v3[i].first>>v3[i].second;
    }
    ans=s.calcEquation(v1,v2,v3);
    for(int i=0;i<m;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
} 
