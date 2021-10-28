#include <stdio.h>
#include <stdlib.h>
#include "header.h"
/*
    struct inventoryText{
     	char id[6];             //Item ID
    	char description[41];   //Item Description
    	unsigned int qty;       //Item Quantity
    	char exp[10];           //Item Expiry Date
    	float price;           //Item price
     };
*/
void delete_rec()
        {
        int found =0;

     	FILE *fp;
     	FILE *fp1;

        struct inventoryText s1;
        
        char charid;
        int id;
        printf("Enter the product ID number you want to delete: ");
        scanf("%s",&charid);
        
        charid = atoi(id);
        fp = fopen("C:inventoryText.csv", "r");   
        fp1 = fopen("C: temp.csv","w");


    	if(!fp)
    	{
    	printf("Can't open file\n");
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
        if(ch1=='N'||ch1=='n')
        {
            int main ();
        }
        }
        while(fread(&s1,sizeof(struct inventoryText),1,fp))
        {
            if(s1.id == id){
            found = 1;
            printf("\nItem ID\tDescription\tQuantity\tExp Date\tPrice");
            printf("\n%6s\t%s\t%d\t%s\t%f",s1.id,s1.description,s1.qty,s1.exp,s1.price);
        }
        else
            fwrite(&s1,sizeof(struct inventoryText),1,fp1);
        }
        fclose(fp);
        fclose(fp1);
        if(found)
            {   
                char ch;
                printf("\nConfirm Delete? Y/N: ");
                fflush(stdin);
                scanf("%c",&ch);
    		        if(ch=='y'||ch=='Y'){
		    
                    fp = fopen("C: inventoryText.csv","w");
                    fp1 = fopen("C: temp.csv","r");
                    while(fread(&s1,sizeof(struct inventoryText),1,fp1)){
                    fwrite(&s1,sizeof(struct inventoryText),1,fp);
            }
            printf("Deleted\n");
            fclose(fp);
            fclose(fp1);}
                    if(ch=='n'||ch=='N')
                        {
                            printf("\nFile not Deleted\n");
                        }
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
                    if(ch1=='N'||ch1=='n')
                    {
                        int main();
                    }
            }

        }
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



