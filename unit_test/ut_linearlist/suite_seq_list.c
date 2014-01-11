/**
 *
 */
#include "suite_seq_list.h"

/* Tested function's header file */
#include "../../linear_list/seq_list.h"


static void test_init_list(void) 
{
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
}

static int cleanup_suite(void)
{
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
