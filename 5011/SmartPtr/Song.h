// REF: C++ 11(and beyond): Smart Pointers.pdf

// Purpose: Encapsulate pointer

#include <iostream>
using namespace std;

class Song {
public:
    Song();
    Song(string, string, int);

    string getTitle();
    string getArtist();
    int getDuration();

private:
    string title;
    string artist;
    int duration;
};

Song::Song() {
    // Description: Constructor (no argument)

    this->title = "TBD";
    this->artist = "TBD";
    this->duration = 0;
}

Song::Song(string title, string artist, int duration) {
    // Description: Constructor (with arguments)

    this->title = title;
    this->artist = artist;
    this->duration = duration;
}

string Song::getTitle() {
    return this->title;
}

string Song::getArtist() {
    return this->artist;
}

int Song::getDuration() {
    return this->duration;
}
