#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 20

void sort(int,char [][100],int[],char [][100]);
 
int main(){
	FILE  *fp;
	char ch;
	char var[100],str[100][100]={0},line[100][100]={0};
	int time[100]={0};
	int count_line=1,i=0;
	
	if((fp=fopen("input.txt","r"))!=NULL)
	{
		while(!feof(fp)){
          
		  fscanf(fp,"%s",var);   
          
		  if((ch=fgetc(fp))=='\n')  //�P�_���� 
          {
            count_line++;
		  }
		  
		  int record=0;
		  for(int j=0;j<i;j++){
		  	
			  if(strlwr(var)==strlwr(str[j]) || strcmp(var,str[j])==0)
		  	  {
		  	  	record++; 
		  	  	time[j]++;                //���e����r�A�p�G�X�{���ƫh+1                  
		  	  	int k=0;
		  	  	while(line[j][k]!='\0')   //�p���ƪ���r�굲��
		  	  	{
					k++;
				}
		  	  	line[j][k]=count_line;   //������Ʀ�m
		      }
		    }
			
			if(record==0)    //�B�z�S���Ƴ���	
		  	  {
		  	  	strcpy(str[i],var);     //�@�Ӥ@�ӳ�rŪ�i�ӫ���str�}�C��
		  	  	time[i]++;              //�NŪ������r�����O���X�{1�� 
		  	  	line[0][0]=1;
		  	  	i++;
		  	  	line[i][0]=count_line;
			  }
		}  
	   
	  sort(i,str,time,line); 
	
	printf("WORD\t\t\tTIMES\t\t\tLINE\n");
	printf("========================================================\n");
	for(int k=0;k<i;k++){
		
		printf("%-20s\t%d\t\t\t",str[k],time[k]);
		
		int c=0;
		while(line[k][c]!='\0')
		{
			if(time[k]==1) printf("%d",line[k][c++]);
			
			else        printf("%d, ",line[k][c++]);
		}
		printf("\n");
	  } 
    fclose(fp);
	}
	else
	{
		printf("�}�ɥ���\n");
		return 0;
	}
}
	void sort(int count,char str[][100],int time[],char line[][100]){
		
		char temp_str[MAXSIZE] , temp_line[MAXSIZE];
		int temp_time;
		
		for(int j=0;j<count;j++){
			
			for(int i=0;i<count-1;i++){
				
				if(strncmp(str[i],str[i+1],MAXSIZE)>0)
				{
					strcpy(temp_str,str[i]);
					strcpy(str[i],str[i+1]);
					strcpy(str[i+1],temp_str);
					
					temp_time=time[i];
					time[i]=time[i+1];
					time[i+1]=temp_time;
					
					strcpy(temp_line,line[i]);
					strcpy(line[i],line[i+1]);
					strcpy(line[i+1],temp_line);
				}
			}
		}	
	} 

