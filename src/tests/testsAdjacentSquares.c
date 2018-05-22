/* Deguerre Benjamin - 04/01/2015 */
/* Deguerre Benjamin - 04/01/2015 */

#include "AdjacentSquares.h"
#include "Square.h"
#include <CUnit/Basic.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int init_suite_success(void) { return 0; }

int clean_suite_success(void) { return 0; }

void test_1_AdjacentSquares(void)
{
  AS_AdjacentSquares *adjacentSquare = AS_createAdjacentSquares();
  CU_ASSERT(AS_getBonus(*adjacentSquare) == 0);
  CU_ASSERT(AS_getNumberOfPoints(*adjacentSquare) == 0);
  CU_ASSERT(AS_getLength(*adjacentSquare) == 0);
}

void test_2_AdjacentSquares(void)
{
  AS_AdjacentSquares *adjacentSquare = AS_createAdjacentSquares();
  S_SQUARE *square = S_createSquare();
  S_SQUARE *square2 = S_createSquare();
  S_defineSquare(square, "T1LD", 1);
  S_defineSquare(square2, "T2MD", 2);
  AS_addSquare(adjacentSquare, square);
  CU_ASSERT(AS_getBonus(*adjacentSquare) == 0);
  CU_ASSERT(AS_getNumberOfPoints(*adjacentSquare) == 2);
  CU_ASSERT(AS_getLength(*adjacentSquare) == 1);
  AS_addSquare(adjacentSquare, square);
  CU_ASSERT(AS_getBonus(*adjacentSquare) == 0);
  CU_ASSERT(AS_getNumberOfPoints(*adjacentSquare) == 4);
  CU_ASSERT(AS_getLength(*adjacentSquare) == 2);
  AS_addSquare(adjacentSquare, square2);
  CU_ASSERT(AS_getBonus(*adjacentSquare) == 2);
  CU_ASSERT(AS_getNumberOfPoints(*adjacentSquare) == 6);
  CU_ASSERT(AS_getLength(*adjacentSquare) == 3);
  AS_deleteSquare(adjacentSquare);
  CU_ASSERT(AS_getBonus(*adjacentSquare) == 0);
  printf("%d\n", AS_getBonus(*adjacentSquare));
  CU_ASSERT(AS_getNumberOfPoints(*adjacentSquare) == 4);
  printf("%d\n", AS_getNumberOfPoints(*adjacentSquare));
  CU_ASSERT(AS_getLength(*adjacentSquare) == 2);
  printf("%d\n", AS_getLength(*adjacentSquare));
}

void test_3_AdjacentSquares(void) {}

void test_4_AdjacentSquares(void) {}

void test_5_AdjacentSquares(void) {}

int test_AdjacentSquares(CU_pSuite pSuite)
{
  return (
      (NULL == CU_add_test(pSuite, "AS_createAdjacentSquares()",
                           test_1_AdjacentSquares)) ||
      (NULL ==
       CU_add_test(
           pSuite,
           "AS_addSquare(AS_AdjacentSquares *adjacentSquare, S_SQUARE *square)",
           test_2_AdjacentSquares)) ||
      (NULL == CU_add_test(pSuite, "S_defineSquare(c,b2MD) == 2 ",
                           test_3_AdjacentSquares)) ||
      (NULL == CU_add_test(pSuite, "S_defineSquare(c,b2MD) == MD",
                           test_4_AdjacentSquares)) ||
      (NULL == CU_add_test(pSuite, "S_defineSquare(c,b2MD) == MD",
                           test_5_AdjacentSquares)));
}

int main()
{

  CU_pSuite pSuite = NULL;

  /* initialisation du registre de test */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d’une suite de test */
  pSuite = CU_add_suite("Tests boite noire", init_suite_success,
                        clean_suite_success);
  if (NULL == pSuite)
  {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* ajout des tests à la suite de tests boite noire */
  if (test_AdjacentSquares(pSuite))
  {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Lancement des tests */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  printf("\n");
  CU_basic_show_failures(CU_get_failure_list());
  printf("\n\n");
}