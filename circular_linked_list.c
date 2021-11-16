#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int key;
    struct node* next;
}node;

node * push(node *linked_list, int key);
node * push_after_key(node *linked_list, int key1, int key2);
node * delete(node *linked_list, int key);
node * search(node *linked_list, int key);

node * push(node *linked_list, int key) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->key = key;
    node *head = linked_list;

    if (linked_list == NULL) {
        linked_list = new_node;
        linked_list->next = new_node;
        head = linked_list;
    }

    else if (linked_list->next == linked_list) {
        new_node->next = linked_list;
        linked_list->next = new_node;
    }

    else {
        new_node->next = linked_list;
        while (linked_list->next != head) {
            linked_list = linked_list->next;
        }
        linked_list->next = new_node;
    }

    return head;
}

node * push_after_key(node *linked_list, int key1, int key2) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->key = key1;
    node *head = linked_list;

    if (linked_list == NULL) {
        printf("List is empty\n");
    }

    else if (linked_list->key == key2) {
        new_node->next = linked_list->next;
        linked_list->next = new_node;
    }

    else {
        int ans = 0;
        linked_list = linked_list->next;
        while (linked_list != head) {
            if (linked_list->key == key2) {
                new_node->next = linked_list->next;
                linked_list->next = new_node;
                ans = 1;
                break;
            }
            linked_list = linked_list->next;
        }

        if (ans == 0) {
            printf("%d is not present in the list", key2);
        }
    }

    return head;
}

node * delete(node *linked_list, int key) {
    node *head = linked_list;
    if (linked_list == NULL) {
        printf("List is empty\n");
    }

    else if (head->key == key) {
        linked_list = linked_list->next;
        while (linked_list->next != head) {
            linked_list = linked_list->next;
        }

        linked_list->next = (linked_list->next)->next;
        head = linked_list->next;
    }

    else {
        while ((linked_list->next)->key != key) {
            linked_list = linked_list->next;
        }

        linked_list->next = (linked_list->next)->next;
    }

    return head;
}

node * search(node *linked_list, int key) {
    int ans = 0;
    node *head = linked_list;
    if (linked_list == NULL) {
        printf("List is empty.\n");
    }

    else if (head->key == key){
        printf("Element is present in the list.\n");
    }
    

    else {
        linked_list = linked_list->next;
        while (linked_list != head) {
            if (linked_list->key == key) {
                ans = 1;
                printf("Element is present in the list.\n");
                break;
            }

            linked_list = linked_list->next;
        }

        if (ans == 0) {
            printf("Element is not present in the list.\n");
        }
    }
}

int main() {
    node *linked_list;
    linked_list = NULL;
    linked_list = push(linked_list, 5);
    linked_list = push(linked_list, 8);
    linked_list = push(linked_list, 2);
    linked_list = push(linked_list, 9);
    linked_list = push(linked_list, 10);
    linked_list = push(linked_list, 6);
    // linked_list = push(linked_list, 1);
    // printf("%d ---> %d\n", linked_list->key, (linked_list->next)->key);
    // node *head = linked_list;
    // linked_list = linked_list->next;
    // while (linked_list != head) {
    //     printf("%d ---> %d\n", linked_list->key, (linked_list->next)->key);
    //     linked_list = linked_list->next;
    // }

    // linked_list = delete(linked_list, 8);
    printf("%d\n", linked_list->key);
    node *head = linked_list;
    linked_list = linked_list->next;
    while (linked_list != head) {
        printf("%d\n", linked_list->key);
        linked_list = linked_list->next;
    }

    // search(linked_list, 2);
    // search(linked_list, 100);
    linked_list = head;
    linked_list = push_after_key(linked_list, 0, 2);
    head = linked_list;
    printf("\n%d\n", linked_list->key);
    linked_list = linked_list->next;
    while (linked_list != head) {
        printf("%d\n", linked_list->key);
        linked_list = linked_list->next;
    }

    return 0;
}