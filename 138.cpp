/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        map<RandomListNode*,int> m;
        map<int,int> m1;
        map<int,RandomListNode*> m2;
        int i=1;
        RandomListNode* h=head;
        if(h==NULL)
        {
            return NULL;
        }
        m[NULL]=0;
        while(h)
        {
            m[h]=i++;
            h=h->next;
        }
        h=head;
        int k=1;
        while(h)
        {
            m1[k++]=m[h->random];
            h=h->next;
        }
        RandomListNode *ans=new RandomListNode(0);
        RandomListNode *hh=ans;
        h=head;
        i=1;
        while(h)
        {
            RandomListNode *p=new RandomListNode(h->label);
            h=h->next;
            m2[i++]=p;
            ans->next=p;
            ans=ans->next;
        }
        h=head;
        ans=hh->next;
        i=1;
        while(h)
        {
            ans->random=m2[m1[i++]];
            ans=ans->next;
            h=h->next;
        }
        return hh->next;
    }
};
