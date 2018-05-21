#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1=rec1[0];
        int y1=rec1[1];
        int x2=rec1[2];
        int y2=rec1[3];
        int xx1=rec2[0];
        int yy1=rec2[1];
        int xx2=rec2[2];
        int yy2=rec2[3];
        if(xx1>=x2||xx2<=x1||yy1>=y2||yy2<=y1)  return false;
        return true;
    }
};

int main()
{
    Solution s;
    vector<int> v1(4),v2(4);
    for(int i=0;i<4;i++)
    {
        cin>>v1[i];
    }
    for(int i=0;i<4;i++)
    {
        cin>>v2[i];
    }
    cout<<(s.isRectangleOverlap(v1,v2)?"Yes":"No")<<endl;
    return 0;
}
