
/**
 *  Name : hw3
 *
 *  Author : Tony Guo
 *  
 *  Country : Taiwan
 *
 *  Date : 16 April, 2019 
 * 
 *  github : https://github.com/tony92151/algorithm_homework
 */

// reference https://gist.github.com/harish-r


#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

class BST{
    node* root;
    node* makeEmpty(node* t){
        if(t == NULL)
            return NULL;
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return NULL;
    }

    node* insert(int x, node* t){
        if(t == NULL){
            t = new node;
            t->data = x;
            t->left = t->right = NULL;
        }
        else if(x < t->data)
            t->left = insert(x, t->left);
        else if(x > t->data)
            t->right = insert(x, t->right);
        return t;
    }

    node* findMin(node* t){
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

    node* findMax(node* t){
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }

    node* remove(int x, node* t){
        node* temp;
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            t->left = remove(x, t->left);
        else if(x > t->data)
            t->right = remove(x, t->right);
        else if(t->left && t->right){
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        }
        else{
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }

        return t;
    }

    void inorder(node* t){
        if(t == NULL)
            return;
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }

    node* find(node* t, int x){
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            return find(t->left, x);
        else if(x > t->data)
            return find(t->right, x);
        else
            return t;
    }

public:
    BST(){
        root = NULL;
    }

    ~BST(){
        root = makeEmpty(root);
    }

    void insert(int x){
        root = insert(x, root);
    }

    void remove(int x){
        root = remove(x, root);
    }

    void display(){
        inorder(root);
        cout << endl;
    }

    void search(int x){
        root = find(root, x);
    }
};


int main(){
    srand(5);

    BST t;

    for(int i = 0; i < 20; i++){
       t.insert(i);
    }
    cout << "Init BTS : \n";
    t.display();


    cout << "\n";
    cout << "Remove 10 from BTS : \n";
    t.remove(10);
    t.display();

    cout << "\n";
    cout << "Add 50 in BTS : \n";
    t.insert(50);
    t.display();

}

