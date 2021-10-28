typedef struct {
    int id;                 //Item ID
    char description[50];   //Item Description
    int qty;                //Item Quantity
    char exp[10];           //Item Expiry Date
    float price;           //Item price
  } item;

struct Node{
  item data;
  struct Node *next;
};

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
      printf("\n%s", last->data.id);
      last = last->next;
    }
        
    return;  
}
