
void add()

	
     {
     	FILE *fp = fopen("C:inventoryText.csv", "a+");
     	
     	char id[6];             //Item ID
    	char description[41];   //Item Description
    	unsigned int qty;       //Item Quantity
    	char exp[10];           //Item Expiry Date
    	float price;           //Item price
    

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
    printf("Input Item Expiry Date in YYYY-MM-DD:");
    scanf(" %10s", &exp);
    printf("\n");
    fflush(stdin);
    printf("Input Item Price:");
    scanf(" %f", &price);
    printf("\n");
    

    
    fprintf(fp, "\"%s\",\"%s\",\"%u\",\"%s\",\"%5.2f\"\n", id, description, qty, exp, price);
    printf(" .......... \n"); 
 	printf(" .......... \n"); 
    printf("Success! Inventory Item has been added!");
    
    fclose(fp);	
	

    return;
		}
	

