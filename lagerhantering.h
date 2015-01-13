#ifndef LAGERHANTERING_H
#define LAGERHANTERING_H

#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

/**
@file lagerhantering.h
@author Axel Bostrom
@author Emil Frojd
@brief Header file containing the typedefinitions of structures and funktions.
 */

struct product_t {
  char* name;
  char* description;
  char* place;
  int price;
  int amount;
};
  
struct db_t {
  struct product_t* product;
  int amount;
};

typedef struct db_t* db_t;

/**
@brief Prints the welcome-screen.
 */
void print_menu();

/**
@brief Prints the choices.
 */
void print_edit();

/**
@brief Asks the user to enter a valid string for the current action being taken.
@param question the currently relevant piece of information
@param message the message which informs the user what is expected of her  
@return the name that the user gave to the given label
 */
char* ask_string_question(char* question, char* message);

/**
@brief Asks the user to enter a number.
@param question the kind of digit the user should give
@return the integer the user gave
 */
int ask_int_question(char* question);

/**
@brief Asks a question that can be answered with a string.
@param question a question the user should answer
@param alternative the alternatives the user should get
@return the answer the user gave as a lowercase letter
 */
char ask_char_question(char* question, char* alternative);

/**
@brief Prints the given product.
@param product the product to print
 */
void print_item(struct product_t product);

/**
@brief Adds the given product to the given database.
@param db the database to add the product in
@param product the product to put into the database
 */
void add_to_db(db_t db, struct product_t product);


/**
@brief Gives the position of the product with the given name in the given databse.
@param db the database to search through
@param name1 the name of a product to look for in the database
@return the position of the product with the given name in the database or -1 if no product has the given name
 */
int position_of_product(db_t db, char* name1);

/**
@brief Returns the place in the database where the product with the given name is placed.
@param db the database to search through
@param place1 the place to look for in the given database
@return the position of the product at the given place in the database or -1 if the place is available
 */
int place_exist(db_t db, char* place1);

/**
@brief Adds an item to the inventory.
@param db the databse where a pontentially product should be put into
 */
void add_item(db_t db);

/**
@brief Remove an item from the inventory
@param db the database to remove a product from
 */
void remove_item(db_t db);

/**
@brief Edit an item from the given inventory.
@param db the database to edit a product from
 */
void edit_item(db_t db);

/**
@brief Frees the whole memoryspace connected to the given inventory.
@param db the database to be freed
 */
void free_db(db_t db);

/**
@brief Returns a copy of the given inventory.
@param db the database to make a copy of
@return a copy of the given database
 */
db_t db_copy(db_t db);

/**
@brief Prints out the given database.
@param db the database to print
 */
void print_db(db_t db, int loop);

/**
@brief Return true if the two given products are equal.
@param p1 the first product to compare
@param p2 the second product compare
@return boolean wether the given products are equal or not.
 */
bool equal_products(struct product_t p1, struct product_t p2);

/**
@brief Returns true if the two given databases are equal.
@param db1 the first database to compare
@param db2 the second databse to compare
@return boolean wether the given databases are equal or not
 */
bool equal_databases(db_t db1, db_t db2);

/**
Runs the program
 */
int main();

#endif
