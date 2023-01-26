// REF: Copying - a design decision.pdf

// Purpose: Class with proper memory management

#include <algorithm>            // For swap

class NoLeak {
public:
    NoLeak(unsigned s = 100) {              // Constructor
        size = s;
        heapData = new int[size];
    }

    NoLeak(const NoLeak& other);            // Copy constructor
    NoLeak& operator=(const NoLeak& other); // Overloaded assignment operator
    ~NoLeak() {                             // Destructor deallocates heapData
        delete[] heapData;
    }

    NoLeak(NoLeak&& other);                 // Move constructor
    NoLeak& operator=(NoLeak&& other);      // Overloaded move assignment operator
private:
    int* heapData;
    int size;

    void copy(const NoLeak& other);
};

NoLeak::NoLeak(const NoLeak& other) {
    // Description: Copy constructor supports call by value

    copy(other);
}

NoLeak& NoLeak::operator=(const NoLeak& other) {
    // Description: Overloaded assignment operator supports deep copying

    if (this == &other) {           // Guard clause
        return *this;
    }

    delete[] heapData;
    copy(other);

    return *this;
}

void NoLeak::copy(const NoLeak& other) {
    // Description: Private helper function

    size = other.size;
    heapData = new int[size];
    
    for (int i = 0; i < size; i++) {
        heapData[i] = other.heapData[i];
    }
}

NoLeak::NoLeak(NoLeak&& other) {
    // Description: Move constructor supports efficient call by value;
    //              heap memory transferred; caller loses access to heap memory

    // Copy size and address to heap memory
    size = other.size;
    heapData = other.heapData;

    // Zero out caller's handle to heap memory
    other.size = 0;
    other.heapData = nullptr;
}

NoLeak& NoLeak::operator=(NoLeak&& other) {
    // Description: Move assignment operator exchanges ownership;
    //              reference returned to support chained assignment

    std::swap(size, other.size);

    // LHS swaps ownership with RHS; no need for distinct copy if RHS goes out of scope
    std::swap(heapData, other.heapData);

    return *this;
}
