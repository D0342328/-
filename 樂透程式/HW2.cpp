#include<stdio.h>
#include<stdlib.h>
#include<time.h> 

struct data
{
   int id;	
   int num[6];
}a;
int lottery(int*,int []);//開獎 
int prize(int*,int,data[],int[]);//對獎
void result(int*,int,data[],int[]);//輸出結果 
int menu(int*);//清單 

int main(){

int x;	
int ch;
struct data a[7];
int prize_num[7]={0};
int counter;
   
    srand(time(NULL)); 
	printf("※FCU樂透開獎與對獎程式\n");
	
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
		   printf("程式結束!\n");
		   exit(0);
		default:
			system("cls");
			printf("※FCU樂透開獎與對獎程式\n");
			printf("錯誤重新選擇\n");
	    }
	}	  	
  return 0;	
}

int menu(int*counter){
	
	int ch;		
	
	if(*counter==0)
	  printf("[1]開獎\n");
	else if(*counter==1)
	  printf("[1]重新開獎\n");
	
	printf("[2]從檔案對獎\n");
	printf("[3]輸出結果\n");
	printf("[4]程式結束\n");
	printf("請選擇:");
	scanf(" %d",&ch);
	return ch;
}


int lottery(int*counter,int prize_num[]){
	
	int i,j,temp,flag=0;
	
	system("cls");
	printf("※FCU樂透開獎與對獎程式\n");
	for(i=0;i<7;i++){
		
		temp=(rand()%43)+1;                //取1~43不重複亂數 
	    
	    for(j=0;j<i;j++){
	    	
	    	if(temp==prize_num[j]){
	    		i--;
	    		break;
			}
		}
		
		if(temp!=prize_num[j])
		prize_num[i]=temp;
	}
	
	printf("開獎號碼為:");
	
    for(i=0;i<6;i++){
	   printf("%02d.",prize_num[i]);
    }
    printf(" 特別號:%02d\n",prize_num[i]);
    
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
   		printf("error:尚未開獎，請先開獎\n");
   		*counter=0;
		return flag;
	}
   	
   	printf("※FCU樂透開獎與對獎程式\n");
	printf("開獎號碼為:");
	
    for(i=0;i<6;i++){
	   printf("%02d.",prize_num[i]);
    }
    printf(" 特別號:%02d\n",prize_num[i]);
	printf("\n\n");
	printf("請輸入檔案名稱:");
   	scanf("%s",filename);
   	if((fp=fopen(filename,"r"))!=NULL){
   		i=0;
   		while((fscanf(fp,"%d. %d,%d,%d,%d,%d,%d",&a[i].id,&a[i].num[0],&a[i].num[1],&a[i].num[2],&a[i].num[3],&a[i].num[4],&a[i].num[5]))!=EOF)
		{   
		    int count=0,count2=0;
		   	for(j=0;j<6;j++){                  //數中幾個號碼			
			  for(k=0;k<6;k++){
				if(a[i].num[j]==prize_num[k]) count++;
			   }
			  if(a[i].num[j]==prize_num[6])count2++;
		    }
			printf("第%d組號碼 ",a[i].id);
		    
			for(j=0;j<6;j++){
			    printf("%02d. ",a[i].num[j]);
		    }
		    i++;
		    if(count==6)
		      printf("中獎等級:頭獎\n");
		    else if(count==5&&count2==1)
		      printf("中獎等級:貳獎\n");
		    else if(count==5)
		      printf("中獎等級:參獎\n");
		    else if(count==4&&count2==1)
		      printf("中獎等級:肆獎\n");
		    else if(count==4)
		      printf("中獎等級:伍獎\n");
		    else if(count==3&&count2==1)
		      printf("中獎等級:陸獎\n");
		    else if(count==3)
		      printf("中獎等級:普獎\n");
		    else
		      printf("中獎等級:無\n");
	    }
	    fclose(fp);
    }
	else{
		printf("開檔失敗 重新選擇\n");
		return flag;
	}
	flag++;
	return flag;
}

void result(int*counter,int flag,data a[],int prize_num[]){
	FILE *fp2;
	int i,j,k;
	
	system("cls");
	printf("※FCU樂透開獎與對獎程式\n");
	if(flag<1){
	   printf("error:尚未開獎，請先開獎\n");
   	   *counter=0;
	   return;
	}
	else if(flag<2){
	   printf("error:尚未讀檔，請先讀檔\n");
	   return;		
	}
	
	fp2=fopen("lotto_output.txt","w");
	
	fprintf(fp2,"開獎號碼為:");
	for(i=0;i<6;i++){
	   fprintf(fp2,"%02d.",prize_num[i]);
    }
    fprintf(fp2," 特別號:%02d\n",prize_num[i]);
	fprintf(fp2,"\n\n"); 	
			
		for(i=0;i<7;i++){  
		  int count=0,count2=0;                     //數中幾個號碼 
		  for(j=0;j<6;j++){
			for(k=0;k<6;k++){
				if(a[i].num[j]==prize_num[k]) count++;
			}
			if(a[i].num[j]==prize_num[6])count2++;	
		  }
		  fprintf(fp2,">>第%d組號碼 ",a[i].id);
		    
		  for(j=0;j<6;j++){
			    fprintf(fp2,"%02d. ",a[i].num[j]);
		    }
		  if(count==6)
		      fprintf(fp2,"中獎等級:頭獎\n");
		  else if(count==5&&count2==1)
		      fprintf(fp2,"中獎等級:貳獎\n");
		  else if(count==5)
		      fprintf(fp2,"中獎等級:參獎\n");
		  else if(count==4&&count2==1)
		      fprintf(fp2,"中獎等級:肆獎\n");
		  else if(count==4)
		      fprintf(fp2,"中獎等級:伍獎\n");
		  else if(count==3&&count2==1)
		      fprintf(fp2,"中獎等級:陸獎\n");
		  else if(count==3)
		      fprintf(fp2,"中獎等級:普獎\n");
		  else
		      fprintf(fp2,"中獎等級:無\n");
	    }
    fclose(fp2);	
}

