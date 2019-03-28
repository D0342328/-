import static org.junit.Assert.*;

import org.junit.Test;

public class mainclassTest {
	
	@Test
	public void testInferMovie() {
		mainclass a = new mainclass();
		assertEquals("無與倫比的超級爛片!!" ,a.inferMovie(0));
		assertEquals("無與倫比的超級爛片!!" ,a.inferMovie(0.5));
		assertEquals("看完會產生嚴重精神傷害的爛片!!" ,a.inferMovie(1));
		assertEquals("看完會產生嚴重精神傷害的爛片!!" ,a.inferMovie(1.5));
		assertEquals("無話可說的大爛片!!" ,a.inferMovie(2));
		assertEquals("無話可說的大爛片!!" ,a.inferMovie(2.5));
		assertEquals("爛到可以成為經典爛片的電影!!" ,a.inferMovie(3));
		assertEquals("爛到可以成為經典爛片的電影!!" ,a.inferMovie(3.5));
		assertEquals("就算付我錢也不想再看的電影!!" ,a.inferMovie(4));
		assertEquals("就算付我錢也不想再看的電影!!" ,a.inferMovie(4.5));
		assertEquals("不值得一看的電影!!" ,a.inferMovie(5));
		assertEquals("不值得一看的電影!!" ,a.inferMovie(5.5));
		assertEquals("還算可打發時間的電影!!" ,a.inferMovie(6));
		assertEquals("還算可打發時間的電影!!" ,a.inferMovie(6.5));
		assertEquals("可值回票價的好電影!!" ,a.inferMovie(7));
		assertEquals("可值回票價的好電影!!" ,a.inferMovie(7.5));
		assertEquals("錯過了非常可惜的好電影!!" ,a.inferMovie(8));
		assertEquals("錯過了非常可惜的好電影!!" ,a.inferMovie(8.5));
		assertEquals("無可比擬的經典曠世鉅作!!" ,a.inferMovie(9));
		assertEquals("無可比擬的經典曠世鉅作!!" ,a.inferMovie(9.5));
		assertEquals("無可比擬的經典曠世鉅作!!" ,a.inferMovie(10));
		assertEquals("分數異常!!" ,a.inferMovie(-1));
		assertEquals("分數異常!!" ,a.inferMovie(11));
		
	}

}
