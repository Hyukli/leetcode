class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p=headA;
        ListNode *q=headB;
        if(p==NULL||q==NULL)
        {
            return NULL;
        }
        while(p!=NULL&&q!=NULL&&q!=p)
        {
            p=p->next;
            q=q->next;
            if(q==p)
            {
                return p;
            }
            if(p==NULL)
            {
                p=headB;
            }
            if(q==NULL)
            {
                q=headA;
            }
        }
        return p;
    }

};