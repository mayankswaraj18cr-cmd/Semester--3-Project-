#include <iostream>
#include <string>

class TextEditor {
private:
    struct Node {
        char value;
        Node *previous;
        Node *next;
    };

    Node *head_ = nullptr;
    Node *tail_ = nullptr;

public:
    TextEditor() = default;
    TextEditor(const TextEditor &) = delete;
    TextEditor &operator=(const TextEditor &) = delete;

    ~TextEditor() {
        clear();
    }

    void append(char value) {
        Node *node = new Node{value, tail_, nullptr};
        if (tail_ == nullptr) {
            head_ = node;
        } else {
            tail_->next = node;
        }
        tail_ = node;
    }

    void clear() {
        while (head_ != nullptr) {
            Node *next = head_->next;
            delete head_;
            head_ = next;
        }
        tail_ = nullptr;
    }

    std::string text() const {
        std::string result;
        for (const Node *current = head_; current != nullptr; current = current->next) {
            result += current->value;
        }
        return result;
    }
};

int main() {
    TextEditor editor;
    for (char value : std::string{"HELLO"}) {
        editor.append(value);
    }

    std::cout << "C++ implementation: " << editor.text() << '\n';
}