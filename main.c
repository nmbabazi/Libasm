#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

#define TEST_FILE "mine.txt"
#define TEST_FILE2 "real.txt"
#define BUFF_SIZE 64

ssize_t	ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
int		ft_strcmp(char *s1, char *s2);
ssize_t	ft_write(int fd, void *buf, size_t count);
ssize_t	ft_read(int fd, void *buf, size_t count);
char	*ft_strdup(char *str);

void	ft_bzero(void *s, int n)
{
	int		i;
	char	*c;
	i = 0;
	if (n == 0)
		return ;
	c = s;
	while (i < n)
	{
		c[i] = 0;
		i++;
	}
	return ;
}
int main()
{
	char	*s1 = "Hello World !";
	char	s2[14];
	char	s3[14];
	char	*cmp = "Hello Earth !";
	char	buf[BUFF_SIZE];
	char	buf2[BUFF_SIZE];
	int		fd;
	int		fd2;
	char	*up;
	char	*up2;
	char	*empty1;
//	char	*empty2;
//	char	*null;
	empty1 = "";
//	empty2 = "";
//	null = NULL;
	printf("\n-----------------------------\n");
	printf("----STRLEN--&--FT_STRLEN-----\n");
	printf("-----------------------------\n");
	printf("\nVALID STR\n");
	printf("str = [%s]\nSTRLEN = \t%zu\tFT_STRLEN = \t%zu\n", s1, strlen(s1), ft_strlen(s1));
	printf("\nEMPTY STR\n");
	printf("str = [%s]\nSTRLEN = \t%zu\tFT_STRLEN = \t%zu\n", empty1, strlen(empty1), ft_strlen(empty1));
		// a strlen of a null str should result to a segfault
/*	printf("\nSEGFAULT STR\n");
	printf("str = [%s]\nSTRLEN = %zu\n", null, strlen(null));
	printf("str = [%s]\nFT_STRLEN = %zu\n", null, ft_strlen(null));*/
	printf("\n-------------------------------\n");
	printf("------STRCPY--&--FT_STRCPY-----\n");
	printf("-------------------------------\n");
	ft_bzero(s2, 14);
	ft_bzero(s3, 14);
	printf("\nEMPTY STRINGS : ETAT INITIAL\nsrc =\t{%p}\t|%s|\n", s1, s1);
	printf("dest1 =\t{%p}\t|%s|\n", s2, s2);
	printf("dest2 =\t{%p}\t|%s|\n", s3, s3);
    printf("STRCPY\t\tdest1 =\t{%p}\t|%s|\n", strcpy(s2, s1), s2);
    printf("FT_STRCPY\tdest2 =\t{%p}\t|%s|\n", ft_strcpy(s3, s1), s3);
	printf("\nNON-EMPTY STRINGS : ETAT INITIAL\nsrc =\t{%p}\t|%s|\n", cmp, cmp);
	printf("dest1 =\t{%p}\t|%s|\n", s2, s2);
	printf("dest2 =\t{%p}\t|%s|\n", s3, s3);
    printf("STRCPY\t\tdest1 =\t{%p}\t|%s|\n", strcpy(s2, cmp), s2);
    printf("FT_STRCPY\tdest2 =\t{%p}\t|%s|\n", ft_strcpy(s3, cmp), s3);
		// a strcpy to or from an empty str result to an error
	/*printf("\nDEST TOO SMALL TEST :\nETAT INITIAL\nsrc =\t{%p}\t|%s|\n", s1, s1);
	printf("dest1 =\t{%p}\t|%s|\n", empty1, empty1);
	printf("dest2 =\t{%p}\t|%s|\n", empty2, empty2);
    printf("STRCPY\t\tdest1 =\t{%p}\t|%s|\n", strcpy(empty1, s1), empty1);
    printf("FT_STRCPY\tdest2 =\t{%p}\t|%s|\n", ft_strcpy(empty2, s1), empty2);*/
		// a strcpy to or from a null str result to a segfault
	/*printf("\nSEGFAULT TEST :\nETAT INITIAL\nsrc =\t{%p}\t|%s|\n", null, null);
	printf("dest1 =\t{%p}\t|%s|\n", s2, s2);
	printf("dest2 =\t{%p}\t|%s|\n", s3, s3);
    printf("STRCPY\t\tdest1 =\t{%p}\t|%s|\n", strcpy(s2, null), s2);
    printf("FT_STRCPY\tdest2 =\t{%p}\t|%s|\n", ft_strcpy(s3, null), s3);*/
	printf("\n-------------------------------\n");
	printf("------STRCMP--&--FT_STRCMP-----\n");
	printf("-------------------------------\n");
	printf("\nDIFFERENT STRINGS\t|%s|\tVS\t|%s|\n", s1, cmp);
	printf("FT_STRCMP =\t%d\n", ft_strcmp(s1, cmp));
	printf("STRCMP =\t%d\n", strcmp(s1, cmp));
	printf("\nSAME STRINGS\t|%s|\tVS\t|%s|\n", s1, s1);
	printf("FT_STRCMP =\t%d\n", ft_strcmp(s1, s1));
	printf("STRCMP =\t%d\n", strcmp(s1, s1));
	printf("\nONE EMPTY STR\t|%s|\tVS\t|%s|\n", s1, empty1);
	printf("FT_STRCMP =\t%d\n", ft_strcmp(s1, empty1));
	printf("STRCMP =\t%d\n", strcmp(s1, empty1));
	printf("\nTWO EMPTY STR\t|%s|\tVS\t|%s|\n", empty1, empty1);
	printf("FT_STRCMP =\t%d\n", ft_strcmp(empty1, empty1));
	printf("STRCMP =\t%d\n", strcmp(empty1, empty1));	
		// a strcmp with a null str should result to a segfault
/*	printf("\nSEGFAULT TEST\t|%s|\tVS\t|%s|\n", null, null);
	printf("FT_STRCMP =\t%d\n", ft_strcmp(null, null));
    printf("STRCMP =\t%d\n", ft_strcmp(null, null));*/
	printf("\n-----------------------------\n");
	printf("------WRITE--&--FT_WRITE-----\n");
	printf("-----------------------------\n");
	errno = 0;
	printf("\nVALID_WRITE\n");
	printf("\t<--WRITE\t");
	printf("return = %ld\t", write(1, s1, strlen(s1)));
	printf(">> errno = %d\t%s\n", errno, strerror(errno));
	errno = 0;
	printf("\t<--FT_WRITE\t");
	printf("return = %ld\t", ft_write(1, s1, strlen(s1)));
	printf(">> errno = %d\t%s\n", errno, strerror(errno));
	errno = 0;
	printf("\nINVALID FD\n");
	printf("\t<--WRITE\t");
	printf("return = %ld\t", write(-3, s1, strlen(s1)));
	printf(">> errno = %d\t%s\n", errno, strerror(errno));
	errno = 0;
	printf("\t<--FT_WRITE\t");
	printf("return = %ld\t", ft_write(-3, s1, strlen(s1)));
	printf(">> errno = %d\t%s\n", errno, strerror(errno));
	errno = 0;
	printf("\nWRONG SIZE\n");
	printf("\t<--WRITE\t");
	printf("return = %ld\t", write(1, s1, 5));
	printf(">> errno = %d\t%s\n", errno, strerror(errno));
	errno = 0;
	printf("\t<--FT_WRITE\t");
	printf("return = %ld\t", ft_write(1, s1, 5));
	printf(">> errno = %d\t%s\n", errno, strerror(errno));
	printf("\nFORBIDDEN FILE\n");
	fd = open(TEST_FILE, O_RDONLY);
	fd2 = open(TEST_FILE2, O_RDONLY);
	errno = 0;
	printf("\t<--WRITE\t");
	printf("return = %ld\t", write(fd, s1, 5));
	printf(">> errno = %d\t%s\n", errno, strerror(errno));
	errno = 0;
	printf("\t<--FT_WRITE\t");
	printf("return = %ld\t", ft_write(fd2, s1, 5));
	printf(">> errno = %d\t%s\n", errno, strerror(errno));
	close(fd);
	close(fd2);
	printf("\n-----------------------------------\n");
	printf("--------READ--&--FT_READ-----------\n");
	printf("-----------------------------------\n");
	printf("VALID_READ FROM FILE\n");
	fd = open(TEST_FILE, O_RDONLY);
	fd2 = open(TEST_FILE2, O_RDONLY);
	ft_bzero(buf, BUFF_SIZE + 1);
	ft_bzero(buf2, BUFF_SIZE + 1);
	errno = 0;
	printf("\t\tRETURN\tBUFFER\t\t\t\t\t\t\t\t\tERRNO\n");
	printf("FT_READ :\t%ld\t", ft_read(fd, buf, BUFF_SIZE));
	printf("[%s]\t%d\t%s\n", buf, errno, strerror(errno));
	close(fd);
	errno = 0;
	printf("READ :\t\t%ld\t", read(fd2, buf2, BUFF_SIZE));
	printf("[%s]\t%d\t%s\n", buf2, errno, strerror(errno));
	close(fd2);
	printf("\nREAD FROM INVALID FD\n");
	ft_bzero(buf, BUFF_SIZE + 1);
	ft_bzero(buf2, BUFF_SIZE + 1);
	errno = 0;
	printf("\t\tRETURN\tBUFFER\t\t\t\t\t\t\t\t\tERRNO\n");
	printf("FT_READ :\t%ld\t", ft_read(-3, buf, BUFF_SIZE));
	printf("[%s]\t%d\t%s\n", buf, errno, strerror(errno));
	errno = 0;
	printf("READ :\t\t%ld\t", read(-3, buf2, BUFF_SIZE));
	printf("[%s]\t%d\t%s\n", buf2, errno, strerror(errno));
	printf("\nREAD FROM FORBIDDEN FILE\n");
	fd = open(TEST_FILE, O_WRONLY);
	fd2 = open(TEST_FILE2, O_WRONLY);
	ft_bzero(buf, BUFF_SIZE + 1);
	ft_bzero(buf2, BUFF_SIZE + 1);
	errno = 0;
	printf("\t\tRETURN\tBUFFER\t\t\t\t\t\t\t\t\tERRNO\n");
	printf("FT_READ :\t%ld\t", ft_read(fd, buf, BUFF_SIZE));
	printf("[%s]\t%d\t%s\n", buf, errno, strerror(errno));
	close(fd);
	errno = 0;
	printf("READ :\t\t%ld\t", read(fd2, buf2, BUFF_SIZE));
	printf("[%s]\t%d\t%s\n", buf2, errno, strerror(errno));
	close(fd2);
	printf("\n----------------------------------\n");
	printf("------STRDUP--&--FT_STRDUP--------\n");
	printf("----------------------------------\n");
	errno = 0;
	printf("\nVALID TEST\n");
	printf("A dupliquer =\t|%s|\t{%p}\n", s1, s1);
	up = ft_strdup(s1);
	printf("FT_STRDUP =\t|%s|\t{%p}\terrno = %d\n", up, up, errno);
	errno = 0;
	up2 = strdup(s1);
	printf("STRDUP =\t|%s|\t{%p}\terrno = %d\n", up2, up2, errno);
	printf("On essaie de free la chaine cree avec FT_STRDUP\t");
	free(up);
	printf("OK\n");
	printf("On essaie de free la chaine cree avec STRDUP\t");
	free(up2);
	printf("OK\n");
	errno = 0;
	printf("\nDUPLICATE EMPTY STR\n");
	printf("A dupliquer =\t|%s|\t{%p}\n", empty1, empty1);
	up = ft_strdup(empty1);
	printf("FT_STRDUP =\t|%s|\t{%p}\terrno = %d\n", up, up, errno);
	errno = 0;
	up2 = strdup(empty1);
	printf("STRDUP =\t|%s|\t{%p}\terrno = %d\n", up2, up2, errno);
	printf("On essaie de free la chaine cree avec FT_STRDUP\t");
	free(up);
	printf("OK\n");
	printf("On essaie de free la chaine cree avec STRDUP\t");
	free(up2);
	printf("OK\n");
	// a strdup of a null str result to a segfault
/*	errno = 0;
	printf("\nSEGFAULT TEST : NULL STR\n");
	printf("A dupliquer =\t|%s|\t{%p}\n", null, null);
	up = ft_strdup(null);
	printf("FT_STRDUP =\t|%s|\t{%p}\terrno = %d\n", up, up, errno);
	errno = 0;
	up2 = strdup(null);
	printf("STRDUP =\t|%s|\t{%p}\terrno = %d\n", up2, up2, errno);
	printf("On essaie de free la chaine cree avec FT_STRDUP\t");
	free(up);
	printf("OK\n");
	printf("On essaie de free la chaine cree avec STRDUP\t");
	free(up2);
	printf("OK\n"); */
	return(0);
}