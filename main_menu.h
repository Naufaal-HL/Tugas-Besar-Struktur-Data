#ifndef MAIN_MENU_H_INCLUDED
#define MAIN_MENU_H_INCLUDED

using namespace std;
#include <iostream>
#include "List_artikel.h"
#include "List_relasi.h"
#include "List_tag.h"

void dummy();
void menu();
void insert_artikel();          //a
void insert_tag();              //b
void koneksikan();              //c
void hapus_artikel();           //d
void hapus_tag();               //e
void isi_artikel_Tag();         //f
void isi_tag_Favorit();         //g
void kesamaan_artikel_Tag();    //h
void isi_artikel_Tag_pilihan(); //i

void jumlahrelasi();            //void 10 //bonus
void tampilartikel();           //void 11 //bonus
void tampiltag();               //void 12 //bonus

#endif // MAIN_MENU_H_INCLUDED
