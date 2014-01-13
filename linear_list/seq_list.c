/**
 * 该文件是<<大话数据结构>>第三章中顺序存储的代码实现.
 *
 * 作者 : 孔祥堃(kongxiangkun)
 * 日期 : 2014.01.08
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "seq_list.h"

/**
 * 有以下expose的函数:
 *    函数名                    时间复杂度
 * 1. Initialize list.          O(1)
 * 2. Get length of seq list.   O(1)
 * 3. Empty list.               O(1)
 * 4. Insert element to list.   O(n)(Not recommand)
 * 5. Delete element from list. O(n)(Not recommand)
 * 6. Fetch any element.        O(1)
 * 7. Destory list.             O(1)
 */

bool init_list( seq_list *s_list,
                const int element_size)
{
        s_list = (seq_list *) malloc(sizeof(seq_list));
        if (s_list == NULL)
                return false;

        /** 
         * 始终为data域分配固定元素个数的内存
         * 当然,具体多大还要看单个元素的大小.
         */
        s_list->data = (unsigned char *) malloc(ELEMENT_NUM_MAX * element_size);
        if (s_list->data == NULL)
                return false;

        memset(s_list->data, 0, ELEMENT_NUM_MAX * element_size);
        s_list->element_size = element_size;
        s_list->length = 0;

        return true;
}

int get_list_len(seq_list *const s_list)
{
        if (s_list == NULL)
                return -1;

        return s_list->length;
}

void cleanup_list(seq_list *const s_list)
{
        if (s_list == NULL || s_list->data == NULL)
                return ;

        memset(s_list->data, 0, s_list->length * s_list->element_size);
        s_list->length = 0;

        return ;
}

static bool check_ins_del_func_param(seq_list *const s_list,
                                const void *const element,
                                const int location)
{
        /* 检查前两个参数 */
        if (s_list == NULL || element == NULL)
                return false;

        /* 检查location参数 */
        if (location < 0 || location >= ELEMENT_NUM_MAX)
                return false;

        /* 检查list->data域 */
        if (s_list->data == NULL)
                return false;

        /* 检查list->element_size域 */
        if (s_list->element_size <= 0)
                return false;

        /* 检查list->length域 */
        if (s_list->length < location || s_list->length >= ELEMENT_NUM_MAX)
                return false;

        return true;
}

bool insert_list_element(seq_list *const s_list,
                        const void *const element,
                        const int location)
{
        /* 检查参数 */
        if (check_ins_del_func_param(s_list, element, location) == false)
                return false;

        /* 计算插入元素的位置 */
        char *p_insert = (char *) (s_list->data + (s_list->element_size * location));

        /* 自插入点以后的元素全部向后移一个元素单位 */
        memcpy( p_insert + s_list->element_size, 
                p_insert, 
                (s_list->length - location) * s_list->element_size);

        /* 插入元素 */
        memcpy(p_insert, element, s_list->element_size);

        /* 更新list长度 */
        s_list->length++;

        return true;
}

bool delete_list_element(seq_list *const s_list,
                        const int location)
{
        if (s_list == NULL)
                return false;

        if (location < 0 || location > ELEMENT_NUM_MAX)
                return false;

        /* 获得要删除元素的位置 */
        char *element = (char *) (s_list->data + (s_list->element_size * location));

        /* 自要删除元素的后一个元素开始,所有元素向前移一个元素单位 */
        memcpy( element,
                element + s_list->element_size, 
                (s_list->length - location - 1) * s_list->element_size);

        /** 
         * 注意,这里并没有对原list最后一个元素进行处理,因为更新了长度
         * 所以可以不用管它.
         **/

        /* 更新list长度 */
        s_list->length--;

        return true;
}

bool fetch_list_element(seq_list *const s_list,
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

void destory_list(seq_list *const s_list)
{
        if (s_list != NULL) {
                if (s_list->data != NULL)
                        free(s_list->data);

                free(s_list);
        }
}
