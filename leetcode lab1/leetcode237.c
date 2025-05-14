#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to delete the node
void deleteNode(struct ListNode* node) {
    struct ListNode* temp = node->next;
    node->val = temp->val;
    node->next = temp->next;
    free(temp);
}

int main() {
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    
    head->val = 4;
    head->next = node1;
    node1->val = 5;
    node1->next = node2;
    node2->val = 1;
    node2->next = NULL;
    
   
deleteNode(node1);  // Delete node with value 5
    
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
    return 0;
}