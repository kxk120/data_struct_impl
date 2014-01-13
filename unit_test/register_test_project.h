#ifndef REGISTER_TEST_PROJECT_H_
#define REGISTER_TEST_PROJECT_H_

#include "CUnit/Automated.h"
#include "CUnit/Console.h"

/**
 * 所有测试suite只需要暴露一个接口给主注册函数,那就是添加suite的函数
 *
 * 添加测试suite的步骤:
 * 1. 添加对应suite的头文件, 该头文件可以只包含添加suite的函数.
 * 2. 在Step 2中的函数指针数组中添加步骤1中的函数.
 */ 

/* Step 1 */
/* Include all header file of test suites */
#include "ut_linearlist/suite_seq_list.h"

/* Step 2 */
static void (*add_suites_func[])(void) = {
        add_seq_list_suite,
        /** 
         * !!注意!! 在这里添加函数, 要保证添加的函数的返回
         * 值和参数都是void 
         **/

        /* 请不要改变或删除NULL, 它必须要作为最后一个值. */
        NULL,
};

#endif /* REGISTER_TEST_PROJECT_H_ */
