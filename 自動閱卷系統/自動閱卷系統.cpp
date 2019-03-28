#include<stdio.h>
#include<stdlib.h>

struct stdans
{
  char question[4];  	
  int score;	
  char ans;	
}a;

struct student
{
  char id[9];	
  char ans[6];	
}b;

struct rank
{
  char id[9];
  int score;
}c;

char menu();
int read(stdans [],student []);
void printGrade(int,rank []);
void result(int,rank []);

int main(){

struct stdans a[10];
struct student b[10];
struct rank  c[15];
char ch;
int x=0;	
	
	while(ch!='D'){
		
		ch=menu();
		fflush(stdin);
		switch(ch){
			case 'A':
			    x=read(a,b);	
				break;
			case 'B':
				printGrade(x,c);
				break;
			case 'C':
			    result(x,c);
				break;	
			case 'D':
			    printf("程式結束!\n"); 
			    exit(0);
			default:
			    system("cls");
				printf("錯誤請重新輸入!\n");	 
		}
	}
	return 0;
} 

char menu(){
	
	char ch;
	
	printf("\t操作\功\能選項\n");
	printf("\t=============\n");
	printf("(A)開始閱\卷\ \n");
	printf("(B)顯示高標、均標、與低標成績\n");
	printf("(C)顯示依總成績排序後的結果\n");
	printf("(D)結束執行\n");
	printf("選擇\功\能:\n");
	scanf("%c",&ch);
	
	return ch;
}

int read(stdans a[],student b[]){
	
	FILE *fp,*fp2,*fp3;
	int i=0,j=0,k,flag=0,count=0;
	char file[30][9]={0};
	int sum[30]={0};
	
	system("cls");
	if((fp=fopen("StdAns.txt","r"))!=NULL){              //先讀標準答案 
       while((fscanf(fp,"%s %d %c",a[i].question,&a[i].score,&a[i].ans))!=EOF){
       	   i++;
	   }
	   	fclose(fp);
	}
	else{
		printf("fail\n");
		return flag;
	}
	flag++;
	
	fp3=fopen("result.txt","w");
	for(k=0;k<30;k++){                          //按照檔名讀取每個檔案 
		sprintf(file[k],"A0%02d.txt",k+1);  
		  if((fp2=fopen(file[k],"r"))!=NULL){
		  	  count++;
			  fscanf(fp2,"%s\n",b->id);
			  while(!feof(fp2))                          
			  {  
			     fgets(b[j].ans,7,fp2);                  //每位學生的答案跟標準答案做批改動作 
				 if(b[j].ans[4]==a[j].ans) sum[k]+=a[j].score;
				 j++;
			  }
			  j=0;                                
			  fprintf(fp3,"%s\t%3d\n",b->id,sum[k]);  //把准考證跟分數印到Result檔案裡 
		  }
		  fclose(fp2);
	}	
	fclose(fp3);
	printf("閱\卷\完成\n");	
    flag++;
	return flag;
}

void printGrade(int flag,rank c[]){
	
	struct rank temp[15];
	FILE *fp;
	float high=0,avg=0,low=0;
	int i=0,j,count=0;
	char ch; 
	 
	system("cls");
	if(flag<2){
		printf("尚未\閱\卷 請先\閱\卷\n");
		return ;
	}
	
   if((fp=fopen("result.txt","r+"))!=NULL){
   	 while((fscanf(fp,"%s %d",c[i].id,&c[i].score))!=EOF){
   	      if((ch=fgetc(fp))=='\n') count++;
   	      i++;
		}
	 for(i=0;i<count;i++){                //先做分數排序再算高低均標 
	 	for(j=i+1;j<count;j++){
	 		if(c[i].score<c[j].score)
			 {
			 	temp[i]= c[i];
			 	c[i]=c[j];
			 	c[j]=temp[i];
			 }
		 }
	 } 
	 
	 printf("考生人數:%d人\n",count);
	 int count2=count/4;
	 for(i=0;i<count2;i++) 	
	 {
	    high+=c[i].score;	
	 }
	 printf("高標:%.2f分\n",high/count2);
	 for(i=0;i<count;i++) 	
	 {
	    avg+=c[i].score;	
	 }
	 printf("均標:%.2f分\n",avg/count);
	 for(i=count-count2;i<count;i++) 	
	 {
	    low+=c[i].score;	
	 }
	 printf("低標:%.2f分\n",low/count2);
	 fprintf(fp,"高標\t\t%.2f\n",high/count2);
	 fprintf(fp,"均標\t\t%.2f\n",avg/count);
	 fprintf(fp,"低標\t\t%.2f\n",low/count2);
	 
	 fclose(fp);	
   }
   else{
   	printf("fail\n");
   	return;
   }	 		
   return;	
}

void result(int flag,rank c[]){
	
	struct rank temp[15];
	FILE *fp; 
	int i=0,j,total=0;
	char ch;
	
	system("cls");
	if(flag<2){
		printf("尚未\閱\卷 請先\閱\卷\n");
		return;
	}
	
	if((fp=fopen("result.txt","r"))!=NULL){
		while((fscanf(fp,"%s %d",c[i].id,&c[i].score))!=EOF)
		{
		  if((ch=fgetc(fp))=='\n') total++; 
		  i++;	
		}
		
		printf("准考證號\t最後成績\t名次\n");
		printf("=====================================\n");
		
		for(i=0;i<total;i++){
			for(j=i+1;j<total;j++){
				if(c[i].score<c[j].score){
					temp[i]=c[i];
					c[i]=c[j];
					c[j]=temp[i];
				}
			}
		}
		for(i=0;i<total;i++){
			printf("%s\t%d\t\t%d\n",c[i].id,c[i].score,i+1);
		}
	}
	else
	{
		printf("fail\n");
		return; 
	}
	fclose(fp);
	printf("恭喜!\n");
	return;
}
