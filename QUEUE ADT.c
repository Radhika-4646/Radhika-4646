#include<stdio.h> #include<stdlib.h> typedef struct qnode_info 
{ 
 	void* dptr;  	struct qnode_info*next; 
}qnode; typedef struct 
{ 
 	int count;  	qnode *front,*rear; 
}queue; queue* create_queue() 
{ 
 	queue* qp; 
 	qp=(queue*)malloc(sizeof(queue));  	if(qp) 
 	{ 
 	qp->front=NULL;  	qp->rear=NULL;  	qp->count=0; 
} 
return qp; 
}
int  en_queue(queue* qp,void* dp) 
{ 
 	qnode*temp; 
 	temp=(qnode*)malloc(sizeof(qnode));  	if(!temp)  	return 0;  	if(temp) 
 	{ 
 	 	temp->dptr=dp;  	 	temp->next=NULL;  	 	if(qp->count==0) 
 	 	{ 
 	 	 	qp->front=temp; 
 	 	} 
 	 	else 
 	 	{ 
 	 	 	qp->rear->next=temp; 
 	 	} 
 	 	    qp->rear=temp; 
 	 	    (qp->count)++; 
 	 	     
 	  } 
 	  return 1; 
} 
int de_queue(queue*qp,void**dp) 
{
qnode*temp;  if(qp->count==0) return 0; temp=qp->front; *dp=temp->dptr; qp->front=temp->next; if(qp->count==1) 
{ 
	 	qp->rear=NULL; 
 	} 
 	free(temp);  	(qp->count)--;  	return 1; 
} 
void* front_queue(queue*qp) 
{ 
 	if(!(qp->count))  	return NULL;  	else 
 	return(qp->front->dptr); 
} 
void* rare_queue(queue*qp) 
{ 
 	if(!(qp->count))  	return  NULL; 
 	else 
 	return(qp->rear->dptr); 
} 
int qcount(queue*qp) 
{ 
 	return(qp->count); 
} 
int qempty(queue*qp) 
{
if(qp->count==0)
return 1; return 0; 
 
} 
int qfull(queue*qp) 
{ 
 	qnode* temp; 
 	temp=(qnode*)malloc(sizeof(qnode));  	if(!temp)  	return 1;  	else 
 	{ 
 	 	free(temp); 
 	    return 0; 
 	} 
} 
 
queue* destroy_queue(queue*qp) 
{ 
 	qnode *temp,*deleteptr;  	if(qp) 
 	{ 
 	 	temp=qp->front;  	 	while(temp) 
 	 	{ 
 	 	 	deleteptr=temp;  	 	 	temp=temp->next; 
 	 	 	free(deleteptr->dptr);  	 	 	free(deleteptr); 
	 	} 
	 	free(qp);
	} 	 
return NULL;  
}
  
 
