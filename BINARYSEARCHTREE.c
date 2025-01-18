#include<stdio.h> #include<stdlib.h> typedef struct node_info 
{ 
 	int data; 
 	struct node_info *l,*r; 
}node; void insertnode(node**proot,int e); node*getnode(int n); void createbst(node** proot) 
{ 
 	int ele; 
 	void insertnode(node**,int);  	printf("Enter root element\n");  	scanf("%d",&ele);  	*proot=getnode(ele);  	printf("Enter the tree elements\n"); 
 
 
 	while(scanf("%d",&ele)!=EOF)  	 	insertnode(proot,ele);  	return ; 
}
void insertnode(node**proot,int e) 
{ 
 	node *t1=*proot,*t2=NULL;  	node*temp;  	temp=getnode(e);  	while(t1) 
 	{ 
 	 	t2=t1; 
 	 	if(t1->data<=temp->data) 
 	 	 	t1=t1->r;  	 	else  	 	 	t1=t1->l; 
 	} 
 	if(temp->data<t2->data) 
 	 	t2->l=temp;  	else  	 	t2->r=temp; 
} 
node*getnode(int n) 
{ 
 	node*temp; 
 	temp=(node*)malloc(sizeof(node));  	temp->data=n;  	temp->l=NULL;  	temp->r=NULL;  	return temp; 
} 
void inorder(node*proot)//ascending 
{ if(proot) 
{ 
	 	inorder(proot->l); 
 	 	printf("%d\t",proot->data);  	 	inorder(proot->r); 
 	} 
} 
void inorder2(node*proot)//descending 
{ 
 	if(proot) 
 	{ 
 	 	inorder2(proot->r);  	 	printf("%d\t",proot->data);  	 	inorder2(proot->l); 
 	} 
} 
void preorder(node*proot) 
{ 
 	if(proot) 
 	{ 
 	 	printf("%d\t",proot->data);  	 	preorder(proot->l);  	 	preorder(proot->r); 
 	} 
} 
void postorder(node*proot) 
{ 
 	if(proot) 
 	{ 
 	postorder(proot->l);  	postorder(proot->r);  	printf("%d\t",proot->data); 
} 
}
int search_node(node*root,int key) 
{ 
 	if(!root) return 0;  	if(root->data==key) return 1; 
 	return(search_node(root->l,key) || search_node(root->r,key)); 
} 
int ele_occ_count(node*root,int key) 
{ 
 	if(!root)return 0;  	if(root->data==key) 
 	return(1+ele_occ_count(root->l,key)+ele_occ_count(root->r,key));  	return(0+ele_occ_count(root->l,key)+ele_occ_count(root->r,key)); 
} 
int height_count(node*root) 
{ 
 	if(!root)return 0;  	int lh=height_count(root->l);  	int rh=height_count(root->r);  	if(lh>rh)return(lh+1);  	else return (rh+1); 
} 
node* copy_tree(node*root) 
{ 
 	node*temp; 
 	if(!root)return NULL;  	temp=(node*)malloc(sizeof(node)); temp->data=root->data; temp->l=copy_tree(root->l); temp->r=copy_tree(root->r); return temp; 
}
int sum_nodes(node*root) 
{ 
 	if(!root)return 0; 
 	return(root->data+sum_nodes(root->l)+sum_nodes(root->r)); 
} 
int node_count(node*root) 
{ 
 	if(!root) return 0; 
 	return(1+node_count(root->l)+node_count(root->r)); 
} 
int leaf_count(node*root) 
{ 
 	if(!root)return 0;  	if(!root->l && !root->r) return 1;  	return(0+leaf_count(root->l)+leaf_count(root->r)); 
} 
int balanced(node*root) 
{ 
 	if(!root)return 1;  	int lh=height_count(root->l);  	int rh=height_count(root->r); 
 	if(abs(lh-rh)<=1 && balanced(root->r) && balanced(root->r)) 
 	return 1;  	return 0; 
} 
int inter_count(node*root) 
{
 	if(!root || (!root->l && !root->r))return 0;  	return(1+inter_count(root->l)+inter_count(root->r)); 
}
//parent key for bst 
node * getParent(node *root, int key) 
{ 
    if (root == NULL) return NULL; 
    else if ((root->r && root->r->data == key) || (root->l && root->l->data == key))      return root;     else if (root->data > key)      return (getParent(root->l, key));     return (getParent(root->r, key));     return root; 
} 
 
int main() 
{ 
 	node*root=NULL;  	node*copy;  	int ch=1,key;  	while(ch) 
 	{ 
 	 	printf("Enter your choice\n1.Create tree\n2.Display tree\n3.Search element\n4.Occurance count\n5.Height of tree\n6.Copy tree\n7.Node sum\n8.Node count\n9.Leaf count\n10.Balanced\n11.Intermediate node count\n12.Parent of key\n"); 
 	 	scanf("%d",&ch);  	 	switch (ch) 
 	 	{ 
 	 	 	case 1: createbst(&root); 
 	 	 	break; 
 	 	 	case 2: printf("Elements in ascending order\n"); 
 	 	 	 	 	inorder(root);  	 	 	 	 	printf("\n"); 
 	 	 	        printf("Elements in descending order\n"); 
 	 	 	        inorder2(root);  	 	 	        printf("\n"); 
 	 	 	break; 
 	 	 	case 3: printf("Enter the key element to be searched\n"); 
 	 	 	 	 	scanf("%d",&key); 
 	 	 	 	 	if(search_node(root,key)) printf("Key element %d exist\n",key); 
 	 	 	 	 	else printf("Key element does not exist\n"); 
 	 	 	break; 
 	 	 	case 4: printf("Enter the key element\n"); 
 	 	 	 	 	scanf("%d",&key); 
     printf("The occurance count of the key element is:%d\n",ele_occ_count(root,key)); 
 	 	 	break; 
 	 	 	case 5: printf("The height of the tree is:%d\n",height_count(root)); 
 	 	 	break; 
 	 	 	case 6: copy=copy_tree(root);  	 	 	 	 	printf("The copied tree is\n"); 
 	 	 	 	 	inorder(copy);  	 	 	 	 	printf("\n");  	 	 	break; 
 	 	 	case 7: printf("The sum of nodes of tree is:%d\n",sum_nodes(root)); 
 	 	 	break; 
 	 	 	case 8: printf("The node count is:%d\n",node_count(root)); 
 	 	 	break; 
 	 	 	case 9: printf("The leaf count of tree is:%d\n",leaf_count(root)); 
 	 	 	break; 
 	 	 	case 10: if(balanced(root))  	 	 	 	 	 printf("Tree is balanced\n"); 
 	 	 	 	 	 else 
 	 	 	 	 	 printf("Tree is not balanced\n"); 
 	 	 	break; 
 	 	 	case 11: printf("The intermediate node count is:%d\n",inter_count(root));  	 	 	break; 
 	 	 	case 12: printf("Enter the key element to be searched\n"); 
 	 	 	 	 	 scanf("%d",&key); 
 	 	 	 	 	 int *x=(int*)getParent(root,key);  	 	 	 	 	 printf("Parent element of %d is %d\n",key,*x); 
 	 	 	break; 
 	 	 	default: printf("Enter valid choice\n"); 
 	 	 	return 0; 
 	 	} 
 	} 
 	return 0; 
} 
 	 	 	             	 	 	            
 	 	 	 	 	    
  
