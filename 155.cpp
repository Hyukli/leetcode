#include<iostream>
#include<stack>
using namespace std;

class MinStack
{
public:
    MinStack()
    {

    }

    void push(int x)
    {
        m.push(x);
        if(n.empty())
        {
            n.push(x);
        }
        else
        {
            n.push(min(n.top(),x));
        }
        return;
    }

    int pop()
    {
        int t=m.top();
        m.pop();
        n.pop();
        return t;
    }

    int top()
    {
        return m.top();
    }

    int getMin()
    {
        return n.top();
    }
private:
    stack<int> m,n;
};

int main()
{

    MinStack obj = MinStack();
    cout<<"please input the num you wanna input:"<<endl;
    int n;
    cin>>n;
     cout<<"please input the num onr by one:"<<endl;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        obj.push(x);
    }
    cout<<"min:"<<obj.getMin()<<endl;
    cout<<"pop:"<<obj.pop()<<endl;
    cout<<"top:"<<obj.top()<<endl;
    cout<<"min:"<<obj.getMin();
    return 0;
}
