#include "main_menu.h"
#include "conio.h"

    List_artikel    LA;
    List_tag        LT;
    List_relasi     LR;

void dummy() {
    address_relasi  R;
    address_artikel P;
    address_tag     Q;

    P = alokasiArtikel("D1");
    insertLast(LA, P);

    P = alokasiArtikel("D2");
    insertLast(LA, P);

    P = alokasiArtikel("D3");
    insertLast(LA, P);
//
//    P = alokasiArtikel("D4");
//    insertLast(LA, P);
//
    Q = alokasiTag("M1");
    insertLast(LT, Q);

    Q = alokasiTag("M2");
    insertLast(LT, Q);
//
//    Q = alokasiTag("M3");
//    insertLast(LT, Q);
//
//    Q = alokasiTag("M4");
//    insertLast(LT, Q);
//
//    Q = alokasiTag("M5");
//    insertLast(LT, Q);
//
//    P = cariElmArtikel(LA, "D1");
//    Q = cariElmTag(LT, 1);
//    R = alokasiRelasi(P, Q);
//    insertLast(LR, R);
//
//    P = cariElmArtikel(LA, "D1");
//    Q = cariElmTag(LT, 2);
//    R = alokasiRelasi(P, Q);
//    insertLast(LR, R);
//
//    P = cariElmArtikel(LA, "D1");
//    Q = cariElmTag(LT, 3);
//    R = alokasiRelasi(P, Q);
//    insertLast(LR, R);
//
//    P = cariElmArtikel(LA, "D2");
//    Q = cariElmTag(LT, 2);
//    R = alokasiRelasi(P, Q);
//    insertLast(LR, R);
//
//    P = cariElmArtikel(LA, "D3");
//    Q = cariElmTag(LT, 4);
//    R = alokasiRelasi(P, Q);
//    insertLast(LR, R);
//
//    P = cariElmArtikel(LA, "D4");
//    Q = cariElmTag(LT, 5);
//    R = alokasiRelasi(P, Q);
//    insertLast(LR, R);
}

void menu(){
    createListArtikel(LA);
    createListTag(LT);
    createListRelasi(LR);

    dummy();

    int pilihan;
    cout << "Selamat Datang di Aplikasi Pencari Artikel Berbasis Tag" << endl << endl;

    do {
        cout << "=============================MENU UTAMA=============================" << endl << endl;
        cout << " 1. Tambah Artikel"<< endl;
        cout << " 2. Tambah Tag"<< endl;
        cout << " 3. Koneksikan Artikel dengan Tag"<< endl;
        cout << " 4. Hapus Artikel Tertentu"<<endl;
        cout << " 5. Hapus Tag Tertentu"<<endl;
        cout << " 6. Tampilkan Semua Artikel beserta Tag-nya"<<endl;
        cout << " 7. Tampilkan Tag Favorit/Yang Paling Banyak Digunakan"<<endl;
        cout << " 8. Tampilkan Artikel yang Memiliki Tag yang Sama"<<endl;
        cout << " 9. Tampilkan Artikel dengan Tag Tertentu"<<endl;
        cout << " 10. Tampilkan Jumlah Relasi/Koneksi"<<endl;
        cout << " 11. Tampilkan Semua Artikel Yang Ada"<<endl;
        cout << " 12. Tampilkan Semua Tag Yang Ada"<<endl;
        cout << " 0. EXIT"<<endl<<endl;
        cout << "Masukan pilihan: ";
        cin >> pilihan;
        cout << endl;

        switch(pilihan) {
            case 1 : insert_artikel();break;
            case 2 : insert_tag();break;
            case 3 : koneksikan();break;
            case 4 : hapus_artikel();break;
            case 5 : hapus_tag();break;
            case 6 : isi_artikel_Tag();break;
            case 7 : isi_tag_Favorit();break;
            case 8 : kesamaan_artikel_Tag();break;
//            case 9 : isi_artikel_Tag_pilihan();break;
            case 10: jumlahrelasi();break;
            case 11: tampilartikel();break;
            case 12: tampiltag();break;
            case 0 : break;
            default:cout<<"Salah input"<<endl<<endl;
            cout << endl;
            }
            cout << "\Tekan Enter Untuk Melanjutkan";getch();
            cout << endl;
    } while (pilihan != 0);
}
void insert_artikel() {
    address_artikel P;

    string artikel;
    bool cari;

    cout << "Masukan Nama Artikel: ";
    cin >> artikel;
    cari = cariElmArtikelHuruf(LA, artikel);
    if (!cari) {
        P = alokasiArtikel(artikel);
        insertLast(LA, P);
        cout << "Artikel anda telah ditambahkan" << endl;
        printInfoArtikel(LA);
        cout << endl << endl;
    } else {
        cout << "Artikel yang Anda Masukan Sudah Ada" << endl << endl;
    }
}

void insert_tag() {
    address_tag     Q;

    string tag;
    bool cari;

    cout << "Masukan Nama Tag: ";
    cin >> tag;
    cari = cariElmTagHuruf(LT, tag);
    if (!cari) {
        Q = alokasiTag(tag);
        insertLast(LT, Q);
        cout << "Tag anda telah ditambahkan" << endl;
        printInfoTag(LT);
        cout << endl << endl;
    } else {
        cout << "Tag yang Anda Masukan Sudah Ada" << endl << endl;
    }
}

void koneksikan() {
    address_relasi  R;
    address_artikel P;
    address_tag     Q;

    int angkatArt;
    int angkaTag;

    cout << "Daftar Artikel: " << endl;
    printInfoArtikel(LA);
    cout << endl;
    cout << "Masukan Nomor Artikel yang Ingin Anda Hubungkan Dengan Tag: ";
    cin >> angkatArt;
    cout << endl;

    cout << "Daftar Tag: " << endl;
    printInfoTag(LT);
    cout << endl;
    cout << "Masukan Nomor Tag yang Ingin Anda Hubungan dengan Artikel: ";
    cin >> angkaTag;
    cout << endl;

    P = cariElmArtikel(LA, angkatArt);
    Q = cariElmTag(LT, angkaTag);
    R = alokasiRelasi(P, Q);
    insertLast(LR, R);
    cout << "Relasi Anda Telah Ditambahkan" << endl;
    printInfoRelasi(LR);
    cout << endl;
}

void hapus_artikel() {
    int angkaArt;

    printInfoArtikel(LA);
    cout << endl;
    cout << "Masukan Nama Artikel yang Ingin Anda Hapus: ";
    cin >> angkaArt;

    address_artikel C;
    address_artikel P = cariElmArtikel(LA, angkaArt);

    if (first(LR) != NULL) {
        address_relasi Q = first(LR);
        while (Q != NULL) {
            if (P == parent(Q)) {
                address_relasi Y;
                if (Q == first(LR)) {
                    deleteFirst(LR, Y);
                } else if (Q == last(LR)) {
                    deleteLast(LR, Y);
                } else {
                    address_relasi Z = cariPrecRel(LR, Q);
                    deleteAfter(LR, prev(Z), Y);
                }
            }
            Q = next(Q);
        }
    }

    if (P == first(LA))
    {
        deleteFirst(LA, P);
    }
    else if (P==last(LA))
    {
        deleteLast(LA, P);
    }
    else
    {
        deleteAfter(LA, P, C);
    }
    printInfoArtikel(LA);
}

void hapus_tag() {
    //address_relasi  R;
    //address_artikel P;
    address_tag     Q;

    int angka;

    printInfoTag(LT);
    cout << endl;
    cout << "Masukan Nomor Tag yang Ingin Anda Hapus: ";
    cin >> angka;

    address_tag R = cariElmTag(LT, angka);
    if (R == first(LT))
    {
        deleteFirst(LT, R);
    }
    else if (R==last(LT))
    {
        deleteLast(LT, R);
    }
    else
    {
        deleteAfterTag(LT, R, Q);
    }
    printInfoTag(LT);

}

void isi_artikel_Tag() {

    cout << "Isi Artikel beserta Tag nya" << endl;
    printInfoRelasi(LR);
    cout << endl;
}

void isi_tag_Favorit() {
    address_relasi T = first(LR);

    if (T == NULL) {
        cout << "Belum ada tag terfavorit" << endl;
    } else {
        address_relasi E;
        string x;
        address_relasi fav;
        int run = 1;
        while (T != NULL)
        {
            int i = 1;
            E = next(T);
            x = info(child(T));
            while (E != NULL)
            {
                if (x == info(child(E)))
                {
                    i++;
                }
                E = next(E);
            }
            if (i > run)
            {
                fav = T;
            }
            run = i;
            T = next(T);

        }
        cout << "Tag terfavorit yaitu:";
        cout << info(child(fav)) << endl;
    }
}

void kesamaan_artikel_Tag() {
    cout << "Menampilkan artikel berdasarkan kesamaan tag: " << endl;
    List_relasi LR1;
    createListRelasi(LR1);
    address_relasi W = first(LR);
    address_relasi T, E;

    insertLast(LR1, W);
    E = next(W);
    while (E != NULL)
    {
        if (info(child(E)) == info(child(W)))
        {
            insertLast(LR1, E);
            T = E;
        }
        E = next(E);
    }
    W = next(W);
    while (W!=NULL)
    {
        if (info(child(W)) != info(child(T)))
        {
            insertLast(LR1, W);
            E = next(W);
            while (E != NULL)
            {
                if (info(child(E)) == info(child(W)))
                {
                    insertLast(LR1, E);
                    T = E;
                }
                E = next(E);
            }
        }
        W = next(W);
    }
    printInfoRelasi(LR1);
}

void isi_artikel_Tag_pilihan() {
//    printInfoTag(LT);
//    int pilih;
//    int i = 2;
//    cout << "Pilih tag yang akan digunakan untuk mencari semua artikel terkait:";
//    cin >> pilih;
//    cout << endl;
//
//    address_relasi W = cariElmRelasi(LR, pilih);
//    cout << "Artikel yang memiliki tag sesuai yang dipilih: "<<endl;
//    cout << "1. " << info(parent(W)) << endl;
//    address_relasi E = next(W);
//    while (E != NULL)
//    {
//        if (info(child(W)) == info(child(E)))
//        {
//            cout << i << ". " << info(parent(E)) << endl;
//        }
//        E = next(E);
//    }
}

void jumlahrelasi() {
    address_relasi R = first(LR);

    if (first(LR) == NULL) {
        cout << "Belum Ada Relasi yang Tersedia" << endl << endl;
    } else {
        int i = 0;
        while (R != NULL) {
            i++;
            R = next(R);
        }
        cout << "Terdapat " << i << " Relasi" << endl << endl;
    }
}

void tampilartikel() {
    address_artikel P = first(LA);

    if (first(LA) == NULL) {
        cout << "Belum Ada Artikel yang Tersedia" << endl;
    } else {
        int i = 0;
        while (P != NULL) {
            i++;
            cout << i << ". " << info(P) << endl;
            P = next(P);
        }
    }
    cout << endl;
}

void tampiltag() {
    address_tag Q = first(LT);

    if (first(LA) == NULL) {
        cout << "Belum Ada Tag yang Tersedia" << endl;
    } else {
        int i = 0;
        while (Q != NULL) {
            i++;
            cout << i << ". " << info(Q) << endl;
            Q = next(Q);
        }
    }
    cout << endl;
}
