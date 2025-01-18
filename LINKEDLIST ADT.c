#include<stdio.h> #include<stdlib.h> typedef int(*comparedata)(void*,void*); typedef struct node_info 
{ 
 	void* data;  	struct node_info* next; 
}node; typedef struct 
{ 
 	int count;  	node *head,*rare,*pos;  	comparedata comp; 
}list; 
int add_node(list*lp,void*pdata); int search(list* lp,node**prev,node**curr,void*key); int insert(list* lp,node*prev,void*data); int remove_node(list* lp,void*key,void**dout); int search_list(list*lp,void*key,void**dout); void delete(list*lp,node*prev,node*curr,void**dout); 
//create 
list* create_list(comparedata cdata) 
{
list* lp; 
 	lp=(list*)malloc(sizeof(list)); 
 	if(lp) 
 	{ 
 	 	lp->count=0;  	 	lp->pos=NULL;  	 	lp->head=NULL;  	 	lp->rare=NULL;  	 	lp->comp=cdata; 
 	} 
 	return lp; 
} 
//insert  int add_node(list* lp,void* pdata) 
{ 
 	int f,i;  	node *prev,*curr;  	f=search(lp,&prev,&curr,pdata); 
 	if(f)  	return 0; 
 	i=insert(lp,prev,pdata);  	if(!i)  	return -1; 
 	else 
 	return 1; 
} 
int insert(list*lp,node*prev,void*pdata) 
{ 
 	node* temp; 
 	temp=(node*)malloc(sizeof(node)); 
    if(!temp) 
    return 0;     else 
    { 
 	 	temp->data=pdata;  	 	temp->next=NULL;  	 	if(!prev) 
 	 	{ 	
 	 	 	temp->next=lp->head; 
 	 	 	lp->head=temp; 
 	 	 	if(!lp->count) 
 	 	 
 	 	} 
 	 	else 
 	 	{ 	lp->rare=temp; 
 	 	 	temp->next=prev->next; 
 	 	 	prev->next=temp; 
 	 	 	if(!temp->next) 
 	 	 	{ 
 	 	 	 	lp->rare=temp; 
 	 	 
 	 	} 	} 
 	 	(lp->count)++;  	 	return 1; 
 	} 
} 
//delete 
int remove_node(list* lp,void* key,void**dout) 
{ int f; 
node *prev,*curr; f=search(lp,&prev,&curr,key); if(f) 
    delete(lp,prev,curr,dout);     return f; 
} 
void delete(list* lp,node* prev,node* curr,void** dout) 
{ 
 	*dout=curr->data;  	if(!prev) 
 	{ 
 	 	lp->head=curr->next; 
 	} 
 	else 
 	{ 
 	 	prev->next=curr->next; 
 	    if(prev->next==NULL) 
 	{ 
 	 	lp->rare=prev; 
 	} 
    } 
 	free(curr); 
 	(lp->count)--; 
} 
//search  
int search_list(list* lp,void*key,void**dout) 
{ 
 	int f;  	node *prev,*curr; 
f=search(lp,&prev,&curr,key); 
if(f) 
{ 
	 	*dout=curr->data; 
} 
else 
{ 
	 	*dout=NULL; 
} 
 	return f; 
} 
int  search(list*lp,node** prev,node** curr,void* key) 
{ 
 	int result; 
 	*prev=NULL;  	*curr=lp->head;  	if(lp->count==0) 
 	{ 
 	 	return 0; 
 	} 
 	result=lp->comp(key,lp->rare->data);  	if(result==1) 
 	{ 
 	 	*prev=lp->rare;  	 	*curr=NULL;  	 	return 0; 
 	} 
 	while((result=(lp->comp(key,(*curr)->data)))>0) 
 	{ 
 	 	*prev=*curr; 
 	 	*curr=(*curr)->next; 
} 
if(result==0) return 1; else 
return 0;
}	 
//retrieve node 
int retrieve_node(list*lp,void*pkey,void**dout) 
{ 
 	int f;  	node *prev,*curr;  	f=search(lp,&prev,&curr,pkey);  	if(!f) 
 	{ 
 	 	*dout=NULL;  	 	return 0; 
 	} 
 	else 
 	{ 
 	 	*dout=curr->data;  	 	return 1; 
 	} 
} 
//empty 
int empty_list(list*lp) 
{ 
 	if(lp->count==0)  	return 1;  	else 
 	return 0; 
}//full int full_list(list*lp) 
{
node* temp; temp=(node*)malloc(sizeof(node)); if(temp)
{ 
	 	free(temp); 
    return 0; 
} 
 	else 
 	return 1; 
} 
//count int list_count(list*lp) 
{ 
 	return(lp->count); 
} 
//traverse int  traverse(list* lp,int fw,void**dout) 
{ 
 	if(empty_list(lp)==1) 
 	{ 
 	 	return 0; 
 	} 
 	if(fw==0) 
 	{ 
 	 	lp->pos=lp->head;  	 	lp->pos->data=*dout;  	 	return 1; 
 	} 
 	else 
 	{ 
	 	if(lp->pos->next==NULL) 
	 	{ 
	 	 	return 0; 
}
lp->pos=lp->pos->next; *dout=lp->pos->data; return 1; 
}
} 
//desroy list list* destroy_list(list*lp) 
{ 
 	node *temp;  	if(lp) 
 	{ 
 	 	temp=lp->head;  	 	while(temp) 
 	 	{ 
 	 	 	temp=temp->next;  	 	 	free(temp->data);  	 	 	free(temp);  	 	 	temp=lp->head; 
 	 	} 
 	 	free(lp); 
 	} 
 	 	return NULL; 
} 
 	 	 
 	 
