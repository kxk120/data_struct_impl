/**
 * Implement sequence list of <<大话设计模式>> 3rd charpter.
 * Author : kongxiangkun
 * Data   : 2014.01.08
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "seq_list.h"

/**
 * Function defination of sequence list.
 * Include:
 * 1. Initialize list.          O(1)
 * 2. Get length of seq list.   O(1)
 * 3. Empty list.               O(1)
 * 4. Insert element to list.   O(n)(Not recommand)
 * 5. Delete element from list. O(n)(Not recommand)
 * 6. Fetch any element.        O(1)
 * 7. Destory list.             O(1)
 */

bool
init_list(seq_list *s_list,
          const int element_size)
{
    s_list = (seq_list *) malloc(sizeof(seq_list));
    if (s_list == NULL)
        return false;

    /* Allocate a fix memory! */
    s_list->data = (unsigned char *) malloc(ELEMENT_NUM_MAX * element_size);
    if (s_list->data == NULL)
        return false;

    memset(s_list->data, 0, ELEMENT_NUM_MAX * element_size);
    s_list->element_size = element_size;
    s_list->length = 0;

    return true;
}

int 
get_list_len(seq_list *const s_list)
{
    if (s_list == NULL)
        return -1;

    return s_list->length;
}

void
cleanup_list(seq_list *const s_list)
{
    if (s_list == NULL || s_list->data == NULL)
        return ;

    memset(s_list->data, 0, s_list->length * s_list->element_size);
    s_list->length = 0;

    return ;
}

static bool 
check_ins_del_func_param(seq_list *const s_list,
                         const void *const element,
                         const int location)
{
    /* Check 2 params */
    if (s_list == NULL || element == NULL)
        return false;

    /* Check last param location */
    if (location < 0 || location >= ELEMENT_NUM_MAX)
        return false;

    /* Check list->data domain */
    if (s_list->data == NULL)
        return false;

    /* Check list->element_size domain */
    if (s_list->element_size <= 0)
        return false;

    /* Check list->length domain */
    if (s_list->length < location || s_list->length >= ELEMENT_NUM_MAX)
        return false;

    return true;
}

bool
insert_list_element( seq_list *const s_list,
                const void *const element,
                const int location)
{
    /* Check params */
    if (check_ins_del_func_param(s_list, element, location) == false)
        return false;

    /* Calculate insert location */
    char *p_insert = (char *) (s_list->data + (s_list->element_size * location));

    /* Element move backward */
    memcpy( p_insert + s_list->element_size, 
            p_insert, 
            (s_list->length - location) * s_list->element_size);

    /* Insert element */
    memcpy(p_insert, element, s_list->element_size);

    s_list->length++;

    return true;
}

bool
delete_list_element( seq_list *const s_list,
                const int location)
{
    if (s_list == NULL)
        return false;

    if (location < 0 || location > ELEMENT_NUM_MAX)
        return false;

    /* Calculate delete location and get element we want delete */
    char *element = (char *) (s_list->data + (s_list->element_size * location));

    /* Element move forward */
    memcpy( element,
            element + s_list->element_size, 
            (s_list->length - location - 1) * s_list->element_size);

    s_list->length--;

    return true;
}

bool
fetch_list_element(seq_list *const s_list,
              void *element,
              const int location)
{
    if (s_list == NULL)
        return false;

    if (location < 0 || location > ELEMENT_NUM_MAX)
        return false;

    element = (void *) (s_list->data + location * s_list->element_size);

    return true;
}

void
destory_list(seq_list *const s_list)
{
    if (s_list != NULL) {
        if (s_list->data != NULL)
            free(s_list->data);

        free(s_list);
    }
}
