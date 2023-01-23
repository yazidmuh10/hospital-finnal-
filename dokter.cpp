#include "dokter.h"

bool isEmptyDkr(Listdkr L){
    return (first(L) == NIL && last(L) == NIL);
}

void createListDkr(Listdkr &L){
    first(L) = NIL;
    last(L) = NIL;
}

adrdkr alokasiDkr(dokter x){
    adrdkr P = new elmdkr;
    info(P).nama = x.nama;
    info(P).Poli = x.Poli;
    info(P).NIP = x.NIP;
    rels(P) = NIL;
    next(P) = NIL;
    return P;
}

void dealokasiDkr(adrdkr &P){
    delete P;
}

void insertFirstDkr(Listdkr &L, adrdkr P){
    if(isEmptyDkr(L)){
        first(L) = P;
        last(L) = P;
    }else{
        next(P) = first(L);
        first(L) = P;
        next(last(L)) = P;
    }
}

void insertAfterDkr(Listdkr &L, adrdkr Prec, adrdkr P){
    if(isEmptyDkr(L)){
        first(L) = P;
        last(L) = P;
    }else if(Prec == last(L)){
        insertLastDkr(L,P);
    }else{
        next(P) = next(Prec);
        next(Prec) = P;
    }
}

void insertLastDkr(Listdkr &L, adrdkr P){
    if(isEmptyDkr(L)){
        first(L) = P;
        last(L) = P;
    }else{
        next(last(L)) = P;
        last(L) = P;
        next(P) = first(L);
    }
}

void deleteFirstDkr(Listdkr &L, adrdkr &P){
    if(isEmptyDkr(L)){
        cout << "LIST KOSONG" << endl;
    }else{
        P = first(L);
        first(L) = next(P);
        next(P) = NIL;
        next(last(L)) = first(L);
    }
}

void deleteLastDkr(Listdkr &L, adrdkr &P){
    if(isEmptyDkr(L)){
        cout << "LIST KOSONG" << endl;
    }else if(next(first(L)) == NIL){
        deleteFirstDkr(L,P);
    }else{
        adrdkr Q = first(L);
        while(next(Q) != last(L)){
            Q = next(Q);
        }
        P = next(Q);
        next(Q) = NIL;
        last(L) = Q;
        next(last(L)) = first(L);
    }
}

void deleteAfterDkr(Listdkr &L, adrdkr Prec, adrdkr &P){
    if(isEmptyDkr(L)){
        cout<<"LIST KOSONG"<<endl;
    }else if(next(Prec) == last(L)){
        deleteLastDkr(L,P);
    }else if(next(Prec) == first(L)){
        cout<<"Tidak dapat mendelete"<<endl;
    }else{
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NIL;
    }
}

void printInfoDkr(Listdkr L){
    adrdkr P = first(L);
    do{
        cout<<info(P).nama<<" ---- "<<info(P).Poli<<" ---- "<<info(P).NIP<<endl;
        P = next(P);
    }while(P != first(L));
    cout << endl;
}

adrdkr findElmDkr(Listdkr L, string x){
    adrdkr P = first(L);
    do{
        if(info(P).nama == x){
            return P;
        }
        P = next(P);
    }while(P != first(L));
    return NIL;
}

/**case relasi*/

adrrel alokasiRel(adrPer C){
    adrrel R = new elmlire;
    inforel(R) = C;
    next(R) = NIL;
    prev(R) = NIL;
    return R;
}

void connect(Listdkr &D,Listper P, string x, string y){
    adrPer P1 = findElmPer(P,y);
    adrdkr D1 = findElmDkr(D,x);
    if(P1 != NIL && D1 != NIL){
        adrrel R = alokasiRel(P1);
        if(rels(D1) == NIL){
            rels(D1) = R;
        }else{
            adrrel Rel = rels(D1);
            while(next(Rel) != NIL){
                Rel = next(Rel);
            }
            next(Rel) = R;
            prev(R) = Rel;
        }
    }
}

adrPer findPerawatPadaDokter(Listdkr D,Listper L, string x, string y){/**x dokter ,y perawat*/
    adrdkr P = findElmDkr(D,x);
    adrPer Q = findElmPer(L,y);
    adrrel R = rels(P);
    if(P != NIL && Q != NIL){
        while(R != NIL && inforel(R) != Q){
            R = next(R);
        }
        if(R == NIL){
            return NIL;
        }else{
            return inforel(R);
        }
    }
    if(R == NIL || P == NIL || Q == NIL){
        return NIL;
    }
}

void deletePerawatPadaDokter(Listdkr &D,Listper L,string x,string y){/**x dokter ,y perawat*/
    adrdkr K = findElmDkr(D,x);
    adrrel Q,R = rels(K);
    adrPer P = findPerawatPadaDokter(D,L,x,y);
    if(P != NIL){
        if(inforel(R) == P){
            if(next(rels(K)) == NIL){
                rels(K) = NIL;
            }else{
                rels(K) = next(R);
                prev(rels(K)) = NIL;
                next(R) = NIL;
                R = NIL;
            }
        }else{
            Q = rels(K);
            while(inforel(Q) != P){
                Q = next(Q);
            }
            if(next(Q) != NIL){
                R = prev(Q);
                next(R) = next(Q);
                prev(next(Q)) = R;
                next(Q) = NIL;
                prev(Q) = NIL;
            }else{
                R = prev(Q);
                next(R) = NIL;
                prev(Q) = NIL;
            }
        }
    }else{
        cout<<" delete gagal "<<endl;
    }
}

int jumlahPerawatDok(Listdkr D,string x){
    adrdkr P = findElmDkr(D,x);
    int counter = 0;
    adrrel R = rels(P);
    if(P != NIL){
        while(R != NIL){
            counter++;
            R = next(R);
        }
        return counter;
    }else{
        return 0;
    }
}

void printAllData(Listdkr L){
    adrdkr P;
    adrrel R;
    P = first(L);
    if(P != NIL){
        /**do while*/
        do{
            cout<<"---- "<<info(P).nama<<" ---- "<<info(P).NIP<<" ----"<<endl;
            cout<<"Poli : "<<info(P).Poli<<endl;
            R = rels(P);
            while(R != NIL){
                cout<<"Perawat ->";
                cout<<" "<<info(inforel(R)).nama<<" -- "<<info(inforel(R)).IDperawat<<" -- "<<info(inforel(R)).shift;
                cout<<endl;
                R = next(R);
            }
            cout<<endl;
            P = next(P);
        }while(P != first(L));
    }else{
        cout<<"??EMPTY TOTAL??"<<endl;
    }
}

void PoliTerbanyak(Listdkr D){
    int N1,M1,nMax,n;
    adrdkr MAX,M,N;
    N = first(D);
    MAX = N;
    nMax = jumlahPerawatDok(D,info(N).nama);
    M = next(N);
    do{
        M1 = jumlahPerawatDok(D,info(M).nama);
        if(M1 > nMax){
            MAX = M;
        }
        M = next(M);
        N = next(N);
    } while(N != first(D));
    n = jumlahPerawatDok(D,info(MAX).nama);
    cout<<" Poli Terbanyak : "<<info(MAX).Poli <<endl;
    cout<<" dengan jumlah perawat : " << n <<endl;
}
