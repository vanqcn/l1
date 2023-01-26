// REF: C++ 11(and beyond): Smart Pointers.pdf

// Purpose: Encapsulate pointer
// Process: Exit scope; call destructor for sp; deallocate heap object
// Output:  No memory leak if missing delete call;
//          exception thrown before delete statement

#include "SmartPtr.h"
#include "Song.h"
#include <iostream>
#include <memory>           // For unique_ptr
using namespace std;

void usePointerRaw();
void usePointerSmart();

int main () {
    Song* ptr = new Song();         // Heap object
    SmartPtr sp(ptr);               // Wrap object
    // ptr null after wrapped in smart pointer

    cout << sp->getTitle() << endl;
    cout << sp->getArtist() << endl;
    cout << sp->getDuration() << endl;

    usePointerSmart();
}

void usePointerRaw() {
    // Description: Use raw pointer (not recommended)

    Song* ptrSong = new Song("Nothing on You", "Bruno Mars", 316);

    delete ptrSong;         // Explicit delete
}

void usePointerSmart() {
    // Description: Use smart pointer (recommended)

    unique_ptr<Song> song2(new Song("Nothing on You", "Bruno Mars", 316));

    cout << song2->getTitle() << endl;
    cout << song2->getArtist() << endl;
    cout << song2->getDuration() << endl;

    // song2 deleted automatically when unique_ptr goes out of scope as
    // delete is defined within unique_ptr
}
