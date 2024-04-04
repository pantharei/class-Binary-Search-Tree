#include <iostream>
struct node{
        int label;
        struct node* left{nullptr};
        struct node*right{nullptr};

        node(int k):label(k){
        }

        void print_node()const{
            std::cout << label << ' ';
        }
};
class Tree{
    node* root{nullptr};

    node* insert(node*,int);
    void inOrder(const node*);
    void preOrder(const node*);
    void postOrder(const node*);
    node* deleteNode(node*, int);
    node* dealloca(node*);

    public:
    void add(int key){
        root = insert(root,key);
    }

    void pre(){
        preOrder(root);
    }
    void in(){
        inOrder(root);
        std::cout << std::endl;
    }
    void post(){
        postOrder(root);
    }
    void cancelNode(int t){
        deleteNode(root,t);
    }
    ~Tree(){
        dealloca(root);
    }
};
