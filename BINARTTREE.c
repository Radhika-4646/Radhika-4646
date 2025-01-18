#include<stdio.h> #include<stdlib.h> typedef struct node_info  
{     int data;     struct node_info *l,*r; }node; void createtree(node**pr); int insert_node(node**proot,int n,char*p); node* getnode(int n); void preorder(node*root); void postorder(node*root); void inorder(node*root); int search_node(node*,int); int ele_occ_count(node*,int); int height_count(node*root); node*copy_tree(node*root); int sum_node(node*root); int node_count(node*root); int leaf_count(node*root); int isBalanced(node* root); int inter_count(node*root); node * getParent(node *root, int key); int main() 
{ 
 	node*root=NULL;  	node*copy;  	int ch=1,key;  	while(ch) 
 	{ 
 	 	printf("Enter your choice\n1.Create tree\n2.Display tree\n3.Search element\n4.Occurance count\n5.Height of tree\n6.Copy tree\n7.Node sum\n8.Node count\n9.Leaf count\n10.Balanced\n11.Intermediate node count\n12.Parent of key\n"); 
 	 	scanf("%d",&ch);  	 	switch (ch) 
 	 	{ 
 	 	 	case 1: createtree(&root); 
 	 	 	break; 
 	 	 	case 2: inorder(root); 
 	 	 	 	 	printf("\n");  	 	 	break; 
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
 	 	 	case 7: printf("The sum of nodes of tree is:%d\n",sum_node(root)); 
 	 	 	break; 
 	 	 	case 8: printf("The node count is:%d\n",node_count(root)); 
 	 	 	break; 
 	 	 	case 9: printf("The leaf count of tree is:%d\n",leaf_count(root)); 
 	 	 	break; 
 	 	 	case 10: if(isBalanced(root))  	 	 	 	 	 printf("Tree is balanced\n"); 
 	 	 	 	 	 else 
 	 	 	 	 	 printf("Tree is not balanced\n"); 
 	 	 	break; 
 	 	 	case 11: printf("The intermediate node count is:%d\n",inter_count(root));  	 	 	break; 
 	 	 	case 12: printf("Enter key element\n"); 
 	 	 	 	 	 scanf("%d",&key); 
 	 	 	 	 	 if(getParent(root,key)==NULL) printf("Element not found\n"); 
 	 	 	 	 	 else { 
 	 	 	 	 	 int *x=(int*)getParent(root,key);  	 	 	 	 printf("The parent of the key is:%d\n",*x); 
 	 	 	 	} 
 	 	 	break; 
 	 	 	default: printf("Enter valid choice\n"); 
 	 	 	return 0; 
 	 	} 
 	} 
} 
 
void createtree(node**pr)  
{ 
    int n;char pos[30]; 
    int insert_node(node**,int,char*);     printf("Enter root element\n");     scanf("%d",&n);     *pr=getnode(n); 
    printf("Enter the tree elements\n");     while(scanf("%d",&n)!=EOF) 
    { 
        printf("Enter the position string :");         scanf("%s",pos);         if(!insert_node(pr,n,pos)) 
 	 	 	printf("Invalid position string or node already exists\n"); 
    } 
} 
int insert_node(node**proot,int n,char*p) 
{ 
    node *temp,*t1=*proot,*t2=NULL;     int i; 
    temp=getnode(n);     for(i=0;*(p+i)!='\0';i++) 
    { 
        if(t1==NULL)             break;         t2=t1;         if(*(p+i)=='l')             t1=t1->l;         else             t1=t1->r; 
    } 
    if(*(p+i)=='\0'&&t1==NULL) 
    {         if(p[i-1]=='l')             t2->l=temp;         else             t2->r=temp; 
    } 
    else         return 0;     return 1; 
} 
node* getnode(int n)  
{ 
    node*temp;     temp=(node*)malloc(sizeof(node));     if(temp) 
    { 
        temp->data=n;         temp->l=NULL;         temp->r=NULL; 
    } 
    return temp; 
}
void preorder(node*root) 
{ 
 	if(root!=NULL){  	 	printf("%d\t",root->data); 
    preorder(root->l);     preorder(root->r); 
 	} 
} 
void postorder(node*root) 
{ 
 	if(root!=NULL){ 
    postorder(root->l);     postorder(root->r);     printf("%d\t",root->data); 
 	} 
} 
void inorder(node*root) 
{ 
 	if(root!=NULL){ 
    inorder(root->l);     printf("%d\t",root->data);     inorder(root->r); 
 	} 
} 
int search_node(node*root,int key){ 
 	if(root==NULL) 
 	 	return 0; 
 	else if(root->data==key) 
 	 	return 1; 
 	return (search_node(root->l,key)||search_node(root->r,key)); 
} 
int ele_occ_count(node*root,int key) 
{ 
 	if(!root) return 0; 
 	if(root->data==key)return(1+ele_occ_count(root->l,key)+ele_occ_count(root->r,key));  	return(0+ele_occ_count(root->l,key)+ele_occ_count(root->r,key)); 
} 
int height_count(node*root) 
{ 
 	if(!root) return 0;  	int lh=height_count(root->l);  	int rh=height_count(root->r);  	if(lh>rh) return (lh+1);  	return(rh+1); 
} 
node*copy_tree(node*root) 
{ 
 	node*temp; 
 	if(!root) return NULL;  	temp=(node*)malloc(sizeof(node));  	temp->data=root->data;  	temp->l=copy_tree(root->l);  	temp->r=copy_tree(root->r);  	return temp; 
} 
int sum_node(node*root) 
{ 
 	if(!root)return 0; 
 	return(root->data+sum_node(root->l)+sum_node(root->r)); 
} 
int node_count(node*root) 
{
 	if(!root)return 0; 
 	return(1+node_count(root->l)+node_count(root->r)); 
} 
int leaf_count(node*root) 
{ 
 	if(!root)return 0;  	if(!root->l && !root->r) return 1; 
 	return(0+leaf_count(root->l)+leaf_count(root->r)); 
} 
int isBalanced(node* root) 
 {     int lh, rh;     if(!root) return 1;     lh = height_count(root->l);     rh = height_count(root->r); 
    if (abs(lh - rh) <= 1 && isBalanced(root->l) && isBalanced(root->r))         return 1;     return 0; 
} 
int inter_count(node*root) 
{ 
 	if(!root || (!root->l && !root->r)) return 0;  	return(1+inter_count(root->l)+inter_count(root->r)); 
} 
//Parent key for bt 
node * getParent(node *root, int key) 
{ 
    if (root == NULL) return NULL; 
    if ((root->l && root->l->data == key) || (root->r && root->r->data == key)) return root;     node *left = getParent(root->l, key);     if (left != NULL) return left; 
    node *right = getParent(root->r, key);     return right; 
} 
 
 
