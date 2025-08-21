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
    data  = nullptr;
    left  = nullptr;
    right = nullptr;
  }
  Node(T data) {
    this->data = data;
  }

  ~Node() {
    if (left) {
      std::cout << "Deleting node with value " << left->data << std::endl;
      delete (left);
    }
    //delete (data);
    if (right) {
      std::cout << "Deleting node with value " << right->data << std::endl;
      delete (right);
    }
  }

  void print_node() {
    std::cout << data << " ";
  }
};//NODE

template <typename T>
class Tree {
  Node<T> * tree_root = nullptr;

public:
  Tree() { tree_root = nullptr; }
  Tree(T data) {
    tree_root = new Node<T>(data);
  }

  void add_item(T item) {
    add_item(item, tree_root);
  }

  void add_item(T item, Node<T> * nd) {
    if (item == (T)nullptr) return;
    if (tree_root == nullptr) { tree_root = new Node<T>(item); return; }
    if (nd->data > item) {
      if (nd->left)
        add_item(item, nd->left);
      else
        nd->left = new Node<T>(item);
    }
    else if (nd->data < item) {
      if (nd->right)
        add_item(item, nd->right);
      else
        nd->right = new Node<T>(item);
    }
  };

  void print_tree() {
    print_tree(tree_root);
  }
  void print_tree(Node<T>* nd) {
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
    if(tree_root) delete tree_root;
  }
};//TREE


template <typename T>
class TreeContainer {
 
    Tree<T> * tree;
public:
    TreeContainer() {
      tree = nullptr;
    }
    TreeContainer(T data) {
      tree = new Tree<T>(data);
    }

    ~TreeContainer() {
      if(tree) delete tree;
    }

    void add_item(T item) {
      if(!tree)
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

  delete &tc;
};

