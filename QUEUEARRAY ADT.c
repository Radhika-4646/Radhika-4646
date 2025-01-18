#include<stdio.h> #include<stdlib.h> typedef struct  
{ 
 	int front,count,rare;  	int maxsize;  	void** qarray; 
}queue; queue* create_queue(int size) 
{ 
 	queue* qp; 
 	qp=(queue*)malloc(sizeof(queue));  	if(!qp)  	return NULL;  	else 
 	{ 
 	 	qp->front=-1;  	 	qp->rare=-1;  	 	qp->count=0;  	 	qp->maxsize=size; 
 	} 
 	qp->qarray=(void**)calloc(size,sizeof(void*));  	if(!qp->qarray) 
 	{ 
 	 	free(qp);  	 	return NULL; 
 	} 
 	else 
   { 
 	   return qp; 
   } 
} 
int en_queue(queue*qp,void*dp) 
{ 
 	if(qp->count==qp->maxsize)  	return 0;  	else 
 	{ 
 	 	(qp->rare)++;  	 	if(qp->rare==qp->maxsize) 
 	 	{ 
 	 	 	qp->rare=0; 
 	 	} 
 	 	qp->qarray[qp->rare]=dp;  	 	if(!qp->count)  	 	qp->front=0;  	 	(qp->count)++;  	 	return 1; 
 	} 
} 
void* de_queue(queue*qp) 
{ 
 	void* dp;  	if(!qp->count)  	return NULL;  	else 
{ 
 	dp=qp->qarray[qp->front];  	(qp->front)++; if((qp->front)==(qp->maxsize)) 
 	   {  	 	    qp->front=0; 
 	 	} 
 	    if(qp->count==1) 
 	  {  	 	qp->front=-1;  	 	qp->rare=-1;  	  } 
 	  (qp->count)--; 
  } 
  return dp; 
} 
int qcount(queue*qp) 
{ 
 	return(qp->count); 
} 
void* qfront(queue*qp) 
{ 
 	if(!qp->count)  	return NULL;  	else 
 	return(qp->qarray[qp->front]); 
} 
void* qrare(queue*qp) 
{ 
 	if(!qp->count)  	return NULL;  	else 
 	return(qp->qarray[qp->rare]); 
}
int qfull(queue*qp) 
{ 
 	if(qp->count==qp->maxsize)  	return 1;  	else 
 	return 0; 
} 
int qempty(queue*qp) 
{ 
 	if(!(qp->count))  	return 1;  	else 
 	return 0; 
} 
queue* qdestroy(queue*qp) 
{ 
 	int i;  	if(qp) 
 	{ 
 	 	if(qp->count>0) 
 	 	{ 
 	 	 	i=qp->front;  	 	 	while(i!=qp->rare) 
 	 	 	{ 
 	 	 	 	free(qp->qarray[i]); 
                 i=i+1;                  if(i==qp->maxsize)                  i=0; 
	 	 	 } 
	 	 	 free(qp->qarray[qp->rare]); 
	 	 } 
 free(qp->qarray); 
 	 	 free(qp); 
 	 } 
 	 return NULL; 
 } 	 	 	 
