/*In an operating system that uses paging for memory management, a page replacement algorithm is needed to decide which page needs to be replaced when new page comes in.

Page Fault – A page fault happens when a running program accesses a memory page that is mapped into the virtual address space, but not loaded in physical memory.

Since actual physical memory is much smaller than virtual memory, page faults happen. In case of page fault, Operating System might have to replace one of the existing pages with the newly needed page. 
In FIFO the first page will be replaced.*/
#include<stdio.h>
#include<conio.h>
int fr[3];
void main()
{
void display();//display current values in frames
int i,j,page[12]={2,3,2,1,5,2,4,5,3,2,5,2};//page references
int flag1=0,flag2=0,pf=0,frsize=3,top=0;
clrscr();
for(i=0;i<3;i++)
{
fr[i]=-1;//initially the frames have no pages
}
for(j=0;j<12;j++)
{
flag1=0;
flag2=0;
  for(i=0;i<12;i++)
  {
  if(fr[i]==page[j])// if the page is already existed in frame then flag1=1 and flag2=1
  {
    flag1=1;
    flag2=1;
    break;
    }
  }
    if(flag1==0)//to fill empty frame
    {
    for(i=0;i<frsize;i++)
    {
    if(fr[i]==-1)
    {
    fr[i]=page[j];
    flag2=1;
    break;
    }
    }
    }
    if(flag2==0)//to add the page to top of the frame
    {
    fr[top]=page[j];
    top++;
    pf++;//number of page faults
    if(top>=frsize)//if top exceeds frame size then set top=0 because first frame should be replaced in FIFO.
    top=0;
    }
    display();//display elements in frames 
    }
printf("Number of page faults  : %d ",pf);
getch();
}
void display()
{
int i;
printf("\n");
for(i=0;i<3;i++)
printf("%d\t",fr[i]);//display elements in frames
}
