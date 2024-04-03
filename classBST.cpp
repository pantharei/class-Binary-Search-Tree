#include "classBST.h"

node* Tree::insert(node*& root,int key){
    if(!root){
        root = new node{key};
        return root;
    }else if(key < root->label){
        root->left = insert(root->left,key);
        return root;
    }
    else if(key>root->label){
        root->right = insert(root->right,key);
        return root;
    }
    else return nullptr;
}

void Tree::inOrder(const node* root){
    if(root){
        inOrder(root->left);
        root->print_node();
        inOrder(root->right);
    }
}

void Tree::preOrder(const node* root){
    if(root){
        root->print_node();
        preOrder(root->left);
        preOrder(root->right);
    }
}

void Tree::postOrder(const node* root){
    if(root){
        postOrder(root->left);
        postOrder(root->right);
        root->print_node();
    }
}

node* Tree::deleteNode(node* r, int key){
    if(!r)return r;
    if(key < r->label){
        r->left = deleteNode(r->left,key);
        return r;
    }else if(key > r->label){
        r->right = deleteNode(r->right,key);
        return r;
    }

    //nodo target trovato
    if(!r->left){
        node* tmp = r;
        r = r->right;
        delete tmp;
        return r;
    }else if(!r->right){
        node* tmp = r;
        r = r->left;
        delete tmp;
        return r;
    }else{
        //nodo con due figli
        //prendo il più grande del sottoalbero sx
        node* succ = r;
        node* prec{nullptr};
        while(succ->right){
            prec = succ;
            succ = succ->right;
        }

        if(!prec){
            prec = succ;
            r->left = succ->left;
            r->label = prec->label;
            delete prec;
            return r;
        }else{
            //maxMin in succ
            prec->right = succ->right;
            r->label = succ->label;
            delete succ;
            return r;
        }
    }
}

node* Tree::dealloca(node* root){
    if(!root)return root;
    root->left = dealloca(root->left);
    root->right = dealloca(root->right);
    delete root;
    return nullptr;
}