# include <stdio.h>
# include <stdlib.h>
int total;
void tot()
{
        printf("the total head movement is %d\n",total);
}
//driver code
void main()
{
        int nc,n,a[10],i,temp,j,ch,cu,t,x;
        printf("enter no of cyllinders\n");
        scanf("%d",&nc);
        printf("enter no of requests\n");
        scanf("%d",&n);
        printf("enter current head position\n");
        scanf("%d",&cu);
        printf("enter requests\n");

        for(i=0; i<n; i++)
        {
                scanf("%d",&a[i]); //read the request into array
        }
        total=0;
        x=cu;
        for(i=0; i<n; i++)
        {       x=x-a[i];
                if(x<0)
                {       x=-x; //for getting absolute value
                }
                printf("%d\t",x); //servicing request in this order
                tot=tot+x;
                
        }
        tot();
}
