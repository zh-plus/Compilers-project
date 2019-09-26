#include "linked_list.h"

node *linked_list_init() {
    node *head = (node *) malloc(sizeof(node));
    head->count = 0;
    head->next = NULL;
    return head;
}

void linked_list_free(node *head) {
    node *cur = head;
    node *last;
    while (cur != NULL) {
        last = cur;
        cur = cur->next;
        free(last);
    }
}

char linked_list_string[0x10000];

char *linked_list_tostring(node *head) {
    node *cur = head->next;
    char *position;
    int length = 0;
    while (cur != NULL) {
        position = linked_list_string + length;
        length += sprintf(position, "%d", cur->value);
        cur = cur->next;
        if (cur != NULL) {
            position = linked_list_string + length;
            length += sprintf(position, "->");
        }
    }
    position = linked_list_string + length;
    length += sprintf(position, "%c", '\0');
    return linked_list_string;
}

int linked_list_size(node *head) {
    return head->count;
}

void linked_list_append(node *head, int val) {
    node *cur = head;
    node *new_node;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    new_node = (node *) malloc(sizeof(node));
    new_node->value = val;
    new_node->next = NULL;
    cur->next = new_node;
    head->count++;
}

/* your implementation goes here */

void linked_list_insert(node *head, int val, int index) {
    if (index > head->count || index < 0) {
        return;
    }

    node *cur = head;
    while (index--) {
        cur = cur->next;
    }

    head->count++;

    node *new_node = (node *) malloc(sizeof(node));;
    new_node->value = val;
    new_node->next = cur->next;
    cur->next = new_node;
}

void linked_list_delete(node *head, int index) {
    if (index >= head->count || index < 0) {
        return;
    }

    index++;

    node *cur = head, *last = head;
    while (index--) {
        last = cur;
        cur = cur->next;
    }

    head->count--;
    last->next = cur->next;
    free(cur);
}

void linked_list_remove(node *head, int val) {
    node *cur = head->next, *last = head;
    while (cur) {
        if (cur->value == val) {
            break;
        }

        last = cur;
        cur = cur->next;
    }

    if (cur && cur->value == val) {
        head->count--;
        last->next = cur->next;
        free(cur);
    }
}

void linked_list_remove_all(node *head, int val) {
    node *cur = head->next, *last = head, *next = NULL;
    while (cur) {
        if (cur->value == val) {
            last->next = cur->next;
            free(cur);
            cur = last->next;

            head->count--;
        } else{
            last = cur;
            cur = cur->next;
        }
    }
}

int linked_list_get(node *head, int index) {
    if (index >= head->count || index < 0) {
        return INT_MIN;
    }

    node *cur = head->next;
    while (index--) {
        cur = cur->next;
    }

    return cur->value;
}

int linked_list_search(node *head, int val) {
    int index = 0;
    node *cur = head->next;
    while (cur) {
        if (cur->value == val) {
            break;
        }
        cur = cur->next;
        index++;
    }

    if (cur && cur->value == val) {
        return index;
    } else {
        return -1;
    }
}

node *linked_list_search_all(node *head, int val) {
    node *result = linked_list_init();

    node *cur = head->next, *cur_result = result;
    node *new_node;
    for (int i = 0; i < head->count; ++i) {
        if(cur->value == val) {
            new_node = (node *) malloc(sizeof(node));
            new_node->value = i;
            new_node->next = NULL;

            cur_result->next = new_node;
            result->count++;

            cur_result = cur_result->next;
        }

        cur = cur->next;
    }

    return result;
}