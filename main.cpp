#include <iostream>

#include "dokter.h"
#include "perawat.h"

void menu();
int main()
{
    /**Hafiz Yazid Muhammad - 1303213026*/
    /**Rizky Yohan Butar Butar - 130323107*/


    int pil;
    string namdok,Yes,namper;
    char i ;
    cout << "// Tekan char apa saja + enter. //" ;
    cin >> i ;
    system("CLS") ;
    Listdkr ldok;           /**List Dokter*/
    dokter dokx;            /**Struct Dokter*/
    adrdkr addok;           /**Address Dokter*/

    Listper lper;           /**List Perawat*/
    perawat perx;           /**Struct Perawat*/
    adrPer adper;           /**Address Perawat*/

    createListPer(lper);
    createListDkr(ldok);


    menu();

    cin>>pil;
    while(pil <= 12 && pil >= 1)
    {
        if(pil == 1){
            int n,i = 0;
            cout << " ===================== " << endl ;
            cout << " TAMBAH DOKTER " << endl ;
            cout << " N data masukan : ";
            cin >> n;
            while(i < n){
                cout << " Masukan ID Dokter : ";
                cin >> dokx.NIP ;
                cout<<" Nama dokter : ";
                cin.ignore();
                getline(cin,dokx.nama);

                cout<<" Poli : ";
                cin>> dokx.Poli;

                addok = alokasiDkr(dokx);
                insertLastDkr(ldok,addok);
                i++;
            }
            cout << " ===================== " << endl ;
            cout << endl ;
        }else if(pil == 2){
            int n,i =0;
            cout << " ===================== " << endl ;
            cout << " TAMBAH PERAWAT " << endl ;
            cout << " N data perawat : ";
            cin >> n;
            while(i < n){
                cout<<" Nama perawat : ";
                cin >> perx.nama;

                cout << " Masukan ID Perawat : ";
                cin >> perx.IDperawat ;

                cout<<" Shift : ";
                cin>> perx.shift;

                adper = alokasiPer(perx);
                insertLastPer(lper,adper);
                i++;
            }
            cout << " ===================== " << endl ;
            cout << endl ;
        }else if(pil == 3){
            int i = 0;
            cout << " ===================== " << endl;
            cout << " MENCARI DOKTER " << endl;
            cout<<" Masukan Nama Dokter : ";
            cin.ignore();
            getline(cin,namdok);
            addok = findElmDkr(ldok,namdok);
            while(addok == NIL && i < 2){
                cout<<" Mohon maaf dokter tidak ditemukan"<<endl;
                cout<<" Masukan Nama Dokter : ";
                getline(cin,namdok);
                addok = findElmDkr(ldok,namdok);
                i++;
            }
            if(addok == NIL){
                cout<<" Dokter tidak ditemukan "<<endl;
            }else{
                cout << " Dokter ditemukan " <<  endl;
                cout << " NIP dokter : "<<info(addok).NIP<<endl<<" Poli : "<<info(addok).Poli<<endl;
            }
            cout << " ===================== " << endl ;
        }else if(pil == 4){
            cout << " ===================== " << endl ;
            int i = 0;
            cout << " MENAMBAH PERAWAT PADA DOKTER TERTENTU " << endl;
            cout << " Masukan nama dokter : ";
            cin.ignore();
            getline(cin,namdok);
            addok = findElmDkr(ldok,namdok);
            while(addok == NIL && i < 2){
                cout << " dokter tidak ditemukan di list"<<endl;
                cout << " masukan nama dokter : ";
                getline(cin,namdok);
                addok = findElmDkr(ldok, namdok);
                i++;
            }
            i = 0;
            if(addok != NIL){
                cout << " masukan nama perawat : ";
                cin >> namper;
                adper = findElmPer(lper,namper);
                while(adper == NIL && i < 2){
                    cout << " perawat tidak ditemukan di list"<<endl;
                    cout << " masukan nama perawat :";
                    cin >> namper;
                    adper = findElmPer(lper,namper);
                    i++;
                }
                adrPer Q = findPerawatPadaDokter(ldok,lper,namdok,namper);
                if(Q == NIL){
                    connect(ldok,lper,namdok,namper);
                    cout <<" Berhasil Terhubung"<<endl;
               }
            }else if(addok == NIL || adper == NIL){
                cout<<" Batalkan proses.............";
            }
            cout << " ===================== " << endl ;
        }else if(pil == 5){
            cout << " ===================== " << endl ;
            cout << " MENCARI DATA PERAWAT PADA DOKTER TERNTU" <<endl;
            cout << " Masukan nama dokter : ";
            cin.ignore();
            getline(cin,namdok);

            cout << " Masukan nama perawat : ";
            cin  >> namper;

            adrPer Q  = findPerawatPadaDokter(ldok,lper,namdok,namper);
            if(Q != NIL){
                cout << " Perawat ditemukan" << endl;
                cout << " ID -> " << info(Q).IDperawat <<" Shift -> "<<info(Q).shift <<endl;
            }else{
                cout<<" Perawat tidak terhubung dengan dokter"<<endl;
            }
            cout << " ===================== " << endl ;
        }else if(pil == 6){
            cout << " ===================== " << endl ;
            adrdkr K,Q;
            int i = 0;
            cout << " MENGHAPUS DATA  DOKTER TERTENTU" <<endl;
            cout << " Nama dokter yang akan dihapus : ";
            cin.ignore();
            getline(cin,namdok);
            addok = findElmDkr(ldok,namdok);
            while(addok == NIL && i < 2){
                cout << " dokter tidak ditemukan di list"<<endl;
                cout << " masukan nama dokter kembali : ";
                getline(cin,namdok);
                addok = findElmDkr(ldok,namdok);
                i++;
            }
            if(addok == first(ldok)){
                deleteFirstDkr(ldok,Q);
                dealokasiDkr(Q);
            }else{
                K = first(ldok);
                while(next(K) != addok){
                    K = next(K);
                }
                deleteAfterDkr(ldok,K,Q);
                dealokasiDkr(Q);
            }
            cout << " ===================== " << endl ;
        }else if(pil == 7){
            int i = 0;
            cout << " ===================== " << endl ;
            cout << " MENGHAPUS DATA PERAWAT PADA DOKTER " <<endl;
            cout << " masukan anama dokter : ";
            cin.ignore();
            getline(cin,namdok);
            addok = findElmDkr(ldok,namdok);
            while(addok == NIL && i < 2){
                cout << " data dokter tidak ditemukan" <<endl;
                cout << " masukan nama dokter : ";
                getline(cin,namdok);
                addok = findElmDkr(ldok,namdok);
                i++;
            }
            if(addok == NIL){
                cout<<" Pengahapusan gagal "<<endl;
            }
            if(addok != NIL){
                i = 0;
                cout << " masukan nama perawat : ";
                cin >> namper;
                adper = findPerawatPadaDokter(ldok,lper,namdok,namper);
                while(adper == NIL && i < 2){
                    cout << " data perawat tidak ditemukan " << endl;
                    cout << " masukan nama perawat : ";
                    cin >> namper;
                    adper = findPerawatPadaDokter(ldok,lper,namdok,namper);
                    i++;
                }
                deletePerawatPadaDokter(ldok,lper,namdok,namper);
                cout << " mengahapus berhasil" <<endl;
            }else if(addok == NIL || adper == NIL){
                cout << " batalkan proses..." << endl;
            }
        }else if(pil == 8){
            cout << " ===================== " << endl ;
            cout << " MENAMPILKAN SEMUA DATA" << endl << endl ;
            printAllData(ldok);
            cout << " ===================== " << endl << endl ;
        }else if(pil == 9){
            int jumper, i = 0;
            cout << " ===================== " << endl ;
            cout << " MENGHITUNG PERAWAT PADA DOKTER TERTENTU "<<endl;
            cout << " masukan nama dokter : ";
            cin.ignore();
            getline(cin,namdok);
            addok = findElmDkr(ldok,namdok);
            while(addok== NIL && i < 2){
                cout << " dokter tidak ditemukan di list"<<endl;
                cout << " masukan nama dokter : ";
                getline(cin,namdok);
                i++;
            }
            if(addok != NIL){
                jumper = jumlahPerawatDok(ldok,namdok);
                cout << " jumlah perawat " << namdok << " : " << jumper <<endl;
            }else{
                 cout << " gagal menghitung perawat ";
            }
            cout << " ===================== " << endl ;
        }else if(pil == 10){
            cout << " ===================== " << endl ;
            cout << " MENAMPILKAN DOKTER " << endl ;
            printInfoDkr(ldok);
            cout << " ===================== " << endl ;
            cout << endl ;
        }else if(pil == 11){
            cout << " ===================== " << endl ;
            cout << " MENAMPILKAN PERAWAT " << endl ;
            printInfoPer(lper);
            cout << " ===================== " << endl ;
            cout << endl ;
        }else if(pil == 12){
            cout << " ===================== " << endl ;
            cout << " POLI DENGAN PERAWAT TERBANYAK " << endl ;
            PoliTerbanyak(ldok);
            cout << " ===================== " << endl ;
        }
        cout << "// Tekan char apa saja + enter. //" ;
        cin >> i ;
        system("CLS") ;
        menu();
        cin>>pil;
    }
    return 0;
}

void menu()
{
    /**Hafiz Yazid Muhammad (13013026)*/
    cout << " ===================== SEHAT ASIK HOSPITAL MENTAL 4646 =====================" << endl ;
    cout << " 1. Menambahkan data dokter " << endl ;
    cout << " 2. Menambahkan data perawat " << endl ;
    cout << " 3. Mencari data dokter tertentu. " << endl ;
    cout << " 4. Menambahkan relasi data perawat yang akan membantu dokter" << endl ;
    cout << " 5. Mencari data perawat pada dokter tertentu " << endl ;
    cout << " 6. Menghapus data dokter berserta relasinya " << endl ;
    cout << " 7. Menghapus data perawat pada dokter tertentu " << endl ;
    cout << " 8. Menampilkan seluruh data dokter beserta para perawat yang membantunya " << endl ;
    cout << " 9. Menghitung banyaknya perawat yang membantu pada dokter tertentu " << endl ;
    cout << " 10. Menampilkan Dokter " << endl ;
    cout << " 11. Menampilkan Perawat " << endl ;
    cout << " 12. Menampilkan data poli yang paling banyak perawatnya " << endl ;
    cout << " Pilih menu : "  ;
    cout<< endl;
    cout<<" -> ";
}
