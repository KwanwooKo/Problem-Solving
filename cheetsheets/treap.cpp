#include <iostream>
#include <algorithm>
#include <cstdlib>
#define endl '\n'
using namespace std;
typedef int KeyType;
struct Node {
    KeyType key;
    int priority, size;
    Node *left, *right;
    Node(const KeyType _key) : key(_key), priority(rand()), size(1), left(NULL), right(NULL) {}
    void setLeft(Node* newLeft) {
        left = newLeft;
        calcSize();
    }
    void setRight(Node* newRight) {
        right = newRight;
        calcSize();
    }
    void calcSize() {
        size = 1;
        if (left) size += left->size;
        if (right) size += right->size;
    }
};

typedef pair<Node*, Node*> NodePair;

class Treap {
    public:
        NodePair split(Node* root, KeyType key) {
            if (root == NULL) return NodePair(NULL, NULL);
            // 오른쪽 쪼개기
            if (root->key < key) {
                NodePair rs = split(root->right, key);
                root->setRight(rs.first);
                return NodePair(root, rs.second);
            }
            // 왼쪽 쪼개기
            NodePair ls = split(root->left, key);
            root->setLeft(ls.second);
            return NodePair(ls.first, root);
        }
        Node* insert(Node* root, Node* node) {
            if (root == NULL) return NULL;
            // root 가 node로 변경
            if (root->priority < node->priority) {
                NodePair splitted = split(root, node->key);
                node->setLeft(splitted.first);
                node->setRight(splitted.second);
                return node;
            }
            else if (node->key < root->key) {
                root->setLeft(insert(root->left, node));
            }
            else {
                root->setRight(insert(root->right, node));
            }
            return root;
        }
        Node* merge(Node* a, Node* b) {
            if (a == NULL) return b;
            if (b == NULL) return a;
            // b가 root가 돼야하는 경우
            if (a->priority < b->priority) {
                b->setLeft(merge(a, b->left));
                return b;
            }
            a->setRight(merge(a->right, b));
            return a;
        }
        Node* erase(Node* root, KeyType key) {
            if (root == NULL) return NULL;
            // root 를 지우고 left, right 서브트리를 합친 뒤 반환
            if (root->key == key) {
                Node* ret = merge(root->left, root->right);
                delete root;
                return ret;
            }
            if (key < root->key) {
                root->setLeft(erase(root->left, key));
            } 
            else {
                root->setRight(erase(root->right, key));
            }
            return root;
        }
        Node* find_kth_node(Node* root, int k) {
            // 왼쪽 서브트리의 크기를 우선 계산
            // 1. k <= l: k번째 노드는 왼쪽 서브트리에 존재
            // 2. k == l + 1: k번째 노드가 root
            // 3. k > l+1: k번째 노드는 오른쪽 서브트리에 존재
            int leftSize = 0;
            if (root->left != NULL) leftSize = root->left->size;
            if (k <= leftSize) {
                return find_kth_node(root->left, k);
            }
            else if (k == leftSize) {
                return root;
            }
            else {
                // 왼쪽 서브트리 + root 의 사이즈 만큼은 빼서 넘겨줘야 해
                return find_kth_node(root->right, k - leftSize - 1);
            }
        }
        int countLessThan(Node* root, KeyType key) {
            if (root == NULL) return 0;
            if (root->key >= key) {
                return countLessThan(root->left, key);
            }
            int ls = (root->left ? root->left->size : 0);
            return ls + 1 + countLessThan(root->right, key);
        }
};
