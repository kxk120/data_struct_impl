#ifndef SEQ_LIST_H_
#define SEQ_LIST_H_

/**
 * This struct is a sequence list that max length is ELEMENT_NUM_MUX.
 *
 * Note:
 * Data element is not necessarily char type, it can be
 * any struct type.
 */
typedef struct {
    unsigned char *data;    /* store all data element */
    int element_size;       
    int length;             /* length of list */
} seq_list;

#define ELEMENT_NUM_MAX (4096)

#endif /*SEQ_LIST_H_*/
