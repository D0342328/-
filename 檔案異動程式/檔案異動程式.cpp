#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
	char id[9];
	int score_T;
	int score_TA;
} master;
typedef struct {
	char id[9];
	char op;
	int score_T;
	int score_TA;
} update;
typedef struct { 
	char id[9];
	int score_T;
	int score_TA;
	int sum;
	float avg;
} student;

int readmasFile(int );
int readupFile(int );
void add(master *,update *,int);
void mod(master *,update *,int);
void del(master *,update *,int);
void output(int );

int main(){
	
	
	FILE *fp,*fp2;
	int ch, i = 0,j = 0;
	
	int masSize = readmasFile(0);
	int upSize = readupFile(0);
	
	master *a = (master*) malloc (masSize * sizeof(master));
	update *b = (update*) malloc (upSize * sizeof(update)); 
	
	if((fp=fopen("master.txt","r"))!=NULL){					//讀取主檔 
		while((fscanf(fp,"%s %d %d",(a+i)->id,&(a+i)->score_T,&(a+i)->score_TA))!=EOF)
		{
			printf("%s %d %d\n",(a+i)->id,(a+i)->score_T,(a+i)->score_TA);
			i++;	
		}
		fclose(fp);
	}
	if((fp2=fopen("update.txt","r"))!=NULL){					//讀取主檔 
		while((fscanf(fp2,"%s %c %d %d",(b+j)->id,&(b+j)->op,&(b+j)->score_T,&(b+j)->score_TA))!=EOF)
		{
			printf("%s %c %d %d\n",(b+j)->id,(b+j)->op,(b+j)->score_T,(b+j)->score_TA);
			j++;	
		}
		fclose(fp2);
	}
}

int readmasFile(int count){
	FILE *fp; 
	master *a = (master*) malloc(sizeof(master));
	
	if((fp=fopen("master.txt","r"))!=NULL){					//讀取主檔 
		while((fscanf(fp,"%s %d %d",a->id,&a->score_T,&a->score_TA))!=EOF)
		{
			count++;
		}
		printf("Master筆數:%d\n",count);
		free(a); 
		fclose(fp);
	}
	return count;
}

int readupFile(int count){
	FILE *fp; 
	update *a = (update*) malloc(sizeof(update));
	
	if((fp=fopen("update.txt","r"))!=NULL){					//讀取主檔 
		while((fscanf(fp,"%s %c %d %d",a->id,&a->op,&a->score_T,&a->score_TA))!=EOF)
		{
			count++;
		}
		printf("Update筆數:%d\n",count);
		free(a);  
		fclose(fp);
	}
	return count;
}
	int up_s = 0;
	if((fp2=fopen("update.txt","r"))!=NULL){				//讀取異動檔 
		while(1)
		{
			up_s++;
			b = (update *)realloc(b, up_s *sizeof(update));
			fscanf(fp2,"%s %c %d %d",(b+up_s-1)->id,&((b+up_s-1)->op),&((b+up_s-1)->score_T),&((b+up_s-1)->score_TA));
			if(feof(fp2))	break;
		}
		fclose(fp2);
	}

	fp=fopen("master.txt","w");
	for(int i=0;i<mas_s;i++){								//比對主異動檔的資料，保留不作變動的部分並重新寫回主檔 
		int index = 0;
		for(int j=0;j<up_s;j++){
			if(strcmp(a[i].id,b[j].id)!=0){
				index++;
			}
		}
		if(index == up_s)	fprintf(fp,"%s %3d %3d\n",a[i].id,a[i].score_T,a[i].score_TA);
	}
	fclose(fp);
	
	printf("\n");
	for(int i=0;i<up_s;i++){								//到對應的函式進行更新動作 
		switch((b+i)->op)								
		{
			case '+':
				add(a,b+i,mas_s);
				break;
			case '*':
				mod(a,b+i,mas_s);
				break;
			case '-':
				del(a,b+i,mas_s);
		}
	}
	
	int count = 0;
	if((fp=fopen("master.txt","r"))!=NULL)
	{
		while(1)
		{
			if((ch=getc(fp))=='\n')	count++;		//計算更新後主檔的資料筆數 
			if(feof(fp))	break;
		}
		fclose(fp);
	}
	
	output(count);										//結果輸出檔案 
	
	free(a);
	free(b);
	return 0;
}

void add(master *x,update *y,int size){
	FILE *fp = fopen("master.txt","a");
	
	int flag = 0;
	for(int i=0;i<size;i++){
		if(strcmp(x[i].id,y->id)==0){
			printf("錯誤：新增時主檔已有相同ID:%s\n",x[i].id);
			flag = -1;
			fprintf(fp,"%s %3d %3d\n",x[i].id,x[i].score_T,x[i].score_TA);
		}
	}
	if(flag!=-1){
		fprintf(fp,"%s %3d %3d\n",y->id,y->score_T,y->score_TA);
	}
	fclose(fp);
}

void mod(master *x,update *y,int size){
	FILE *fp = fopen("master.txt","a");
	
	int index,flag = 0;
	for(int i=0;i<size;i++){
		if(strcmp(x[i].id,y->id)==0){
			strcpy(x[i].id,y->id);
			if(y->score_T!=-1)	 x[i].score_T = y->score_T;
			if(y->score_TA!=-1)	 x[i].score_TA = y->score_TA;
			flag = -1;
			fprintf(fp,"%s %3d %3d\n",x[i].id,x[i].score_T,x[i].score_TA);
		}
	}
	if(flag!=-1){
		printf("錯誤：更新時主檔不存在ID:%s\n",y->id);
	}
	fclose(fp);
}

void del(master *x,update *y,int size){
	FILE *fp = fopen("master.txt","a");
	
	int flag = 0;
	for(int i=0;i<size;i++){
		if(strcmp(x[i].id,y->id)==0){
			flag = -1;
		}
	}
	if(flag!=-1){
		printf("錯誤：刪除時主檔不存在ID:%s\n",y->id);
	}
	fclose(fp);
}

void output(int cn){										
	student stu[cn],temp;
	FILE *fp,*fp2;
	float sum;
	float ave[2]={0},stan[2]={0},sigma[2]={0};
	
	int i = 0;
	if((fp=fopen("master.txt","r"))!=NULL){					//讀取更新後的主檔資料 
		while(fscanf(fp,"%s %d %d",stu[i].id,&stu[i].score_T,&stu[i].score_TA)!=EOF)
		{
			i++;
		} 
		fclose(fp);
	}
	for(i=0;i<cn-1;i++){										//ID排序
		for(int j=i+1;j<cn;j++){
			if(strncmp(stu[i].id,stu[j].id,8)>0){
				temp = stu[i];
				stu[i] = stu[j];
				stu[j] = temp;
			}
		}
	}
	
	fp2 = fopen("d0382115.txt","w");
	for(i=0;i<cn;i++){										//總分與平均 
		stu[i].sum = stu[i].score_T + stu[i].score_TA;
		stu[i].avg = stu[i].sum / 2.0;
		sum += stu[i].sum;
		ave[0] += stu[i].score_T; 
		ave[1] += stu[i].score_TA;
		fprintf(fp2,"%s %3d %3d %3d %.2f\n",stu[i].id,stu[i].score_T,stu[i].score_TA,stu[i].sum,stu[i].avg);
	}
	fclose(fp2); 
	
	sum /= (cn<<1);
	ave[0] /= cn;
	ave[1] /= cn;

	fp2 = fopen("d0382115.txt","a");
	for(i=0;i<cn;i++){										//標準差 
		stan[0] = stu[i].score_T - ave[0];
		stan[0] *= stan[0];
		sigma[0] += stan[0];
		stan[1] = stu[i].score_TA - ave[1];
		stan[1] *= stan[1];
		sigma[1] += stan[1];
	}
	sigma[0] /= cn;
	sigma[1] /= cn;
	fprintf(fp2,"\nAvg. %.2f %.2f %.2f\nDev. %.2f %.2f",ave[0],ave[1],sum,sqrt(sigma[0]),sqrt(sigma[1]));
	fclose(fp2);	
}
