#include<stdio.h>
#include<stdlib.h>
int w, mutex = 1, full = 0, empty = 4, x = 0, b[4];
main()
{
    int n;
    void producer(); //Function Declaration void consumer();
    int wait(int);
    int signal(int);
    printf("\nProducer-Consumer Problem\n");
    printf("\n1.Produce\n2.Consume\n3.Exit\n");
    do {
        printf("Enter your choice: ");
        scanf("%d", & n);
        switch (n)
        {
        case 1: //Produce if((mutex==1)&&(empty!=0))
            producer();
            break;
            else
                printf("Buffer full\n");
        case 2: //Consume if((mutex==1)&&(full!=0))
            consumer();
            break;
            else
                printf("Buffer empty\n");
        case 3:
            exit(0);
            break;
        }
    }
    while (1);
}
int wait(int s) //wait
{
    return (--s);
}
int signal(int s) //signal
{
    return (++s);
}
void producer()
{
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    printf("Enter the value: ");
    scanf("%d", & b[x]);
    printf("Producer produces the item %d\n", b[x]);
    x++;
    mutex = signal(mutex);
}
void consumer()
{
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("Consumer consumes item %d\n", b[x - 1]);
    x--;
    mutex = signal(mutex);
}