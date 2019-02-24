#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*
TABLA DE HASH CON SUS FUNCIONES BASICAS
*/

#define SIZE 27

//Esta es una caja que tiene dato y clave
struct DataItem {
   int data;   
   int key;
};


//Este es un arreglo de cajas que tiene dato y clave
//struct DataItem* hashArray[SIZE]; 

//Con esto organizo mis cajas en la tabla de hash
int hashCode(int key) {
	if(key==32){
		return 26;
	}
    return (key-65)%SIZE;
}

// Funcion que busca una caja a partir de una clave
struct DataItem *search(int key,struct DataItem* hashArray) {
   int hashIndex = hashCode(key);

   while(hashArray[hashIndex] != NULL) {
	
      if(hashArray[hashIndex]->key == key)
         return hashArray[hashIndex]; 

      ++hashIndex;

      hashIndex %= SIZE;
   }        
	
   return NULL;        
}

//Funcion insertar un cajita a partir de sus datos
void insert(int key,int data,struct DataItem* hashArray) {

   struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
   item->data = data;  
   item->key = key;

   
   int hashIndex = hashCode(key);
   hashArray[hashIndex] = item;
}

//Funcion que elimina un elemento de la tabla de hash
struct DataItem* delete(struct DataItem* item,struct DataItem* hashArray) {
   int key = item->key;

 
   int hashIndex = hashCode(key);


    if(hashArray[hashIndex]->key == key) {
       struct DataItem* temp = hashArray[hashIndex]; 
       hashArray[hashIndex] = NULL; 
       return temp;
    }
     
	
   return NULL;        
}

//Muestra la tabla de hash
void display(struct DataItem* hashArray) {
   int i = 0;
	
   for(i = 0; i<SIZE; i++) {
	
      if(hashArray[i] != NULL)
         printf(" [%c:%c]",hashArray[i]->key,hashArray[i]->data);
      else
         printf("[ : ]");
   }
	
   printf("\n");
}

//Crear tabla
struct DataItem *create_hashTable(int size){
	struct DataItem* hashArray[size];
	return hashArray;
}

/*
FUNCIONES PARTICULARES PARA LA TAREA
*/

struct DataItem* createHashTableWithStrings(char *string1,char *string2){
	struct DataItem* tabla = create_hashTable(27);
	for(int i=0;i<strlen(string1);i++){
		if(search(string1[i],tabla)==NULL){
			printf("%c\n", string1[i]);
			insert(string1[i],string2[i],tabla);
		}
	}
	return tabla;
}

char* cifrar(char *string,struct DataItem* tabla){
	char string2[50];
	char *stringPtr = string2;
	for(int i=0;i<strlen(string);i++){
		if(search(string[i],tabla)!=NULL){
			string2[i]= (search(string[i],tabla))->data;
		}
		else{string2[i]=35;}
	}
	return stringPtr;
}

/*
MAIN PARA PROBAR LAS FUNCIONES DE HASH
*/
int main() {
   struct DataItem *pedro;
   char string[50];
   char string1[50];
   char string2[50];
   printf("%s\n","String1: ");
   fgets(string1, sizeof(string1), stdin);
   printf("%s\n","String2: ");
   fgets(string2, sizeof(string2), stdin);
   pedro=createHashTableWithStrings(string1,string2);
   display(pedro);
   printf("%s\n","StringACifrar: ");
   fgets(string, sizeof(string), stdin);
   char *p = cifrar(string,pedro);
   printf("%s\n", p);
}
