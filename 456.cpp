#include<iostream>
#include<limits.h>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int s3=INT_MIN;
        stack<int> st;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]<s3)
            {
                return true;
            }
            else
            {
                while(!st.empty()&&nums[i]>st.top())
                {
                    s3=st.top();
                    st.pop();
                }
            }
            st.push(nums[i]);
        }
        return false;
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
    cout<<(s.find132pattern(v)?"Yes":"No")<<endl;
    return 0;
}
