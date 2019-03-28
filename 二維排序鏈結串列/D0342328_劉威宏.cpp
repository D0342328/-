#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct list
{
	int number;
	struct list *next;
	struct list *down;
};
typedef struct list NODE;
typedef NODE* llist;

llist createtail(int );
llist getrandom(llist );
llist createnode();

int main(){
	llist head = NULL;
	int choice;
	
	srand(time(NULL));
	while(1)
	{
		printf("1)���Ͷü�(��C)  2)�����{�� :");
		scanf("%d",&choice);
		switch(choice){
			case 1 :
				system("cls");
				head = getrandom(head);
				break;
			case 2 :
				exit(0);
		}
	}
	return 0;
} 

llist createtail(int ran){
	int tail = ran % 10;
	llist head = (llist) malloc(sizeof(NODE));
	head->number  = tail;
	head->next = NULL;
	head->down = NULL; 
	return head;
}

llist createnode(){
	int ran = (rand()%999)+1;
	llist temp = (llist) malloc(sizeof(NODE));
	temp->number = ran;
	temp->down = NULL;
	temp->next = NULL;
	return temp;
}

llist getrandom(llist head){
 	llist ptr1,ptr=head,ptr_d=head,ptr_d1;

	llist temp = createnode();

	llist begin = createtail(temp->number);

	if(head==NULL){  //�@�}�l���J 
		head = begin;
		head->next = temp;
	}
	else
	{
		while(ptr_d!=NULL && ptr_d->number!=begin->number){  //�M����� 
			
			ptr_d = ptr_d->down;
		}
		if(ptr_d==NULL){ //��S���������� 
			begin->next = temp;
			ptr_d = head;
			while(ptr_d!=NULL && begin->number > ptr_d->number){  //���J�s�����Ʀ�C 
				ptr_d1 = ptr_d;
				ptr_d = ptr_d->down;
			}
			if(ptr_d==head)
			{
				begin->down = head;
				head = begin;	
			} 
			else
			{
				begin->down = ptr_d1->down;
				ptr_d1->down = begin;
			}
		}
		else        //�����Ʈɷs�W����ƫ� 
		{
			ptr = ptr_d->next;
			ptr1 = ptr_d;
			while(ptr!=NULL && temp->number > ptr->number){
				ptr1 = ptr;
				ptr = ptr->next;
			}
			if(ptr!=NULL)
			{
				if(temp->number==ptr->number)
				{
					printf("�üƤw�s�b!!\n");
					return head;
				}
			} 
				temp->next = ptr1->next;
				ptr1->next = temp;
				free(begin);
		}
	}
	
	ptr = head;
	ptr_d = head;

	while(ptr_d!=NULL){  //�L�X 
		printf("|%d| :",ptr_d->number);
		ptr = ptr_d->next;
		while(ptr!=NULL){
			printf(" %d->",ptr->number);
			ptr = ptr->next;	
		}
		printf("\n");
		ptr_d = ptr_d->down;
	}
	printf("\n");
	return head;
} 




