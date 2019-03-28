import java.io.IOException;
import java.io.FileNotFoundException;
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Scanner;
import java.text.DecimalFormat;

public class mainclass {
	static int movieNum =20;
	public static void main(String[] args)throws IOException {
		
			mainclass mov = new mainclass();
		String[] movies = new String[movieNum]; //儲存電影名
		mov.getMovieNames(movies); //讀電影檔案
		Scanner in=new Scanner(System.in);
		System.out.println("請輸入評審人數:");
		int r =in.nextInt(); //儲存評審人數
		int[][] stda= new int[r][movieNum]; //儲存劇情分數 
		int [] a_sum = new int[movieNum];	//儲存劇情分數總和
		double[] avg_a = new double[movieNum]; //儲存劇情分數平均
		int[][] stdb= new int[r][movieNum]; //儲存聲音畫面表現分數
		int [] b_sum = new int[movieNum]; 	//儲存聲音畫面表現總和
		double[] avg_b = new double[movieNum]; //儲存聲音畫面表現平均
		int[][] stdc= new int[r][movieNum];  //儲存啟發性分數
		int [] c_sum = new int[movieNum];	//儲存啟發性分數總和
		double[] avg_c = new double[movieNum]; 	//儲存啟發性分數平均
		int[]  sum = new int[movieNum];    //儲存總分
		double[] avg = new double[movieNum]; //儲存總評分數
		String[] rev = new String[movieNum]; //儲存評語
		String[] result = new String[movieNum]; //儲存全部資料
		int i = 0,reviewer = 1;
		double temp=0;
		while(i<r) {   
			System.out.println("第" + (i+reviewer) + "位評審評分"); //每位評審評分
			mov.reviewMovies(movies, stda[i], stdb[i], stdc[i]);
			mov.sumMovies(stda[i], stdb[i], stdc[i],a_sum,b_sum,c_sum,sum);
			i++;
		}
		
		for( i = 0;i<movieNum;i++) {  												
			mov.divMovie(a_sum, b_sum, c_sum, sum, avg_a, avg_b, avg_c, avg, i, r);	//算平均分數並評定每部電影
			temp = avg[i];
			rev[i] = mov.inferMovie(temp);
			result[i] = movies[i] + "\t" + avg_a[i] + "\t" + avg_b[i] + "\t\t" + avg_c[i] + "\t\t" +  avg[i] + "\t" + rev[i];//把每項資料彙整到一個陣列
		}
		mov.sortMovie(avg,result);  //排序
		mov.displayres(result);   //顯示結果
	}

	void getMovieNames(String[] movies)throws IOException{
		
		FileReader fr = new FileReader("movielist.txt"); 
		BufferedReader br = new BufferedReader(fr);
		 String line;
	     int i=0;
	     while((line = br.readLine())!=null) {
	    	  
	    	 movies[i] = line;
	    
	    	 i++;
	     }
	     
	 /*    for(i=0;i<movieNum;i++) {
	    	 System.out.println(movies[i]);
	     }*/
	}
	
	void reviewMovies(String[] movies , int[] stda ,int[] stdb ,int[] stdc ) {
		Scanner s=new Scanner(System.in);
											//輸入每項評分標準
			for(int j=0;j<movieNum;j++) {
				System.out.println(  movies[j] + "電影評分" );
				System.out.println(  "劇情(0~10分)" );
				stda[j] = s.nextInt();
				System.out.println(  "聲音畫面表現(0~10分)" );
				stdb[j] = s.nextInt();
				System.out.println(  "啟發性(0~10分)" );
				stdc[j] = s.nextInt();
				System.out.println(stda[j] +"   "+stdb[j]+"   "+stdc[j]);
			}
	}
	
	void sumMovies(int[] stda ,int[] stdb ,int[] stdc,int a_sum[],int b_sum[],int c_sum[],int sum[]) {
		
		for(int i = 0;i<movieNum;i++) {
			
			a_sum[i] += stda[i]; 
			b_sum[i] += stdb[i];
			c_sum[i] += stdc[i];
			sum[i]+= stda[i] + stdb[i] + stdc[i];
		}
	}
	
	void divMovie(int a_sum[],int b_sum[],int c_sum[],int sum[],double avg_a[],double avg_b[],double avg_c[],double avg[],int i,int r) {
		
		DecimalFormat df = new DecimalFormat("##.00");
		avg_a[i] = (double) (a_sum[i]/r);
		avg_b[i] = (double) (b_sum[i]/r);
		avg_c[i] = (double) (c_sum[i]/r);
		avg[i] = (double) (sum[i]/3.0/r);
		avg_a[i] =  Double.parseDouble(df.format(avg_a[i]));
		avg_b[i] =  Double.parseDouble(df.format(avg_b[i]));
		avg_c[i] =  Double.parseDouble(df.format(avg_c[i]));
		avg[i] =  Double.parseDouble(df.format(avg[i]));
	}
	
public	String inferMovie(double temp) {  //測案在這個函式寫,assertEquals(無與倫比的超級爛片!!, a.inferMovie(0,0));
		
		
			if(temp >= 0 && temp<1 )
			{ 
				return "無與倫比的超級爛片!!";
			}
			else if(temp >= 1 && temp<2 )
			{	
				return "看完會產生嚴重精神傷害的爛片!!";
			}
			else if(temp >= 2 && temp<3 )
			{	
				return "無話可說的大爛片!!";
			}
			else if(temp >= 3 && temp<4 )
			{	
				return "爛到可以成為經典爛片的電影!!";
			}
			else if(temp >= 4 && temp<5 )
			{	
				return "就算付我錢也不想再看的電影!!";
			}
			else if(temp >= 5 && temp<6 )
			{	
				return "不值得一看的電影!!";
			}
			else if(temp >= 6 && temp<7 )
			{	
				return "還算可打發時間的電影!!";
			}
			else if(temp >= 7 && temp<8 )
			{	
				return "可值回票價的好電影!!";
			}
			else if(temp >= 8 && temp<9 )
			{	
				return "錯過了非常可惜的好電影!!";
			}
			else if(temp >= 9 && temp<=10 )
			{	
				return "無可比擬的經典曠世鉅作!!";
			}
			else
			{ 
					return "分數異常!!";
			}
	}
	
	void sortMovie(double avg[],String result[]) {
		
		String temp;
		double temp2;
		for(int i=0;i<avg.length;i++) {
			for(int j=i+1;j<avg.length;j++) {
				if(avg[i]<avg[j]) {
				 	temp2 = avg[i];	temp = result[i];
				 	avg[i] = avg[j]; result[i] = result[j];
				 	avg[j] = temp2;	result[j] = temp; 
				}
			}
		}	
	}
	
	void displayres(String result[] ) {
		
	System.out.println( "排名" + "\t" + "電影名" + "\t\t\t" + "劇情分數" + "\t" +  "聲音畫面表現分數" + "\t" + "啟發性分數" + "\t" + "總分" + "\t" 
	+ "評價" + "\t");
		
		int rank = 1;
		for(int i =0 ;i<movieNum;i++) {
			
			System.out.println( "#" + (rank+i) + "\t" + result[i]);
		}
	}
}
