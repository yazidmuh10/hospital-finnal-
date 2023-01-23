#include "perawat.h"

void createListPer(Listper &L){
    first(L) = NIL;
    last(L) = NIL;
}
void insertFirstPer(Listper &L, adrPer P){
    if(perawatKosong(L)){
        first(L) = P;
        last(L) = P;
    }else{
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}
void insertLastPer(Listper &L, adrPer P){
    if(perawatKosong(L)){
        first(L) = P;
        last(L) = P;
    }else{
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
}
void insertAfterPer(Listper &L, adrPer Prec, adrPer P){
    if(perawatKosong(L)){
        first(L) = P;
        last(L) = P;
    }else if(Prec == last(L)){
        insertLastPer(L,P);
    }else{
        next(P) = next(Prec);
        prev(P) = Prec;
        prev(next(Prec)) = P;
        next(Prec) = P;
    }
}
void deleteFirstPer(Listper &L, adrPer &P){
    if(perawatKosong(L)){
        cout << "List Kosong" << endl;
    }else{
        P = first(L);
        first(L) = next(P);
        next(P) = NIL;
        prev(first(L)) = NIL;
    }
}
void deleteLastPer(Listper &L, adrPer &P){
    if(perawatKosong(L)){
        cout<<"List Kosong"<<endl;
    }else if(next(first(L)) == NIL){
        deleteFirstPer(L,P);
    }else{
        P = last(L);
        last(L) = prev(last(L));
        prev(P) = NIL;
        next(last(L)) = NIL;
    }
}
void deleteAfterPer(Listper &L,adrPer Prec, adrPer &P){
    if(perawatKosong(L)){
        cout<<"LIST KOSONG"<<endl;
    }else if(next(Prec) == last(L)){
        deleteLastPer(L,P);
    }else if(next(Prec) == NIL){
        cout<<"Tidak dapat mendelete"<<endl;
    }else{
        P = next(Prec);
        next(Prec) = next(P);
        prev(next(P)) = Prec;
        next(P) = NIL;
        prev(P) = NIL;
    }
}
adrPer alokasiPer(perawat x){
    adrPer P = new elmper;
    info(P).IDperawat = x.IDperawat;
    info(P).nama = x.nama;
    info(P).shift = x.shift;
    prev(P) = NIL;
    next(P) = NIL;
    return P;
}
void dealokasiPer(adrPer &P){
    delete P;
}
adrPer findElmPer(Listper L, string x){ /**find nama*/
    adrPer P = first(L);
    while(P != NIL && info(P).nama != x){
        P = next(P);
    }
    return P;
}
adrPer findElmIDPer(Listper L, int x){  /**find ID*/
    adrPer P = first(L);
    while(P != NIL && info(P).IDperawat != x){
        P = next(P);
    }
    return P;
}
void printInfoPer(Listper L){
    adrPer P = first(L);
    while(P != NIL){
        cout<< info(P).IDperawat<<" "<< info(P).nama<<" "<< info(P).shift<<endl;
        P = next(P);
    }
    cout << endl;
}

/**Case Functionality*/

bool perawatKosong(Listper L){
    return first(L) == NIL && last(L) == NIL;
}
