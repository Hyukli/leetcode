#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int tmp;
        int x1=max(A,E),y1=max(B,F),x2=min(C,G),y2=min(D,H);
        if(x1>=x2||y1>=y2)
        {
            tmp= 0;
        }
        else tmp=(x2-x1)*(y2-y1);
        return (C-A)*(D-B)+(G-E)*(H-F)-tmp;
    }
};

int main()
{
    Solution s;
    int A,B,C,D,E,F,G,H;
    cin>>A>>B>>C>>D>>E>>F>>G>>H;
    cout<<s.computeArea(A,B,C,D,E,F,G,H)<<endl;
    return 0;
}
