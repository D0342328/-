/*�H�}�C�x�s52�i�P
�~�P�ɥH�üƭ��m52�i�P�Ƨ�
�o�P�ɨ̰}�C�ǵo�P�A�N���|���ƤF
���|���{������ʧ@�[�t���h(�]�������C���o�P���ˬd���ӱi�P�O�_����)
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#define SIZE 1000 

int choice(int);
int gamble(int);
int cardgame(int);
void showcard(int,int);
int point(int*,int);

int main()
{
	int choose,a;
		while(a!=3){
			a = choice(choose);
		}
		
		return 0;	
}

int choice(int choose){
	int a,b;
	do{
		printf("---------------------------------------\n");
		printf("�п��(1)�i��21�I(2)�իٹ��(3)�����C��\n");
		printf("---------------------------------------\n");
		scanf("%d",&choose);
		switch(choose){
			case 1:
				cardgame(10);
				break;
			case 2:
				b =	gamble(a);
				break;
			case 3:
				printf("\n�����@Game is Over�@����");
				break;
			default:
				printf("Error�I\n");	
		}
	} while(choose!=3);
	return choose;
}
int gamble(int get){
	
	int pay;
	system("cls");
	printf("�z����l�w�X:$%d\n",SIZE);
	printf("--------------------\n");
	printf("��J���:");
	scanf("%d",&pay);
	get = cardgame(pay);
	printf("\n�Ѿl�w�X:$%d\n",get);
	if(get<pay){
		printf("�w�X�����A�L�k�~��ի١I\n");
		
	} 
	return pay;
	
}
int cardgame(int money){
	
	srand(time(NULL));
	int pay;
	int a;
	int card[52][2]={0};
	int mycard[13][2]={0};
	int bacard[13][2]={0};
	int myleng=0,baleng=0;
    int mypoint,bapoint;
    int temp[13]={0};
//------------------------------------------------------------	
	for(int i=0;i<52;i++){
		int randa,randb;
		do{
			int out=0;
			randa=rand()%13+1;
			randb=rand()%4+1;
			for(int j=0;j<52;j++){
				if(randa==card[j][0]&&randb==card[j][1]){
					out++;                                                //52�i�P�ƦC 
					break;
				}
			}
			if(out>0)continue;
			break;
		} while(1);
		card[i][0]=randa;
		card[i][1]=randb;	
	}
//----------------------------------------------------------------
	mycard[0][0]=card[0][0];
	mycard[0][1]=card[0][1];
	mycard[1][0]=card[1][0];
	mycard[1][1]=card[1][1];
	myleng=myleng+2;                                                 //�������a�򪱮a�U��i 
	
	bacard[0][0]=card[2][0];
	bacard[0][1]=card[2][1];
	bacard[1][0]=card[3][0];
	bacard[1][1]=card[3][1];
	baleng=baleng+2;
//------------------------------------------------------------------	
	int i=0;
	
	printf("�A���P:");
	while(1){
        if(mycard[i][0]==0)break;
        showcard(mycard[i][0],mycard[i][1]);							 //�@�}�l����i�P
        i++;
    }    
	                                                                
    printf("\n���a���P:");
    showcard(bacard[0][0],bacard[0][1]);
    printf("\n");
//-------------------------------------------------------------------	
    do{
        char add='N';
        
        printf("�O�_�n�[�P?Y/N\n");
        add = getch();
        if(add=='Y'||add=='y'){
            mycard[myleng][0]=card[myleng+baleng][0];
            mycard[myleng][1]=card[myleng+baleng][1];
            myleng++;
            int i=0;

	        printf("�A���P:");
	        while(1){                                                     //���a�[�P 
                if(mycard[i][0]==0)break;
                showcard(mycard[i][0],mycard[i][1]);
                i++;
            }  
             
            for(int j=0;j<myleng;j++)
                temp[j]=mycard[j][0];
            mypoint=point(temp,myleng);
            printf("�{�b��%d�I\n",mypoint);
            if(mypoint>21)goto end;
        }                                                                 
        
        else if(add=='N'||add=='n') break;								   //���b 
        	
        else printf("��J���~�A�Э��s��J");
        
    } while(1);    
//-------------------------------------------------------------------    
    do{
        for(int j=0;j<baleng;j++)
                temp[j]=bacard[j][0];
                
        bapoint=point(temp,baleng);
        if(bapoint<17){
            bacard[baleng][0]=card[baleng+myleng][0];
            bacard[baleng][1]=card[baleng+myleng][1];                    //���a�[�P 
            baleng++;
            
        }
        else break; 

    }while(1);
    
    
//------------------------------------------------------------------    
    end:
    for(int j=0;j<myleng;j++)
        temp[j]=mycard[j][0];
    mypoint=point(temp,myleng);    
        
    for(int j=0;j<baleng;j++)
        temp[j]=bacard[j][0];
    bapoint=point(temp,baleng);
    
    i=0;

    while(1){                                                    
        
        if(bacard[i][0]==0)break;
        showcard(bacard[i][0],bacard[i][1]);
        i++;
    }
    
    i=0;
    printf("\n");
    
    while(1){                                                    
        
        if(mycard[i][0]==0)break;
        showcard(mycard[i][0],mycard[i][1]);
        i++;
    } 
    //�ӭt 
    if(mypoint>21){
    	int a;
        printf("���a>>%d�I�A�A>>%d�I�C�A�z�F�A���aĹ\n",bapoint,mypoint);
        money = SIZE;
        return  money;                                                        
    }
    else if(bapoint>21){
    
        printf("���a>>%d�I�A�A>>%d�I�C���a�z�F�A���aĹ\n",bapoint,mypoint);
        return money;
    }
    else if(bapoint>=mypoint){
    	
        printf("���a>>%d�I�A�A>>%d�I�A���aĹ\n",bapoint,mypoint);
        return money;
    }
    else if(mypoint>bapoint){
    	
        printf("���a>>%d�I�A�A>>%d�I�A�AĹ�F\n",bapoint,mypoint);
        return money;
    }  
//-------------------------------------------------------------------

}

void showcard(int num,int flo){
	
	if(num<=10&&num>1)printf("%d",num);
	else if(num==11)printf("J");
	else if(num==12)printf("Q");
	else if(num==13)printf("K");
	else if(num==1)printf("A");
	
	switch (flo){
		case 1:
		    printf("%c ",flo+4);	
		    break;
	    case 2:                                                   //��ܵP 
		    printf("%c ",flo+2);		
		    break;
	    case 3:
		    printf("%c ",flo);
		    break;
	    case 4:
		    printf("%c ",flo+2);
		    break;
    }
}
//-------------------------------------------------------------------- 
int point(int *card,int leng){
    
    int count=0,except=0;

    for(int i=0;i<leng;i++){
        
        if(card[i]<=10&&card[i]>1){
            
            count=count+card[i];
            
        }
        
        else if(card[i]>10){
            
            count=count+10;
        }
       
        else if(card[i]==1){
            
            count=count+11;
            except++;                                                 //�P���I�� 
        }   
    }
    
    if(count>21&&except!=0){
        for(;except>0;){
            if(count>21&&except>0){
                except--;
                count=count-10;
            }
            if(count<=21)break;
        }
    }
    return count;
}

