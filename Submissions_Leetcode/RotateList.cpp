#include <iostream>
using std::cout;
using std::endl;
/* 
Given the head of a linked list, rotate the list to the right by k places.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]
 

Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109

Runtime: 11 ms, faster than 52.08% of C++ online submissions for Rotate List.
Memory Usage: 11.7 MB, less than 55.87% of C++ online submissions for Rotate List.

*/


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotate(ListNode* head, int k)
    {
        //take last elem, make it point to head, make it the new head, repeat k times.
        if(k==0)return head;
        ListNode *temp=head;
        while(temp->next->next)
        {
            temp=temp->next;
        }
        ListNode* newhead=temp->next;
        temp->next=nullptr;
        newhead->next=head;
        head=newhead;
        return rotate(head,k-1);
        
    }
    ListNode* rotateRight(ListNode* head, int k) {
        //sanity checks + size find
        if(!head)return head;
        ListNode *temp=head;
        int count=1;
        while(temp->next)
            {++count;temp=temp->next;}
        cout<<count<<endl;
        
        //redudndant operation reduction 
        if(k>=count)
            k=k%count;
        cout<<k<<endl;
        if(k==0)return head;
        
        //begin rotating
        
        
        return rotate(head,k);
    }
};
