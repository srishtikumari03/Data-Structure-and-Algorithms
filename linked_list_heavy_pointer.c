#include<stdio.h>
#include<stdlib.h>

typedef struct object{
    int key;
    struct object *next;
}object;

void push_front(object **pointer_linked_list, int key) {
    object *new_object = (object *)malloc(sizeof(object));
    if ((*pointer_linked_list) == NULL) {
        (*pointer_linked_list) = new_object;
        (*pointer_linked_list)->key = key;
        (*pointer_linked_list)->next = NULL;
    }

    else {
        new_object->key = key;
        new_object->next = (*pointer_linked_list);
        (*pointer_linked_list) = new_object;
    }
}

void print_linked_list(object **pointer_linked_list) {
    while(*pointer_linked_list != NULL) {
        printf("%d\n", (*pointer_linked_list)->key);
        (*pointer_linked_list) = ((*pointer_linked_list)->next);
    }
}

int main() {
    object **pointer_linked_list;
    object *linked_list;
    linked_list = NULL;
    pointer_linked_list = &linked_list;

    push_front(pointer_linked_list, 3);
    push_front(pointer_linked_list, 7);
    push_front(pointer_linked_list, 2);
    print_linked_list(pointer_linked_list);

    return 0;
}
