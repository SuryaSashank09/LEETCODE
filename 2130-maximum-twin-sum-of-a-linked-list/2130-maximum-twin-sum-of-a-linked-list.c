/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int pairSum(struct ListNode* head) {
    int arr[100000];
    int n = 0;
    struct ListNode* node = head;
    while (node != NULL) {
        arr[n++] = node->val;
        node = node->next;
    }

    int maxSum = 0;
    for (int i = 0; i < n/2; i++) {
        int sum = arr[i] + arr[n-1-i];
        if (sum > maxSum) {
            maxSum = sum;
        }
    }

    return maxSum;
}
