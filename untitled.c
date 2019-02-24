#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct DataItem {
   int data;   
   int key;
};

int hashCode(int key) {
   return (key-65)%5;
}

void insert(int key,int data,struct DataItem hashArray[5]) {

   struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
   item->data = data;  
   item->key = key;

   
   int hashIndex = hashCode(key);
   hashArray[hashIndex] = item;
}

void display(struct DataItem hashArray[5]) {
   int i = 0;
    
   for(i = 0; i<5; i++) {
    
      if(hashArray[i] != NULL)
         printf(" [%c:%c]",hashArray[i]->key,hashArray[i]->data);
      else
         printf("[ : ]");
   }
    
   printf("\n");
}

int main()
{
    struct DataItem* hashArray1[5];
    struct DataItem* hashArray2[5];
    int a= 'A';
    int b= 'B';
    int c= 'C';
    insert(a, b,hashArray1);
    insert(b, c,hashArray1);
    insert(c, a,hashArray2);
    display(hashArray1);
    display(hashArray2);
    
    return 0;
}