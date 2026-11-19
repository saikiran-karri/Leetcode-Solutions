class Solution {
public:
    // Find the Kth node in the linked list (1-based indexing)
    ListNode* findtail(ListNode* temp, int k) {
        int count = 1;

        while (temp != NULL) {
            if (count == k) return temp;

            count++;
            temp = temp->next;
        }

        return temp;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k == 0) return head;

        ListNode* tail = head;
        int len = 1;

        // Calculate the length and find the original tail
        while (tail->next != NULL) {
            tail = tail->next;
            len++;
        }

        // No rotation needed
        if (k % len == 0) return head;

        k = k % len;

        // Make the linked list circular
        tail->next = head;

        // Find the new tail
        ListNode* newtail = findtail(head, len - k);

        // Update the head and break the circular link
        head = newtail->next;
        newtail->next = NULL;

        return head;
    }
};