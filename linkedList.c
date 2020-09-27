#include "BasicOperations.h"
struct node * insertTail(int val2,struct node * head)
{
    printf("%d",val2);
    return Add_End (val2,head);

}

struct node * insertAfter(int val2,int val3,struct node * head)
{
    int x=Search(val2,head);
    if(x!=0)
    {
        return Add_pos(x+1,head,val3);    
    }
    int y=Search(val3,head);
    if(y!=0)
    {
        return Add_pos(y-1,head,val3);    
    }
    return head;
}
struct node * insertBetween(int val4,int val2,int val3,struct node * head){
    printf("%d %d %d",val4,val2,val3);
    int y=SearchBetween(val2,val3,head);
    if(y!=0)
    {
        return Add_pos(y+1,head,val4);    
    }
    return head;
}
struct node * linkTo(int val1,int val2,struct node * head)
{
    printf("%d %d",val1,val2);
    int y=Search(val1,head);
    if(y!=0)
    {
        return Link_pos(y,y+val2,head);    
    }
    return head;
}
int main()
{
    void printOutput(struct node * );
    int n;
    char op;
    int val1,val2;
    scanf("%d",&n);
    printf("%d\n",n);
    int i;
    struct node * head =NULL;
    for(i=0;i<n;i++)
    {

        scanf("%c",&op);
        fflush(stdin);
        scanf("%d",&val1);
        scanf("%d",&val2);
        printf("%c %d %d ",op,val1,val2);
        if(op=='I')
        {
            if(val1==0)
            {
                head=insertTail(val2,head);
            }
            else if(val1==1)
            {
                int val3;
                scanf("%d",&val3);
                head=insertAfter(val2,val3,head);
            }
            else if(val1==2)
            {
                int val3,val4;
                scanf("%d",&val3);
                scanf("%d",&val4);
                head=insertBetween(val4,val2,val3,head);

            }
            else{

            }
        }
        else if(op=='U')
        {
            head=linkTo(val1,val2,head);
        }
        else{
            
            printf("break");
            break;
        }
        printf("%d\n",i);
        fflush(stdin);


    }
    printOutput(head);
}
void printOutput(struct node * head)
{

}
