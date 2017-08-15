#include<iostream>
#include<vector>
#include<stdlib.h>
#include<math.h>
using namespace std;

class Solution {
public:
    Solution(vector<int> nums) {
        old=nums;
    }

    vector<int> reset() {
        return old;
    }

    vector<int> shuffle() {
        tmp=old;
        ans.clear();
        while(tmp.size())
        {
            int t=rand()%(tmp.size());
            ans.push_back(tmp[t]);
            tmp.erase(tmp.begin()+t);
        }
        return ans;
    }
    vector<int> old;
    vector<int> tmp;
    vector<int> ans;
};

int main()
{
    int n;
    cin>>n;
    vector<int> v(n),tmp;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    Solution s(v);
    tmp=s.shuffle();
    cout<<"shuffle:";
    for(int i=0;i<tmp.size();i++)
    {
        cout<<tmp[i]<<" ";
    }
    cout<<endl;
    tmp=s.reset();
    cout<<"reset:";
    for(int i=0;i<tmp.size();i++)
    {
        cout<<tmp[i]<<" ";
    }
    cout<<endl;
    tmp=s.shuffle();
    cout<<"shuffle:";
    for(int i=0;i<tmp.size();i++)
    {
        cout<<tmp[i]<<" ";
    }
    cout<<endl;
    return 0;
}
