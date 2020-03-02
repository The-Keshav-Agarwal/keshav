#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *pre;
struct node* next;
};
int main()
{
	struct node *first = NULL,*last = NULL, *t = NULL,*tem=NULL;
	int ch,data;
	while(1)
	{
		printf("enter 1 for insertion ,2 for deletion ,3 for display and 4 for stop : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: t = (struct node*)malloc(sizeof(struct node));
					printf("enter the data : ");
					scanf("%d",&t->data);
					t->next = NULL;
					t->pre = NULL;
					if(first == NULL)
					{
						first = t;
						last = t;
						first ->pre = last;
						last->next = first;
					}
					else
					{
						last ->next = t;
						t->pre = last ;
						last = t;
						first->pre=last ;
						last ->next = first;
					}
					break;
			case 2: printf("enter the data which you want to delete : ");
					scanf("%d",&data);
					   t = first;
					   if(first->data==data)
					   {
					   	    first=first->next;
					   	    last->next = first;
					   	    first->pre = last;
							free(t);
					   }
					   else{
						while(t->data!=data&&t!=last)
						{
							t=t->next;
						}
						if(t!=last)
						{
							tem=t->pre;
							tem->next = t->next;
							t->next->pre=tem;
							free(t);
				     	}
				     	else
				     	{
				     		if(t->data==data)
				     		{
								last=last->pre;
								last->next = first;
								first->pre = last;
								free(t);
				     		}
				     		else
				     		{
				     			printf("data which you want to delete is not present in linked list \n");
				     		}
				     	}
				     }
					break;
			case 3: t=first;
			        while(t!=last)
			        {
			        	printf("%d\n",t->data);
			        	t = t->next;
			        }
			        printf("%d\n",t->data);
			        break;
			case 4: exit(0);        
		}
	}
	return 0;
}