#include "BSTNode.cpp"
#include <iostream>
using namespace std;


class BST {

public:
  BSTNode* root;

  BST() {
    root = nullptr; // empty
  }

  void printInorder(BSTNode *node)
  {
    if (node == nullptr)
    {
      return;
    }
    printInorder(node->left);
    cout << node->value << " ";
    printInorder(node->right);
  }

  void insert(int value){ // new insert (+กรณีไม่ซ้ำ)
    if (!check_re(value)){
        
        BSTNode* n = new BSTNode();
        n -> left = nullptr;
        n -> right = nullptr;
        n -> value = value;
    
        // root is empty
        if (!root)
            root = n;
        else{
            BSTNode* n1 = root;

            while (true){
        
                if (value > n1->value){ // greater than -> right
                  if (n1->right == nullptr){ // find null
                      n1->right = n;
                      break;}
                  n1 = n1->right;  
                }
        
                else if (value < n1->value){ // less than -> left
                      if (n1->left == nullptr){ // find null
                          n1->left = n;
                          break;
                      }
                    n1 = n1->left;
                }
            }
        }
    }
  }

  bool check_re(int value){
      BSTNode* c = root;
    
      while (c!=nullptr){
          // greater than
        if (value == c->value){
                  return true;
              }
          else if (value > c->value){
            c = c->right;
          }
          
        // less than
        else {
              c = c->left;
            }
    }
    return false;
}

  void remove(int value) {
      if (check_re(value)){
        BSTNode* cu = root;
        BSTNode* pr_ = root;
        bool lft;

        // position
        while (value != cu->value){
              if (value > cu->value){ // right
                  pr_ = cu;
                  cu = cu->right;
                  lft = false;}
              else if (value < cu->value){ // left
                    pr_ = cu;
                    cu = cu->left;
                    lft = true;}
        }
        
        
        // case 1
        if (cu->right == nullptr && cu->left == nullptr){
            if (cu == root)
                root = nullptr;
            else if (!lft) // right
                pr_->right = nullptr;
            else // left
                pr_->left = nullptr;
        }
          
        // case 2
        else if (cu->left == nullptr){ // right
              if (cu == root)
                  root = cu->right;
              else if (!lft)
                  pr_->right = cu->right;
              else
                  pr_->left = cu->right;
        }
        else if (cu->right == nullptr){ //left
              if (cu == root)
                  root = cu->left;
              else if (!lft)
                  pr_->right = cu->left;
              else
                  pr_->left = cu->left;
        }

      // case 3
      else {
        // min
        
          BSTNode* cmin = cu->right;
          BSTNode* pmin = cu;
          BSTNode* tt;
          bool lft1 = false; // right
        
          while(cmin->left != nullptr){
                pmin = cmin;
                cmin = cmin->left;
                lft1 = true; 
          }
          tt = cmin->right;
        // current's lft child -> left min
          cmin->left = cu->left;
        
          if (cmin != cu->right){
              cmin->right = cu->right;
          }

        // case 3.1
          if (cu == root){
              if (lft1)
                  root = pmin->left;
              else
                  root = pmin->right;
          }

          else if (lft){ //left
              if (lft1)
                  pr_->left = pmin->left;
              else
                  pr_->left = pmin->right;   
          }

          else{ // right
              if (lft1)
                  pr_->right = pmin->left;
              else
                  pr_->right = pmin->right;
          }

        if (lft1)
            pmin->left = tt;
        else
            pmin->right = tt;

        
      }
    }
  }

  int get_depth(int value) {
     if (check_re(value))
    {
      BSTNode* cu = root;
      int dep = 0;
      while (cu->value != value){
          if (value < cu->value)
              cu = cu->left;
          else
              cu = cu->right;
        
          dep++;
      }
      return dep;
    }
    else
      return -1;
}
}
;