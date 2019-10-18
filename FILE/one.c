#include<stdlib.h>
#include<string.h>
#include<stdio.h>
struct
{
char dname[10],//to store directory name
 fname[10][10];//to store filename.there  is 10 files in each directory and maximum string length is 10.
int fcnt;//to store the file count in a directory.
}dir;//in one level only single directory is needed.
void main()//source code
{
int i,ch;
char f[30];
dir.fcnt = 0;//initially no files.
printf("\nEnter name of directory -- ");
scanf("%s", dir.dname);
while(1)
{
printf("\n\n1. Create File\t2. Delete File\t3. Search File \n 4. Display Files\t5. Exit\nEnter your choice -- ");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("\nEnter the name of the file -- ");
       scanf("%s",f);
       for(i=0;i<dir.fcnt;i++)
       {
        if(strcmp(f,dir.fname[i])==0)//file name should be unique.it checks whether the file is already created or not.
        {
        printf("file %s is already exists",f);
        break;
        }
       }
       if(i==dir.fcnt)
        strcpy(dir.fname[dir.fcnt],f);//copy the new file name in to array.
       dir.fcnt++;
       break;
case 2: printf("\nEnter the name of the file -- ");
        scanf("%s",f);
        for(i=0;i<dir.fcnt;i++)
        {
         if(strcmp(f, dir.fname[i])==0)
         {
           printf("File %s is deleted ",f);
           strcpy(dir.fname[i],dir.fname[dir.fcnt-1]); //the last file is copied in to empty position.
            break; 
         }
        }
        if(i==dir.fcnt) 
           printf("File %s not found",f);
        else
         dir.fcnt--;
        break;
case 3: printf("\nEnter the name of the file -- ");
        scanf("%s",f);
        for(i=0;i<dir.fcnt;i++)
        {
        if(strcmp(f, dir.fname[i])==0)//to search a file.
        {
          printf("File %s is found ", f);
          break;
        }
        }
        if(i==dir.fcnt)
        printf("File %s not found",f);
        break;
case 4: if(dir.fcnt==0)
          printf("\nDirectory Empty");
        else
        {
          printf("\nThe Files are -- ");
          for(i=0;i<dir.fcnt;i++)
          printf("\t%s",dir.fname[i]);//display the files.
        }
        break;
 default: exit(0);
        }
   }
}

