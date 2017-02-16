#include <iostream>
using namespace std;
struct node;
struct node1;
node1 * newNode(node i);
node1 *insert(node1 *root, node i);
bool matchinterval(node i1, node i2);
node *overlap(node1 *root, node i);
void traversal(node1 *root);
struct node
{
    int low, high;
};
struct node1
{
    node *i;
    int max;
    node1 *left, *right;
};
int main()
{
    node ints[] = {{15, 20}, {10, 30}, {17, 19},{5, 20}, {12, 15}, {30, 40}};
    int n = sizeof(ints)/sizeof(ints[0]);
    node1 *root = NULL;
    for (int i = 0; i < n; i++)
        root = insert(root, ints[i]);
    cout << "Traversal of constructed node Tree is\n";
    traversal(root);
    node x = {14,16};
    cout << "\nSearching for node [" << x.low << "," << x.high << "]";
    node *res = overlap(root, x);
    if (res == NULL) cout << "\nNo Overlapping node";
    else cout << "\nOverlaps with [" << res->low << ", " << res->high << "]";
    node y = {21,23};
    cout << "\nSearching for node [" << y.low << "," << y.high << "]";
    node *res1 = overlap(root, y);
    if (res == NULL) cout << "\nNo Overlapping node";
    else cout << "\nOverlaps with [" << res1->low << ", " << res1->high << "]";
    return 0;
}
node1 * newNode(node i)
{
    node1 *t = new node1;
    t->i = new node(i);
    t->max = i.high;
    t->left = t->right = NULL;
};
node1 *insert(node1 *root, node i)
{
    if (root == NULL)
        return newNode(i);
    int l = root->i->low;
    if (i.low < l)
        root->left = insert(root->left, i);
    else root->right = insert(root->right, i);
    if (root->max < i.high)
        root->max = i.high;
    return root;
}
bool matchinterval(node i1, node i2)
{
    if (i1.low <= i2.high && i2.low <= i1.high)return true;
    return false;
}
node *overlap(node1 *root, node i)
{
    if (root == NULL) return NULL;
    if (matchinterval(*(root->i), i))return root->i;
    if (root->left != NULL && root->left->max >= i.low)return overlap(root->left, i);
    return overlap(root->right, i);
}
void traversal(node1 *root)
{
    if (root == NULL) return;
    traversal(root->left);
    cout << "[" << root->i->low << ", " << root->i->high << "]"<< " max = " << root->max << endl;
    traversal(root->right);
}
