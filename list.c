#include <stdio.h>
#include <stdlib.h>
//#include "../h/lexer.h"
#include "../h/list.h"

List *initialisation(void) {
    List *liste = (List*)malloc(sizeof(*liste));
    Element *element = (Element*)malloc(sizeof(*element));

    if ( liste == NULL ||element == NULL ) {
        exit(EXIT_FAILURE);
    }
    token *prems = (token*)malloc(sizeof(*prems));
    prems->content = "begin";

    element->el = prems;
    element->next = NULL;
    liste->premier = element;

    return liste;
}

//Insert at the end of the List liste an element
//containing any also passed in argument of the function
void insert_at_the_end(List *liste, token *any) {
    Element *newEl = (Element*)malloc(sizeof(Element*));
    newEl->el = any;
    newEl->next = NULL;
    //printf("%s\n", newEl->el->content);

    if ( liste == NULL ||newEl == NULL) {
        exit(EXIT_FAILURE);
    }
    
    Element *current = liste->premier;

    while(current->next != NULL) {
        current = current->next;
    }

    current->next = newEl;
}

//Display the Liste liste. 
void display_list(List *liste) {
   if (liste == NULL) {
      exit(EXIT_FAILURE);
   }

  Element *current = liste->premier; 
  //printf("%s\n", current->next->el->content);
  while ( current != NULL) {
      printf("%s\t", current->el->content);
      current = current->next;
  }
}
