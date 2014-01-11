#ifndef REGISTER_TEST_PROJECT_H_
#define REGISTER_TEST_PROJECT_H_

#include "CUnit/Automated.h"

/**
 * If you want to add a suite, you should do:
 * Step 1. Add a header file that is your one of data struct implementation. Like below Step 1.
 *         There is declaration of adding suites function.
 * Step 2. Add a adding suites function to array. Like below Step 2.
 */ 

/* Step 1 */
/* Include all header file of test suites */
#include "ut_linearlist/suite_seq_list.h"

/* Step 2 */
static void (*add_suites_func[])(void) = {
        add_seq_list_suite,
        /* Add function pointer here */
};

#endif /* REGISTER_TEST_PROJECT_H_ */
