#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Node
{
    int x,y;
};

bool cmp(const Node& a,const Node& b)
{
    if(a.y!=b.y)
    {
        return a.y>b.y;
    }
    return a.x<b.x;
}

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<Node> v(4);
        v[0].x=p1[0];v[0].y=p1[1];
        v[1].x=p2[0];v[1].y=p2[1];
        v[2].x=p3[0];v[2].y=p3[1];
        v[3].x=p4[0];v[3].y=p4[1];
        sort(v.begin(),v.end(),cmp);
        //cout<<v[0].x<<" "<<v[0].y<<" "<<v[1].x<<" "<<v[1].y<<" "<<v[2].x<<" "<<v[2].y;
        int x1,x2,y1,y2;
        x1=v[0].x-v[3].x;
        y1=v[0].y-v[3].y;
        x2=v[1].x-v[2].x;
        y2=v[1].y-v[2].y;
        if(x1==0&&y1==0)
        {
            return false;
        }
        if(x1*x1+y1*y1==x2*x2+y2*y2&&x1*x2+y1*y2==0&&v[0].x+v[3].x==v[1].x+v[2].x&&v[0].y+v[3].y==v[1].y+v[2].y)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> p1(2),p2(2),p3(2),p4(2);
    cin>>p1[0]>>p1[1]>>p2[0]>>p2[1]>>p3[0]>>p3[1]>>p4[0]>>p4[1];
    cout<<(s.validSquare(p1,p2,p3,p4)?"Yes":"No")<<endl;
    return 0;
}
