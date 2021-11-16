#include<stdio.h>
#include<stdlib.h>

typedef struct object{
    int key;
    struct object *next;
}object;

//functions
object * push_front(object *linked_list, int key);
object * push_back(object *linked_list, int key);
object * delete_front(object *linked_list);
object * delete_back(object *linked_list);
object * delete_middle(object *linked_list, int key);
void search(object *linked_list, int key);

object * push_front(object *linked_list, int key) {
    object *new_object = (object *)malloc(sizeof(object));
    if (linked_list == NULL) {
        linked_list = new_object;
        linked_list->key = key;
        linked_list->next = NULL;
    }

    else {
        new_object->key = key;
        new_object->next = linked_list;
        linked_list = new_object;
    }

    return linked_list;
}

object * push_back(object *linked_list, int key) {
    object *new_object = (object *)malloc(sizeof(object));
    new_object->key = key;
    new_object->next = NULL;
    object *head = linked_list;

    if (linked_list == NULL) {
        linked_list = new_object;
        linked_list->next = NULL;
    }

    else {
        while (linked_list->next != NULL) {
            linked_list = (linked_list->next);
        }
    }

    linked_list->next = new_object;
    return head;
}

object * delete_front(object *linked_list) {
    if (linked_list == NULL) {
        printf("List is empty\n");
    }

    else {
        linked_list = linked_list->next;
    }

    return linked_list;
}

object * delete_back(object *linked_list) {
    object *head = linked_list;
    if (linked_list == NULL) {
        printf("List is empty\n");
    }

    else {
        while((linked_list->next)->next != NULL) {
            linked_list = linked_list->next;
        }
        
        linked_list->next = NULL;
    }

    return head;
}

object * delete_middle(object *linked_list, int key) {
    object *head = linked_list;
    int ans = 0;

    if (linked_list == NULL) {
        printf("List is empty\n");
    }

    else if (linked_list->key == key) {
        head = linked_list->next;
    }

    else {
        while(linked_list->next != NULL) {
            if ((linked_list->next)->key == key) {
                linked_list->next = (linked_list->next)->next;
                ans = 1;
                break;
            }

            linked_list = linked_list->next;
        }

        if (ans == 0) {
            printf("Element not present in the list\n");
        }
    }

    return head;
}

void search(object *linked_list, int key) {
    int ans = 0;
    if (linked_list == NULL) {
        printf("List is empty.\n");
    }

    else {
        while (linked_list != NULL) {
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
    object *linked_list;
    linked_list = NULL;
    linked_list = push_front(linked_list, 3);
    linked_list = push_front(linked_list, 7);
    linked_list = push_front(linked_list, 2);

    object *head = linked_list;
    // while(head != NULL) {
    //     printf("%d\n", head->key);
    //     head = (head->next);
    // }

    linked_list = push_back(linked_list, 9);
    linked_list = push_back(linked_list, 4);
    // head = linked_list;
    // while(head != NULL) {
    //     printf("%d\n", head->key);
    //     head = (head->next);
    // }

    // linked_list = delete_front(linked_list);
    // head = linked_list;
    // while(head != NULL) {
    //     printf("%d\n", head->key);
    //     head = (head->next);
    // }

    // linked_list = delete_back(linked_list);
    // head = linked_list;
    // while(head != NULL) {
    //     printf("%d\n", head->key);
    //     head = (head->next);
    // }

    //linked_list = delete_middle(linked_list, 9);
    // head = linked_list;
    // while(head != NULL) {
    //     printf("%d\n", head->key);
    //     head = (head->next);
    // }

    // search(linked_list, 10);
    //search(linked_list, 7);

    return 0;
}
