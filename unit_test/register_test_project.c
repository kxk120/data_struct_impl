/**
 * 该文件是整个测试工程的入口, 它主要完成两件工作.
 * 1. 添加所有测试suite到测试registry中.
 * 2. 开始运行test并生成结果文件.
 *
 * 作者 : 孔祥堃
 * 日期 : 2014.01.10
 */

#include <stdio.h>
#include "register_test_project.h"

static void add_all_suites()
{
        int i = 0;
        for ( ; add_suites_func[i] != NULL; i++)
                (*add_suites_func[i])();
}

int main(void)
{
        CU_pSuite p_suite = NULL;
        CU_ErrorCode error= CUE_SUCCESS;

        /* Initialize the CUnit test registry */
        if (CU_initialize_registry() != CUE_SUCCESS)
                return CU_get_error();

        /* Add all suites to registry */
        add_all_suites();

        CU_set_output_filename("data_struct_impl");
        CU_list_tests_to_file();

        /* Run tests and generate result xml file(data_struct_impl-Result.xml) */
        CU_automated_run_tests();

        CU_cleanup_registry();

        return 0;
}
