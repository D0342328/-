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
		String[] movies = new String[movieNum]; //�x�s�q�v�W
		mov.getMovieNames(movies); //Ū�q�v�ɮ�
		Scanner in=new Scanner(System.in);
		System.out.println("�п�J���f�H��:");
		int r =in.nextInt(); //�x�s���f�H��
		int[][] stda= new int[r][movieNum]; //�x�s�@������ 
		int [] a_sum = new int[movieNum];	//�x�s�@�������`�M
		double[] avg_a = new double[movieNum]; //�x�s�@�����ƥ���
		int[][] stdb= new int[r][movieNum]; //�x�s�n���e����{����
		int [] b_sum = new int[movieNum]; 	//�x�s�n���e����{�`�M
		double[] avg_b = new double[movieNum]; //�x�s�n���e����{����
		int[][] stdc= new int[r][movieNum];  //�x�s�ҵo�ʤ���
		int [] c_sum = new int[movieNum];	//�x�s�ҵo�ʤ����`�M
		double[] avg_c = new double[movieNum]; 	//�x�s�ҵo�ʤ��ƥ���
		int[]  sum = new int[movieNum];    //�x�s�`��
		double[] avg = new double[movieNum]; //�x�s�`������
		String[] rev = new String[movieNum]; //�x�s���y
		String[] result = new String[movieNum]; //�x�s�������
		int i = 0,reviewer = 1;
		double temp=0;
		while(i<r) {   
			System.out.println("��" + (i+reviewer) + "����f����"); //�C����f����
			mov.reviewMovies(movies, stda[i], stdb[i], stdc[i]);
			mov.sumMovies(stda[i], stdb[i], stdc[i],a_sum,b_sum,c_sum,sum);
			i++;
		}
		
		for( i = 0;i<movieNum;i++) {  												
			mov.divMovie(a_sum, b_sum, c_sum, sum, avg_a, avg_b, avg_c, avg, i, r);	//�⥭�����ƨõ��w�C���q�v
			temp = avg[i];
			rev[i] = mov.inferMovie(temp);
			result[i] = movies[i] + "\t" + avg_a[i] + "\t" + avg_b[i] + "\t\t" + avg_c[i] + "\t\t" +  avg[i] + "\t" + rev[i];//��C����ƷJ���@�Ӱ}�C
		}
		mov.sortMovie(avg,result);  //�Ƨ�
		mov.displayres(result);   //��ܵ��G
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
											//��J�C�������з�
			for(int j=0;j<movieNum;j++) {
				System.out.println(  movies[j] + "�q�v����" );
				System.out.println(  "�@��(0~10��)" );
				stda[j] = s.nextInt();
				System.out.println(  "�n���e����{(0~10��)" );
				stdb[j] = s.nextInt();
				System.out.println(  "�ҵo��(0~10��)" );
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
	
public	String inferMovie(double temp) {  //���צb�o�Ө禡�g,assertEquals(�L�P�ۤ񪺶W�����!!, a.inferMovie(0,0));
		
		
			if(temp >= 0 && temp<1 )
			{ 
				return "�L�P�ۤ񪺶W�����!!";
			}
			else if(temp >= 1 && temp<2 )
			{	
				return "�ݧ��|�����Y���믫�ˮ`�����!!";
			}
			else if(temp >= 2 && temp<3 )
			{	
				return "�L�ܥi�����j���!!";
			}
			else if(temp >= 3 && temp<4 )
			{	
				return "���i�H�����g��������q�v!!";
			}
			else if(temp >= 4 && temp<5 )
			{	
				return "�N��I�ڿ��]���Q�A�ݪ��q�v!!";
			}
			else if(temp >= 5 && temp<6 )
			{	
				return "���ȱo�@�ݪ��q�v!!";
			}
			else if(temp >= 6 && temp<7 )
			{	
				return "�ٺ�i���o�ɶ����q�v!!";
			}
			else if(temp >= 7 && temp<8 )
			{	
				return "�i�Ȧ^�������n�q�v!!";
			}
			else if(temp >= 8 && temp<9 )
			{	
				return "���L�F�D�`�i�����n�q�v!!";
			}
			else if(temp >= 9 && temp<=10 )
			{	
				return "�L�i�������g���m�@�d�@!!";
			}
			else
			{ 
					return "���Ʋ��`!!";
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
		
	System.out.println( "�ƦW" + "\t" + "�q�v�W" + "\t\t\t" + "�@������" + "\t" +  "�n���e����{����" + "\t" + "�ҵo�ʤ���" + "\t" + "�`��" + "\t" 
	+ "����" + "\t");
		
		int rank = 1;
		for(int i =0 ;i<movieNum;i++) {
			
			System.out.println( "#" + (rank+i) + "\t" + result[i]);
		}
	}
}
