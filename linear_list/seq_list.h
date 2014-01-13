#ifndef SEQ_LIST_H_
#define SEQ_LIST_H_

/**
 * This struct is a sequence list that max length is ELEMENT_NUM_MUX.
 *
 * Note:
 * Data element is not necessarily char type, it can be any struct type.
 */
typedef struct {
        unsigned char *data;    /* store all data element sequentially */
        int element_size;       
        int length;             /* length of list */
} seq_list;

#define ELEMENT_NUM_MAX (4096)

/* Export function */
extern seq_list* init_list(const int);
extern int  get_list_len(seq_list *const);
extern void cleanup_list(seq_list *const);
extern bool insert_list_element(seq_list *const, const void *const, const int);
extern bool delete_list_element(seq_list *const, const int);
extern bool fetch_list_element(seq_list *const, void *, const int);
extern void destory_list(seq_list *const);

#endif /*SEQ_LIST_H_*/
