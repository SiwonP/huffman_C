#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List *initialisation(void) {
    List *liste = (List*)malloc(sizeof(*liste));

    if ( liste == NULL ) {
        exit(EXIT_FAILURE);
    }

    return liste;
}

//Insert at the end of the List liste an element
//containing any also passed in argument of the function
void insert_at_the_end(List *liste) {
    List *current = liste;

    if ( liste == NULL ) {
        exit(EXIT_FAILURE);
    }
    
    while(current->next != NULL) {
        current = current->next;
    }

}

//Display the Liste liste. 
void display_list(List *liste) {
    List *current = liste;
   if (liste == NULL) {
      exit(EXIT_FAILURE);
   }

  while ( current != NULL) {
      current = current->next;
  }
}
