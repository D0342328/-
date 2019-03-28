#include<stdio.h>
#include<stdlib.h>
#include<time.h> 

struct data
{
   int id;	
   int num[6];
}a;
int lottery(int*,int []);//�}�� 
int prize(int*,int,data[],int[]);//���
void result(int*,int,data[],int[]);//��X���G 
int menu(int*);//�M�� 

int main(){

int x;	
int ch;
struct data a[7];
int prize_num[7]={0};
int counter;
   
    srand(time(NULL)); 
	printf("��FCU�ֳz�}���P����{��\n");
	
	while(ch!=4){
		
		ch = menu(&counter);
		fflush(stdin);
		switch(ch){
		case 1:
		   x=lottery(&counter,prize_num);
		   break;	
		case 2:
		   x=prize(&counter,x,a,prize_num);
		   break;
		case 3:
		   result(&counter,x,a,prize_num);
		   break;
		case 4:
		   printf("�{������!\n");
		   exit(0);
		default:
			system("cls");
			printf("��FCU�ֳz�}���P����{��\n");
			printf("���~���s���\n");
	    }
	}	  	
  return 0;	
}

int menu(int*counter){
	
	int ch;		
	
	if(*counter==0)
	  printf("[1]�}��\n");
	else if(*counter==1)
	  printf("[1]���s�}��\n");
	
	printf("[2]�q�ɮ׹��\n");
	printf("[3]��X���G\n");
	printf("[4]�{������\n");
	printf("�п��:");
	scanf(" %d",&ch);
	return ch;
}


int lottery(int*counter,int prize_num[]){
	
	int i,j,temp,flag=0;
	
	system("cls");
	printf("��FCU�ֳz�}���P����{��\n");
	for(i=0;i<7;i++){
		
		temp=(rand()%43)+1;                //��1~43�����ƶü� 
	    
	    for(j=0;j<i;j++){
	    	
	    	if(temp==prize_num[j]){
	    		i--;
	    		break;
			}
		}
		
		if(temp!=prize_num[j])
		prize_num[i]=temp;
	}
	
	printf("�}�����X��:");
	
    for(i=0;i<6;i++){
	   printf("%02d.",prize_num[i]);
    }
    printf(" �S�O��:%02d\n",prize_num[i]);
    
    flag++;
    *counter=1;
    return flag;
}

int prize(int*counter,int flag,data a[],int prize_num[]){
   	FILE *fp;
   	int i=0,j,k;
   	char filename[100];
   	
   	
   	system("cls");
   	if(flag<1){
   		printf("error:�|���}���A�Х��}��\n");
   		*counter=0;
		return flag;
	}
   	
   	printf("��FCU�ֳz�}���P����{��\n");
	printf("�}�����X��:");
	
    for(i=0;i<6;i++){
	   printf("%02d.",prize_num[i]);
    }
    printf(" �S�O��:%02d\n",prize_num[i]);
	printf("\n\n");
	printf("�п�J�ɮצW��:");
   	scanf("%s",filename);
   	if((fp=fopen(filename,"r"))!=NULL){
   		i=0;
   		while((fscanf(fp,"%d. %d,%d,%d,%d,%d,%d",&a[i].id,&a[i].num[0],&a[i].num[1],&a[i].num[2],&a[i].num[3],&a[i].num[4],&a[i].num[5]))!=EOF)
		{   
		    int count=0,count2=0;
		   	for(j=0;j<6;j++){                  //�Ƥ��X�Ӹ��X			
			  for(k=0;k<6;k++){
				if(a[i].num[j]==prize_num[k]) count++;
			   }
			  if(a[i].num[j]==prize_num[6])count2++;
		    }
			printf("��%d�ո��X ",a[i].id);
		    
			for(j=0;j<6;j++){
			    printf("%02d. ",a[i].num[j]);
		    }
		    i++;
		    if(count==6)
		      printf("��������:�Y��\n");
		    else if(count==5&&count2==1)
		      printf("��������:�L��\n");
		    else if(count==5)
		      printf("��������:�Ѽ�\n");
		    else if(count==4&&count2==1)
		      printf("��������:�v��\n");
		    else if(count==4)
		      printf("��������:���\n");
		    else if(count==3&&count2==1)
		      printf("��������:����\n");
		    else if(count==3)
		      printf("��������:����\n");
		    else
		      printf("��������:�L\n");
	    }
	    fclose(fp);
    }
	else{
		printf("�}�ɥ��� ���s���\n");
		return flag;
	}
	flag++;
	return flag;
}

void result(int*counter,int flag,data a[],int prize_num[]){
	FILE *fp2;
	int i,j,k;
	
	system("cls");
	printf("��FCU�ֳz�}���P����{��\n");
	if(flag<1){
	   printf("error:�|���}���A�Х��}��\n");
   	   *counter=0;
	   return;
	}
	else if(flag<2){
	   printf("error:�|��Ū�ɡA�Х�Ū��\n");
	   return;		
	}
	
	fp2=fopen("lotto_output.txt","w");
	
	fprintf(fp2,"�}�����X��:");
	for(i=0;i<6;i++){
	   fprintf(fp2,"%02d.",prize_num[i]);
    }
    fprintf(fp2," �S�O��:%02d\n",prize_num[i]);
	fprintf(fp2,"\n\n"); 	
			
		for(i=0;i<7;i++){  
		  int count=0,count2=0;                     //�Ƥ��X�Ӹ��X 
		  for(j=0;j<6;j++){
			for(k=0;k<6;k++){
				if(a[i].num[j]==prize_num[k]) count++;
			}
			if(a[i].num[j]==prize_num[6])count2++;	
		  }
		  fprintf(fp2,">>��%d�ո��X ",a[i].id);
		    
		  for(j=0;j<6;j++){
			    fprintf(fp2,"%02d. ",a[i].num[j]);
		    }
		  if(count==6)
		      fprintf(fp2,"��������:�Y��\n");
		  else if(count==5&&count2==1)
		      fprintf(fp2,"��������:�L��\n");
		  else if(count==5)
		      fprintf(fp2,"��������:�Ѽ�\n");
		  else if(count==4&&count2==1)
		      fprintf(fp2,"��������:�v��\n");
		  else if(count==4)
		      fprintf(fp2,"��������:���\n");
		  else if(count==3&&count2==1)
		      fprintf(fp2,"��������:����\n");
		  else if(count==3)
		      fprintf(fp2,"��������:����\n");
		  else
		      fprintf(fp2,"��������:�L\n");
	    }
    fclose(fp2);	
}

