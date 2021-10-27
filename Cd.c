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
            fp = fopen("mystudents1.txt","w");
            fp1 = fopen("temp.txt","r");

            while(fread(&s1,sizeof(student),1,fp1)){
                fwrite(&s1,sizeof(student),1,fp);
            }
            fclose(fp);
            fclose(fp1);
    }
    else
        printf("\nNot Found.....\n");
}


