#include<iostream>

using namespace std;

// if declared for a class X, destructor will be invoked implicitly when
// object goes out of scope or is deleted.
//
// if we want to delete the object explicitly, declaring its destructor
// =delete or making it private.
//

class NoLocal {
    public:
        void destroy() { this->~NoLocal(); };
    private:
        ~NoLocal();    // don't destroy implicitly
};

NoLocal::~NoLocal() {
    cout << "Destructor is invoked explicitly" << endl;
}

int main() {
    // NoLocal nl;         // error, cannot destroy nl
    NoLocal* p = new NoLocal; // ok

    // delete p;           // error, cannot be deleted
    p->destroy();

    return 0;
}
