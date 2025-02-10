#include "seuraaja.h"
#include "notifikaattori.h"

int main()
{
    Notifikaattori notif;

    Seuraaja a("A");
    Seuraaja b("B");
    Seuraaja c("C");

    notif.lisaa(&a);
    notif.lisaa(&b);
    notif.lisaa(&c);
    notif.tulosta();

    notif.postita("Tama on viesti 1");

    notif.poista(&b);

    notif.postita("Tama on viesti 2");

    return 0;
}
