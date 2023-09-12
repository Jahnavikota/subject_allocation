/*
#include <bits/stdc++.h>
#include <string.h>
using namespace std
;

// this stucture is used to store the details of 
faculty his name his preferences,his total no of sections assigned to him so far,what 
sections are assigned
struct faculty{
    int total,pref[3];
    char name[20],cour[3][10];
};

//this structure is used to store the section details what subject each section has and what teachers are assigned to those subjects
struct section{
    int sem;
    char section[10],sub[10][10];
};

//no of techers, no of sections, no of subjects for each section
const int le=34,se=14,su=10;
struct faculty f[le];
struct section p[se];
void findfaculty(string a[], int i, int y, int *x) //faculty sec subject 
{
	for(int k=0;k<3 && (*x)<su;k++)//subj
	{
		for(int j=0;j<le && (*x)==y;j++)//faculty  y-sec subj
		{	//fac course  and sec subj comparing
		
		//until a teacher get 3 subjects we are giving him sections
		    if(strcmp(f[j].cour[k],p[i].sub[y])==0 && f[j].total<3 && 
		    !(f[j].pref[(i+1)%3]==1 && f[j].pref[(i+2)%3]==1 && (*x)<su))
			{
			    a[(*x)++]=f[j].name;
			    f[j].total++;
			    f[j].pref[k]=1;
			    break;
		    }
		}
		if((*x)==y)
		(*x)++;
	}
}
int main()
{
    FILE *fptr=fopen("faculty.txt","r");  //pointers  pointing to files
    FILE *ptr=fopen("sections2.txt","r");
    FILE *pt=fopen("output.txt","w");
    for(int i=0;i<le;i++)  //reading faculty file and storing them in structures for further solving
	{
        fscanf(fptr,"%s\t\t%s\t%s\t%s\n",f[i].name,f[i].cour[0],f[i].cour[1],f[i].cour[2]);
        f[i].total=0;
        f[i].pref[0]=0;
        f[i].pref[1]=0;
        f[i].pref[2]=0;
    }
    for(int i=0;i<se;i++)  //reading section file and storing them in structures for further solving
	fscanf(ptr,"%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",&p[i].sem,p[i].section,p[i].sub[0],p[i].sub[1],
	p[i].sub[2],p[i].sub[3],p[i].sub[4],p[i].sub[5],p[i].sub[6],p[i].sub[7],p[i].sub[8],p[i].sub[9]);
    for(int i=0;i<se;i++){  //loop to copy the details into output file
    	string a[su];
    	int x=0;
    	fprintf(pt,"\n\n");
    	fprintf(pt,"%s\n",p[i].section);
		for(int y=0;y<su;y++)
		findfaculty(a,i,y,&x);
		
		for(int j=0;j<su;j++)
		{   
			fprintf(pt,"%s\t - ",p[i].sub[j]);
			fputs(a[j].c_str(),pt);
			fprintf(pt,"\t");
		}
	}
	fclose(pt);
    fclose(fptr);
    fclose(ptr);
    return 0;
}*/



#include <bits/stdc++.h>
#include <string.h>
using namespace std
;
// this stucture is used to store the details of faculty his name his preferences,his total no of sections assigned to him so far,what sections are assigned
struct faculty{
    int total,pref[3];
    char name[20],cour[3][10];
};

//this structure is used to store the section details what subject each section has and what teachers are assigned to those subjects
struct section{
    int sem;
    char section[10],sub[10][10];
};

//no of techers, no of sections, no of subjects for each section
const int nooffac=34,noofsec=14,noofsub=5;
struct faculty f[nooffac];
struct section p[noofsec];
void findfaculty(string a[], int i, int y, int *x)
{
	for(int k=0;k<3 && (*x)<noofsub;k++)
	{
		for(int j=0;j<nooffac && (*x)==y;j++)
		{	//until a teacher get 3 subjects we are giving him sections
		    if(strcmp(f[j].cour[k],p[i].sub[y])==0 && f[j].total<3 && 
		    !(f[j].pref[(i+1)%3]==1 && f[j].pref[(i+2)%3]==1 && (*x)<noofsub))
			{
			    a[(*x)++]=f[j].name;
			    f[j].total++;
			    f[j].pref[k]=1;
			    break;
		    }
		}
		if((*x)==y)
		(*x)++;
	}
}
int main()
{
    FILE *fptr=fopen("faculty.txt","r");   //pointers  pointing to files
    FILE *ptr=fopen("sections2.txt","r");
    FILE *pt=fopen("output.txt","w");
    for(int i=0;i<nooffac;i++) //reading faculty file and storing them in structures for further solving
	{
        fscanf(fptr,"%s\t\t%s\t%s\t%s\n",f[i].name,f[i].cour[0],f[i].cour[1],f[i].cour[2]);
        f[i].total=0;
        f[i].pref[0]=0;
        f[i].pref[1]=0;
        f[i].pref[2]=0;
    }
    for(int i=0;i<noofsec;i++)   //reading section file and storing them in structures for further solving
	fscanf(ptr,"%d\t%s\t%s\t%s\t%s\t%s\t%s\n",&p[i].sem,p[i].section,p[i].sub[0],p[i].sub[1],
	p[i].sub[2],p[i].sub[3],p[i].sub[4]);
    
	for(int i=0;i<noofsec;i++)   //loop to copy the details into output file
	{
    	string a[noofsub];
    	int x=0;
    	fprintf(pt,"%s\n",p[i].section);
		for(int y=0;y<noofsub;y++)
		findfaculty(a,i,y,&x);
		
		for(int j=0;j<noofsub;j++)
		{   
			fprintf(pt,"%s - ",p[i].sub[j]);
			fputs(a[j].c_str(),pt);
			fprintf(pt,"\t\t");
		}
		fprintf(pt,"\n\n");
	}
	fclose(pt);
    fclose(fptr);
    fclose(ptr);
    return 0;
}
