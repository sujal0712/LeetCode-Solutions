/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {

        if (head == nullptr || head->next == nullptr)
            return;
        
         ListNode* slow = head;
         ListNode* fast = head;
         ListNode* curr = head;
    
    while(fast!= nullptr && fast->next != nullptr ){
        slow=slow->next;
        fast= fast->next->next;
    }

    ListNode* temp= slow->next;
     slow->next = NULL;

    ListNode* prev = NULL;

    while(temp != nullptr){
        ListNode* next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
        
    }

    while(prev != nullptr){
        ListNode* first_next = curr->next;
        ListNode* second_next = prev->next;
        curr->next = prev;
        prev->next= first_next;
        curr=first_next;
        prev = second_next;

    }
    }
};