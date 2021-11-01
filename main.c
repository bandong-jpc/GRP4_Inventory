#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
#include "newdelete.c"
#include "addinventory.c"

void filecheck();
void update();
void displayInven();
void choice();
void search();

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
    filecheck();
      add();
      break;
    case 'b':
    filecheck();
      update();
      break;
    case 'c':
    filecheck();
      displayInven();
      break;
    case 'd':
    filecheck();
      search();
      break;
    case 'e':
    filecheck();
      delete_rec();
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
  char line[255] = "";
  
  char detail[50];
  int i = 0, pos = -1, entries=0;
  char confirm = 'x';
  //check for how many entries in the file
  while(!feof(fpointer)){
    fgets(line, 255, fpointer); 

    strcpy(detail, line);

    if(strlen(detail) <= 10) continue; //check if line is empty
    if(strlen(detail) <= 10 && feof(fpointer)) break;
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
        if (strcmp(detail, toUpdate) == 0 && pos == -1)
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
      if(i==4){
        append(&head, x.id, x.description, x.qty, x.exp, x.price);
        i=0;
        break;
      }
      i++;
   }

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



void choice(){
	
	char choice;
	
	printf("\n[1]Search again\n");
    printf("[2]Return Main Menu: \n");
    printf("Enter: ");
    fflush(stdin);
    scanf(" %d",&choice);
        if(choice == 1 )
	      {
	       search();
         return;
		    }
        if(choice == 2)
        {
            return;
        }
	
}


void search(){
  char id[6];
  struct Node* head = NULL;
  int c;
  int v;
  int num = 0;
  int s = 0;
  char a[50];
  item x;
  
  
  while (num == 0){


  	printf("\n\nPlease input Item ID to Search: ");
  	scanf (" %s", id);    	  	
  	
  	
  	for (c=0; c<5 ; c++){
 	if ( id[c] >= 'a' && id[c] <= 'z' ){
 		printf("\nSorry, the Item ID you entered is not valid.\nPlease try another one.\n\n");
		choice();
    return;
		c = 6;
	   }
  	
  	if ( sscanf(id, " %d", &num) != 1){
  		num = 0;
  		printf("\nSorry, the Item ID you entered is not valid.\nPlease try another one.\n\n");
  		choice();
      return;
	   }
	  
  	if (num < 1 || num > 99999 ){
  	 	num = 0;
  	 	printf("\nSorry, the Item ID you entered is not valid.\nPlease try another one.\n\n");
  	 	choice();
       return;
	   }
 	  
 	
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

  if(pos == -1) printf("\nSorry, the Item ID you entered doesn't exist.\nPlease try another one.\n\n");
  else{
    showItem(&head, pos);


  }
  
  
   deleteList(&head);
   

   choice();

 

}
