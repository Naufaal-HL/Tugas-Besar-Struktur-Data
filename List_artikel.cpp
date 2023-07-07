#include "List_artikel.h"

void createListArtikel(List_artikel &L){
    first(L) = NULL;
    last(L) = NULL;
}

void insertFirst(List_artikel &L, address_artikel P){
    if (first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertAfter(List_artikel &L, address_artikel Prec, address_artikel P){
    if (first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        if (Prec == last(L)) {
            insertLast(L, P);
        } else if (Prec != last(L)){
            prev(P) = Prec;
            next(P) = next(Prec);
            prev(next(Prec)) = P;
            next(Prec) = P;
        } else {
            cout << "Prec Tidak Ditemukan" << endl << endl;
        }
    }
}

void insertLast(List_artikel &L, address_artikel P){
    if (first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }
}

void deleteFirst(List_artikel &L, address_artikel &P){
    if (first(L) == NULL) {
        cout << "Isi List Artikel Kosong" << endl << endl;
    } else {
        if (first(L) == last(L)) {
            first(L) = NULL;
            last(L) = NULL;
        } else {
            P = first(L);
            first(L) = next(P);
            prev(first(L)) = NULL;
        }
    }
}

void deleteLast(List_artikel &L, address_artikel &P){
    if (first(L) == NULL) {
        cout << "Isi List Artikel Kosong" << endl << endl;
    } else {
        if (first(L) == last(L)) {
            first(L) = NULL;
            last(L) = NULL;
        } else {
            address_artikel M;
            P = last(L);
            M = prev(last(L));
            last(L) = M;
            next(M) = NULL;
            prev(P) = NULL;
        }
    }
}

void deleteAfter(List_artikel &L, address_artikel Prec, address_artikel &P){
    if (first(L) == NULL) {
        cout << "Isi List Artikel Kosong" << endl << endl;
    } else {
       if (first(L) == last(L)) {
            P = first(L);
            next(P) = first(L);
            prev(first(L)) = NULL;
        } else {
            if (Prec != NULL) {
                P = prev(Prec);
                next(P) = next(Prec);
                prev(next(Prec)) = P;
                prev(Prec) = NULL;
                next(Prec) = NULL;
            }   else {
            cout << "Prec Tidak Ditemukan" << endl << endl;
            }
        }
    }
}

//void dealokasiArtikel(address_artikel &P){
//    delete p;
//}

void printInfoArtikel(List_artikel L){
    if(first(L) == NULL) {
        cout << "List Artikel Kosong" << endl;
    } else {
        address_artikel O = first(L);
        int i = 0;
        while (O != NULL) {
            i++;
            cout << i << ". Artikel yang tersedia: " << info(O) << endl;
            O = next(O);
        }
    }
}

address_artikel alokasiArtikel(infotype_artikel x){
    address_artikel P;

    P = new elmList_artikel;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

address_artikel cariElmArtikel(List_artikel L, int x){
    address_artikel P = first(L);

    int i = 1;
    while (P != NULL) {
        if (i == x){
            return P;
        }
        i++;
        P = next(P);
    }
    return NULL;
}

address_artikel cariPrecArt(List_artikel L, address_artikel P){
    address_artikel R = first(L);

    while (R != NULL) {
        if(R == P){
            return R;
        }
        R = next(R);
    }
    return NULL;
}

address_artikel cariElmArtikelHuruf(List_artikel L, infotype_artikel x){
    address_artikel Q = first(L);

    while (Q != NULL) {
        if (info(Q) == x) {
            return Q;
        }
        Q = next(Q);
    }
    return NULL;
}
