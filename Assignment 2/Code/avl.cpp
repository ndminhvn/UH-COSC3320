#include <iostream>
#include <stdlib.h> 
#include <stdio.h>
#include <ctime>
#include <time.h>
#include <math.h>

using namespace std;

struct node { 
	int data;  	 	
	int* matrix;
	node* left;  	 	
	node* right; 
	int height;
};

class BST { 
    private:
        int size_0 = pow(2, 20);  	
        int size_1 = pow(2, 19) + pow(2, 18);  	
        int size_2 = pow(2, 18) + pow(2, 17); 
        int node_count=0;  	
        int insert_count = 0;  	
        int delete_count = 0; 
 
 	node* root; 
 
 	node* insert(int x, node* t) { 
 	 	int remainder = x % 3; 
 	 	if (t == NULL) { 
            t = new node;  	 	 	
            t->data = x;  	 	 	
            t->height = 0; 
 	 	 	t->left = t->right = NULL;

 	 	 	if (remainder == 0) { 
 	 	 	 	t->matrix = new int[size_0]; 
 	 	 	} 
 	 	 	else if (remainder == 1) { 
 	 	 	 	t->matrix = new int[size_1]; 
 	 	 	} 
 	 	 	else if (remainder == 2) { 
 	 	 	 	t->matrix = new int[size_2]; 
 	 	 	} 
 	 	} 
 	 	else if (x < t->data) { 
 	 	 	t->left = insert(x, t->left);  	 	 	
            if (height(t->left) - height(t->right) == 2) { 
 	 	 	 	if (x < t->left->data) 
	 	 	 	    t = singleRightRotate(t); 
	 	 	    else 
	 	 	 	 	t = doubleRightRotate(t);
	 	 	} 
	 	} 
	 	else if (x > t->data) { 
 	 	 	t->right = insert(x, t->right); 
 	 	 	if (height(t->right) - height(t->left) == 2) { 
 	 	 	 	if (x > t->right->data) 
 	 	 	 	 	t = singleLeftRotate(t); 
 	 	 	 	else 
 	 	 	 	 	t = doubleLeftRotate(t); 
 	 	 	} 
 	 	} 
		
		insert_count++;  	 	 	
        node_count++;  	 	 	
 
 	 	t->height = max(height(t->left), height(t->right)) + 1;

 	 	return t; 
 	} 
 
 	node* singleRightRotate(node* &t) { 
 	 	if (t == NULL || t->left == NULL) { 
 	 	 	return t;
 	 	} 
 	 	else { 
            node* u = t->left;    
            t->left = u->right; 
 	 	 	u->right = t; 
 	 	 	t->height = max(height(t->left), height(t->right)) + 1;  	 	 	
            u->height = max(height(u->left), height(t)) + 1; 
 	 	 	return u;
 	 	} 
 	 	return t;
 	} 
 
 	node* singleLeftRotate(node* &t) { 
 	 	if (t == NULL || t->right == NULL) { 
 	 	 	return t; 
 	 	} 
 	 	else { 
            node* u = t->right;   
			t->right = u->left; 
	 	 	u->left = t; 
	 	 	t->height = max(height(t->left), height(t->right)) + 1; 
	 	 	u->height = max(height(t->right), height(t)) + 1; 
	 	 	return u; 
	 	} 
	 	return t; 
    } 
    
    node* doubleLeftRotate(node* &t) { 
 	 	t->right = singleRightRotate(t->right); 
 	 	return singleLeftRotate(t); 
 	} 
 
 	node* doubleRightRotate(node* &t) { 
 	 	t->left = singleLeftRotate(t->left); 
 	 	return singleRightRotate(t); 
 	} 
 
 	node* findMin(node* t) { 
        if (t == NULL)    
            return NULL; 
        else if (t->left == NULL) 
 	 	 	return t;
        else 
 	 	 	return findMin(t->left); 
 	} 
 
 	node* findMax(node* t) { 
 	 	if (t == NULL) 
 	 	 	return NULL; 
 	 	else if (t->right == NULL) 
 	 	 	return t; 
 	 	else 
 	 	 	return findMax(t->right); 
 	} 
 
 	node* remove(int x, node* t) { 
 	 	node* temp; 
 
        // Element not found   
        if (t == NULL) 
 	 	 	return NULL; 
 
 	 	// Searching for element  	 	
        else if (x < t->data)  	 	 	
            t->left = remove(x, t->left);

        else if (x > t->data) 
 	 	 	t->right = remove(x, t->right); 
 
 	 	// Element found  	 	
		// With 2 children  	 	
        else if (t->left != NULL && t->right != NULL) { 
 	 	    temp = findMin(t->right);  	 	
            t->data = temp->data; 
	 	 	t->right = remove(t->data, t->right); 
	 	} 
	 	// With one or zero child 
	 	else { 
	 	 	temp = t; 
            if (t->left == NULL) 
	 	 	    t = t->right; 
	 	    else if (t->right == NULL) 
	 	 	 	t = t->left; 
            delete[] temp->matrix;   
            delete temp; 
 	 	}
		
		delete_count++; 
		node_count--; 

 	 	// if (t == NULL) 
 	 	//  	return t; 
 
 	 	t->height = max(height(t->left), height(t->right)) + 1; 
 
 	 	// If node is unbalanced 
        // If left node is deleted, right case   
        if (height(t->left) - height(t->right) == 2) { 
 	 	 	// right right case 
 	 	 	if (height(t->left->left) - height(t->left->right) == 1)  	 	 	 	
                return singleLeftRotate(t); 
 	 	 	// right left case 
 	 	 	else 
 	 	 	 	return doubleLeftRotate(t); 
 	 	} 

 	 	// If right node is deleted, left case 
 	 	else if (height(t->right) - height(t->left) == 2) { 
 	 	 	// left left case 
 	 	 	if (height(t->right->right) - height(t->right->left) == 1)  	 	 	 	
                return singleRightRotate(t); 
 	 	 	// left right case 
 	 	 	else 
 	 	 	 	return doubleRightRotate(t); 
 	 	} 
 	 	return t; 
 	} 
 
 	int height(node* t) { 
 	 	return (t == NULL ? -1 : t->height); 
 	} 

  	int getBalance(node* t) { 
 	 	if (t == NULL) 
 	 	 	return 0; 
 	 	else 
 	 	 	return height(t->left) - height(t->right); 
    } 
    void inOrder(node* t) { 
 	    if (t == NULL)  	 	
            return; 
 	    inOrder(t->left);  	
        cout << t->data << " ";  	
        inOrder(t->right); 
    } 
    public: 
        BST() { 
            root = NULL;
		 	node_count = 0;
			insert_count = 0;
        } 
    
        void insert(int x) { 
            root = insert(x, root); 
        } 
    
        void remove(int x) { 
            root = remove(x, root); 
        } 
    
        void display() { 
            inOrder(root);  	 	
            cout << endl; 
        } 

        int getNodeCount() { 
            return node_count; 
        } 

        int getInsertCount() { 
            return insert_count; 
        } 
        
        int getDeleteCount() { 
            return delete_count; 
        } 

        void resetCount() { 
            insert_count = 0; 
        } 
}; 
 
int main(int argc, char* argv[]) {
	srand((unsigned int)time(0));  	
	clock_t initial_insertion;  	
	clock_t timer;
	double insertion = 0.0;  	
	double deletion = 0.0;  	
	double time;  	
	int *num_array = new int[100000]; 
	int counter = 0; 

	for (int i = 0; i < 100000; i++) { 
	 	num_array[i] = rand() % 299 + 1; 
	} 

	BST* node = new BST();

	int j = 0;
	initial_insertion = clock(); 
	while (node->getNodeCount() < 50) { 
	 	node->insert(num_array[j]); 
		j++;
	}
	initial_insertion = clock() - initial_insertion;
	cout << "Initial insertion time: " << (double)initial_insertion / CLOCKS_PER_SEC * 1000 << " miliseconds " << endl;
	 
	BST* node2 = new BST();
	
	int k = 0;
	for (int i = 0; i < 100000; i++) { 
 	 	while (node2->getNodeCount() < 50) { 
			timer = clock();
 	 	 	node2->insert(num_array[k]); 
			timer = clock() - timer; 	
			k++;
			time = (double)timer / CLOCKS_PER_SEC;
			insertion += time;
 	 	} 
 	 	while (node2->getNodeCount()>= 50) { 
			timer = clock();
			node2->remove(num_array[k]);  	 	 	
			timer = clock() - timer; 
			k--;
 	 		time = (double)timer / CLOCKS_PER_SEC;
 	 		deletion += time;
 	 	} 
 	}
	cout << "Insertion time: " << insertion * 1000 << " miliseconds " << endl;
	cout << "Deletion time: " << deletion * 1000 << " miliseconds " << endl;
	return 0;
}
