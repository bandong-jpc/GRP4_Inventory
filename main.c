#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
#include "addinventory.c"

void filecheck();
void update();

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
      add();
      break;
    case 'b':
      update();
      break;
    case 'c':
      /* code */
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

void update(){
  char toUpdate[6];
  struct Node* head = NULL;
  item x;


  printf("\n\nENTER ITEM ID TO UPDATE: ");
  scanf(" %s", toUpdate);

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

  if(pos == -1) printf("\nITEM NOT FOUND! RETURNING TO MAIN MENU\n");
  else{
    showItem(&head, pos);

    do
    {
      printf("\nDO YOU WANT TO PROCEED (y/n)? ");
      scanf(" %c", &confirm);
    } while ((confirm!='y' && confirm!='n') || (confirm=='y' && confirm=='n'));
    
    if(confirm=='y'){
      updateItem(&head, pos);
    }

  }

  deleteList(&head);
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