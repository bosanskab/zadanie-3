  #include <string.h>           
 #include <stdio.h>
 #include <time.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <sys/stat.h>
 #include <fcntl.h>
  
  void analyzator (char *file, int n){
 	char *buf,p[n];
	int i,length=0,pocet=0,suma=1,priemer=0,m=1,pocetprvkov=0;
 	int in,out,prvok;
 	
 	in= open(file, O_RDONLY);
  	while (read(in,&buf,1)==1)
  		length++;
  		
  	if (sizeof(in)==sizeof(unsigned char)){
  		scanf("%c",*buf);
  		buf=buf+sizeof(unsigned char);
	}
  		else scanf("%lf",*buf);
  	
	buf=buf+sizeof(float);
    pocet++;
    	
  	for (i=1;i<length*sizeof(float);i=+sizeof(unsigned char)){
  		prvok=*buf+i;
  		printf("postup.: %d",prvok);
 		suma=+prvok;
 		pocetprvkov++;
 		
		if (sizeof(buf)==sizeof(unsigned char)){
			printf("\n");
 	   		p[m]=suma/pocetprvkov;
 	   		suma=0;
 	    	pocetprvkov=0;
 	    	priemer=+p[m];
 	    	m++;
 	    	}
 	    	
 	priemer=priemer/m;
 	}
 	
  	printf("celkova dlzka: %d",length);
  	printf("pocet postup.: %d",pocet);
  	printf("priemer postup.: %d",priemer);
  	
 	close(in);
 }
 
 
 int main(int argc, int **argv){
	char *file;
	int n=atoi((const char*)argv[2]);
    
    file =(char *)argv[1];

	analyzator (file,n);
}
