//����һ�ֿռ临�Ӷ�Ϊ1�ķ�����������һ����ÿ�μ���Ķ����Լ��ĸ�λƽ���ͣ���һ���Ǽ������κ�ĸ�λƽ���ͣ���������ͬʱ�����Ƿ�Ϊ1���ǽ��ܷ���ܾ���
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
