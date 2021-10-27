#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void update();
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

    scanf(" %c", &option);

    switch (option)
    {
    case 'a':
      /* code */
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
  //item variable to store read data
  item temp;
  //check if file exists
  filecheck();
  //dynamic array to store all of the file contents
  DynamicArray list;
  //initialize the array
  initArray(&list, 1);
  
  //File pointer
  FILE *fpointer = fopen("Inventory.csv", "r+");
  //line variable for reading line
  char line[255];
  //entries variable for storing number of entries
  int entries = 0;
  //variable for storing index of item to be updated
  int pos = -1;

  //loop through file reading every line
  while(!feof(fpointer)){
    fgets(line, 255, fpointer); 

  char detail[50];
  int i = 0;
   // Extract the first token
   char * token = strtok(detail, ",\"");
   // loop through the string to extract all other tokens
   while( token != NULL ) {
      strcpy(detail, token);
     
      token = strtok(NULL, ",\"");

      switch (i)
      {
      case 0:
        strcpy(temp.id, detail);

        break;
      
      case 1:
        strcpy(temp.description, detail);
        break;
      
      case 2:
        temp.qty = atoi(detail);
        break;
      
      case 3:
        strcpy(temp.exp, detail);
        break;
      
      case 4:
        temp.price = atof(detail);
        break;
    
      default:
        break;
      }
      i++;
   }

    insertArray(&list, temp);

    entries++;
  }
  fclose(fpointer);

  for (int j = 0; j < entries; j++)
  {
    printf("\n%d\t%s", j, list.array[j].id);
  }
  

  freeArray(&list);

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
