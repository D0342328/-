/*以陣列儲存52張牌
洗牌時以亂數重置52張牌排序
發牌時依陣列序發牌，就不會重複了
此舉讓程式執行動作加速極多(因為不必每次發牌時檢查比對該張牌是否重複)
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
		printf("請選擇(1)進行21點(2)博弈對戰(3)結束遊戲\n");
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
				printf("\n＊＊　Game is Over　＊＊");
				break;
			default:
				printf("Error！\n");	
		}
	} while(choose!=3);
	return choose;
}
int gamble(int get){
	
	int pay;
	system("cls");
	printf("您有初始籌碼:$%d\n",SIZE);
	printf("--------------------\n");
	printf("輸入押金:");
	scanf("%d",&pay);
	get = cardgame(pay);
	printf("\n剩餘籌碼:$%d\n",get);
	if(get<pay){
		printf("籌碼不足，無法繼續博弈！\n");
		
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
					out++;                                                //52張牌排列 
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
	myleng=myleng+2;                                                 //先給莊家跟玩家各兩張 
	
	bacard[0][0]=card[2][0];
	bacard[0][1]=card[2][1];
	bacard[1][0]=card[3][0];
	bacard[1][1]=card[3][1];
	baleng=baleng+2;
//------------------------------------------------------------------	
	int i=0;
	
	printf("你的牌:");
	while(1){
        if(mycard[i][0]==0)break;
        showcard(mycard[i][0],mycard[i][1]);							 //一開始的兩張牌
        i++;
    }    
	                                                                
    printf("\n莊家的牌:");
    showcard(bacard[0][0],bacard[0][1]);
    printf("\n");
//-------------------------------------------------------------------	
    do{
        char add='N';
        
        printf("是否要加牌?Y/N\n");
        add = getch();
        if(add=='Y'||add=='y'){
            mycard[myleng][0]=card[myleng+baleng][0];
            mycard[myleng][1]=card[myleng+baleng][1];
            myleng++;
            int i=0;

	        printf("你的牌:");
	        while(1){                                                     //玩家加牌 
                if(mycard[i][0]==0)break;
                showcard(mycard[i][0],mycard[i][1]);
                i++;
            }  
             
            for(int j=0;j<myleng;j++)
                temp[j]=mycard[j][0];
            mypoint=point(temp,myleng);
            printf("現在有%d點\n",mypoint);
            if(mypoint>21)goto end;
        }                                                                 
        
        else if(add=='N'||add=='n') break;								   //防呆 
        	
        else printf("輸入有誤，請重新輸入");
        
    } while(1);    
//-------------------------------------------------------------------    
    do{
        for(int j=0;j<baleng;j++)
                temp[j]=bacard[j][0];
                
        bapoint=point(temp,baleng);
        if(bapoint<17){
            bacard[baleng][0]=card[baleng+myleng][0];
            bacard[baleng][1]=card[baleng+myleng][1];                    //莊家加牌 
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
    //勝負 
    if(mypoint>21){
    	int a;
        printf("莊家>>%d點，你>>%d點。你爆了，莊家贏\n",bapoint,mypoint);
        money = SIZE;
        return  money;                                                        
    }
    else if(bapoint>21){
    
        printf("莊家>>%d點，你>>%d點。莊家爆了，玩家贏\n",bapoint,mypoint);
        return money;
    }
    else if(bapoint>=mypoint){
    	
        printf("莊家>>%d點，你>>%d點，莊家贏\n",bapoint,mypoint);
        return money;
    }
    else if(mypoint>bapoint){
    	
        printf("莊家>>%d點，你>>%d點，你贏了\n",bapoint,mypoint);
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
	    case 2:                                                   //顯示牌 
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
            except++;                                                 //牌的點數 
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

