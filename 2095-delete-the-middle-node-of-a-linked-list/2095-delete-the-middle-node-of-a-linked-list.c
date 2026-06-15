/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        free(head);
        return NULL;
    }

    int n = 0;
    struct ListNode* temp = head;
    while (temp != NULL) {
        n++;
        temp = temp->next;
    }

    int mid = n / 2;

    temp = head;
    for (int i = 0; i < mid - 1; i++) {
        temp = temp->next;
    }

    struct ListNode* del = temp->next;
    temp->next = del->next;
    free(del);

    return head;
}
