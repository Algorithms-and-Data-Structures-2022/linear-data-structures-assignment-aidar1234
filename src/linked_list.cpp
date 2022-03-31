#include "assignment/linked_list.hpp"

namespace assignment {

  LinkedList::~LinkedList() {

    LinkedList::Clear();
  }

  void LinkedList::Add(int value) {
    Node* node = new Node(value);
    size_++;
    if (front_ == nullptr) {
      front_ = node;
    }
    else {
      back_->next = node;
    }
    back_ = node;
  }

  bool LinkedList::Insert(int index, int value) {
    if (index >= 0 && index <= size_) {
      Node* node = new Node(value);
      if (index == 0) {
        if (size_ != 0) {
          node->next = front_;
        }
        else {
          back_ = node;
        }
        front_ = node;
        size_++;
        return true;
      }

      if (index == size_) {
        back_->next = node;
        back_ = node;
        size_++;
        return true;
      }
      int cursor = 0;
      Node* p = front_;
      while (cursor != index - 1) {
        p = p->next;
        cursor++;
      }
      node->next = p->next;
      p->next = node;
      size_++;
      return true;
    }
    return false;
  }

  bool LinkedList::Set(int index, int new_value) {
    if (index >= 0 && index < size_) {
      int cursor = 0;
      Node* node = front_;
      while (cursor != index) {
        node = node->next;
        cursor++;
      }
      node->value = new_value;
      return true;
    }
    return false;
  }

  std::optional<int> LinkedList::Remove(int index) {
    if (index >= 0 && index < size_) {
      if (index == 0) {
        int val = front_->value;
        front_ = front_->next;
        size_--;
        return val;
      }
      int cursor = 0;
      Node* n = front_;
      while (cursor != index - 1) {
        n = n->next;
        cursor++;
      }
      if (index == size_ - 1) {
        int val = back_->value;
        n->next = nullptr;
        back_ = n;
        size_--;
        return val;
      }
      int val = n->next->value;
      n->next = n->next->next;
      size_--;
      return val;
    }
    return std::nullopt;
  }

  void LinkedList::Clear() {
    Node* node = front_;
    while (node != nullptr) {
      Node* p = node->next;
      delete node;
      node = p;
    }
    size_ = 0;
    front_ = back_ = nullptr;
  }

  std::optional<int> LinkedList::Get(int index) const {
    if (index >= 0 && index < size_) {
      int cursor = 0;
      Node* node = front_;
      while (cursor != index) {
        node = (*node).next;
        cursor++;
      }
      return (*node).value;
    }
    return std::nullopt;
  }

  std::optional<int> LinkedList::IndexOf(int value) const {
    int cursor = 0;
    Node* node = front_;
    while (cursor != size_) {
      if (node->value == value) {
        return cursor;
      }
      node = node->next;
      cursor++;
    }
    return std::nullopt;
  }

  bool LinkedList::Contains(int value) const {
    Node* node = front_;
    while (node != nullptr) {
      if (node->value == value) {
        return true;
      }
      node = node->next;
    }
    return false;
  }

  bool LinkedList::IsEmpty() const {
    return size_ == 0;
  }

  int LinkedList::size() const {
    return size_;
  }

  std::optional<int> LinkedList::front() const {
    if (size_ != 0) {
      return front_->value;
    }
    return std::nullopt;
  }

  std::optional<int> LinkedList::back() const {
    if (size_ != 0) {
      return back_->value;
    }
    return std::nullopt;
  }

  Node* LinkedList::FindNode(int index) const {
    if (index >= 0 && index < size_) {
      int cursor = 0;
      Node* node = front_;
      while (cursor != index) {
        node = node->next;
        cursor++;
      }
      return node;
    }
    return nullptr;
  }

  // ДЛЯ ТЕСТИРОВАНИЯ
  LinkedList::LinkedList(const std::vector<int>& values) {

    if (values.empty()) {
      return;
    }

    auto* curr_node = new Node(values.front());
    front_ = curr_node;

    for (int index = 1; index < values.size() - 1; ++index) {
      curr_node->next = new Node(values[index]);
      curr_node = curr_node->next;
    }

    if (values.size() == 1) {
      back_ = front_;
    } else {
      curr_node->next = new Node(values.back());
      back_ = curr_node->next;
    }

    size_ = static_cast<int>(values.size());
  }

  std::vector<int> LinkedList::toVector() const {

    if (front_ == nullptr || size_ == 0) {
      return {};
    }

    std::vector<int> array;
    array.reserve(size_);

    for (auto* node = front_; node != nullptr; node = node->next) {
      array.push_back(node->value);
    }

    return array;
  }

}  // namespace assignment