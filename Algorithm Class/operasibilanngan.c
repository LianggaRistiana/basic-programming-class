#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void input_angka();
float kecepatan();
float debit();
float skala();
float peluang();
void menu();


int main()
{   float hasil = 0;
    int pilih;
    menu();
    scanf("%d",&pilih);
    system("cls");

    switch (pilih)
    {
        case 1:
            hasil = kecepatan();
            break;
        case 2:
            hasil = debit();
            break;
        case 3:
            hasil = skala();
            break;
        case 4:
            hasil = peluang();
            break;            
        default:
            printf("PILIHAN TIDAK TERSEDIA\n");
            // main();
            break;
    }

    if (hasil != 0)
    {
        printf("%.2f", hasil);}

    return 0;
}

void input_angka(float *var, char *pesan){
    printf("%s",pesan);
    scanf("%f",var);
}
float kecepatan(){
    float jarak ,waktu;
    printf ("RUMUS KECEPATAN\n");
    printf("=======================\n");
    
    input_angka(&jarak, "MASUKAN JARAK :");
    input_angka(&waktu, "MASUKAN WAKTU :");

    printf("=======================\n");
    printf("KECEPETANNYA ADALAH ");
    return jarak/waktu;
} 
float debit(){
    float volume, waktu;
    printf("RUMUS DEBIT\n");
    printf("=======================\n");

    input_angka(&volume, "MASUKAN VOLUME :");
    input_angka(&waktu, "MASUKAN WAKTU :");

    printf("=======================\n");
    printf("DEBITNYA ADALAH ");
    return volume/waktu;
}
float skala(){
    float real, peta;
    printf("RUMUS SKALA\n");
    printf("=======================\n");

    input_angka(&real, "MASUKAN JARAK SEBENARNYA :");
    input_angka(&peta, "MASUKAN JARAK PADA PETA  :");

    printf("=======================\n");
    printf("SKALANYA ADALAH 1 :");
    return real/peta;
}
float peluang(){
    float kejadian,seluruh;
    printf("RUMUS PELUANG\n");
    printf("=======================\n");

    input_angka(&kejadian, "MASUKAN JUMLAH KEJADIAN TERTENTU:");
    input_angka(&seluruh, "MASUKAN JUMLAH SELURUH KEJADIAN :");

    printf("=======================\n");
    printf("PELUANGNYA ADALAH ");    
    return kejadian,seluruh;
}
void menu(){
    printf("===OPERASI ARITMATIKA==\n");
    printf("1. KECEPATA\n");
    printf("2. DEBIT\n");
    printf("3. SKALA\n");
    printf("4. PELUANG\n");
    printf("=======================\n");
    printf("MASUKAN PILIHAN :");
}