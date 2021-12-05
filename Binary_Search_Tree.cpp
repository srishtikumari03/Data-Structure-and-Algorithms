#include<bits/stdc++.h>
using namespace std;

struct node{
    int key;
    node* left;
    node* right;
    node* parent;
};

class bst{
    public:
    node* Tree;
    bst() {
        Tree = nullptr;
    }

    void insert(int key) {
        node* new_node = (node*)malloc(sizeof(node));
        new_node->key = key;
        new_node->left = nullptr;
        new_node->right = nullptr;

        if (Tree == nullptr) {
            new_node->parent = nullptr;
            Tree = new_node;
        }

        else {
            node* curr = Tree;
            node* parent = Tree;
            while (curr != nullptr) {
                parent = curr;
                if (curr->key > key) {
                    curr = curr->left;
                }

                else {
                    curr = curr->right;
                }
            }

            new_node->parent = parent;
            if (parent->key > key) {
                parent->left = new_node;
            }

            else {
                parent->right = new_node;
            }
        }

        return;
    }

    void delete_key(int key) {
        node* required = search_node(key);
        if (required->left == nullptr && required->right == nullptr) {
            if (required->parent == nullptr) {
                Tree = nullptr;
            }

            else if ((required->parent)->key > required->key) {
                (required->parent)->left = nullptr;
            }

            else {
                (required->parent)->right = nullptr;
            }
        } 

        else if (required->left == nullptr) {
            if ((required->parent)->key > required->key) {
                (required->parent)->left = required->right;
                (required->right)->parent = required->parent;
            }

            else {
                (required->parent)->right = required->right;
                (required->right)->parent = required->parent;
            }

            if (required->parent == nullptr) {
                Tree = required->right;
            }
        }

        else if (required->right == nullptr) {
            if ((required->parent)->key > required->key) {
                (required->parent)->left = required->left;
                (required->left)->parent = required->parent;
            }

            else {
                (required->parent)->right = required->left;
                (required->left)->parent = required->parent;
            }

            if (required->parent == nullptr) {
                Tree = required->left;
            }
        }

        else if((required->right)->left == nullptr) {
            (required->right)->left = required->left;
            if (required->left != nullptr) {
                (required->left)->parent = required->right;
            }

            (required->right)->parent = required->parent;
            if (required->parent != nullptr) {
                (required->parent)->right = required->right;
            }

            else {
                Tree = required->left;
            }
        }

        else {
            node* mini = minimum_node(required->right);
            (mini->parent)->left = mini->right;
            if (mini->right != nullptr) {
                (mini->right)->parent = mini->parent;
            }

            mini->left = required->left;
            if (required->left != nullptr) {
                (required->left)->parent = mini;
            }

            mini->right = required->right;
            if (required->right != nullptr) {
                (required->right)->parent = mini;
            }

            mini->parent = required->parent;

            if (mini->parent == nullptr) {
                Tree = mini;
            }
        }

        return;
    }

    node* minimum_node(node* tree) {
        while (tree->left != nullptr) {
            tree  = tree->left;
        }

        return tree;
    }

    node* search_node(int key) {
        node* curr = Tree;

        while (curr != nullptr) {
            if (curr->key == key) {
                return curr;
            }

            else if (curr->key > key) {
                curr = curr->left;
            }

            else {
                curr = curr->right;
            }
        }

        return nullptr;
    }

    int successor(int key) {
        node* required = search_node(key);
        if (required != nullptr) {
            if (required->right != nullptr) {
                return minimun(required->right);
            }

            else {
                node* y = required->parent;
                while (y != nullptr && y->right == required) {
                    required = y;
                    y = y->parent;
                }

                if (y == nullptr) {
                    return -1;
                }
                else {
                    return y->key;
                }
            }
        }

        return -1;
    }

    void search(int key) {
        int ans = 0;
        node* curr = Tree;
        while(curr != nullptr) {
            if (curr->key > key) {
                curr = curr->left;
            }

            else if (curr->key < key) {
                curr = curr->right;
            }

            else if (curr->key == key) {
                ans = 1;
                cout << "key found!!\n";
                break;
            }
        }

        if (ans == 0) {
            cout << "key not found!!\n";
        }

        return;
    }

    int maximum(node* Tree) {
        node* curr = Tree;
        while (curr->right != nullptr) {
            curr = curr->right;
        }

        return curr->key;
    }

    int minimun(node* Tree) {
        node* curr = Tree;
        while (curr->left != nullptr) {
            curr = curr->left;
        }

        return curr->key;
    }

    void inorder(node* Tree) {
        if (Tree->left == nullptr && Tree->right == nullptr) {
            cout << Tree->key << "\n";
            return;
        }

        if (Tree->left != nullptr) {
            inorder(Tree->left);
        }
        cout << Tree->key << "\n";
        if (Tree->right != nullptr) {
            inorder(Tree->right);
        }

        return;
    }
};

int main() {
    bst tree = bst();
    tree.insert(10);
    tree.insert(12);
    tree.insert(9);
    tree.insert(8);
    tree.insert(7);
    tree.insert(13);
    tree.insert(11);
    tree.insert(14);
    tree.inorder(tree.Tree);

    // tree.search(9);
    // tree.search(16);
    // cout << tree.minimun(tree.Tree) << "\n";
    // cout << tree.maximum(tree.Tree) << "\n";

    // cout << "-----\n";
    // cout << tree.successor(13) << "\n";
    // cout << tree.successor(11) << "\n";
    // cout << tree.successor(7) << "\n";
    // cout << tree.successor(35) << "\n";
    // cout << tree.successor(10) << "\n";

    // cout << "-----\n";
    // tree.delete_key(14);
    // tree.inorder(tree.Tree);

    // cout << "-----\n";
    // tree.delete_key(8);
    // tree.inorder(tree.Tree);

    cout << "-----\n";
    tree.delete_key(14);
    tree.inorder(tree.Tree);
    
    return 0;
}