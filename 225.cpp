#include<iostream>
#include<queue>
using namespace std;

class MyStack {
    queue<int> q;
public:
    /** Initialize your data structure here. */

    /** Push element x onto stack. */
    int push(int x) {
        q.push(x);
        for(int i=0;i<q.size()-1;i++)
        {
            q.push(q.front());
            q.pop();
        }
        return 0;
    }
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int k=q.front();
        q.pop();
        return k;

    }
    /** Get the top element. */
    int top() {
        return q.front();
    }
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

int main()
{
    MyStack s;
    cout<<"pleaase input the num you wanna push in to stack:"<<endl;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        s.push(k);
    }
    cout<<"q.top():"<<s.top()<<endl;
    cout<<"q.pop():"<<s.pop()<<endl;
    cout<<"q.empty():"<<(s.empty()?"Yes":"No")<<endl;
    return 0;
}
