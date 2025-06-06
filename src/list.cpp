#include "list.h"
#include <stdexcept>

LinkedList::LinkedList() = default;

LinkedList::LinkedList(const LinkedList& source) {
    head = deepCopy(source.head);
}

LinkedList& LinkedList::operator=(LinkedList other) {
    std::swap(head, other.head);
    return *this;
}

LinkedList::~LinkedList() { freeChain(head); }

void LinkedList::prepend(int val) {
    head = new Node{val, head};
}

void LinkedList::append(int val) {
    Node* node = new Node{val, nullptr};

    if (isEmpty()) {
        head = node;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = node;
    }
}

int LinkedList::removeFront() {
    if (isEmpty()) throw runtime_error("removeFront on empty list");

    Node* temp = head;
    int result = temp->data;
    head = head->next;
    delete temp;
    return result;
}

bool LinkedList::isEmpty() const { return head == nullptr; }

void LinkedList::print(ostream& out) const {
    out << '[';
    for (Node* current = head; current; current = current->next) {
        out << current->data;
        if (current->next) out << " → ";
    }
    out << ']';
}

LinkedList::Node* LinkedList::deepCopy(Node* source) {
    if (source == nullptr) return nullptr;

    Node* copy = new Node{source->data, nullptr};
    copy->next = deepCopy(source->next);
    return copy;
}
void LinkedList::freeChain(Node* node) {
    while (node) {
        Node* nextNode = node->next;
        delete node;
        node = nextNode;
    }
}