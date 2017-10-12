#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

class NumArray {
public:
    NumArray(vector<int> nums) {
        memset(bit,0,sizeof(bit));
        num=nums;
        n=nums.size();
        for(int i=0;i<n;i++)
        {
            init(i,num[i]);
        }
    }

    void init(int i,int val)
    {
        i++;
        while(i<=n)
        {
            bit[i]+=val;
            i+=(i&-i);
        }
    }

    void update(int i, int val) {
        int diff=val-num[i];
        num[i]=val;
        init(i,diff);
    }

    int getsum(int i)
    {
        int sum=0;
        i++;
        while(i>0)
        {
            sum+=bit[i];
            i-=(i&-i);
        }
        return sum;
    }

    int sumRange(int i, int j) {
        return getsum(j)-getsum(i-1);
    }
private:
    vector<int> num;
    int bit[200000];
    int n;
};

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    NumArray obj = NumArray(v);
    int i,j;
    cout<<"please input the left and right of the interval:"<<endl;
    cin>>i>>j;
    cout<<obj.sumRange(i,j)<<endl;;
    cout<<"please input the position and val you wanna change:"<<endl;
    cin>>i>>j;
    obj.update(i,j);
    cout<<"please input the left and right of the interval:"<<endl;
    cin>>i>>j;
    cout<<obj.sumRange(i,j)<<endl;
    return 0;
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
