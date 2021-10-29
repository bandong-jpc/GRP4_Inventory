#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

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


void add()
	
     {
     	FILE *fp = fopen("Inventory.csv", "a+");
     	
     	char id[6];             //Item ID
    	char description[41];   //Item Description
    	unsigned int qty;       //Item Quantity
    	char exp[10];           //Item Expiry Date
    	float price;           //Item price
    	int x;
    	int y;
    	int m;
    	int d;
    
    	if(!fp)
    	{
    	printf("Can't open file\n");
        return;
        }
  
    printf("Input 5-digit Item ID:");   
    scanf(" %6s", &id);
    printf("\n");
    fflush(stdin);
    printf("Input Item Description:");
    scanf(" %41s", &description);
    printf("\n");
    fflush(stdin);
    printf("Input Item Quantity:");
    scanf(" %u", &qty);
    printf("\n");
    fflush(stdin);
    printf("Input Item Expiry Date in YYYY-MM-DD\n");
    printf("Year: ");
    scanf(" %d", &y);
    fflush(stdin);
    printf("Month: ");
    scanf(" %d", &m);
    fflush(stdin);
    printf("Date: ");
    scanf(" %d", &d);
	printf("\n");
    fflush(stdin);
    printf("Input Item Price:");
    scanf(" %f", &price);
    printf("\n");
    
	x = atoi(id);
	
	if(x > 9999 && x < 100000 && m <13 && d <32 && y >2000 && qty > 0 && price > 0)
	{	
	fprintf(fp, "\"%s\",\"%s\",\"%u\",\"%d-%d-%d\",\"%5.2f\"\n", id, description, qty, y, m, d, price);
    printf("............ \n"); 
 	printf("............ \n"); 
    printf("Success! Inventory Item added! \n" );
    
    fclose(fp);	
	}
	else
	{	
	printf("Error! Invalid Input! Item not added. \n");
	}
	
	return;
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

void choice(){
	
	char choice;
	
	printf("\n[1]Search again\n");
    printf("[2]Return Main Menu: \n");
    printf("Enter: ");
    fflush(stdin);
    scanf("%d",&choice);
        if(choice == 1 )
	    {
	       search();
		}
        if(choice == 2)
        {
            int main ();
        }
	
}


void search(){
  char id[5];
  struct Node* head = NULL;
  int c;
  int v;
  int num = 0;
  int s = 0;
  char a[50];
  item x;
  
  
  while (num == 0){


  	printf("\n\nPlease input Item ID to Search: ");
  	scanf ("%s", id);    	  	
  	
  	
  	for (c=0; c<5 ; c++){
 	if ( id[c] >= 'a' && id[c] <= 'z' ){
 		printf("\nSorry, the Item ID you entered is not valid.\nPlease try another one.\n\n");
		choice();
		c = 6;
	   }
  	
  	if ( sscanf(id, "%d", &num) != 1){
  		num = 0;
  		printf("\nSorry, the Item ID you entered is not valid.\nPlease try another one.\n\n");
  		choice();
	   }
	  
  	if (num < 1 || num > 99999 ){
  	 	num = 0;
  	 	printf("\nSorry, the Item ID you entered is not valid.\nPlease try another one.\n\n");
  	 	choice();
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
