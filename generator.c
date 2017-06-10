#include<string.h>           
#include<stdio.h>
#include <time.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

void generator (char *file, int n){
	int i,j,out;
	float buf;
	unsigned char dlzka;
	
 	out=open("avg[1]_kopia", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
 	if(out<0){
		return 0;
	}
	
	for (j=1;j<n;j++){
		dlzka=10+rand()%11;
		printf("%d ", dlzka);
		write(out, &dlzka, 1);
		for (i=1;i<dlzka;i++){
			buf=((float)rand())/((float)RAND_MAX/1024);
			printf("%lf ",buf);
	  		write(out,&buf,1);
		}
	}
	printf("\n");
	close(out);
	
}

	
int main(int argc, int **argv){
	char *file;
	int n;
	
	srand(time(NULL));
	if (argc<3){
		printf("Malo argumentov");
		return 1;
	}
    
	file=(char *)argv[1];
	n=atoi((const char*)argv[2]);

	printf("%c",n);
	
	if((malloc(sizeof((char *)argv[1]))) == NULL){
	return 0;
	}

	generator (file,n);
	free(file);
    
    return 0;
}
