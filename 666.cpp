#include<iostream>
#include<vector>
using namespace std;

struct Node
{
    int deep,num,val;
};

class Solution {
public:
    int pathSum(vector<int>& nums) {
        vector<Node> v;
        for(int i=0;i<nums.size();i++)
        {
            Node n;
            n.deep=nums[i]/100;
            n.num=nums[i]/10%10;
            n.val=nums[i]%10;
            v.push_back(n);
        }
        fun(v,1,1,v[0].val);
        return sum;
    }
private:
    int sum=0;
    int fun(vector<Node> v,int de,int nu,int tmp)
    {
        int flag=0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i].deep==de+1&&(v[i].num==nu*2-1||v[i].num==nu*2))
            {
                flag++;
                fun(v,de+1,v[i].num,tmp+v[i].val);
            }
        }
        if(!flag)
        {
            sum+=tmp;
        }
        return 0;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<s.pathSum(v)<<endl;
    return 0;
}
