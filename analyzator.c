#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct {
	unsigned char size;
	float *hodnoty;
} POSTUPNOST;

void jednotlive_postupnosti(int in, POSTUPNOST *p, int i){
	unsigned char size;
	int j;
	float h;

	read(in, &size, 1);
	p[i].size=size;
	p[i].hodnoty=(float*)malloc(size * sizeof(float));

	for(j=0; j<size; j++){
		read(in, &h, sizeof(h));
		p[i].hodnoty[j]=h;
	}
}
  
void analyzator (char *file, int n){
 	char buf;
	int i,j,pocet=0,suma=0,in,size;
 	float *priemer, priemerpriemerov;
 	POSTUPNOST *p;
 	
 	in= open(file, O_RDONLY);
 	if(in < 0)
        return 1;
        
    size = lseek(in, 0, SEEK_END);
    
    if ((buf=malloc(size*sizeof(float)))==NULL)
    	return NULL;
        
	lseek(in,0,SEEK_SET);
	for(i=0;i<size;i++){
		read(in,&buf,sizeof(unsigned char));
		lseek(in,sizeof(float)*buf,SEEK_CUR);
		pocet++;
		i=i+sizeof(float)*buf;
	}
	printf("pocet postuposti: %d",pocet);
	
 	lseek(in,0,SEEK_SET);
	p=malloc(pocet*sizeof(POSTUPNOST));
	priemer=malloc(pocet*sizeof(float));
	
	for(i=0; i<n; i++){
		jednotlive_postupnosti(in, p, i);
	}
	
	for(i=0; i<pocet; i++){
		for(j=0; j<p->size; j++){
			suma=suma+p->hodnoty[i];
		}
		priemer[i]=suma/p->size;
		printf("priemer: %.2lf\n",priemer[i]);
		priemerpriemerov=priemerpriemerov+priemer[i];
	}
	priemerpriemerov=priemerpriemerov/pocet;
	
	printf("Priemer priemerov: %.2lf\n", priemerpriemerov /n);
	printf("Priemery:\n");
	for(i=0; i<n; i++){
		printf("%.2lf\n", priemer[i]);
	}
  	
  	free(buf);
  	free(p);
  	free(priemer);
 	close(in);
 }
 
 
 int main(int argc, int **argv){
	char *file;
	int n;
	
	if (argc<3){
		printf("Malo argumentov");
		return 1;
	}
	   		 	  
    file =(char *)argv[1];
    n=atoi((const char*)argv[2]);

	analyzator (file,n);
}
