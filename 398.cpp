#include<iostream>
#include<vector>
#include<stdlib.h>

using namespace std;

class Solution {
public:
    Solution(vector<int> nums)
    {
        v=nums;
    }
    int pick(int target)
    {
        int ans;
        int j=1;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]==target)
            {
                if(rand()%j++==0)
                {
                    ans=i;
                }
            }
        }
        return ans;
    }
private:
    vector<int> v;
};

int main()
{
    int n,k;
    cout<<"please input the num of the arroy"<<endl;
    cin>>n;
    vector<int> v(n);
    cout<<"please input the arroy one by one"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    Solution obj = Solution(v);
    cout<<"please input the num of the figure you wanna find"<<endl;
    int m;
    cin>>m;
    cout<<"please input the figure one by one"<<endl;
    while(m--)
    {
        cin>>k;
        cout<<obj.pick(k)<<endl;
    }
    return 0;
}
