//还有一种空间复杂度为1的方法，就是让一个数每次计算的都是自己的各位平方和，另一个是计算两次后的各位平方和，当两者相同时，看是否为1，是接受否则拒绝。
#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        if(a.find(n)==a.end())
        {
            a[n]=1;
        }
        else
        {
            return false;
        }
        int ans=0;
        while(n)
        {
            ans+=(n%10)*(n%10);
            n/=10;
        }
        if(ans==1)
        {
            return true;
        }
        else
        {
            return isHappy(ans);
        }
    }
    map<int,int> a;
};

int main()
{
    int n;
    cin>>n;
    Solution s;
    cout<<(s.isHappy(n)?"Yes":"No")<<endl;
    return 0;
}
