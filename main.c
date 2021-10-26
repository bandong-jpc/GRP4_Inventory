#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

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
  
  item x;


  char id[255];
  //File pointer
  FILE *fpointer = fopen("Inventory.csv", "r+");

  fgets(id, 255, fpointer);

  fclose(fpointer);

    char detail[50];
    int i = 0;
   // Extract the first token
   char * token = strtok(id, ",\"");
   // loop through the string to extract all other tokens
   while( token != NULL ) {
      
      strcpy(detail, token);
     
      token = strtok(NULL, ",\"");


      switch (i)
      {
      case 0:
        x.id = atoi(detail);
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

  /* printf( "\n%d", x.id ); //printing each token
  printf( "\n%s", x.description ); //printing each token
  printf( "\n%d", x.qty ); //printing each token
  printf( "\n%s", x.exp ); //printing each token
  printf( "\n%.2f", x.price ); //printing each token */
  
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

//function for counting the number of entries in the file
int entry_counter(){
  //File pointer
  FILE *fpointer = fopen("Inventory.csv", "r+");
  //line variable for reading line
  char line[255];
  //entries variable for storing number of entries
  int entries = 0;

  //check for how many entries in the file
  while(!feof(fpointer)){
    fgets(line, 255, fpointer); 

    



    entries++;
  }

  fclose(fpointer);

  return entries;
}