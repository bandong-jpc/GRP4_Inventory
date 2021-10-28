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




int readFile() // read file function
{
    int n = 0;
    int i;
    FILE *f;
    
    f = fopen("inventory.csv", "+r");
    if (f == NULL)
        return -1;
    fscanf(f, "%d\n", &n);
    for (i = 0; i < n; ++i)
    {
        fgets(x[i].id, 10, f);
        x[i].id[strlen(x[i].id) - 1] = 0; 
        fgets(x[i].description, 20, f);
        x[i].description[strlen(prod[i].description)-1] = 0; 
        fscanf(f, "%d", &x[i].qty);
        fscanf(f, "%d", &x[i].exp);
        fscanf(f, "%f", &x[i].price);
    }
    fclose(f);
    return n;
}


void searchInvItem(){
	

	int i;
    char id[10];
    int z = false;
    item x;
    count = readFile();
    printf("\nItem ID: ");
    
	fflush(stdin);
	scanf("%s", &id);
	//gets(id);
    for (i=0; i<count; i++){
        if (strcmp(id,x[i].id)==0) 	// compare Item ID to list.
        {
        	z=true;
        printf("\nItem found! Containing: \n");//...then display the match
        printf("\nProduct name: %s",x[i].id);
	   	printf("\nProduct name: %s",x[i].description);
		printf("\nPrice: %d",x[i].qty);
		printf("\nquantity: %d",x[i].exp);
		printf("\ndiscount: %f\n\n",x[i].price);
	
			}
	
	}
 if(z==false){	//if the Item ID doesn't exist.
 
	printf("Cant find the product id: %s.",id);
}
	

}


