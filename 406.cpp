#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<pair<int, int> > reconstructQueue(vector<pair<int, int> >& people) {
        vector<Node> v;
        vector<pair<int, int> > ans;
        for(int i=0;i<people.size();i++)
        {
            Node n;
            n.p=people[i];
            n.q=n.p.second;
            v.push_back(n);
        }
        int min;
        while(v.size())
        {
            pair<int,int> cha;
            min=1000000000;
            int k;
            for(int i=0;i<v.size();i++)
            {
                if(v[i].q==0&&v[i].p.first<min)
                {
                    min=v[i].p.first;
                    k=i;
                    cha=v[i].p;
                }
            }
            ans.push_back(cha);
            v.erase(v.begin()+k);
            for(int i=0;i<v.size();i++)
            {
                if(v[i].p.first<=min)
                {
                    v[i].q--;
                }
            }
        }
        return ans;
    }
private:
    struct Node
    {
        pair<int, int> p;
        int q;
    };
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<pair<int, int> > people;
    vector<pair<int, int> >ans;
    for(int i=0;i<n;i++)
    {
        pair<int, int> p;
        cin>>p.first>>p.second;
        people.push_back(p);
    }
    ans=s.reconstructQueue(people);
    for(int i=0;i<ans.size();i++)
    {
        cout<<"["<<ans[i].first<<" "<<ans[i].second<<"] ";
    }
    cout<<endl;
    return 0;
}
