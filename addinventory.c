#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char id[6];             //Item ID
    char description[41];   //Item Description
    unsigned int qty;       //Item Quantity
    char exp[10];           //Item Expiry Date
    float price;           //Item price
  } item;
  
void filecheck()
{
  //open file to read
  FILE *fpointer = fopen("C:inventoryText.csv", "r+");


  //check if file exists. if not, create a new file with no content
  if(!fpointer){
    fclose(fpointer); //close current pointer to file
    fpointer = fopen("C:inventoryText.csv", "w"); //open new file for writing
    printf("\nInventory.csv DOES NOT EXISTS. CREATING NEW FILE. \n");
    fprintf(fpointer, "", "");
  }


  //close file to read
  fclose(fpointer);
}
void add()
	
     {
     	FILE *fp = fopen("C:inventoryText.csv", "a+");
     	
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
	
	if(x >= 10000 && x <= 99999 && m <13 && d <32 && y >2000 )
	{	
	fprintf(fp, "\"%s\",\"%s\",\"%u\",\"%d-%d-%d\",\"%5.2f\"\n", id, description, qty, y, m, d, price);
    printf("............ \n"); 
 	printf("............ \n"); 
    printf("Success! Inventory Item has been added! \n" );
    
    fclose(fp);	
	}
	else
	{	
	printf("Error! Invalid Input! Item not added. \n");
	}
	
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

    scanf("%c", &option);

    switch (option)
    {
    case 'a':
      // Add Inventory Item 
	filecheck();
	add();    
	return main();
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