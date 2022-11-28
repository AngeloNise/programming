//header files
#include <stdio.h>
#include <stdlib.h>

struct node{  //structure definition & structure variable declaration
	int num;
	struct node *prev;
	struct node *next;
}*head, *tail;  //tucked-in

//declaration of functions
void nodeCreation(int nd);
void insertBeginning(int num);
void nodeDisplay(int a);

int main(){  //main program
	int nd, num1, a, ans;
	head = NULL;
	tail = NULL;
	
	printf("\n\t\t\t    DOUBLY LINKED LIST");
	printf("\n\t\t--Inserting a New Node at the Beginning--");
	
	do{
		printf("\n\n\t   Please enter the number of nodes you want to make: ");
		scanf("%d", &nd);
		
		if(nd == 0){
			printf("\n\t    >> Invalid input! <<");
			printf("\n\n\t   Would you like to try again? (1 for YES, 0 for NO): ");
			scanf("%d",&ans);
		}
		else{
			nodeCreation(nd);  //function call
			a=1;  //value to be sent in the function for display; value for displaying the data of all nodes
			
			nodeDisplay(a);  //function call
			printf("\n\t   Please input data to insert at the beginning: ");
			scanf("%d",&num1);
			
			insertBeginning(num1);  //function call
			a=2;  //value to be sent in the function for display; value for displaying the new list of nodes
			
			nodeDisplay(a);  //function call
			
			printf("\n\t   Would you like to try again? (1 for YES, 0 for NO): ");
			scanf("%d",&ans);
		}
	}while(ans==1);
	
	printf("\n\n\t\t  --Thank you for using the program!--\n");
	return 0;
}

void nodeCreation(int nd){  //function for creating nodes
	int i, num;
	struct node *curr;
	
	if(nd>=1){
		head = (struct node *)malloc(sizeof(struct node));  //assigns an address for the head
		
		if(head != NULL){
			printf("\n\t     > Kindly input data for Node 1: ");
			scanf("%d",&num);
			
			head->num = num;  //assigns data for the head
			head->prev = NULL;  //previous address of head is set to NULL
			head->next = NULL;  //next address of head is set to NULL
			tail = head;  //the tail of the list is also the head; we still haven't determined the next node
			
			for(i=2; i<=nd; i++){
				curr = (struct node *)malloc(sizeof(struct node));  //assigns an address for a node
				
				if(curr != NULL){
					printf("\t     > Kindly input data for Node %d: ",i);
					scanf("%d",&num);
					
					curr->num = num;  //assigns data to current node
					curr->prev = tail;  //current node is linked with tail or the last node
					curr->next = NULL;  //next address of current node is set to NULL
					tail->next = curr;  //next address of tail is set to the address of current node
					tail = curr;  //assigns current node as the new tail
				}
				else{
					printf("\n\t   Memory cannot be allocated.");
					break;
				}
			}
		}
		else{
			printf("\n\t   Memory cannot be allocated.");
		}
	}
}

void nodeDisplay(int a){  //function for displaying all nodes
	struct node *tmp;
	int n=1;
	
	if(head == NULL){
		printf("\n\t   No data found in the list yet.");
	}
	else{
		tmp = head;
		
		if(a==1){
			printf("\n\t   Data entered in the list are:\n");
		}
		else{
			printf("\n\t   After insertion, the new list is:\n");
		}
		
		while(tmp != NULL){  //displays all the nodes inside the list
			printf("\t     Node %d: %d\n",n,tmp->num);
			n++;
			tmp = tmp->next;
		}
	}
}

void insertBeginning(int num){  //function to add a new node at the beginning of the list
	struct node *newNode;
	
	if(head == NULL){
		printf("\n\t   No data found in the list!");
	}
	else{
		newNode = (struct node *)malloc(sizeof(struct node));  //assigns an address for the new node
		newNode->num = num;  //assigns the new node a value
		newNode->next = head;  //next address of new node is linked with the head
		newNode->prev = NULL;  //previous address of new node is set to NULL
		head->prev = newNode;  //previous address of head is linked with new node
		head = newNode;  //new node as the new head of the list
	}
}
