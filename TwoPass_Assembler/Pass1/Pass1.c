#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	FILE *f1,*f2,*f3,*f4;
	char lab[30],optab[30],opa[30],optab1[30],opa1[30];
	int locctr,x=0;
	f1=fopen("input.txt","r");
	f2=fopen("optab.txt","r");
	f3=fopen("intermediate.txt","w");
	f4=fopen("symtab.txt","w");
	while (fscanf(f1,"%s%s%s",lab,optab,opa)!=EOF)
    {
		if (strcmp(lab,"**")==0)
        {
			if(strcmp(optab,"START")==0)
			{
				fprintf(f3,"%s%s%s",lab,optab,opa);
				locctr=(atoi(opa));
			}
			else
            {
				rewind(f2);
			    x=0;
				while (fscanf(f2,"%s%s",optab1,opa1)!=EOF)
				{
					if (strcmp(optab,optab1)==0)
                    {
						x=1;
					}
				}
			}
		}
		else
        {
			if(x==1)
			{
				fprintf(f3,"\n %d %s %s %s",locctr,lab,optab,opa);
				locctr=locctr+3;
			}
			if(strcmp(optab,"RESW")==0)
			{
				fprintf(f3,"\n %d %s %s %s",locctr,lab,optab,opa);
				fprintf(f4,"\n %d %s",locctr,lab);
				locctr=locctr+(3*(atoi(opa)));
            }
            else if(strcmp(optab,"WORD")==0)
			{
				fprintf(f3,"\n %d %s %s %s",locctr,lab,optab,opa);
				fprintf(f4,"\n %d %s",locctr,lab);
				locctr=locctr+3;
			}
			else if(strcmp(optab,"BYTE")==0)
            {
				fprintf(f3,"\n %d %s %s %s",locctr,lab,optab,opa);
				fprintf(f4,"\n %d %s",locctr,lab);
				locctr=locctr+1;
			}
			else if(strcmp(optab,"RESB")==0)
            {
				fprintf(f3,"\n %d %s %s %s",locctr,lab,optab,opa);
				fprintf(f4,"\n %d %s",locctr,lab);
				locctr=locctr+1;
			}
			else
			{
				fprintf(f3,"\n %d %s %s %s",locctr,lab,optab,opa);
				fprintf(f4,"\n %d %s",locctr,lab);
				locctr=locctr+(atoi(opa));
			}
		}
	}
}
