// 
// Написать класс,  работающий как контейнер на базе бинарного дерева
// Организовать обход дерева в глубину с выводом элементов в порядке сортировки
// Простое бинарное дерево, без крассно-черных и без 234 балансировок
// Добавить git ignore для проекта вижуал студии
// Отправить ссылку на git-репозиторий
//
#include <iostream>
#include <memory>
#include <cstdlib>
#include <ctime>

template<typename T>
class Node {
public:
  T data;
  std::unique_ptr<Node> left;
  std::unique_ptr<Node> right;

  Node(T data) : data(data), left(nullptr), right(nullptr) {}

  void print_node() {
    std::cout << data << " ";
  }
};

template <typename T>
class Tree {
  std::unique_ptr<Node<T>> tree_root;

public:
  Tree() : tree_root(nullptr) {}

  void add_item(T item) {
    add_item(item, tree_root);
  }

  void add_item(T item, std::unique_ptr<Node<T>>& nd) {
    if (!nd) {
      nd = std::make_unique<Node<T>>(item);
      return;
    }
    if (nd->data > item) {
      add_item(item, nd->left);
    }
    else if (nd->data < item) {
      add_item(item, nd->right);
    }
  }

  void print_tree() {
    if (!tree_root) {
      std::cout << "Tree is empty!" << std::endl;
      return;
    }
    print_tree(tree_root.get());
  }

  void print_tree(Node<T>* nd) {
    if (nd->left) {
      print_tree(nd->left.get());
    }
    nd->print_node();
    if (nd->right) {
      print_tree(nd->right.get());
    }
  }
};

template <typename T>
class TreeContainer {
  std::unique_ptr<Tree<T>> tree;

public:
  TreeContainer() : tree(nullptr) {}

  void add_item(T item) {
    if (!tree) {
      tree = std::make_unique<Tree<T>>();
    }
    tree->add_item(item);
  }

  void print_tree() {
    if (!tree) {
      std::cout << "Tree is empty!" << std::endl;
      return;
    }
    tree->print_tree();
  }
};

int main() {
  srand(static_cast<unsigned>(time(nullptr)));
  TreeContainer<int> tc;
  for (int i = 0; i < 20; ++i) {
    tc.add_item(rand() % 100);
  }

  tc.print_tree();
  return 0;
}
