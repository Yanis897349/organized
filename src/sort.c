/*
** EPITECH PROJECT, 2023
** organized
** File description:
** quicksort
*/

#include "include/my_list.h"
#include "organized.h"
#include <stddef.h>

static void fb_split(linked_list_t *head, linked_list_t **front_ref,
    linked_list_t **back_ref)
{
    linked_list_t *fast = NULL;
    linked_list_t *slow = NULL;

    slow = head;
    fast = head->next;
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *front_ref = head;
    *back_ref = slow->next;
    slow->next = NULL;
}

static linked_list_t *merge_back(linked_list_t *a, linked_list_t *b,
    int (*cmp)(), int is_reverse)
{
    linked_list_t *result = NULL;

    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;
    if (cmp(a, b, is_reverse)) {
        result = a;
        result->next = merge_back(a->next, b, cmp, is_reverse);
    } else {
        result = b;
        result->next = merge_back(a, b->next, cmp, is_reverse);
    }
    return result;
}

void merge_sort(linked_list_t **head_ref, int (*cmp)(), int is_reverse)
{
    linked_list_t *head = *head_ref;
    linked_list_t *a = NULL;
    linked_list_t *b = NULL;

    if ((head == NULL) || (head->next == NULL))
        return;
    fb_split(head, &a, &b);
    merge_sort(&a, cmp, is_reverse);
    merge_sort(&b, cmp, is_reverse);
    *head_ref = merge_back(a, b, cmp, is_reverse);
}
