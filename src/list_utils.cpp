#include "list_utils.h"
#include "list.h"

int length(const LinkedList& list) {
    int size = 0;
    LinkedList::Node* node = list.getHead();
    while (node != nullptr) {
        size++;
        node = node->next;
    }
    return size;
}

int sum(const LinkedList& list) {
    int result = 0;
    LinkedList::Node* node = list.getHead();
    while (node != nullptr) {
        result += node->data;
        node = node->next;
    }
    return result;
}

bool contains(const LinkedList& list, int value) {
    LinkedList::Node* node = list.getHead();
    while (node != nullptr) {
        if (node->data == value) {
            return true;
        }
        node = node->next;
    }
    return false;
}

void reverse(LinkedList& list) {
    LinkedList::Node* previous = nullptr;
    LinkedList::Node* curr = list.getHead();
    LinkedList::Node* nextNode = nullptr;

    while (curr != nullptr) {
        nextNode = curr->next;
        curr->next = previous;
        previous = curr;
        curr = nextNode;
    }

    list.setHead(previous);
}

int nthFromEnd(const LinkedList& list, int n) {
    if (n < 0) {
        throw runtime_error("Invalid position");
    }

    LinkedList::Node* ahead = list.getHead();
    LinkedList::Node* behind = list.getHead();

    for (int i = 0; i < n; ++i) {
        if (ahead == nullptr) {
            throw runtime_error("Invalid position");
        }
        ahead = ahead->next;
    }

    if (ahead == nullptr) {
        throw runtime_error("Invalid position");
    }

    while (ahead->next != nullptr) {
        ahead = ahead->next;
        behind = behind->next;
    }

    return behind->data;
}