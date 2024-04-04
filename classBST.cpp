#include "classBST.h"

//inserimento 
node* Tree::insert(node* root,int key){
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

//visita simmetrica
void Tree::inOrder(const node* root){
    if(root){
        inOrder(root->left);
        root->print_node();
        inOrder(root->right);
    }
}

//visita anticipata
void Tree::preOrder(const node* root){
    if(root){
        root->print_node();
        preOrder(root->left);
        preOrder(root->right);
    }
}

//visita posticipata
void Tree::postOrder(const node* root){
    if(root){
        postOrder(root->left);
        postOrder(root->right);
        root->print_node();
    }
}

//metodo che elimina un nodo esistente di label = key
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
    if(!r->left){ //comprende 2 casi : nodo foglia e nodo con un figlio soltanto
        node* tmp = r;
        r = r->right;
        delete tmp;
        return r;
    }else if(!r->right){ //come prima
        node* tmp = r;
        r = r->left;
        delete tmp;
        return r;
    }else{
        //nodo con due figli
        //prendo il più grande elemento del sottoalbero sx
        node* succ = r;
        node* prec{nullptr};
        while(succ->right){
            prec = succ;
            succ = succ->right;
        }

        if(!prec){ //se coincide con l'elemento stesso
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

//funzione che dealloca dalla memoria dinamica l'albero binario di ricerca
node* Tree::dealloca(node* root){
    if(!root)return root;
    root->left = dealloca(root->left);
    root->right = dealloca(root->right);
    delete root;
    return nullptr;
}
