#include <iostream>
#include <cstdlib>

#include "BST.h"

using namespace std;


BST::BST()
{
    root = nullptr;
};


BST::node* BST::createLeaf(int key)
{
    //cout << "1Working\n";
    node* n = new node;
    
    n->key = key;
    n->left = nullptr;
    n->right = nullptr;
    
    return n;
};

void BST::addLeafPrivate(int key, node *parent)
{
    //cout << "2Working\n";
    if (root == nullptr)
    {
        //cout << "Hello\n";
        root = createLeaf(key);
    }
    else if(key < parent->key)
    {
        if(parent->left != nullptr)
        {
            addLeafPrivate(key, parent->left);
        }
        else
        {
            parent->left = createLeaf(key);
        }
    }
    else if(key > parent->key)
    {
        if(parent->right != nullptr)
        {
            addLeafPrivate(key, parent->right);
        }
        else
        {
            parent->right = createLeaf(key);
        }
    }
    else
    {
        cout << "The key: " << key << " has already been added to the tree \n";
    }
};

void BST::addLeaf(int key)
{
    //cout << "3Working\n";
    addLeafPrivate(key, root);
};

void BST::printInOrderPrivate(node *current)
{
    //cout << "4Working\n";
    if(root != nullptr )
    {
       if(current->left != nullptr) 
       {
         printInOrderPrivate(current->left);
       }
       cout << current->key << ", ";
       if(current->right != nullptr)
       {
           printInOrderPrivate(current->right);
       }
    }
    else
    {
      cout << "The tree is empty \n";  
    }
};

void BST::printInOrder()
{
    //cout << "5Working\n";
   printInOrderPrivate(root); 
};

BST::node* BST::returnNodePrivate(int key, node *data)
{
    if(data != nullptr)
    {
        if(data->key == key)
        {
            return data;
        }
        else
        {
            if(key < data->key)
            {
                return returnNodePrivate(key, data->left);
            }
            else
            {
                return returnNodePrivate(key, data->right);
            }
        }
    }
    else
    {
        return nullptr;
    }
};

BST::node* BST::returnNode(int key)
{
  return returnNodePrivate(key, root);  
};

int BST::returnRoot()
{
  if(root != nullptr)
  {
      return root->key;
  }
  else
  {
      return -1000;
  }
};

void BST::printChildren(int key)
{
    node *parent = returnNode(key);
    
    if(parent != nullptr)
    {
       cout << "The parent node = " << parent->key <<endl;
       
       parent->left == nullptr ? 
       cout << "The left child is: empty \n" :
       cout << "The left child is: " << parent->left->key << endl;
       
       parent->right == nullptr ? 
       cout << "The right child is: empty \n" :
       cout << "The right child is: " << parent->right->key << endl;
    }
    else
    {
        cout << "This key: " << key << " is not in the tree \n";
    }
};

int BST::findSmallestPrivate(node *small)
{
    if(root == nullptr)
    {
        cout << "This tree is empty \n";
        return -1000; 
    }
    else
    {
        if(small->left != nullptr)
        {
            return findSmallestPrivate(small->left);
        }
        else
        {
            return small->key;
        }
    }
};

int BST::findSmallest()
{
    return findSmallestPrivate(root);
};

void BST::removeNodeMatch(node *parent, node *match, bool left)
{
    if(root != nullptr)
    {
        node *delptr;
        int matchKey = match->key;
        int smallestInRightSubtree;
        
        if(match->left == nullptr && match->right == nullptr)
        {
          delptr = match;
          left == true ? parent->left = nullptr : parent->right = nullptr;
          delete delptr;
          cout << "The node containg key: " << matchKey << " has been deleted. \n";
        }
        else if(match->left == nullptr && match->right != nullptr)
        {
          left == true ? parent->left = match->right : parent->right = match->right;
          match->right = nullptr;
          delptr = match;
          delete delptr;
          cout << "The node containg key: " << matchKey << " has been deleted. \n";
        }
        else if(match->left != nullptr && match->right == nullptr)
        {
          left == true ? parent->left = match->left : parent->right = match->left;
          match->left = nullptr;
          delptr = match;
          delete delptr;
          cout << "The node containg key: " << matchKey << " has been deleted. \n";
        }
        else
        {
            smallestInRightSubtree = findSmallestPrivate(match->right);
            removeNodePrivate(smallestInRightSubtree, match);
            match->key = smallestInRightSubtree;
            cout << "The node containg key: " << matchKey << " has been updated to: " << match->key 
            << " and the node containg key: " << smallestInRightSubtree << " has been deleted. \n";
        }
    }
    else
    {
        cout << "Could not remove this match as the tree is empty \n";
    }
};

void BST::removeNodePrivate(int key, node *parent)
{
    if(root != nullptr)
    {
       if(root->key == key)
       {
           removeRootMatch();
       }
       else
       {
           if(key < parent->key && parent->left != nullptr)
           {
               parent->left->key == key ?
               removeNodeMatch(parent, parent->left, true) :
               removeNodePrivate(key, parent->left);
           }
           else if(key > parent->key && parent->right != nullptr)
           {
               parent->right->key == key ?
               removeNodeMatch(parent, parent->right, false) :
               removeNodePrivate(key, parent->right);
           }
           else
           {
               cout << "This value is not in the tree \n";
           }
       }
    }
    else
    {
        cout << "This tree is empty \n";
    }
};

void BST::removeNode(int key)
{
    removeNodePrivate(key, root);
};

void BST::removeRootMatch()
{
    if(root != nullptr)
    {
       node *delptr = root;
       int rootKey = root->key;
       int smallestInRightSubtree;
       
       if(root->left == nullptr && root->right == nullptr)
       {
           root = nullptr;
           delete delptr;
       }
       else if(root->left == nullptr && root->right != nullptr)
       {
           root = root->right;
           delptr->right = nullptr;
           delete delptr;
           cout << "The root has been updated from: " << rootKey << " to: " << root->key << endl;
       }
       else if(root->left != nullptr && root->right == nullptr)
       {
           root = root->left;
           delptr->left = nullptr;
           delete delptr;
           cout << "The root has been updated from: " << rootKey << " to: " << root->key << endl;
       }
       else
       {
           smallestInRightSubtree = findSmallestPrivate(root->right);
           removeNodePrivate(smallestInRightSubtree, root);
           root->key = smallestInRightSubtree;
           cout << "The root has been updated from: " << rootKey << " to: " << root->key << endl;
       }
    }
    else
    {
        cout << "Can not reomver root as the tree is empty \n";
    }
};

