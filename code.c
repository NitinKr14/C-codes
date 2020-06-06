#include <stdio.h>
#include <stdlib.h>
int op;
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node *newNode(int item)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    //temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
	return temp;
}
void preorder(struct node *root);
int check(struct node* root)
{

   if (root != NULL)
    {
        op++;
        int x=check(root->left);
        int y=check(root->right);
    }
    return op;
}
void preorder(struct node *root)
{

    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }

}


struct node **constructTrees(int start, int end)
{
	struct node **list;
	list=(struct node**)malloc(sizeof(struct node*));
	list[0]=NULL;
	if (start > end)
	{

		return list;
	}
	for (int i = start; i <= end; i++)
	{
		/* constructing left subtree */
		struct node **leftSubtree = constructTrees(start, i - 1);

		/* constructing right subtree */
		struct node **rightSubtree = constructTrees(i + 1, end);
		int q=0,t=0;
		while(leftSubtree[q]!=NULL)
		q++;
		while(rightSubtree[t]!=NULL)
		t++;
		for (int j = 0; j < q+1; j++)
		{
			struct node* left = leftSubtree[j];
			for (int k = 0; k < t+1; k++)
			{
				struct node * right = rightSubtree[k];
				struct node * mode = newNode(i);// making value i as root
				mode->left = left;			 // connect left subtree
				mode->right = right;		 // connect right subtree
				int f=0;
				while(list[f]!=NULL)
                		f++;
				list[f]=mode;
				int l=(f+2)*sizeof(struct node*);
				list=(struct node**)realloc(list,l);
				list[f+1]=NULL;

						 // add this tree to list
			}
		}
	}
	int z=0;
	while(list[z]!=NULL)
	z++;
	int r=z*sizeof(struct node*);
	list=realloc(list,r);
	return list;
}
int main()
{
	// Construct all possible BSTs
	int n;
	scanf("%d", &n);
	struct node** numb=constructTrees(1, n);
	int t=0;
	while(numb[t]!=NULL)
	t++;
    printf("Preorder traversals of all constructed BSTs are \n");

	for (int i = 0; i <t; i++)
	{
		op=0;
		if(check(numb[i])==n){
		preorder(numb[i]);
		printf("\n");}
	}
	return 0;
}
