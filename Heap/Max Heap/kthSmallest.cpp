//Using Max-Heap (priority queue)

#include<stdio.h>
using namespace std;

class Node{
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

