#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

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
            printf("Incheck ID");
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
                     printf("\nDELETE SUCCESSFUL!!!!!!!\n\n");
                     fclose(fp);
                     fclose(fpl);
                     deleteG = 1;
                }
                else if(strcmp (choke, "N") == 0 || strcmp (choke, "n") == 0)
                {
                    printf("\nDELETE CANCELLED\n\n");
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
