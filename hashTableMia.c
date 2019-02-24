#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define ABC "ABCDEFGHIJKLMNOPQRSTUVWXYZ #@\0"
#define SIZE 29

// Mi caja con los dos valores.
struct DataItem {
   // valor encriptado
   char *data;
   // valor real
   char *key;
};

struct DataItem* hashArray[SIZE]; 
struct DataItem* dummyItem;
struct DataItem* item;

int hashCode(char *key) {
    //Busca la clave en el ABCdario y le pone un indice.
    int index=(int)(strchr(ABC,key[0])-ABC);
    return index;   
}

struct DataItem *search(char *key) {
   //Obtengo el indice
   int hashIndex = hashCode(key);  
    
   //Busco en la tabla hasta encontrar keys iguales 
    if(hashArray[hashIndex]->key[0] == key[0]){
        return hashArray[hashIndex]; 
    }
   return NULL;        
}

void insert(char *key,char *data) {
    // Creo un elemento (caja con dato y clave)
   struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
   item->data[0] = data[0];  
   item->key[0] = key[0];

   //Obtengo su indice y lo inserto en la tabla de hash
   // Pd: este insert no resuelve colisiones (como planteamos el ejercicio no hace falta)
   int hashIndex = hashCode(key);
   hashArray[hashIndex] = item;
}

struct DataItem* delete(char *key) {
   int hashIndex = hashCode(key);  
   if(hashArray[hashIndex]->key[0] == key[0]) {
      struct DataItem* temp = hashArray[hashIndex];
      hashArray[hashIndex] = dummyItem; 
      return temp;
   }
        
   return NULL;        
}

void display() {
   int i = 0;
    
   for(i = 0; i<SIZE; i++) {
    
      if(hashArray[i] != NULL)
         printf(" [%c:%c]",hashArray[i]->key[0],hashArray[i]->data[0]);
      else
         printf("[ : ]");
   }
    
   printf("\n");
}

int main() {
   dummyItem = (struct DataItem*) malloc(sizeof(struct DataItem));
   dummyItem->data = "@";  
   dummyItem->key = "@"; 

   char *letra1 ="A";
   char *letra2 ="B";
   insert(letra1, letra2);
   insert("C", "A");
   insert("B", "C");
   insert("H", "O");
   insert("O", "H");
   insert("L", "U");
   
   display();
   item = search("A");

   if(item != NULL) {
      printf("Element found: %s\n", item->data);
   } else {
      printf("Element not found\n");
   }
   
   delete("E");
   item = search("H");

   if(item != NULL) {
      printf("Element found: %s\n", item->data);
   } else {
      printf("Element not found\n");
   }
}