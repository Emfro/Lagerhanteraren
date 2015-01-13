#include <string.h>
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <stdlib.h>
#include "lagerhantering.h"
/**
@file unittests.c
@author Axel Bostrom
@author Emil Frojd
@brief Tests for Lagerhanteraren
 */
/**
@brief Initialies suite 1
@return always 0
 */
int init_suite_1(void)
{
  return 0;
}

/**
@brief Cleans suite 1
@return always 0
 */
int clean_suite_1(void)
{
  return 0;
}

/**
@brief Tests the funcion equal_products
 */
void testLAGER_equal_products(void)
{
  struct product_t product1;
  product1.name = "Apple";
  product1.description = "A fruit";
  product1.place = "A01";
  product1.price = 12;
  product1.amount = 10;
  
  struct product_t product2;
  product2.name = "Cookie";
  product2.description = "Pastry";
  product2.place = "B02";
  product2.price = 20;
  product2.amount = 7;
  CU_ASSERT(equal_products(product1, product1) == true);
  CU_ASSERT(equal_products(product1, product2) == false);
}
/**
@brief Tests the function add_to_db
 */
void testLAGER_add_to_db(void) 
{
  db_t db1 = malloc(sizeof(struct db_t));
  struct product_t product1;
  product1.name = "Apple";
  product1.description = "A fruit";
  product1.place = "A01";
  product1.price = 12;
  product1.amount = 10;
  
  struct product_t product2;
  product2.name = "Cookie";
  product2.description = "Pastry";
  product2.place = "B02";
  product2.price = 20;
  product2.amount = 7;
  // Test add_to_db instead of add_item
  add_to_db(db1, product1);
  add_to_db(db1, product2);

  CU_ASSERT(equal_products(db1->product[0], product1));
  CU_ASSERT(equal_products(db1->product[1], product2));
}
/**
@brief Tests the funcion equal_databases
 */
void testLAGER_equal_databases(void)
{
  db_t db1 = malloc(sizeof(struct db_t));
  db_t db2 = malloc(sizeof(struct db_t));

  struct product_t product1;
  product1.name = "Apple";
  product1.description = "A fruit";
  product1.place = "A01";
  product1.price = 12;
  product1.amount = 10;
  
  add_to_db(db1, product1);
  add_to_db(db2, product1);

  CU_ASSERT(equal_databases(db1, db2) == true);
}
/**
@brief Tests the function position_of_product
 */
void testLAGER_position_of_product(void)
{
  db_t db1 = malloc(sizeof(struct db_t));
  struct product_t product1;
  product1.name = "Apple";
  product1.description = "A fruit";
  product1.place = "A01";
  product1.price = 12;
  product1.amount = 10;
  
  struct product_t product2;
  product2.name = "Cookie";
  product2.description = "Pastry";
  product2.place = "B02";
  product2.price = 20;
  product2.amount = 7;
 
  add_to_db(db1, product1);
  add_to_db(db1, product2);
  
  CU_ASSERT(position_of_product(db1, product1.name) == 0);
  CU_ASSERT(position_of_product(db1, product2.name) == 1);
}
/**
@brief Tests the function place_exist
 */
void testLAGER_place_exist(void)
{
  db_t db1 = malloc(sizeof(struct db_t));
  struct product_t product1;
  product1.name = "Apple";
  product1.description = "A fruit";
  product1.place = "A01";
  product1.price = 12;
  product1.amount = 10;
  
  struct product_t product2;
  product2.name = "Cookie";
  product2.description = "Pastry";
  product2.place = "B02";
  product2.price = 20;
  product2.amount = 7;
 
  add_to_db(db1, product1);
  add_to_db(db1, product2);
  
  CU_ASSERT(place_exist(db1, product1.place) == 0);
  CU_ASSERT(place_exist(db1, product2.place) == 1);
}

/**
@brief Tests the function db_copy and looks if it is equal to the database it copies.
*/
void testLAGER_db_copy(void) {
  db_t db1 = malloc(sizeof(struct db_t));
  CU_ASSERT(equal_databases(db_copy(db1),db1));
}

/**
@brief Tests the most crucial functions, like add, all varieties of edit before removing. Uses test.input as an automated user
 */
void testLAGER_scenario(void) {
  db_t db1 = malloc(sizeof(struct db_t));
  add_item(db1);
  CU_ASSERT(position_of_product(db1, "Apple\n") == 0);
  CU_ASSERT(place_exist(db1, "A01\n") == 0);
  edit_item(db1);
  CU_ASSERT(place_exist(db1, "B3\n") == 0);
  edit_item(db1);
  CU_ASSERT(strcmp(db1->product[0].description, "A round ripe fruit\n") == 0);
  edit_item(db1);
  CU_ASSERT(db1->product[0].price == 2);
  edit_item(db1);
  CU_ASSERT(db1->product[0].amount == 5);
  edit_item(db1);
  CU_ASSERT(position_of_product(db1, "Orange\n") == 0);
  remove_item(db1);
  CU_ASSERT(position_of_product(db1, "Orange\n") == -1);
}

/**
@brief Main function that runs the tests functions
@return error if it occurs
 */
int main()
{
  CU_pSuite pSuite1 = NULL;

  /* initialize the CUnit test registry */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* add a suites to the registry */
  pSuite1 = CU_add_suite("Functions Suite", init_suite_1, clean_suite_1);
  if (NULL == pSuite1)
    {
      CU_cleanup_registry();
      return CU_get_error();
    }

  /* add the tests to the suites */
  if (
      (NULL == CU_add_test(pSuite1, "test of lager_equal_products()", testLAGER_equal_products)) ||
      (NULL == CU_add_test(pSuite1, "test of lager_add_to_db()", testLAGER_add_to_db)) ||
      (NULL == CU_add_test(pSuite1, "test of lager_equal_databases()", testLAGER_equal_databases)) ||
      (NULL == CU_add_test(pSuite1, "test of lager_position_of_product()", testLAGER_position_of_product)) ||
      (NULL == CU_add_test(pSuite1, "test of lager_place_exist()", testLAGER_place_exist)) ||
      (NULL == CU_add_test(pSuite1, "test of lager_db_copy()", testLAGER_db_copy)) ||
      (NULL == CU_add_test(pSuite1, "test of lager_scenario()", testLAGER_scenario))
      )
    {
      CU_cleanup_registry();
      return CU_get_error();
    }

  /* Run all tests using the CUnit Basic interface */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();
  return CU_get_error();
}


