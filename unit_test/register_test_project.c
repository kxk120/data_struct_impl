/**
 * The whole test project entry. There is mainly 2 things to do.
 * 1. Add all suites to the test registry.
 * 2. Start test and generate result file to "result" folder.
 *
 * Author : kongxiangkun
 * Date   : 2014.01.10
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
