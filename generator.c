#include<string.h>           
#include<stdio.h>
#include <time.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

void generator (char *file, int n2){
	int n1,i,j;
	int in, out;
	float F[n1],buf;
	
 	in= open("argv[1]", O_RDONLY);
 	out=open("avg[1]_kopia", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
	
	for (j=1;j<n2;j++){
		n1=10+rand()%11;
        F[0]=(unsigned char)n1;
	 for (i=1;i<n1;i++){
	   F[i]=rand()%RAND_MAX/1024;
		 printf("%.1lf\n",	F[i]);
	 		 buf=((float)rand())/((float)RAND_MAX/1024);
	  	 		write(out,&buf,1);
		}

	}
	close(in);
	close(out);
}

int main(int argc, int **argv){
	int *memory;
	char *file =(char *)argv[1];
	int n=atoi((const char*)argv[2]);
    
	srand(time(NULL));
	memory=malloc(20*n*sizeof(float));
		if (memory==NULL)
	  printf("malloc zlyhal\n");

	generator (file,n);
	void free (int *memory){
		free(memory);
	}
}
