/*
** EPITECH PROJECT, 2023
** organized
** File description:
** quicksort
*/

#include "include/my_list.h"
#include "organized.h"
#include <stddef.h>

linked_list_t *get_tail(linked_list_t *head)
{
    linked_list_t *tmp = head;

    while (tmp != NULL && tmp->next != NULL)
        tmp = tmp->next;
    return tmp;
}

static linked_list_t *arrange_around_pivot(linked_list_t *head,
    linked_list_t *tail, int (*cmp)(), int is_reverse)
{
    linked_list_t *pivot = head;
    linked_list_t *front = head;
    void *tmp = NULL;

    while (front != NULL && front != tail) {
        if (cmp(front, tail, is_reverse)) {
            pivot = head;
            tmp = head->data;
            head->data = front->data;
            front->data = tmp;
            head = head->next;
        }
        front = front->next;
    }
    tmp = head->data;
    head->data = tail->data;
    tail->data = tmp;
    return pivot;
}

void quick_sort(linked_list_t *head, linked_list_t *tail, int (*cmp)(), int
    is_reverse)
{
    linked_list_t *pivot = NULL;

    if (head == tail)
        return;
    pivot = arrange_around_pivot(head, tail, cmp, is_reverse);
    if (pivot != NULL && pivot->next != NULL)
        quick_sort(pivot->next, tail, cmp, is_reverse);
    if (pivot != NULL && head != pivot)
        quick_sort(head, pivot, cmp, is_reverse);
}
