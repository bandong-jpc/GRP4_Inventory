#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  FILE *fpointer = fopen("inventoryText.csv", "r+");


  //check if file exists. if not, create a new file with no content
  if(!fpointer){
    fclose(fpointer); //close current pointer to file
    fpointer = fopen("inventoryText.csv", "w"); //open new file for writing
    printf("\nInventory.csv DOES NOT EXISTS. CREATING NEW FILE. \n");
    fprintf(fpointer, "", "");
  }


  //close file to read
  fclose(fpointer);
}
void add()

     {
     	FILE *fp = fopen("inventoryText.csv", "a+");

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

void delete_rec()
	   {
    int found=0;
    item s1;
    FILE *fp, *fp1;
    char id[6];
    printf("Enter ID No. to Delete : ");
    scanf(" %6s",&id);
    fp = fopen("inventoryText.csv","r");
    fp1 = fopen("temp.csv","w");
    while(fread(&s1,sizeof(item),1,fp)){
        if(strcmp(id, s1.id) == 0){
            found = 1;
        }
        else
            fwrite(&s1,sizeof(item),1,fp1);

    }	if(strcmp(id, s1.id) == 0){
            found != 1;
        }
        else
            fwrite(&s1,sizeof(item),1,fp1);

    }
    fclose(fp);
    fclose(fp1);

    if(found=1){

    		char ch;
    		printf("\n%-3s",s1.id);
    		printf("\nConfirm Delete?Y/N: ");
    		fflush(stdin);
    		scanf("%c",&ch);
    		if(ch=='y'||ch=='Y'){

            fp = fopen("inventoryText.csv","w");
            fp1 = fopen("temp.csv","r");

            while(fread(&s1,sizeof(item),1,fp1)){
                fwrite(&s1,sizeof(item),1,fp);
            }
            printf("Deleted\n");
            fclose(fp);
            fclose(fp1);}
          else
          {
		printf("Not Deleted\n");
		char ch1;
        printf("[Y]Enter Another ID No:\n");
        printf("[N]Return Main Menu: \n");
        printf("Enter: ");
        fflush(stdin);
        scanf("%c",&ch1);
        if(ch1=='Y'||ch1=='y')
	   {
	   delete_rec();
		}
		else
			return;

    }}
    else{

        printf("\nInvalid\n");

		char ch;
        printf("[Y]Enter Another ID No:\n");
        printf("[N]Return Main Menu: \n");
        printf("Enter: ");
        fflush(stdin);
        scanf("%c",&ch);
	 	if(ch=='Y'||ch=='y')
	   {
	   delete_rec();
		}
	if(ch=='N'||ch=='n'){
		return;
		}
	}
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

    scanf(" %c", &option);

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
      // Delete Inventory Item
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
