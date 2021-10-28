#include <stdio.h>
#include <stdlib.h>
#include "header.h"

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

void search(){
  char id[6];
  struct Node* head = NULL;
  item x;
  int num = 0;
  
  
  while (num == 0){
  	
  	printf("\n\nPlease input Item ID to Search: ");
  	  scanf("%s", id);
  	
  	if ( sscanf(id, "%d", &num) != 1){
  		num = 0;
  		printf("\nSorry, the Item ID you entered is not valid.\nPlease try another one.\n");
  		continue;
	  }
	  
  	 if (num < 1 || num > 99999 ){
  	 	num = 0;
  	 	printf("Invalid range\n");
  	 	continue;
  	 	
	   }
 
 
  }
  
  

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
        if (strcmp(detail, id) == 0)
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

  if(pos == -1) printf("\nSorry, the Item ID you entered doesn't exist.\nPlease try another one.\n");
  else{
    showItem(&head, pos);

  }
  
  
   deleteList(&head);
   

        char choice;
        printf("[1]Search again\n");
        printf("[2]Return Main Menu: \n");
        printf("Enter: ");
        fflush(stdin);
        scanf("%c",&choice);
        if(choice== 1 )
	    {
	       search();
		}
        if(choice== 2)
        {
            int main ();
        }

 

}
