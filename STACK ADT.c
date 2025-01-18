
#include<stdio.h> #include<stdlib.h> typedef struct node_info 
{ 
 	void* data;  	struct node_info* next; 
}node; typedef struct  
{ 
 	int count;  	node* top; 
}stack; stack* create_stack() 
{ stack* sp; sp=(stack*)malloc(sizeof(stack)); 
if(sp) 
{ 
	 	sp->top=NULL; 
 	 	sp->count=0; 
 	} 
 	return sp; 
} 
int push_stack(stack*ps,void*pele) 
{ 
 	node* temp; 
 	temp=(node*)malloc(sizeof(node));  	if(temp) 
 	{ 
 	 	temp->data=pele;  	 	temp->next=ps->top;  	 	ps->top=temp;  	 	(ps->count)++;  	 	return 1; 
 	} 
 	else 
 	return 0; 
} 
void* pop_stack(stack*ps) 
{ 
 	node* temp;  	void* dout;  	if(ps->count==0) 
 	{ 
	 	return NULL; 
} 
else 
{ 
 	temp=ps->top;  	dout=temp->data; 
 	 	ps->top=temp->next; 
 	 	(ps->count)--; 
        free(temp);         return dout; 
 	} 
} 
void* stack_top(stack*ps) 
{ 
 	void*dout;  	if(ps->count==0)  	return NULL;  	else 
 	{ 
 	 	dout=ps->top->data;  	 	return dout; 
    } 
} 
int stack_count(stack*ps) 
{ 
 	return(ps->count); 
} 
int stack_empty(stack*ps) 
{ 
 	if(ps->count==0)  	return 1;  	else 
 	return 0; 
} 
int stack_full(stack*ps) 
{
 	node* temp; 
 	temp=(node*)malloc(sizeof(node));  	if(!temp)  	return 1;  	else 
 	free(temp);  	return 0; 
} 
 
stack* destroy_stack(stack*ps) 
{ 
 	node*temp;  	if(ps) 
 	{ 
 	 	while(ps->top) 
 	 	{ 
 	 	 	temp=ps->top;  	 	 	ps->top=temp->next;  	 	 	free(temp->data);  	 	 	free(temp); 
 	 	} 
 	 	free(ps); 
 	} 
 	return NULL; 
} 
