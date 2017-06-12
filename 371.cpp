#include<iostream>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        while(b)
        {
            int carry=a&b;//进位位置
            a=a^b;//亦或结果，缺1+1的进位
            b=carry<<1;//产生进位的左移动
        }
        return a;
    }
};

int main()
{
    int a,b;
    cin>>a>>b;
    Solution s;
    cout<<s.getSum(a,b)<<endl;;
    return 0;
}
