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
          	delete_rec();
    }
    else
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
}
