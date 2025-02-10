#include "notifikaattori.h"

Notifikaattori::Notifikaattori() {
    cout << "Luodaan notifikaattori" << endl;
}

void Notifikaattori::lisaa(Seuraaja *fptr) {
    fptr->next = Notifikaattori::seuraajat;
    Notifikaattori::seuraajat = fptr;

    cout << "Notifikaattori lisaa seuraajan " << fptr->getNimi() << endl;
}

void Notifikaattori::poista(Seuraaja *dlt) {
    Seuraaja *ptr = Notifikaattori::seuraajat;
    while(ptr != nullptr)
    {
        if(ptr->next == dlt)
        {
            cout << "Notifikaattori poistaa seuraajan " << ptr->next->getNimi() << endl;
            ptr->next = ptr->next->next;
        }

        ptr = ptr->next;
    }
}

void Notifikaattori::tulosta() {
    Seuraaja *ptr = Notifikaattori::seuraajat;

    cout << "Notifikaattorin seuraajat:" << endl;

    while(ptr != nullptr) {
        cout << "Seuraaja " << ptr->getNimi() << endl;
        ptr = ptr->next;
    }
}

void Notifikaattori::postita(string msg) {
    cout << "Notifikaattori postaa viestin " << msg << endl;
    Seuraaja *ptr = Notifikaattori::seuraajat;

    while(ptr != nullptr) {
        ptr->paivitys(msg);
        ptr = ptr->next;
    }
}
