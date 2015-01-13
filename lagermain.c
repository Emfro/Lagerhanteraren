#include <string.h>
#include <stdlib.h>
#include "lagerhantering.h"

/**
@file lagermain.c
@author Axel Bostrom
@author Emil Frojd
@brief Creates a databases and ask the user what she would like to do.
 */

/**
@brief Runs the program and calls funcitons from the headerfile lagerhantering.h
@return always 0
 */
int main() {
  bool cont = true;
  db_t database = malloc(sizeof(struct db_t));
  database->amount = 0;
  db_t backup;
  int i = 0;
  while (cont) { 
    print_menu();
    switch (ask_char_question("What will we be doing today?", "AaRrEeUuPpQq")){
      // Add
    case 'a':
      puts("You chose 'Add'");
      if (i > 0) free_db(backup);
      backup = db_copy(database);
      i++;
      add_item(database);
      break;

      // Remove
    case 'r':
      puts("You chose 'Remove'");
      if (i > 0) free_db(backup);          
      backup = db_copy(database);
      i++;
      remove_item(database);
      break;
      
      // Edit
    case 'e':
      puts("You chose 'Edit'");
      if (i > 0) free_db(backup);
      backup = db_copy(database);
      i++;
      edit_item(database);
      break;
      
      // Undo
    case 'u':
      puts("You chose 'Undo'");
      if (i > 0) free_db(database);
      database = db_copy(backup);
      i++;
      // backup = db_copy(db1);
      break;
      
      // Print
    case 'p':
      puts("You chose 'Print'");
      print_db(database, 1);
      break;
      
      // Quit
    case 'q':
      if (ask_char_question("Do you wish to exit the program?", "YyNn") == 'y') {
	puts("Goodbye!");
	cont  = false;
	free_db(database);
	if(i > 0){
	  free_db(backup);
	}
	/*	if(db1 != NULL){
                free_db(db1);
                }
                else
                free(db1);
                if (backup != NULL) {
                free_db(backup);
                }
                else if(backup == NULL){
                free(backup);
                }*/ 
      }
      break;
    default:
      puts("Did not enter any valid command, please try again.\n");
    }
  }
  return 0;
}
