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
//	(unsigned char)F[0]=(unsigned char)n1;
	 for (i=1;i<n1;i++){
	   F[i]=rand()%RAND_MAX;
		 printf("%.3lf\n",	F[i]);
	 		 buf=((float)rand())/(float)RAND_MAX;
	  	 		write(out,&buf,1);
		}

	}
	close(in);
	close(out);
}

void analyzator (char *file, int n){
	char *buf;
	int i,length=0,pocet=0,suma=1;
	int in,out,prvok;
	
	in= open("argv[1]_kopia", O_RDONLY);
 	while (read(in,&buf,1)==1)
 	length++;
 	if (sizeof(in)==sizeof(unsigned char))
 	pocet++;
   	exit(0);
   	
 	for (i=1;i<length;i++){
 	 prvok=*buf+i;
 	 suma=+prvok
 		if (sizeof(buf)==sizeof(unsigned char)){
	    priemer=suma/i;
	    suma=0;
		}
	}
 	printf("celkova dlzka: %d",length);
 	printf("pocet postup.: %d",pocet);
 	
	close(in);
}



int main(int argc, int **argv){
	char *file = (char *)argv[1];
//	int n =atoi(int *)(argv[2]);
	int n=10;
	generator (file,n);
	analyzator (file,n);

}