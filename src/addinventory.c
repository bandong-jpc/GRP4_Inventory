#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void add()
	
{

		FILE *fp;
     	fp = fopen("Inventory.csv", "a+");
     	char id[6];              //Item ID
    	char description[41];    //Item Description
    	unsigned int qty;        //Item Quantity
		char exp[10];            //Item Expiry Date
    	float price;             //Item price
    	int x;				     //Char converter to Int
    	char y[5];                   //Format Year
    	char m[3];                   //Format Month
    	char d[3];                   //Format Date
    	int year;
    	int month;
    	int date;
    	int bufferLength = 255;
	    int idExists = 0;
    	
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
    scanf(" %[^\n]s", description);
    printf("\n");
    fflush(stdin);
    printf("Input Item Quantity:");
    scanf(" %d", &R);
    printf("\n");
    fflush(stdin);
    printf("Input Item Expiry Date in YYYY-MM-DD\n");
    printf("Year: ");
    scanf(" %s", y);
    fflush(stdin);
    printf("Month: ");
    scanf(" %s", m);
    fflush(stdin);
    printf("Date: ");
    scanf(" %s", d);
	printf("\n");
    fflush(stdin);
    printf("Input Item Price:");
    scanf(" %f", &price);
    printf("\n");
    
	x = atoi(id);
	year = atoi(y);
	month = atoi(m);
	date = atoi(d);

	char line[bufferLength];
	fp = fopen("Inventory.csv", "r");
		while(fgets(line, bufferLength, fp))
	{
		char *ptr = strstr(line, id);
		if (ptr != NULL) 
		{
			idExists=1;
			break;
		}
	}
	fclose(fp);
	if (idExists==1)
	{
		printf("Error! ID already exists! Item not added. \n");
	}
	else
	{
	if(
    (x > 9999 && x < 100000 && R > 0 && price > 0) &&
    ((month < 13 || month == '-') && (date <32) && (year < 3000 || year > 2000)) && 
    ((month < 13) && (date <32  || date == '-') && (year < 3000 || year > 2000)) && 
    ((month < 13) && (date <32) && (year < 3000 || year == '-' || year > 2000 )))
		{	
					fp = fopen("Inventory.csv", "a+");
					fprintf(fp, "\n\"%s\",\"%s\",\"%d\",\"%s-%s-%s\",\"%5.2f\"", id, description, R, y, m, d, price);
   					printf("............ \n"); 
 					printf("............ \n"); 
   	 				printf("Success! Inventory Item added! \n" );
    
    				fclose(fp);	
		}
	else
		{	
					printf("Error! Invalid Input! Item not added. \n");
		}		
	}

	
	return;
}
