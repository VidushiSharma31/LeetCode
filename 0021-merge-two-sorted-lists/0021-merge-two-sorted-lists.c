/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* dummyHead = createNode(0);
    struct ListNode* current = dummyHead;
    while(list1 != NULL && list2 != NULL) {
        if(list1->val > list2->val){
            current->next = list2;
            list2 = list2->next;
        }
        else {
            current->next = list1;
            list1 = list1->next;
        }
        current = current->next;
    }
    if(list1 != NULL)
        current->next = list1;
    else
        current->next = list2;
    struct ListNode* mergedList = dummyHead->next;
    free(dummyHead);
    return mergedList;
}