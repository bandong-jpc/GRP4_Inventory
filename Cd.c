void delete_rec(){
    int i, j, found=0;
    student s1;
    FILE *fp, *fp1;
    int rno;
    printf("Enter RollNo to Delete : ");
    scanf("%d",&rno);

    fp = fopen("mystudents1.txt","r");
    fp1 = fopen("temp.txt","w");
    while(fread(&s1,sizeof(student),1,fp)){
        if(s1.rno == rno){
            found = 1;
        }
        else
            fwrite(&s1,sizeof(student),1,fp1);
    }
    fclose(fp);
    fclose(fp1);
    if(found){
    		            printf("\n%-5d%-20s",s1.rno,s1.name);
            for(j=0;j<3;j++){
                printf("%4d",s1.sub[j].mark);
            }
            printf("%5d%7.2f",s1.total,s1.per);
    		char ch;
    		printf("\nConfirm Delete?Y/N: ");
    		fflush(stdin);
    		scanf("%c",&ch);
    		if(ch=='y'||ch=='Y'){
		    
            fp = fopen("mystudents1.txt","w");
            fp1 = fopen("temp.txt","r");

            while(fread(&s1,sizeof(student),1,fp1)){
                fwrite(&s1,sizeof(student),1,fp);
            }
            printf("Deleted\n");
            fclose(fp);
            fclose(fp1);}
          else
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
			int main();
		
    }
    else{
   
        printf("\nNot Found.....\n");
	
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
			int main();
		}
	}
}

