#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        set<int> s;
        for(int i=0;i<flowers.size();i++)
        {
            int x=flowers[i];
            set<int>::iterator m=s.upper_bound(x);
            if(m!=s.end()&&*m-x-1==k)
            {
                return i+1;
            }
            if(m!=s.begin())
            {
                m--;
                if(x-*m-1==k)
                {
                    return i+1;
                }
            }
            s.insert(x);
        }
        return -1;
    }
};

int main()
{
    Solution s;
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<s.kEmptySlots(v,k)<<endl;
    return 0;
}
