
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
	char opcode[10],operand[10],label[10],code[10],mnemonic[10],len[6],leng[7],addr[10],add[10],sym[10],address[10],cop[10],csy[10];
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
	for(i=0;i<10;i++)
		add[i]=addr[i];
	fprintf(fp4,"^T^00%s^1E^",addr);
	 //fseek(fp4,14,SEEK_SET);
	printf("%s %s %s",label,opcode,operand);
	while(strcmp(opcode,"END")!=0)
	{
		fscanf(fp2,"%s\t%s",code,mnemonic);
		while(!feof(fp2))
		{
			if(strcmp(opcode,code)==0)
			{
				strcpy(cop,mnemonic);
				if(operand!=0)
				{
					fscanf(fp3,"%s\t%s",sym,address);
					while(!feof(fp3))
					{
						if(strcmp(operand,sym)==0)
						{
							strcpy(csy,address);
							strcat(cop,csy);
							fprintf(fp6,"%s\t\t %s \t\t\t%s  \t\t%s \t\t%s\n",addr,label,opcode,operand,cop);
							fprintf(fp4,"%s^",cop);
							break;
						}
						fscanf(fp3,"%s\t%s",sym,address);
						if(feof(fp3)==0)
						{
							fprintf(fp6,"%s\t\t %s \t\t\t%s \t\t%s \t\t%s\n",addr,label,opcode,operand,cop);
							fprintf(fp4,"%s0000^",cop);
							break;
						}
					}
				}
				else
				{
					fprintf(fp4,"000000^");
				}
				break;
			}
			else if((strcmp(opcode,"BYTE")==0) || (strcmp(opcode,"WORD")==0))
			{
				j=atoi(operand);
				printf("%d",j);
				n=6-strlen(operand);
				for(i=0;i<n;i++)
					leng[i]='0';
				leng[i]='\0';
				i=n;
				for(j=0;operand[j]!='\0';j++,i++)
					leng[i]=operand[j];
				leng[i]='\0';
				fprintf(fp6,"%s\t\t %s \t\t%s \t\t%s \t\t%s\n",addr,label,opcode,operand,leng);
				fprintf(fp4,"%s^",leng);
				break;
			}
			else if((strcmp(opcode,"RESW")==0) || (strcmp(opcode,"RESB")==0))
			{
				fprintf(fp6,"%s\t\t %s \t\t%s \t\t%s\n",addr,label,opcode,operand);
				break;
			}
			fscanf(fp2,"%s\t%s",code,mnemonic);
		}
		fscanf(fp1,"%s\t\t%s\t%s\t%s",addr,label,opcode,operand);
		rewind(fp3);
	}
	fprintf(fp4,"\n^E^%s^",add);
}
