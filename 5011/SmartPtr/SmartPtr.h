// REF: C++ 11(and beyond): Smart Pointers.pdf

// Purpose: Encapsulate pointer

template<typename T>
class SmartPtr {
public:
    SmartPtr(T*& p): ptr(p) {           // Constructor; assume ownership
        p = nullptr;
    }
    
    /*
    SmartPtr(T*& p) {                   // Same as above, but this is     
        ptr = p;                        // less efficient
        p = nullptr;
    }
    */

    ~SmartPtr() {                       // Destructor; ensure deallocation
        delete ptr;
    }

    T*& operator->() {                  // Provide transparent access
        return ptr;
    }

    T& operator*() {                    // Provide transparent access
        return *ptr;
    }

private:
    T* ptr;
};
