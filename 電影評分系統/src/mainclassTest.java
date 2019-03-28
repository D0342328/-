import static org.junit.Assert.*;

import org.junit.Test;

public class mainclassTest {
	
	@Test
	public void testInferMovie() {
		mainclass a = new mainclass();
		assertEquals("�L�P�ۤ񪺶W�����!!" ,a.inferMovie(0));
		assertEquals("�L�P�ۤ񪺶W�����!!" ,a.inferMovie(0.5));
		assertEquals("�ݧ��|�����Y���믫�ˮ`�����!!" ,a.inferMovie(1));
		assertEquals("�ݧ��|�����Y���믫�ˮ`�����!!" ,a.inferMovie(1.5));
		assertEquals("�L�ܥi�����j���!!" ,a.inferMovie(2));
		assertEquals("�L�ܥi�����j���!!" ,a.inferMovie(2.5));
		assertEquals("���i�H�����g��������q�v!!" ,a.inferMovie(3));
		assertEquals("���i�H�����g��������q�v!!" ,a.inferMovie(3.5));
		assertEquals("�N��I�ڿ��]���Q�A�ݪ��q�v!!" ,a.inferMovie(4));
		assertEquals("�N��I�ڿ��]���Q�A�ݪ��q�v!!" ,a.inferMovie(4.5));
		assertEquals("���ȱo�@�ݪ��q�v!!" ,a.inferMovie(5));
		assertEquals("���ȱo�@�ݪ��q�v!!" ,a.inferMovie(5.5));
		assertEquals("�ٺ�i���o�ɶ����q�v!!" ,a.inferMovie(6));
		assertEquals("�ٺ�i���o�ɶ����q�v!!" ,a.inferMovie(6.5));
		assertEquals("�i�Ȧ^�������n�q�v!!" ,a.inferMovie(7));
		assertEquals("�i�Ȧ^�������n�q�v!!" ,a.inferMovie(7.5));
		assertEquals("���L�F�D�`�i�����n�q�v!!" ,a.inferMovie(8));
		assertEquals("���L�F�D�`�i�����n�q�v!!" ,a.inferMovie(8.5));
		assertEquals("�L�i�������g���m�@�d�@!!" ,a.inferMovie(9));
		assertEquals("�L�i�������g���m�@�d�@!!" ,a.inferMovie(9.5));
		assertEquals("�L�i�������g���m�@�d�@!!" ,a.inferMovie(10));
		assertEquals("���Ʋ��`!!" ,a.inferMovie(-1));
		assertEquals("���Ʋ��`!!" ,a.inferMovie(11));
		
	}

}
