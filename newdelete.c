#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

typedef struct item{
    int id;                 //Item ID
    char description[41];   //Item Description
    unsigned int qty;       //Item Quantity
    char exp[10];           //Item Expiry Date
    float price;           //Item price
  } item;
void filecheck();
 void add()
 {
    item p1;
    FILE *fp;
    fp = fopen("inventoryN.csv", "a");

    printf("\nEnter ID : ");
    scanf(" %d",&p1.id);
    printf("Enter Description : ");
    scanf(" %s",p1.description);
    printf("Enter Quantity : ");
    scanf(" %d",&p1.qty);
    printf("Enter Expiration : ");
    scanf(" %s",p1.exp);
    printf("Enter Price : ");
    scanf(" %f",&p1.price);

    fwrite(&p1, sizeof(item), 1, fp);


    fclose(fp);
 }
void delete_rec()
{

    int check = 0;
    int deleteG = 0;
    int i = 0;
    char dinputID[20];
    while(strcmp (dinputID, "R") != 0 || strcmp(dinputID, "r") != 0|| deleteG != 1){
        printf("\nDELETE ITEM MENU");
        printf("\n[R] Return Main Menu");
        printf("\n\n[ID] ITEM ID: ");
        printf("\n\n Type ID or [R]: ");
        scanf("%s", &dinputID);
        if (strcmp (dinputID, "R") == 0 || strcmp (dinputID, "r") == 0)
        {

            return;
        }

        check = 1;
        for(i=0; i < strlen(dinputID); i++)
        {
            if(isalpha(dinputID[i]))
            {
                check = 0;
            }
            i++;
        }
        if (check == 0)
        {
            printf("\nIncheck ID\n");
        }
        else if (check == 1)
        {

            int itemID = atoi(dinputID);

            item s1;
            FILE *fp, *fpl;
            int j, rno, found = 0;
            char details[100];

            fp = fopen("inventoryN.csv","r");
            fpl = fopen("inventoryB.csv","w");
            while (fread(&s1,sizeof(item),1,fp))
            {

                if(s1.id == itemID)
                {
                    found=1;
                  printf("\nDO YOU WANT TO DELETE ?\n \n/*Product ID*/\n%-15d\n/*Description*/\n%-20s\n/*Quantity*/\n%-15d\n/*Exp Date*/\n%-20s\n/*Price*/\n%-15f"
                         ,s1.id, s1.description, s1.qty, s1.exp, s1.price);
                }
                else
                {
                    fwrite(&s1,sizeof(item),1,fpl);
                }
            }
            fclose(fp);
            fclose(fpl);
            if (found)
            {
                printf("\n \n Yes [y] / N [n]: ");
                char choke[10];
                scanf(" %s",&choke);
                if(strcmp (choke, "Y") == 0 || strcmp (choke, "y") == 0)
                {
                     fpl = fopen("inventoryB.csv","r");
                     fp = fopen("inventoryN.csv","w");
                     while (fread(&s1,sizeof(item),1,fpl))
                     {
                        fwrite(&s1,sizeof(item),1,fp);
                     }
                     printf("\n/*/*/*DELETED*/*/*/n\n");
                     fclose(fp);
                     fclose(fpl);
                     deleteG = 1;
                }
                else if(strcmp (choke, "N") == 0 || strcmp (choke, "n") == 0)
                {
                    printf("\n/*/*/*CANCELLED DELETE*/*/*/\n\n");
                    deleteG = 1;
                    delete_rec();

                }

            }
            else
            {
                printf("\nItem Does Not Exist\n\n");
            }

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
    printf("\n[E] DELETE INVENTORY ITEM");
    printf("\n[X] EXIT PROGRAM");
    printf("\nEnter Your Choice: ");

    scanf(" %c", &option);

    switch (option)
    {
    case 'a':
    // Add Inventory Item
        filecheck();
        add();
        break;
    case 'e':
      // Delete Inventory Item
        filecheck();
        delete_rec();
      break;
    case 'E':
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
