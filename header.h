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
  FILE *fpointer = fopen("Inventory.csv", "r+");

    if (*head_ref == NULL)
    {
      printf("\nEMPTY LIST");
       return;
    } 
      
    while (last->next != NULL){
      fprintf(fpointer, "\"%s\",\"%s\",\"%d\",\"%s\",\"%.2f\"\n", 
        last->data.id,
        last->data.description,
        last->data.qty,
        last->data.exp,
        last->data.price
      );
      last = last->next;
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

    printf("\n================ITEM DETAILS=================\n");
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
          printf("\nONE INPUT IS INVALID! PLEASE TRY AGAIN\n");
        }
      }else{
        printf("\nONE INPUT IS INVALID! PLEASE TRY AGAIN\n");
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
    while (last->next != NULL){
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
