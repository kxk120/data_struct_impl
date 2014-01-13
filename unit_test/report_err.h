#ifndef REPORT_ERR_H_
#define REPORT_ERR_H_

#include "CUnit/CUError.h"
/**
 * 当添加一个suite出错时,返回的错误码一定是以下所列的一种:
 * CUE_SUCCESS
 * CUE_NOREGISTRY
 * CUE_NO_SUITENAME
 * CUE_DUP_SUITE
 * CUE_NOMEMORY
 * 
 * 具体请参考http://cunit.sourceforge.net/doc/managing_tests.html
 */
static void report_suite_reg_error(const CU_ErrorCode error, const char *message)
{
        switch (error) {
        case CUE_SUCCESS:
                fprintf(stdout, "%s->No error condition. Add suits Success!\n", message); break;
        case CUE_NOREGISTRY:
                fprintf(stderr, "%s->Test registry not initialized.\n"        , message); break;
        case CUE_NO_SUITENAME:
                fprintf(stderr, "%s->Required CU_Suite name not provided.\n"  , message); break;
        case CUE_DUP_SUITE:
                fprintf(stderr, "%s->Duplicate suite name not allowed.\n"     , message); break;
        case CUE_NOMEMORY:
                fprintf(stderr, "%s->Memory allocation failed.\n"             , message); break;
        default:
                break;/* imposible code */
        }

        return ;
}
#endif /* REPORT_ERR_H_ */

