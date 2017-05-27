#include<iostream>

// types and type alias can be members of a class
//
//
// a member class can refer to types and static member of its enclosing class
// a member class can access non-static member of object of class
//     ||
// a nested class can access members of its enclosing-classes, even private
// members, but has no notion about the object of enclosing class
//
// a nested class does not have any special access to members of its nested classes

template<typename T>
class Tree {
    using value_type = T;
    enum class Policy {rb, splay, treeps};
    class Node {
        value_type value;
        Node* left;
        Node* right;
        public:
        void f(Tree*);
    };
    Node* top;
    public:
    void g(const T&);
};

template<typename T>
void Tree::Node::f(Tree* t) {
    // top = right; error, no object of type Tree specified
    p->top = right;
    value_type v = left->value;
}

template<typename T>
void Tree::g(Tree::Node* p) {
    // value_type val = right->value;  // error
    // value_type v = p->right->value; // error
    p->f(this);
}

int main() {
    return 0;
}
