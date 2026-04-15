/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 1
 *   Hari dan Tanggal    : Rabu, 15 April 2026
 *   Nama (NIM)          : Rafi Arif Putra (13224033)
 *   Nama File           : soal2.c
 *   Deskripsi           : Fungsi yang menghitung jumlah transformasi (rekursi) dari bilangan aslinya sampai mencapai bilangan 1 dengan operasi tertentu berdasarkan ganjil/genapnya bilangan pada tiap transformasi.
 * 
 */

#include <stdio.h>

// Fungsi rekursi
void counttransformation(int n, int transformation){
    int next_n;
    int odd = n%2; // jika ganjil, n%2 = 1. jika genap, n%2 = 0

    if (n == 1){ // jika n = 1, langsung print transformation = 0
        printf("\nLANGKAH %d\n", transformation);
    }

    else if (n == 2){ // jika n = 2, berikutnya adalah 1, dan rekursi selesai
        printf("LANGKAH %d\n", transformation+1);
        return;
    }

    else if ((odd == 1) && (n > 1)){ // ganjil DAN n>1
        next_n = (n*3)+1;
        counttransformation(next_n, transformation+1);
    }
    else if (odd == 0) { // genap
        next_n = n/2;
        counttransformation(next_n, transformation+1);
    }
}

int main(){
    int num_count; // Deklarasi n sebagai jumlah bilangan
    scanf("%d", &num_count);
    int arr[num_count];

    // Iterasi for loop untuk bilangan dari user input sebanyak n (jumlah bilangan)
    for (int i=0; i<num_count; i++){
        scanf("%d", &arr[i]); // Bilangan disimpan sebagai data pada array ke-i
    }

    // Menghitung jumlah transformasi tiap bilangan satu-satu
    for (int i=0; i<num_count; i++){
        counttransformation(arr[i], 0);
    }
}
