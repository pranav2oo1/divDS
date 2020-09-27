#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};
//making array of pointer to store references of all the nodes
struct list{
	struct node * item;
	struct list * next;
};
struct list * all;
int countAll=0;
void Add_List (struct node * newNode) {
	int i;
	
	struct list * temp = (struct list *)malloc(sizeof(struct list));
	temp->item=newNode;
	temp->next=NULL;
	
	if(all == NULL)
	{
		all=temp;
	}
	else
	{
		struct list * P;
		P=all;
		while(P->next != NULL)
		{
			P=P->next;
		}
		P->next=temp;
	}
	countAll++;
}
void checkCircle(struct node * head){
	int pData=head->data;
	struct node * temp=head;
	while(temp!=NULL)
	{
		if(temp->data==pData)
		{
			printf("1\n");
			break;
		}
		temp=temp->next;
	}
	if(temp==NULL)
	{
		printf("0\n");
	}
}
void displayOutput(struct node * head)
{
	checkCircle(head);
	//finding all values and storing in thes two arrays 
	int val[countAll];
	int item[countAll];
	struct list * temp=all;
	int i=0;
	while(temp!=NULL)
	{
		//making an array of all the values
		struct node * pNode=temp->item;
		item[i]=pNode->data;
		val[i]=0;
		temp=temp->next;
		i++;
	}
	temp=all;
	while(temp!=NULL)
	{
		//ading to value of next in each node 
		struct node * pNode=temp->item;
		for(int j=0;j<countAll;j++)
		{
			if(pNode->next==item[j])
			{
				val[j]=val[j]+1;
				break;
			}
		}
		temp=temp->next;
	}
	insertionSort(val,countAll,item);
	//by this sorting we have sorted values where there are coressponding item numbers
	if(val[countAll-1]==0)
	{
		//implies the max value is also 0,so simple linked list
		Display(head);
	}
	else
	{
		//show line 3 and 4
		int i=0;
		while(val[i]==0)
		{
			i++;
		}
		//writing all nodes that have multipe next
		while(i<countAll)
		{
			printf("%d ",item[i]);
		}
		printf("\n");
		while(i<countAll)
		{
			printf("%d ",val[i]);
		}
	}
	


}

int binarySearch(int a[], int item, int low, int high) 
{ 
    if (high <= low) 
        return (item > a[low])?  (low + 1): low; 
  
    int mid = (low + high)/2; 
  
    if(item == a[mid]) 
        return mid+1; 
  
    if(item > a[mid]) 
        return binarySearch(a, item, mid+1, high); 
    return binarySearch(a, item, low, mid-1); 
} 
  
// Function to sort an array a[] of size 'n' 
void insertionSort(int a[], int n,int item[]) 
{ 
    int i, loc, j, k, selected,sVal; 
  
    for (i = 1; i < n; ++i) 
    { 
        j = i - 1; 
        selected = a[i]; 
		sVal=item[i];
        // find location where selected sould be inseretd 
        loc = binarySearch(a, selected, 0, j); 
  
        // Move all elements after location to create space 
        while (j >= loc) 
        { 
            a[j+1] = a[j];
			item[j+1]=item[j];
            j--; 
        } 
        a[j+1] = selected; 
		item[j+1]=sVal;
    } 
} 
struct node * Add_End (int data,struct node *root) {
	int i;
	
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->next  = NULL;
	
	if(root == NULL)
	{
		root=temp;
	}
	
	else
	{
		struct node *P;
		P=root;
		while(P->next != NULL)
		{
			P=P->next;
		}
		P->next=temp;
	}
	Add_List (temp);
	return root;
		
}

struct node * Add_Start(int data,struct node * root) {
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data =data;
	temp->next=NULL;
	
	if(root == NULL)
	{
		root = temp;
	}
	else
	{
		temp->next = root;
		root = temp;
	}
	Add_List (temp);
	return root;
}

struct node * Add_pos(int loc,struct node * root,int data)
{
	struct node *temp , *p=root;
	int i=1;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->next = NULL;
	
	while(i<loc-1)
	{
		p=p->next;
		i++;
	}
		
	temp->next = p->next;
	p->next = temp;
	Add_List (temp);
	return root;
}

struct node * Delete_Start(struct node * root)
{
	struct node *temp=root;
	root=temp->next;
	temp->next = NULL;
	free(temp);
	
}

struct node * Delete_pos(int loc,struct node * root) {
	struct node *p,*q;
	int i=1;
	p = root;
	while(i<loc-1)
	{
		p=p->next;
		q=p->next;
		i++;
	}
	
	p->next = q->next;
	q->next = NULL;
	free(q);
}

int Search(int item,struct node * root)
{
 	struct node *temp=root;
	
 	int c=1;
 	while(temp != NULL)
 	{
 		if(item == temp->data)
 			{
				 return c;
			}
			 	
 		temp=temp->next;
 		c++;
	 }
	 return 0;
}
int SearchBetween(int item1,int item2,struct node * root)
{
 	struct node *temp=root;
	
 	int c=1;
 	while(temp != NULL)
 	{
 		if(item1 == temp->data)
 			{
				 if(item2==temp->next->data)
				 {
					 return c;
				 }
			}
 		temp=temp->next;
 		c++;
	 }
	 return 0;
}
struct node * Link_pos(int y,int y2,struct  node * head)
{
	int count=1;
	struct node * temp =head;
	struct node * pNode;
	while(count!= y2)
	{
		if(count == y )
		{
			pNode=temp;
		}
		
		if(temp->next==NULL)
		{
			//going in circle
			temp->next=head;
			temp=temp->next;
		}
		count ++;
	}
	pNode->next=temp;
	return head;
	
}
void Display(struct node * root) {
	if(root == NULL)
	{
		printf("\nList is Empty");
	}
	else
	{
		struct node *P;
		int i=1;
		P=root;
		while(P != NULL)
		{
			printf("%d ",P->data);
			P=P->next;
			i++;
		}
	
	}
}

// int main() {
// 	int n,loc,loc_del,item;
	
// 	printf("Adding nodes at End\n\n");
// 	printf("Enter no. of nodes:");
// 	scanf("%d", &n);	
// 	Add_End (n);
// 	Display();
// 	printf("\nAdding nodes at Start\n");
// 	Add_Start();
// 	Display();
// 	printf("\nAdding nodes in between and at End\n");
// 	printf("\nEnter location for adding node:");
// 	scanf("%d", &loc);
// 	Add_pos(loc);
// 	Display();
// 	printf("\nDeleting nodes at Start\n");
// 	Delete_Start();
// 	Display();
// 	printf("\nDeleting nodes in between and at End\n");
// 	printf("\nEnter location for deleting node:");
// 	scanf("%d", &loc_del);
// 	Delete_pos(loc_del);
// 	Display();
// 	printf("\nSearching data\n");
// 	printf("\nEnter data to be searched:");
// 	scanf("%d", &item);
// 	int loc_item = Search(item);
// 	if(loc_item <= n)
// 	printf("\nFound at %d", loc_item);
// 	else
// 	printf("\nItem not found");
	
// }

