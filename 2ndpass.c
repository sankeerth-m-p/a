#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
	char opcode[10],operand[10],label[10],code[10],mnemonic[10],len[6],leng[7],addr[10],sym[10],address[10],cop[10],csy[10];
	int locctr,start,n,i,j;
	FILE *fp1,*fp2,*fp3,*fp4,*fp5,*fp6;
	
	fp1=fopen("inter.txt","r");
	fp2=fopen("optab.txt","r");
	fp3=fopen("symtab.txt","r");
	fp4=fopen("output.txt","w");
	fp5=fopen("length.txt","r");
	fp6=fopen("obj.txt","w");
	fscanf(fp5,"%s",len);
	n=6-strlen(len);
	for(i=0;i<n;i++)
		leng[i]='0';
	leng[i]='\0';
	i=n;
	for(j=0;len[j]!='\0';j++,i++)
	{
		leng[i]=len[j];
	}
	leng[i]='\0';
	fscanf(fp1,"%s\t%s\t%s",label,opcode,operand);
	if(strcmp(opcode,"START")==0)
	{
		fprintf(fp4,"^H^%s  ^00%s^%s^\n",label,operand,leng);
		fscanf(fp1,"%s\t\t%s\t%s\t%s",addr,label,opcode,operand);
	}
	else
	{
		fprintf(fp4,"^H^    ^00%s^%s^\n",operand,leng);
		fscanf(fp1,"%s\t\t%s\t%s\t%s",addr,label,opcode,operand);
	}
	printf("%s %s %s",label,opcode,operand);
	while(strcmp(opcode,"END")!=0)
	{
		fscanf(fp2,"%s\t%s",code,mnemonic);
		while(strcmp(code,"END")!=0)
		{
			if(strcmp(opcode,code)==0)
			{
				strcpy(cop,mnemonic);
				break;
			}
			fscanf(fp2,"%s\t%s",code,mnemonic);
		}
		fscanf(fp3,"%s\t%s",sym,address);
		while(strcmp(sym,"END")!=0)
		{
			if(strcmp(operand,sym)==0)
			{
				strcpy(csy,address);
				break;
			}
			fscanf(fp3,"%s\t%s",sym,address);
		}
		strcat(cop,csy);
		fprintf(fp6,"%s\t\t%s\t%s\t%s\t%s\n",addr,label,opcode,operand,cop);
		fscanf(fp1,"%s\t\t%s\t%s\t%s",addr,label,opcode,operand);
		rewind(fp3);
	}
}
