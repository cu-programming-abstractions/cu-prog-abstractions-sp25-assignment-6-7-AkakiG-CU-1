#include "list.h"
#include "list_utils.h"
#include <iostream>
#include <cassert>
#include <stdexcept>

using namespace std;

// Helper function to print test results
void printTestResult(const string& name, bool success) {
    cout << (success ? "✓ " : "✗ ") << name << endl;
}

void testBasicOperations() {
    cout << "\n=== Testing Basic Operations ===" << endl;

    LinkedList lst;
    bool result = true;

    // Test empty list
    result &= lst.isEmpty();
    printTestResult("Empty list is empty", result);

    // Test prepend
    lst.prepend(1);
    result = !lst.isEmpty();
    printTestResult("List not empty after prepend", result);

    // Test append
    lst.append(2);
    lst.append(3);
    cout << "List after append: ";
    lst.print(cout);
    cout << endl;

    // Test removeFront
    int value = lst.removeFront();
    result = (value == 1);
    printTestResult("removeFront returns correct value", result);
}

void testCopyOperations() {
    cout << "\n=== Testing Copy Operations ===" << endl;
    bool success = true;

    // Create original list
    LinkedList source;
    source.append(1);
    source.append(2);
    source.append(3);

    // Test copy constructor
    LinkedList first(source);
    success = (length(first) == length(source));
    printTestResult("Copy constructor creates correct length", success);

    // Test assignment operator
    LinkedList second;
    second = source;
    success = (length(second) == length(source));
    printTestResult("Assignment operator creates correct length", success);

    // Test deep copy
    source.append(4);
    success = (length(first) == 3 && length(second) == 3);
    printTestResult("Copies are independent", success);
}

void testUtilityFunctions() {
    cout << "\n=== Testing Utility Functions ===" << endl;
    bool success = true;

    LinkedList lst;
    lst.append(1);
    lst.append(2);
    lst.append(3);

    // Test length
    success = (length(lst) == 3);
    printTestResult("length returns correct value", success);

    // Test sum
    success = (sum(lst) == 6);
    printTestResult("sum returns correct value", success);

    // Test contains
    success = contains(lst, 2) && !contains(lst, 4);
    printTestResult("contains works correctly", success);

    // Test reverse
    reverse(lst);
    success = (lst.removeFront() == 3);
    printTestResult("reverse works correctly", success);

    // Test nthFromEnd
    lst.append(4);
    lst.append(5);
    success = (nthFromEnd(lst, 0) == 5 && nthFromEnd(lst, 2) == 2);
    printTestResult("nthFromEnd works correctly", success);
}

void testEdgeCases() {
    cout << "\n=== Testing Edge Cases ===" << endl;
    bool result = true;

    // Test empty list operations
    LinkedList emptyList;
    try {
        emptyList.removeFront();
        result = false;
    } catch (const runtime_error&) {
        result = true;
    }
    printTestResult("removeFront throws on empty list", result);

    // Test nthFromEnd with invalid index
    try {
        nthFromEnd(emptyList, 0);
        result = false;
    } catch (const runtime_error&) {
        result = true;
    }
    printTestResult("nthFromEnd throws on invalid index", result);

    // Test self-assignment
    LinkedList lst;
    lst.append(1);
    lst = lst;
    result = (length(lst) == 1);
    printTestResult("Self-assignment works correctly", result);
}

void testMemoryManagement() {
    cout << "\n=== Testing Memory Management ===" << endl;
    bool success = true;

    LinkedList lst;
    for (int idx = 0; idx < 1000; idx++) {
        lst.append(idx);
    }
    success = (length(lst) == 1000);
    printTestResult("Large list creation works", success);
}

int main() {
    cout << "Starting Linked List Tests\n" << endl;

    try {
        testBasicOperations();
        testCopyOperations();
        testUtilityFunctions();
        testEdgeCases();
        testMemoryManagement();

        cout << "\nAll tests completed!" << endl;
    } catch (const exception& e) {
        cout << "\nTest failed with exception: " << e.what() << endl;
        return 1;
    }

    return 0;
}