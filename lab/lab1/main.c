#include "linked_list.h"

int main(void) {
    node *head = linked_list_init();

    char *string;
    printf("%d\n", linked_list_size(head));

    linked_list_append(head, 1);
    linked_list_append(head, 3);
    linked_list_append(head, 7);

    string = linked_list_tostring(head);
    puts(string);
    linked_list_append(head, 101);

    string = linked_list_tostring(head);
    puts(string);

    printf("%d\n", linked_list_size(head));
    linked_list_free(head);

    head = linked_list_init();
    linked_list_append(head, 1);
    linked_list_append(head, 2);
    linked_list_append(head, 3);
    linked_list_insert(head, 5, 2);
    linked_list_insert(head, 6, 2);
    puts(linked_list_tostring(head)); // '1 2 6 5 3

    linked_list_insert(head, 999, 999);
    printf("%d\n", linked_list_size(head)); // 5
    puts(linked_list_tostring(head)); // '1 2 6 5 3

    linked_list_delete(head, 2);
    puts(linked_list_tostring(head)); // '1 2 5 3

    linked_list_delete(head, -1);
    puts(linked_list_tostring(head)); // '1 2 5 3

    linked_list_delete(head, 3);
    printf("%d\n", linked_list_size(head)); // 1 2 5

    printf("start\n");
    linked_list_append(head, 2); // 1 2 5 2
    linked_list_remove(head, 2);
    puts(linked_list_tostring(head)); // 1 5 2
    linked_list_remove(head, 2);
    puts(linked_list_tostring(head)); // 1 5
    linked_list_remove(head, -1);
    puts(linked_list_tostring(head)); // 1 5
    linked_list_remove(head, 1);
    linked_list_remove(head, 5);  // Head -> Null
    printf("%d\n", linked_list_size(head)); // 0

    linked_list_append(head, 1);
    linked_list_append(head, 3);
    linked_list_append(head, 3);
    linked_list_append(head, 7); // 1 3 3 7
    linked_list_remove_all(head, 3); // 1 7
    puts(linked_list_tostring(head)); // 1 7
    linked_list_remove_all(head, 1); // 1 7
    puts(linked_list_tostring(head)); // 7
    linked_list_remove_all(head, 7); // 1 7
    printf("%d\n", linked_list_size(head)); // 0

    linked_list_append(head, 1);
    linked_list_append(head, 3);
    linked_list_append(head, 3);
    linked_list_append(head, 7); // 1 3 3 7

    printf("%d\n", linked_list_get(head, 0));
    printf("%d\n", linked_list_get(head, 1));
    printf("%d\n", linked_list_get(head, 2));
    printf("%d\n", linked_list_get(head, 3));
    printf("%d\n", linked_list_get(head, -1));
    printf("%d\n", linked_list_get(head, 8));

    printf("%d\n", linked_list_search(head, 3));
    printf("%d\n", linked_list_search(head, 7));
    printf("%d\n", linked_list_search(head, 11));

    node *all = linked_list_search_all(head, 3);
    puts(linked_list_tostring(all));

    all = linked_list_search_all(head, 13);
    printf("%d\n", linked_list_size(all));

//    perror()

    return 0;
}