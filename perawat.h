#ifndef PERAWAT_H_INCLUDED
#define PERAWAT_H_INCLUDED

#include <iostream>
using namespace std;

#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info
#define first(L) L.first
#define last(L) L.last
#define NIL NULL

/**INFOTYPE*/
struct perawat{
    int IDperawat;
    string nama;
    string shift;
};

/**TYPEDEF*/
typedef struct elmper *adrPer;

/**ELMLIST*/
struct elmper{
    /**DLL*/
    perawat info;
    adrPer next;
    adrPer prev;
};

/**LIST*/
struct Listper {
    adrPer first;
    adrPer last;
};

/**Double!!!!!!!*/
void createListPer(Listper &L);
void insertFirstPer(Listper &L, adrPer P);
void insertLastPer(Listper &L, adrPer P);
void insertAfterPer(Listper &L,adrPer Prec, adrPer P);
void deleteFirstPer(Listper &L, adrPer &P);
void deleteLastPer(Listper &L, adrPer &P);
void deleteAfterPer(Listper &L,adrPer Prec, adrPer &P);
adrPer alokasiPer(perawat x);
void dealokasiPer(adrPer &P);
adrPer findElmPer(Listper L, string x);
adrPer findElmIDPer(Listper L, int x);
void printInfoPer(Listper L);

/**Case Functionality*/
bool perawatKosong(Listper L);

#endif // PERAWAT_H_INCLUDED
