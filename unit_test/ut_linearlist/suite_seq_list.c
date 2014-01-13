/**
 *
 */
#include "suite_seq_list.h"

/* 包含被测试函数的头文件 */
#include "../../linear_list/seq_list.h"


/**
 * init_lsit原型: 
 *      bool init_list(seq_list *s_list, const int element_size)
 *
 * init_list函数检查说明:
 *      1. element_size的有效值是正整数.
 *      2. 当element_size输入无效参数时, 返回值为NULL.
 */ 
static void test_init_list(void) 
{
        seq_list *ps_list = NULL;
        int element_size = 0;

        /* case 1: element_size = 0 */
        element_size = 0;
        ps_list = init_list(element_size);
        CU_ASSERT_PTR_NULL(ps_list);

        /* case 2: element_size < 0 */ 
        element_size = -1;
        ps_list = init_list(element_size);
        CU_ASSERT_PTR_NULL(ps_list);

        /* case 3: element_size > 0 */
        element_size = 1;
        ps_list = init_list(element_size);
        CU_ASSERT_PTR_NOT_NULL(ps_list);
        CU_ASSERT_EQUAL(ps_list->element_size, element_size);
        CU_ASSERT_EQUAL(ps_list->length, 0);
}

static void test_get_list_len(void)
{
}

static void test_cleanup_list(void)
{
}

static void test_insert_list_element(void)
{
}

static void test_delete_list_element(void)
{
}

static void test_fetch_list_element(void)
{
}

static void test_destory_list(void)
{
}

static CU_TestInfo test_cases[] = {
        { "test init_list"          , test_init_list },        
        { "test get_list_len"       , test_get_list_len},
        { "test cleanup_list"       , test_cleanup_list},
        { "test insert_list_element", test_insert_list_element},
        { "test delete_list_element", test_delete_list_element},
        { "test fetch_list_element" , test_fetch_list_element},
        { "test destory_list"       , test_destory_list},
        /* Add test case here */
        CU_TEST_INFO_NULL,
};

static int init_suite(void)
{
        return CUE_SUCCESS;
}

static int cleanup_suite(void)
{
        return CUE_SUCCESS;
}

static CU_SuiteInfo suites[] = {
        { "sequence list test suite", init_suite, cleanup_suite, test_cases },
        CU_SUITE_INFO_NULL,
};

void add_seq_list_suite(void)
{
        CU_ErrorCode error = CU_register_suites(suites);
        if (error != CUE_SUCCESS)
                report_suite_reg_error(error, __func__);

        return ;
}
