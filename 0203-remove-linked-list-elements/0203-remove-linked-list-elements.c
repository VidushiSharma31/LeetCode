/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    
    while(head != NULL && head->val == val) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while(curr != NULL) {
        if(curr->val == val) {
            prev->next = curr->next;
            free(curr);
            curr = prev->next;
        } else {
        prev = curr;
        curr = curr->next;
        }
    }   
    return head;
}