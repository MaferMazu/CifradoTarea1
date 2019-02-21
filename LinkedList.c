#include "LinkedList.h"


struct Node {
        char id;
        struct Node *next;
        struct Node *prev;
        };

struct Node *head = NULL;
struct Node *tail = NULL;


struct Node* create(char id)
{
	struct  Node *ptr = (struct Node*)malloc(sizeof(struct Node));
	if (ptr == NULL){
		printf("Fallo al crear\n");
		return NULL;
	}
	ptr->id = id;
	ptr->next = NULL;
	ptr->prev = NULL;

	head = ptr;
	tail = ptr;
	return ptr;
};

struct Node* add(char id, _Bool add_to_end)
{
	if(head == NULL){
		return (create(id));
	}

	struct  Node *ptr = (struct Node*)malloc(sizeof(struct Node));
	if (ptr == NULL){
		printf("Fallo al crear\n");
		return NULL;
	}

	ptr->id = id;
	ptr->next = NULL;

	if(add_to_end){
		ptr->prev = tail;
        tail->next = ptr;
        tail = ptr;
    }
    else{
    	ptr->next = head;
    	head->prev = ptr;
    	head = ptr;

    }
    return ptr;

}

struct Node* delete(char id)
{
	
};

/*struct Node* search(char id)
{
	_Bool found = false;

	while(ptr != NULL){
		if(ptr->id == id){
			found = true
			break;
		}
		else{

		}

	}
};*/

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}