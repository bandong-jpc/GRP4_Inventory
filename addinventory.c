#include <stdio.h>
#include <stdlib.h>

void add()
	
     {
     	FILE *fp = fopen("Inventory.csv", "a+");
     	
     	char id[6];              //Item ID
    	char description[41];    //Item Description
    	unsigned int qty;        //Item Quantity
		  char exp[10];            //Item Expiry Date
    	float price;             //Item price
    	int x;				           //Char converter to Int
    	int y;                   //Format Year
    	int m;                   //Format Month
    	int d;                   //Format Date
    	
    	
    	int R = qty;
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
    scanf(" %d", &R);
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
	
	if(x > 9999 && x < 100000 && m <13 && d <32 && y >2000 && R > 0 && price > 0 )
	{	
	fprintf(fp, "\"%s\",\"%s\",\"%d\",\"%d-%d-%d\",\"%5.2f\"\n", id, description, R, y, m, d, price);
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
	