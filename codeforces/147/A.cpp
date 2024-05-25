#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char s[10100];
	fgets(s,10100,stdin);
	int len = strlen(s),h=0;
	s[len-1] ='\0';
	char *token = strtok(s," "),**k=(char**)malloc(10100*sizeof(char*));
	while(token!=NULL){
		char t[10100];
		k[h]=(char*)malloc(10100*sizeof(char));
		strcpy(t,token); 
		strcpy(k[h++],t);
		token = strtok(NULL," ");
	}
	int lenk = strlen(k[0]),hT=0;
	char T[10100];
	for(int i=1;i<h;i++){	
		if(isalpha(k[0][lenk-1])&&isalpha(k[i][0])){
//			printf("%c %c\n",k[0][lenk-1],k[i][0]);
			int lentmp=strlen(k[0]);
			k[0][lentmp]='-'; k[0][lentmp+1]='\0';
			strcat(k[0],k[i]);
	    }else strcat(k[0],k[i]);
	    lenk = strlen(k[0]);
	}
	for(int i=0;i<lenk;i++){
		if(k[0][i]=='-') T[hT++]=' ';
		else if(isalpha(k[0][i])==0){
			T[hT++]=k[0][i];
			T[hT++]=' ';
		}else T[hT++]=k[0][i];
	}
	T[hT]='\0';
	printf("%s",T);
}