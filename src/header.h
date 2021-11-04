typedef struct {
    char id[6];             //Item ID
    char description[41];   //Item Description
    unsigned int qty;       //Item Quantity
    char exp[11];           //Item Expiry Date
    float price;           //Item price
  } item;

struct Node{
  item data;
  struct Node *next;
};



void saveToFile(struct Node** head_ref){
  struct Node *last = *head_ref;  /* used in step 5*/
  FILE *fpointer = fopen("Inventory.csv", "w");

    if (*head_ref == NULL)
    {
      printf("\nEMPTY LIST");
       return;
    }

    while (1){
      fprintf(fpointer, "\"%s\",\"%s\",\"%d\",\"%s\",\"%.2f\"",
        last->data.id,
        last->data.description,
        last->data.qty,
        last->data.exp,
        last->data.price
      );

      if(last->next != NULL) {
        last = last->next;
        fprintf(fpointer, "\n");
      }
      else {
        break;
      }

    }

    fclose(fpointer);
}

void append(struct Node** head_ref, char* id, char* desc, unsigned int qty, char* exp, float price )
{

    /* 1. allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    struct Node *last = *head_ref;  /* used in step 5*/

    /* 2. put in the data  */
    strcpy(new_node->data.id, id);
    strcpy(new_node->data.description, desc);
    new_node->data.qty = qty;
    strcpy(new_node->data.exp, exp);
    new_node->data.price = price;

    /* 3. This new node is going to be the last node, so make next
          of it as NULL*/
    new_node->next = NULL;

    /* 4. If the Linked List is empty, then make the new node as head */
    if (*head_ref == NULL)
    {
       *head_ref = new_node;
       return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;

    /* 6. Change the next of last node */
    last->next = new_node;
    return;
}

void insert(struct Node** head_ref, char* id, char* desc, unsigned int qty, char* exp, float price){
  /* 1. allocate node */

    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    struct Node *last = *head_ref;  
    struct Node *toMove = *head_ref;  

    /* 2. put in the data  */
    strcpy(new_node->data.id, id);
    strcpy(new_node->data.description, desc);
    new_node->data.qty = qty;
    strcpy(new_node->data.exp, exp);
    new_node->data.price = price;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
       *head_ref = new_node;
       saveToFile(head_ref);
       return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL && atoi(last->data.id) < atoi(new_node->data.id)){
      last = last->next;
    }

    if(last->next == NULL){
      new_node->next = last->next;
      last->next = new_node;
    }else{
      if(toMove == last){
        new_node->next = toMove;
        *head_ref = new_node;
      }else{
      while (toMove->next != last)
      {
        toMove = toMove->next;
      }
      new_node->next = toMove->next;
      toMove->next = new_node;
      }
      
      
    }

  saveToFile(head_ref);

}

/* Function to delete the entire linked list */
void deleteList(struct Node** head_ref)
{
   /* deref head_ref to get the real head */
   struct Node* current = *head_ref;
   struct Node* next;

   while (current != NULL)
   {
       next = current->next;
       free(current);
       current = next;
   }

   /* deref head_ref to affect the real head back
      in the caller. */
   *head_ref = NULL;

   return;
}

void showList(struct Node** head_ref){

    struct Node *last = *head_ref;  /* used in step 5*/


    if (*head_ref == NULL)
    {
      printf("\nEMPTY LIST");
       return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL){
      printf("\n%s\t%s\t%d", last->data.id, last->data.description, last->data.qty);
      last = last->next;
    }

    return;
}

void showItem(struct Node** head_ref, int pos){
  struct Node *last = *head_ref;  /* used in step 5*/
  int i = 0;
    if (*head_ref == NULL)
    {
      printf("\nEMPTY LIST");
       return;
    }


    while (last->next != NULL && i != pos){
      last = last->next;
      i++;
    }

    printf("\n\n================ITEM DETAILS=================\n");
    printf("\nITEM ID:\t%s\n", last->data.id);
    printf("DESCRIPTION:\t%s\n", last->data.description);
    printf("QUANTITY:\t%d\n", last->data.qty);
    printf("EXPIRY DATE:\t%s\n", last->data.exp);
    printf("PRICE:\t\t%.2f\n", last->data.price);
    printf("\n=============================================\n");


    return;
}

void updateItem(struct Node** head_ref, int pos){
  struct Node *last = *head_ref;  /* used in step 5*/
  int i = 0, year, month, day, quan;
  float pr;

  char description[41];   //Item Description
  char qty[5];            //Item Quantity
  char exp[11];           //Item Expiry Date
  char price[10];

    if (*head_ref == NULL)
    {
      printf("\nEMPTY LIST");
       return;
    }
    while (last->next != NULL && i != pos){
      last = last->next;
      i++;
    }

    do
    {
      printf("\nITEM DESCRIPTION: ");
      scanf(" %[^\n]s", description);
      printf("\nITEM QUANTITY: ");
      scanf(" %s", qty);
      printf("\nITEM EXPIRATION DATE: ");
      scanf(" %s", exp);
      printf("\nITEM PRICE:  ");
      scanf(" %s", price);

      if (
        (sscanf(exp, "%4d-%2d-%2d", &year, &month, &day) == 3 || strcmp("-", exp) == 0) &&
        (sscanf(qty, "%d", &quan) == 1) &&
        (sscanf(price, "%f", &pr) == 1)
      )
      {
        if(quan >= 0 && pr >= 0 && quan < 5000 && pr < 100000){
          strcpy(last->data.description, description);
          last->data.qty = quan;
          strcpy(last->data.exp, exp);
          last->data.price = pr;

          saveToFile(head_ref);

          printf("\nITEM UPDATED!\n");

          break;
        }else{
          printf("\nAN INPUT IS INVALID! PLEASE TRY AGAIN\n");
        }
      }else{
        printf("\nAN INPUT IS INVALID! PLEASE TRY AGAIN\n");
      }


    } while (1);

    return;
}

void display(struct Node** head_ref){

    struct Node *last = *head_ref;  /* used in step 5*/


    if (*head_ref == NULL)
    {
      printf("\nEMPTY LIST");
       return;
    }
    /* 5. Else traverse till the last node */
    while (last != NULL){
      printf("ID: %s\n", last->data.id);
      printf("Description: %s\n", last->data.description);
      printf("Quantity: %d\n", last->data.qty);
      printf("Expiry Date: %s\n", last->data.exp);
      printf("Price: %5.2f\n", last->data.price);
      printf("=========================================\n");
      last = last->next;
    }

    return;
}

void deleteItem(struct Node** head_ref, char *id ){
  struct Node* last = *head_ref, *temp = *head_ref;  /* used in step 5*/
  int i = 0;

    while (temp->next != NULL && strcmp(id, temp->data.id) != 0){
      temp = temp->next;
    }

    //if temp is the first item in the list, point head to temp->next
    if(temp == last){
      *head_ref = temp->next;
    }else{
      //search for the node before node to be deleted
      while (last->next != temp){
        last = last->next;
      }

      //point node before node to be deleted to the next node after the node to be deleted
      last->next = temp->next;
    }
    
    saveToFile(head_ref);

    printf("\n\n===============ITEM DELETED================\n");
    printf("\nITEM ID:\t%s\n", temp->data.id);
    printf("DESCRIPTION:\t%s\n", temp->data.description);
    printf("QUANTITY:\t%d\n", temp->data.qty);
    printf("EXPIRY DATE:\t%s\n", temp->data.exp);
    printf("PRICE:\t\t%.2f\n", temp->data.price);
    printf("\n=============================================\n");

    /* display(head_ref); */
    free(temp);
    
}

//function for readting from file
void readFromFile(struct Node** head_ref){
  item x;

  FILE *fpointer = fopen("Inventory.csv", "r+");
  //line variable for reading line
  char line[255] = "";

  char detail[50];
  int i = 0, pos = -1, entries=0;
  char confirm = 'x';
  //check for how many entries in the file
  while(!feof(fpointer)){
    fgets(line, 255, fpointer);

    strcpy(detail, line);

    if(strlen(detail) <= 10) continue; //check if line is empty
    if(strlen(detail) <= 10 && feof(fpointer)) break;
    i=0;
   // Extract the first token
   char * token = strtok(detail, ",\"");
   // loop through the string to extract all other tokens
   while( token != NULL ) {

      strcpy(detail, token);

      token = strtok(NULL, ",\"");
      switch (i)
      {
      case 0:
        strcpy(x.id, detail);
        break;

      case 1:
        strcpy(x.description, detail);
        break;

      case 2:
        x.qty = atoi(detail);
        break;

      case 3:
        strcpy(x.exp, detail);
        break;

      case 4:
        x.price = atof(detail);
        break;
      default:
        break;
      }
      if(i==4){
        append(head_ref, x.id, x.description, x.qty, x.exp, x.price);
        i=0;
        break;
      }
      i++;
   }

    entries++;
  }

  fclose(fpointer);
}
