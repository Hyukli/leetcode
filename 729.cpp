#include<iostream>
#include<vector>
using namespace std;

struct Node
{
    int x,y;
};

class MyCalendar {
private:
    vector<Node> v;
public:
    MyCalendar() {
        v.clear();
    }

    bool book(int start, int end) {
        Node n;
        n.x=start,n.y=end;
        for(int i=0;i<v.size();i++)
        {
            if(!(end<=v[i].x||start>=v[i].y))
            {
                return false;
            }
        }
        v.push_back(n);
        return true;
    }
};

int main()
{
    MyCalendar obj =  MyCalendar();
    int n;
    cin>>n;
    while(n--)
    {
        int s,t;
        cin>>s>>t;
        cout<<(obj.book(s,t)?"Yes":"No")<<endl;
    }
    return 0;
}
