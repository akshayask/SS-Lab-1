#include <stdio.h>
int m, n;
int safe ( int a[10][10],int ma[10][10],int av[10],int ne[10][10])
{
        int k,i,j,y,f[n],ans[n],ind=0,d,e,flag,t=0;

        for(t=0; t<n; t++)
        {
                f[t]=0; //finish=0 for all process.

                printf("%d\n",f[t]);
        }
        for(k=0; k<n; k++)
        {
                for(e=0; e<n; e++)
                {
                        if (f[e] == 0)
                        {
                                flag = 0;
                                for (j = 0; j < m; j++)
                                {
                                        if (ne[e][j] > av[j])

                                                flag = 1;
                                        break;
                                }
                                if (flag == 0)
                                {
                                        f[e] = 1;

                                        for (j = 0; j < m; j++)

                                                av[j] += a[e][j];


                                        ans[ind++]=e; //the safety sequence is arranged in to array named ans[].
                                }
                        }
                }
        }

        for(y=0; y<n; y++)
        {
                if(f[y]!=1) //process is not completed.
                        return 0;  //request is not granted.
                else
                {printf("p[%d]->",ans[y]); }

        }
        return 1;
}

void main ()
{
        int i, j,a[10][10],f, ma[10][10], av[10], ne[10][10],k=0,d=0,r[10],w;
        printf ("enter no of p\n");
        scanf ("%d", &n);
        printf ("enter no of r\n");
        scanf ("%d", &m);
        printf ("allocation vector\n");
        for (i = 0; i < n; i++)
        {



                for (j = 0; j < m; j++)
                {

                        scanf ("%d", &a[i][j]);
                }
        }
        printf ("maximum vector\n");
        for (i = 0; i < n; i++)
        {

                for (j = 0; j < m; j++)
                {

                        scanf ("%d", &ma[i][j]);
                }
        }




        printf ("available");
        for (j = 0; j < m; j++)
        {

                scanf ("%d", &av[j]);
        }
        printf ("need\n");
        for (k=0; k<n; k++)
        {
                for (j = 0; j<m; j++)
                {
                        ne[k][j]=ma[k][j] - a[k][j]; //need=maximum-allocation
                        printf ("%d",ne[k][j] );
                }
                printf("\n");
        }
        printf("process\tallocation\tmaximum\tneed\n");
        for(d=0; d<n; d++)
        {
                for(j=0; j<m; j++)
                {
                        printf("%d",a[d][j]);
                } printf("\t");
                for(j=0; j<m; j++)
                {
                        printf("%d",ma[d][j]);
                } printf("\t");
                for(j=0; j<m; j++)
                {
                        printf("%d",ne[d][j]);
                } printf("\n");
        }
        printf("available\n");
        for(j=0; j<m; j++)
        {
                printf("%d",av[j]);
        }
        printf("\n");
        printf(" process number\n"); //enter number of process to request resources
        scanf("%d",&w);
        printf("enter request\n"); //resource request
        for(j=0; j<m; j++)
        {
                scanf("%d",&r[j]);
        }
        for(k=0; k<n; k++)
        {    if(k==w)
             {
                     for(j=0; j<m; j++)
                     {
                             if(r[j]<=ne[k][j]) //if request <=need
                             {
                                     if(r[j]<=av[j]) //if request<=available
                                     {
                                             av[j]=av[j]-r[j];
                                             a[k][j]=a[k][j]+r[j];
                                             ne[k][j]=ne[k][j]-r[j];


                                     }
                                     else
                                             printf("resources are not available\n");
                             }
                             else
                                     printf("request exceeds claim\n");
                     }
                     f=safe ( a, ma, av, ne); //go to safety algorithm
             }}
        printf("\n");

        if(f=1) //resources are allocated
                printf("request is granted\n");
        else
                printf("not granted");  //the request is not permitted.because there is a chance for deadlock.
}
