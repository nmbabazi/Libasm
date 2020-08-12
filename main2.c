#include <stdio.h> 
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

size_t		ft_strlen(const char *s);
char        *ft_strcpy(char *dest, const char *src);
int         ft_strcmp(char *s1, char *s2);
char        *ft_strdup(char *src);
ssize_t     ft_write(int fd, const void *buf, size_t count);
int         * __errno_location(void);
ssize_t     ft_read(int fd, void *buf, size_t count);


int main()
{
    char *s = "";
    char *s2 ="BON";
    char d[10];
    size_t ret;
    int r;
    ssize_t out;
    char *retour;
    int fd = open("mine.txt", O_WRONLY);
    int fd2 = open("real.txt", O_WRONLY);
    char buf[1000];
    char buf2[2];
    char buf3[10];


    retour = NULL;
    printf("----------STRLEN----------\n");
    ret = strlen(s);
	printf("The real strlen does : %zu\n", ret);
	ret = ft_strlen(s);
	printf("My strlen does : %zu\n", ret);


    printf("----------STRCPY----------\n");
    strcpy(d, s);
	printf("The real strcpy does: %s\n", d);
    ft_strcpy(d, s);
	printf("My strcpy does : %s\n", d);


    printf("----------STRCMP----------\n");
    r = strcmp(s, s2);
	printf("The real strcmp does : %d\n", r);
    r = ft_strcmp(s, s2);
	printf("My strcmp does : %d\n", r);


    printf("----------STRDUP----------\n");
    retour = strdup(s);
	printf("The real strdup does: %s\n", retour);
    retour = ft_strdup(s);
	printf("My strdup does : %s\n", retour);
    free(retour);


    printf("----------WRITE----------\n");
    out = write(fd2, "Bonjour", 7);
    printf("\nThe real write does : %ld\n", out);
    out = ft_write(fd, "Bonjour", 7);
    printf("\nMy write does : %ld\n", out);   
    out = write(1, "", 0);
    printf("\nThe real write does : %ld\n", out);
    out = ft_write(1, "", 0);
    printf("\nMy write does : %ld\n", out);
    out = write(-1, "Bonjour", 7);
    printf("\nThe real write does : %ld\n", out);
    out = ft_write(-1, "Bonjour", 7);
    printf("\nMy write does :%ld\n", out);

    printf("----------READ----------\n");
    fd = open("real.txt", O_RDONLY);
    out = read(fd, buf, 8);
    printf("\nThe real read does : %ld --%s--\n", out, buf);
    fd = open("real.txt", O_RDONLY);
    out = ft_read(fd, buf, 8);
    printf("\nMy read does : %ld --%s--\n", out, buf);
    fd = open("real.txt", O_RDONLY);
    out = read(fd, buf2, 8);
    printf("\nThe real read does : %ld --%s--\n", out, buf);
    fd = open("real.txt", O_RDONLY);
    out = ft_read(fd, buf2, 8);
    printf("\nMy read does : %ld --%s--\n", out, buf);
    out = ft_read(-1, buf3, 8);
    printf("\nThe real read does : %ld --%s--\n", out, buf3);
    out = ft_read(-1, buf3, 8);
    printf("\nMy read does : %ld --%s--\n", out, buf3);
    return (0);
}