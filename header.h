typedef struct {
    char id[6];             //Item ID
    char description[41];   //Item Description
    unsigned int qty;       //Item Quantity
    char exp[10];           //Item Expiry Date
    float price;           //Item price
  } item;

typedef struct{
  item *array;
  size_t used;
  size_t size;
} DynamicArray;

void initArray(DynamicArray *a, size_t initialSize) {
  a->array = malloc(initialSize * sizeof(item));
  a->used = 0;
  a->size = initialSize;
}

void insertArray(DynamicArray *a, item element) {
  // a->used is the number of used entries, because a->array[a->used++] updates a->used only *after* the array has been accessed.
  // Therefore a->used can go up to a->size 
  if (a->used == a->size) {
    a->size *= 2;
    a->array = realloc(a->array, a->size * sizeof(item));
  }
  a->array[a->used++] = element;
}

void freeArray(DynamicArray *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}