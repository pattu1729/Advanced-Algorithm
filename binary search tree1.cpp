#include<stdio.h>
#include<stdlib.h>
struct node
{
   int key;
   struct node *left, *right;
};
struct node *newNode(int item)
{
   struct node *temp = (struct node *)malloc(sizeof(struct node));
   temp->key = item;
   temp->left = temp->right = NULL;
   return temp;
}
void traversetree(struct node *root)
{
   if (root != NULL)
   {
      traversetree(root->left);
      printf("%d \t", root->key);
      traversetree(root->right);
   }
}
struct node* search(struct node* root, int key)
{
   if (root == NULL || root->key == key)
      return root;
   if (root->key < key)
      return search(root->right, key);
   return search(root->left, key);
}
struct node* insert(struct node* node, int key)
{
  if (node == NULL) 
    return newNode(key);
  if (key < node->key)
    node->left = insert(node->left, key);
  else if (key > node->key)
    node->right = insert(node->right, key);
  return node;
}
struct node *minValueNode(struct node *node) {
  struct node *current = node;

  // Find the leftmost leaf
  while (current && current->left != NULL)
    current = current->left;

  return current;
}
struct node *deleteNode(struct node *root, int key) {
  // Return if the tree is empty
  if (root == NULL) return root;

  // Find the node to be deleted
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);

  else {
    // If the node is with only one child or no child
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL)    
    {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    // If the node has two children
    struct node *temp = minValueNode(root->right);

    // Place the inorder successor in position of the node to be deleted
    root->key = temp->key;

    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}
int main()
{
  struct node *root = NULL;
  root = insert(root, 23);
  insert(root, 11);
  insert(root, 17);
  insert(root, 12);
  insert(root, 24);
  insert(root, 16);
  printf("The tree is :\n");
  traversetree(root);
  printf("\nUpdation..enter number\n");
  int u;
  scanf("%d",&u);
  insert(root, u);
  printf("Tree after updation is :\n");
  traversetree(root);
  printf("\n");
  printf("searching a node...Enter a number\n");
  int s;
  scanf("%d",&s);
  if(search(root,s))
    printf("Node %d found\n",s);
  else
    printf("Node not found %d\n",s);
  printf("\nDeleting...Enter number\n");
  int d;
  scanf("%d",&d);
  root = deleteNode(root, d);
  printf("\nAfter Deleting\n");
  traversetree(root);
  printf("\n");
  return 0;
}
