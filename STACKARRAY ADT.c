#include<stdio.h> #include<stdlib.h> typedef struct 
{ 
 	int count,maxsize,top;  	void** starr; 
}stack; stack* create_stack(int size) 
{
stack* sp; 
sp=(stack*)malloc(sizeof(stack)); if(!sp) 
 	{ 
 	 	return NULL; 
 	} 
 	else 
 	{ 
 	 	sp->count=0;  	 	sp->maxsize=size;  	 	sp->top=-1; 
 	 	sp->starr=(void**)calloc(size,sizeof(void*));  	 	if(!(sp->starr)) 
 	 	{ 
 	 	 	free(sp);  	 	 	return NULL; 
 	 	} 
 	 	return sp; 
 	} 
} 
int push_stack(stack* sp,void* pdata) 
{ 
 	if(sp->count==sp->maxsize)  	return 0;  	(sp->top)++;  	sp->starr[sp->top]=pdata;  	(sp->count)++;  	return 1; 
} 
void* pop_stack(stack* sp) 
{
void* dptr; if(sp->count==0) return NULL; else 
{ 
 	 	dptr=(sp->starr[sp->top]); 
 	 	(sp->top)--;  	 	(sp->count)--;  	 	return dptr; 
 	} 
} 
void* stack_top(stack* sp) 
{ 
 	void* dptr;  	if(sp->count==0)  	return NULL;  	else 
 	 
 	{ 
 	 	dptr=(sp->starr[sp->top]);  	 	return dptr; 
 	} 
} 
int stack_count(stack* sp) 
{ 
 	return(sp->count); 
} 
int stack_empty(stack*sp) 
{ 
 	if(!(sp->count)) return 1; 
else return 0; 
}
int stack_full(stack*sp) 
{ 
 	if(sp->count==sp->maxsize)  	return 1;  	else 
 	return 0; 
} 
stack* destroy_stack(stack* sp) 
{ 
 	if(sp) 
 	{ 
 	 	for(int i=(sp->top);i>=0;i--) 
 	 	{ 
 	 	 	free(sp->starr[i]); 
 	 	} 
 	 	 	free(sp->starr);  	 	 	free(sp); 
 	} 
 	return NULL; 
} 
