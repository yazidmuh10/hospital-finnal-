#ifndef DOKTER_H_INCLUDED
#define DOKTER_H_INCLUDED

#include <iostream>
#include "perawat.h"
using namespace std;

/**RELASTION*/

/**TYPEDEF*/
#define inforel(P) P->inforel
#define prevrel(P) P->prevrel
#define next(P) P->next

typedef struct elmlire *adrrel;

/**ELMLIST*/
struct elmlire{
    adrrel next;
    adrrel prev;
    adrPer inforel;
};
/**FUNGSIONAL*/
adrrel alokasiRel(adrPer C);

/**=============ELEMENT DOKTER==============*/
#define next(P) P->next
#define info(P) P->info
#define last(L) L.last
#define first(L) L.first
#define rels(P) P->rels
#define NIL NULL

/**INFOTYPE*/
struct dokter {
    string nama,Poli;
    int NIP;
};

/**TYPEDEF*/
typedef struct elmdkr *adrdkr;

/**ELMLIST*/
struct elmdkr {
    /**SLLC*/
    dokter info;
    adrdkr next;
    adrrel rels;
};

/**LIST*/
struct Listdkr {
    adrdkr first;
    adrdkr last;
};

/**Case Functionality !!!!!!!*/

void insertFirstDkr(Listdkr &L, adrdkr P);
void insertAfterDkr(Listdkr &L, adrdkr Prec, adrdkr P);
void insertLastDkr(Listdkr &L, adrdkr P);

void deleteFirstDkr(Listdkr &L, adrdkr &P);
void deleteLastDkr(Listdkr &L, adrdkr &P);
void deleteAfterDkr(Listdkr &L, adrdkr Prec, adrdkr &P);

void dealokasiDkr(adrdkr &P);
void createListDkr(Listdkr &L);
adrdkr alokasiDkr(dokter x);
adrdkr findElmDkr(Listdkr L, string x);
adrdkr findIDDkr(Listdkr L, int x);
void printInfoDkr(Listdkr L);

/**Case Use Relation*/
bool isEmptyDkr(Listdkr L);
void connect(Listdkr &D,Listper P, string x, string y);
adrPer findPerawatPadaDokter(Listdkr D,Listper L, string x, string y);
void deletePerawatPadaDokter(Listdkr &D,Listper L,string x,string y);
int jumlahPerawatDok(Listdkr D,string x);
void printAllData(Listdkr L);
void PoliTerbanyak(Listdkr D);

#endif // DOKTER_H_INCLUDED
