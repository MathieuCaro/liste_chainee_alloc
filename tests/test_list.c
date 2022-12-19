#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "../linked_list.h"

void test_add_index(void)
{
    linked_list *test_add_index = new_element(10, NULL);
    int list_value[] = {20, 40, 50, 60, 70};
    int new_list_value[] = {20, 30, 40, 50, 60, 70};
    for (int i = 0; i < 5; i++)
    {
        push(test_add_index, list_value[i], NULL);
    }
    add_index(test_add_index, 30, 3, NULL);
    test_add_index = test_add_index->next;
    for (int i = 0; i < 5; i++)
    {
        CU_ASSERT(test_add_index->size == new_list_value[i]);
        test_add_index = test_add_index->next;
    }
    list_free(test_add_index);
}

void test_pop(void)
{
    linked_list *test_pop = new_element(5, NULL);
    int liste_value[] = {12, 25, 9, 45, 4};
    for (int i = 0; i < 5; i++)
    {
        push(test_pop, liste_value[i], NULL);
    }
    linked_list *pt = test_pop;
    CU_ASSERT(pt->size == 5);
    for (int i = 0; i < 5; i++)
    {
        pt = pt->next;
        CU_ASSERT(pt->size == liste_value[i]);
    }
    pt = pt->previous;
    pop(test_pop);

    CU_ASSERT(pt->size == 45);
    pt = pt->previous;
    pop(test_pop);

    CU_ASSERT(pt->size == 9);
    list_free(test_pop);
}

void test_list_search(void)
{
    linked_list *list_search_ = new_element(5, NULL);
    int liste_value[] = {12, 25, 9, 45, 4};
    for (int i = 0; i < 5; i++)
    {
        push(list_search_, liste_value[i], NULL);
    }
    linked_list *pt = list_search_;
    CU_ASSERT(pt->size == 5);
    for (int i = 0; i < 5; i++)
    {
        pt = pt->next;
        CU_ASSERT(pt->size == liste_value[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        pt = pt->previous;
    }
    printf("value   %d\n", pt->size);
    CU_ASSERT(list_search(pt, 9) == 9);
}

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

int main()
{
    CU_pSuite pSuite = NULL;

    /* initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* add a suite to the registry */
    pSuite = CU_add_suite("Suite_1", init_suite, clean_suite);
    if (NULL == pSuite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* add the tests to the suite */
    if (
        NULL == CU_add_test(pSuite, "test add index", test_add_index) ||
        NULL == CU_add_test(pSuite, "test pop", test_pop) ||
        NULL == CU_add_test(pSuite, "test list search", test_list_search))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}