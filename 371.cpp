#include<iostream>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        while(b)
        {
            int carry=a&b;//��λλ��
            a=a^b;//�������ȱ1+1�Ľ�λ
            b=carry<<1;//������λ�����ƶ�
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
