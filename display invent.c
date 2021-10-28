#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"




void displayInven(){
	 char toUpdate[6];
	struct Node* head = NULL;
  item x;

	
  //File pointer
  FILE *fpointer = fopen("Inventory.csv", "r+");
  //line variable for reading line
  char line[255];
  
  char detail[50];
  int i = 0, pos = -1, entries=0;
  char confirm = 'x';
  //check for how many entries in the file
  while(!feof(fpointer)){
    fgets(line, 255, fpointer); 

    strcpy(detail, line);
    i=0;
   // Extract the first token
   char * token = strtok(detail, ",\"");
   // loop through the string to extract all other tokens
   while( token != NULL ) {
      
      strcpy(detail, token);
     
      token = strtok(NULL, ",\"");


      switch (i)
      {
      case 0:
        strcpy(x.id, detail);
        if (strcmp(detail, toUpdate) == 0)
        {
          pos=entries;
        }
        
        break;
      
      case 1:
        strcpy(x.description, detail);
        break;
      
      case 2:
        x.qty = atoi(detail);
        break;
      
      case 3:
        strcpy(x.exp, detail);
        break;
      
      case 4:
        x.price = atof(detail);
        break;
      default:
        break;
      }
      i++;
   }

    append(&head, x.id, x.description, x.qty, x.exp, x.price);
    entries++;
  }

  fclose(fpointer);
  
  printf("==========INVENTORY LIST==========\n");
  display(&head);
    
    return;  
}

	

int main()
{
  
  
  char option = 'x';

  do
  {
    printf("\n\nMAIN MENU");
    printf("\n[A] ADD INVENTORY ITEM");
    printf("\n[B] UPDATE INVENTORY ITEM");
    printf("\n[C] VIEW INVENTORY LIST");
    printf("\n[D] SEARCH INVENTORY LIST");
    printf("\n[E] DELETE INVENTORY ITEM");
    printf("\n[X] EXIT PROGRAM");

    printf("\n\nPLEASE INPUT CHOICE: ");

    scanf(" %c", &option);

    switch (option)
    {
    case 'a':
      /* code */
      break;
    case 'b':
      /* code */
      break;
    case 'c':
      displayInven();
      break;
    case 'd':
      /* code */
      break;
    case 'e':
      /* code */
      break;
    case 'x':
      break;

    default:
      printf("\n\nINVALID OPTION\n\n");
    }

  } while (
    option!='x'
  );
  
  return 0;
}