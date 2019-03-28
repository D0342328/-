#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct list
{
	int number;
	struct list *next;
};

typedef struct list Node;
typedef Node* llist;

llist createlist(char [],int);
void addzero(llist ,llist ,int ,int );
llist addition(llist ,llist );
void inverlisting(llist );

int main(){
	llist ptr1,ptr2,ptr3;
	char a[100],b[100];
	
	printf("輸入第一個數:");
	scanf("%s",a);
	int lenA = strlen(a);
	printf("ptr1->");
	ptr1 = createlist(a,lenA);
	printf("輸入第二個數:");
	scanf("%s",b);
	int lenB = strlen(b);
	printf("ptr2->");
	ptr2 = createlist(b,lenB);
	
	if(lenA > lenB || lenB > lenA)
	{
		addzero(ptr1,ptr2,lenA,lenB);
	}
	
	ptr3 = addition(ptr1,ptr2);
	
	inverlisting(ptr3);
	return 0;
} 

llist createlist(char arr[],int len){
	int i;
	llist head = (llist) malloc(sizeof(Node));
	head->number = *(arr+len-1)-'0';
	head->next = NULL;
	
	llist ptr = head;
	for(i=len-2;i>-1;i--){
		
		llist temp = (llist) malloc(sizeof(Node)); 
		temp->number = *(arr+i)-'0';
		temp->next = NULL;
		ptr->next = temp;
		ptr = ptr->next;
	}
	
	ptr = head;
	
	while(ptr!=NULL){
		
		printf("%d->",ptr->number);
		ptr = ptr->next;
	}
	printf("\n");
	return head;
}

void addzero(llist ptr1,llist ptr2,int lenA,int lenB){
	int i;
	llist p1 = ptr1,p2 = ptr2;
	if(lenA > lenB){
		
		int diff = lenA - lenB;
		
		for(i=0;i<diff;i++){
			llist temp = (llist) malloc(sizeof(Node));
			temp->number = 0;
			temp->next = NULL;
			while(p2->next!=NULL){
				p2 = p2->next;
			}
			p2->next = temp;
		}
	}
	else{
		
		int diff = lenB - lenA;
		
		for(i=0;i<diff;i++){
			llist temp = (llist) malloc(sizeof(Node));
			temp->number = 0;
			temp->next = NULL;
			while(p1->next!=NULL){
				p1 = p1->next;
			}
			p1->next = temp;
		}
	}	
}

llist addition(llist p1,llist p2){
	llist ptr,prev;
	int carry = 0;
	llist head = (llist) malloc(sizeof(Node));
	head->next = NULL;
	ptr = head;
	while(p1!=NULL && p2!=NULL){
		llist temp = (llist) malloc(sizeof(Node));	
		temp->next = NULL;
		ptr->number = p1->number + p2->number + carry;
		carry = ptr->number / 10;
		ptr->number = ptr->number % 10;
		ptr->next = temp;
		prev = ptr;
		ptr = ptr->next; 
		p1 = p1->next;
		p2 = p2->next;
	}
	if(carry!=0){
		ptr->number = carry;
	}
	else{
		
		free(ptr);
		prev->next = NULL;
	} 
	return head;
}

void inverlisting(llist head){
	
	llist ptr=head,cur,prev;
	printf("反轉前結果:");
	while(ptr!=NULL){
		printf("%d ",ptr->number);
		ptr = ptr->next;
	}
	cur = head;
	ptr = head->next;
	head->next = NULL;
	while(ptr!=NULL){
		prev = cur;
		cur = ptr;
		ptr = ptr->next;
		cur->next = prev;
	}
	head = cur;  
	ptr = head;
	printf("\n反轉後結果:");
	while(ptr!=NULL){
		printf("%d ",ptr->number);
		ptr = ptr->next;
	}
}
