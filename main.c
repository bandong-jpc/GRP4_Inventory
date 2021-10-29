#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "add & search.c"

void filecheck();

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

    scanf("%c", &option);

    switch (option)
    {
    case 'a':
      /* code */
      break;
    case 'b':
      /* code */
      break;
    case 'c':
      /* code */
      break;
    case 'd':
      search();
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

void filecheck(){
  //open file to read
  FILE *fpointer = fopen("Inventory.csv", "r+");
  

  //check if file exists. if not, create a new file with no content
  if(!fpointer){
    fclose(fpointer); //close current pointer to file
    fpointer = fopen("Inventory.csv", "w"); //open new file for writing
    printf("\nInventory.csv DOES NOT EXISTS. CREATING NEW FILE. \n");
    fprintf(fpointer, "", "");
  }
  

  //close file to read
  fclose(fpointer);
}
