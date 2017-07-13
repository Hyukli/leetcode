#include<iostream>
#include<stack>
using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(s2.empty())
        {
            helper(s1,s2);
        }
        int t=s2.top();
        s2.pop();
        return t;
    }

    /** Get the front element. */
    int peek() {
        if(s2.empty())
        {
            helper(s1,s2);
        }
        return s2.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty()&&s2.empty();
    }
private:
    stack<int> s1;
    stack<int> s2;
    int helper(stack<int> &s1,stack<int> &s2)
    {
        while(!s1.empty())
        {
            int t=s1.top();
            s1.pop();
            s2.push(t);
        }
        return 0;
    }
};

int main()
{
    MyQueue mq;
    int n;
    cout<<"Please input the num you wanna push into the queue:"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        mq.push(k);
    }
    cout<<"mq.pop()="<<mq.pop()<<endl;
    cout<<"mq.peek()="<<mq.peek()<<endl;
    cout<<"mq.empty()="<<(mq.empty()?"Yes":"No")<<endl;
    return 0;
}
