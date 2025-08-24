// 
// Написать класс,  работающий как контейнер на базе бинарного дерева
// Организовать обход дерева в глубину с выводом элементов в порядке сортировки
// Простое бинарное дерево, без крассно-черных и без 234 балансировок
// Добавить git ignore для проекта вижуал студии
// Отправить ссылку на git-репозиторий
//
#include <iostream>
#include <time.h>

template<typename T>
class Node {
public:
  T data;
  Node* left;
  Node* right;
public:
  Node() { 
  }
  Node(T data) {
    this->data = data;
    left  = nullptr;
    right = nullptr;
  }

  ~Node() {
    if (left) delete (left);
    if (right)  delete (right);
  }

  void print_node() {
    std::cout << data << " ";
  }
};//NODE

template <typename T>
class Tree {
  Node<T>* tree_root;

public:
  Tree() { }
  Tree(T data) {
    tree_root = new Node<T>(data);
  }

  void add_item(T item) {
    if (tree_root == nullptr) 
      tree_root = new Node<T>(item);       
    else 
      add_item2(item, tree_root);
  }

  void add_item2(T item, Node<T> * nd) {
    if (nd == nullptr) return;
    if (nd->data > item) {
      if (nd->left)
        add_item2(item, nd->left);
      else
        nd->left = new Node<T>(item);
    }
    else if (nd->data < item) {
      if (nd->right)
        add_item2(item, nd->right);
      else
        nd->right = new Node<T>(item);
    }
  };

  void print_tree() {
    print_tree(tree_root);
  }
  void print_tree(Node<T>* nd) {
    if (!nd) return;
    if (tree_root == nullptr) {
      std::cout << "Tree is empty!" << std::endl;
      return;
    }
    if (nd->left)
      print_tree(nd->left);

    nd->print_node();

    if (nd->right)
      print_tree(nd->right);

  }

  ~Tree() {
    if (tree_root) {
      delete tree_root;
    }
  }
};//TREE


template <typename T>
class TreeContainer {

  Tree<T>* tree;
public:
  TreeContainer() {
    tree = nullptr;
  }
  TreeContainer(T data) {
    tree = new Tree<T>(data);
  }

  ~TreeContainer() {
    if (tree) delete tree;
  }

  void add_item(T item) {
    if (tree == nullptr)
      tree = new Tree<T>(item);
    else
      tree->add_item(item);
  }

  void print_tree() {
    if (!tree)
      std::cout << "Tree is empty!" << std::endl;

    tree->print_tree();
  }

};

int main()
{
  srand((unsigned)time(NULL));
  TreeContainer<int> * tc = new TreeContainer<int>();
  for (int i = 0; i < 20; ++i) {
    tc->add_item(rand() % 100);
  }

  tc->print_tree();

  delete tc;
};