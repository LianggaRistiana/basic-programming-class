#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>

#define ADMIN_RT 10000 // biaya admin rumah tangga
#define ADMIN_U 12500  // biaya admin usaha
#define DENDA 25000    // denda bila lewat jatuh tempo
#define BPM_RT 5000    // biaya pemeliharaan rumah tangga
#define BPM_U 7500     // biaya pemeliharaan usaha
#define JATUH_TEMPO 20 // jatuh tempo tgl 20

typedef struct data_pelanggan
{
    char nama[20];
    int UkuranJalan,
        watt,
        denda;

    float PemakaianAir,
        TotalHarga,
        BiayaAir;
} data_pelanggan;


void intro(),
    selesai(),
    pause(),
    input_int(int *var, char *intruksi),
    positif_int(int *var, char *intruksi),
    range_int(int *var, int range1, int range2, char *intruksi),
    input_float(float *var, char *intruksi),

    menu_kelompok(int *var),
    menu_jalan(int *var, int menu),
    menu_watt(int *var),
    menu_pemakaian(float *var, char *nama, int *ulang),

    File_struck(float AirPtr, int menu, int jalan, int watt, float harga, int denda, float air, char *namaptr),
    File_txt(data_pelanggan *D, int menu),

    rumus(float *AirPtr, int menu, int jalan, int watt, float *pakaiAir, float *hargaptr, int *dendaptr),
    denda_tempo(int *var),
    struk(float *AirPtr, int menu, int jalan, int watt, float harga, int denda, float air, char *namaptr);


int main()
{
    data_pelanggan Data1;
    
    int menu, UkuranJalan, watt, ulang, denda;
    //float Pemakaian, TotalHarga, BiayaAir;
    char nama[20];

    intro();
    pause();
    while (1)
    {   
        ulang = 9;
        menu_kelompok(&menu);
        if (menu == 0)
            break;
        while (1)
        {
            ulang = 9;
            menu_jalan(&Data1.UkuranJalan, menu);
            if (Data1.UkuranJalan == 0)
                break;
            while (1)
            {
                ulang = 9;
                menu_watt(&Data1.watt);
                if (Data1.watt == 0)
                    break;
                while (1)
                {
                    ulang = 9;
                    fflush(stdin);
                    menu_pemakaian(&Data1.PemakaianAir, Data1.nama, &ulang);

                    if (ulang == 4)
                        break;
                    else if (ulang == 5)
                        continue;
                    while (1)
                    {

                        fflush(stdin);
                        rumus(&Data1.BiayaAir, menu, Data1.UkuranJalan, Data1.watt, &Data1.PemakaianAir, &Data1.TotalHarga, &Data1.denda);
                        struk(&Data1.BiayaAir, menu, Data1.UkuranJalan, Data1.watt, Data1.TotalHarga, Data1.denda, Data1.PemakaianAir, Data1.nama);
                        //File_struck(Data1.BiayaAir, menu, Data1.UkuranJalan, Data1.watt, Data1.TotalHarga, Data1.denda, Data1.PemakaianAir, Data1.nama);
                        File_txt(&Data1,menu);
                        range_int(&ulang, 0, 4, "\n\n\t\t\t[0]Keluar\n\t\t\t[1]Kembali ke Menu Kelompok\n\t\t\t[2]Kembali ke Menu Lebar Jalan\n\t\t\t[3]Kembali ke Menu Besar Listrik\n\t\t\t[4]Kembali ke Form Pelanggan\n\t\t\t:");
                        break;
                    }
                    if (ulang < 4)
                        break;
                }
                if (ulang < 3)
                    break;
            }
            if (ulang < 2)
                break;
        }
        if (ulang < 1)
            break;
    }
    selesai();
    return 0;
}

void range_int(int *var, int range1, int range2, char *intruksi) // membatasi input
{
    while (1)
    {
        input_int(var, intruksi);
        fflush(stdin);
        if (*var >= range1 && *var <= range2)
            break;
        printf("\033[0;31m");
        printf("\t\t\t Input salah! Menu Tidak Tersedia\n");
        printf("\033[0m");
    }
}
void positif_int(int *var, char *intruksi) // membatasi input agar positif
{
    while (1)
    {
        input_int(var, intruksi);
        fflush(stdin);
        if (*var >= 0)
            break;
        printf("\033[0;31m");
        printf("\t\t\t\tMasukan Tahun Masehi!!\n");
        printf("\033[0m");
    }
}
void input_int(int *var, char *intruksi) //
{
    char buff[1024];
    char cek;

    while (1)
    {
        printf("%s", intruksi);
        fflush(stdin);
        if (fgets(buff, sizeof(buff), stdin) != NULL)
        {
            if (sscanf(buff, "%d %c", var, &cek) == 1)
            {
                break;
            }
        }
        printf("\033[0;31m\t\t\t Input salah! Silahkan coba lagi\n\033[0m");
    }
}
void input_float(float *var, char *intruksi) //
{
    char buff[1024];
    char cek;

    while (1)
    {
        printf("%s", intruksi);
        fflush(stdin);
        if (fgets(buff, sizeof(buff), stdin) != NULL)
        {
            if (sscanf(buff, "%f %c", var, &cek) == 1)
            {
                break;
            }
        }
        printf("\033[0;31m\t\t\t Input salah! Silahkan coba lagi\n\033[0m");
    }
}

void intro()
{
    system("cls");
    printf("\n");
    printf("\t================================================\n"); //////);
    printf("\t||                 \e[1mProgram PDAM\e[m               ||\n");
    printf("\t||            \e[1mPT. Blangkon Sejahtera\e[m          ||\n");
}
void pause()
{
    printf("\t================================================\n");
    printf("\t             click enter to continue");
    while (_getch() != 13)
        ;
}
void selesai()
{
    system("cls");
    printf("\n");

    printf("\t================================================\n"); ///////)
    printf("\t||               \e[1mPROGRAM SELESAI\e[m              ||\n");
    printf("\t================================================\n");
}

void menu_kelompok(int *var)
{
    intro();
    printf("\t||============================================||\n"); ///////;
    printf("\t||           \e[1mMENU KELOMPOK PELANGGAN\e[m          ||\n");
    printf("\t||                                            ||\n");
    printf("\t|| 1. Rumah Tangga                            ||\n");
    printf("\t|| 2. Usaha                                   ||\n");
    printf("\t||                                            ||\n");
    printf("\t================================================\n"); ///////;
    printf("\t                                   [0]Keluar\n");
    range_int(var, 0, 3, "\t   MASUKAN PILIHAN ANDA : ");
}
void menu_jalan(int *var, int menu)
{
    intro();
    printf("\t||============================================||\n"); ///////;
    printf("\t||              \e[1mMENU LEBAR JALAN\e[m              ||\n");
    printf("\t||                                            ||\n");

    if (menu == 1)
    {
        printf("\t|| 1. 0 - 3,99 meter                          ||\n");
        printf("\t|| 2. 4 - 6,99 meter                          ||\n");
        printf("\t|| 3. 7 - 10   meter                          ||\n");
        printf("\t|| 4.  > 10    meter                          ||\n");
        printf("\t|| 5. Memiliki Rumah dengan kios              ||\n");
    }
    else if (menu == 2)
    {
        printf("\t|| 1. 0 - 6,99 meter                          ||\n");
        printf("\t|| 2. 7 - 10   meter                          ||\n");
        printf("\t|| 3. >10      meter                          ||\n");
    }
    printf("\t||                                            ||\n");
    printf("\t||           Ukuran jalan termasuk            ||\n");
    printf("\t||             got dan berm Anda              ||\n");
    printf("\t||        serta apabila memiliki kios         ||\n");
    printf("\t================================================\n"); ////////;
    printf("\t                                   [0]Kembali\n");

    if (menu == 1)
        range_int(var, 0, 5, "\t   MASUKAN PILIHAN ANDA : ");
    else if (menu == 2)
        range_int(var, 0, 3, "\t   MASUKAN PILIHAN ANDA : ");
}
void menu_watt(int *var)
{
    intro();
    printf("\t||============================================||\n"); ///////;
    printf("\t||        \e[1mMENU BESAR TEGANGAN LISTRIK\e[m         ||\n");
    printf("\t||                                            ||\n");
    printf("\t|| 1.    450    Watt                          ||\n");
    printf("\t|| 2.    900    Watt                          ||\n");
    printf("\t|| 3.   1300    Watt                          ||\n");
    printf("\t|| 4. > 1300    Watt                          ||\n");
    printf("\t||                                            ||\n");
    printf("\t================================================\n"); ////////;
    printf("\t                                   [0]Kembali\n");
    range_int(var, 0, 4, "\t   MASUKAN PILIHAN ANDA : ");
}
void menu_pemakaian(float *var, char *nama, int *ulang)
{
    float BulanLalu, BulanIni;

    intro();
    printf("\t||============================================||\n"); ///////;
    printf("\t||                                            ||\n");
    printf("\t||               \e[1mFORM PELANGGAN\e[m               ||\n");
    printf("\t||                                            ||\n");
    printf("\t================================================\n"); ///////;
    printf("\t   MASUKAN NAMA ANDA             : ");
    scanf("%[^\n]", nama);
    input_float(&BulanLalu, "\t   PEMAKAIAN AIR BULAN LALU (M^3): ");
ulang:
    input_float(&BulanIni, "\t   PEMAKAIAN AIR BULAN LALU (M^3): ");
    if (BulanIni < BulanLalu)
    {
        printf("\033[0;31m\t\t\tPemakaian Bulan ini tidak boleh lebih kecil dari bulan lalu !\n\033[0m");
        goto ulang;
    }
    *var = BulanIni - BulanLalu;

    range_int(ulang, 0, 2, "\n\t\t\t[0]Kembali ke menu sebelumnnya\n\t\t\t[1]Isi Form Ulang\n\t\t\t[2]Print Struck\n\t\t\t:");
    if (*ulang == 0)
        *ulang = 4;
    else if (*ulang == 1)
        *ulang = 5;
    else if (*ulang == 2)
        *ulang = 6;
}

void rumus(float *AirPtr, int menu, int jalan, int watt, float *pakaiAir, float *hargaptr, int *dendaptr)
{

    float biaya;
    switch (menu)
    {
    case 1: // rumah tangga
        switch (jalan)
        {

        case 1: // 0 - 3,99
            switch (watt)
            {
            case 1: // 450 w D1-1
                if (*pakaiAir <= 10)
                {
                    biaya = 17800;
                }
                else if (*pakaiAir > 10 && *pakaiAir <= 20)
                {
                    biaya = *pakaiAir * 2060;
                }
                else if (*pakaiAir > 20)
                {
                    biaya = *pakaiAir * 5880;
                }
                break;
            case 2: // 900 w D1-3
                if (*pakaiAir <= 10)
                {
                    biaya = 20600;
                }
                else if (*pakaiAir > 10 && *pakaiAir <= 20)
                {
                    biaya = *pakaiAir * 2340;
                }
                else if (*pakaiAir > 20)
                {
                    biaya = *pakaiAir * 5940;
                }
                break;
            case 3: // 1300 w D1-3
                if (*pakaiAir <= 10)
                {
                    biaya = 63400;
                }
                else if (*pakaiAir > 10 && *pakaiAir <= 20)
                {
                    biaya = *pakaiAir * 9200;
                }
                else if (*pakaiAir > 20)
                {
                    biaya = *pakaiAir * 9600;
                }
                break;
            case 4: // >1300 w D1-4
                if (*pakaiAir <= 10)
                {
                    biaya = 64200;
                }
                else if (*pakaiAir > 10 && *pakaiAir <= 20)
                {
                    biaya = *pakaiAir * 9350;
                }
                else if (*pakaiAir > 20)
                {
                    biaya = *pakaiAir * 9650;
                }
                break;

            default:
                printf("RT - jalan 1");
                pause();
                break;
            }
            break;

        case 2: // 4 - 6,99
            switch (watt)
            {
            case 1: // 450 w D2-1
                if (*pakaiAir <= 10)
                {
                    biaya = 23400;
                }
                else if (*pakaiAir > 10 && *pakaiAir <= 20)
                {
                    biaya = *pakaiAir * 2620;
                }
                else if (*pakaiAir > 20)
                {
                    biaya = *pakaiAir * 6000;
                }
                break;
            case 2: // 900 w D2-2
                if (*pakaiAir <= 10)
                {
                    biaya = 26200;
                }
                else if (*pakaiAir > 10 && *pakaiAir <= 20)
                {
                    biaya = *pakaiAir * 2900;
                }
                else if (*pakaiAir > 20)
                {
                    biaya = *pakaiAir * 6060;
                }
                break;
            case 3: // 1300 w D2-3
                if (*pakaiAir <= 10)
                {
                    biaya = 64900;
                }
                else if (*pakaiAir > 10 && *pakaiAir <= 20)
                {
                    biaya = *pakaiAir * 9500;
                }
                else if (*pakaiAir > 20)
                {
                    biaya = *pakaiAir * 9800;
                }
                break;
            case 4: // >1300 w D2-4
                if (*pakaiAir <= 10)
                {
                    biaya = 65700;
                }
                else if (*pakaiAir > 10 && *pakaiAir <= 20)
                {
                    biaya = *pakaiAir * 9650;
                }
                else if (*pakaiAir > 20)
                {
                    biaya = *pakaiAir * 9950;
                }
                break;

            default:
                printf("RT - jalan 2");
                pause();
                break;
            }
            break;

        case 3: // 7 - 10
            switch (watt)
            {
            case 1: // 450 w D3-1
                if (*pakaiAir <= 10)
                {
                    biaya = 29000;
                }
                else if (*pakaiAir > 10 && *pakaiAir <= 20)
                {
                    biaya = *pakaiAir * 3180;
                }
                else if (*pakaiAir > 20)
                {
                    biaya = *pakaiAir * 6120;
                }
                break;
            case 2: // 900 w D3-2
                if (*pakaiAir <= 10)
                {
                    biaya = 31800;
                }
                else if (*pakaiAir > 10 && *pakaiAir <= 20)
                {
                    biaya = *pakaiAir * 3460;
                }
                else if (*pakaiAir > 20)
                {
                    biaya = *pakaiAir * 6180;
                }
                break;
            case 3: // 1300 w D3-3
                if (*pakaiAir <= 10)
                {
                    biaya = 66400;
                }
                else if (*pakaiAir > 10 && *pakaiAir <= 20)
                {
                    biaya = *pakaiAir * 9800;
                }
                else if (*pakaiAir > 20)
                {
                    biaya = *pakaiAir * 10100;
                }
                break;
            case 4: // >1300 w D3-4
                if (*pakaiAir <= 10)
                {
                    biaya = 67200;
                }
                else if (*pakaiAir > 10 && *pakaiAir <= 20)
                {
                    biaya = *pakaiAir * 9950;
                }
                else if (*pakaiAir > 20)
                {
                    biaya = *pakaiAir * 10250;
                }
                break;

            default:
                printf("RT jalan 3");
                pause();
                break;
            }
            break;

        case 4: // >10
            switch (watt)
            {
            case 1: // 450 w D4-1
                if (*pakaiAir <= 10)
                {
                    biaya = 34600;
                }
                else if (*pakaiAir > 10 && *pakaiAir <= 20)
                {
                    biaya = *pakaiAir * 3740;
                }
                else if (*pakaiAir > 20)
                {
                    biaya = *pakaiAir * 6240;
                }
                break;
            case 2: // 900 w D4-2
                if (*pakaiAir <= 10)
                {
                    biaya = 37400;
                }
                else if (*pakaiAir > 10 && *pakaiAir <= 20)
                {
                    biaya = *pakaiAir * 4020;
                }
                else if (*pakaiAir > 20)
                {
                    biaya = *pakaiAir * 6300;
                }
                break;
            case 3: // 1300 w D4-3
                if (*pakaiAir <= 10)
                {
                    biaya = 67900;
                }
                else if (*pakaiAir > 10 && *pakaiAir <= 20)
                {
                    biaya = *pakaiAir * 10100;
                }
                else if (*pakaiAir > 20)
                {
                    biaya = *pakaiAir * 10400;
                }

                break;
            case 4: // >1300 w D4-4
                if (*pakaiAir <= 10)
                {
                    biaya = 68700;
                }
                else if (*pakaiAir > 10 && *pakaiAir <= 20)
                {
                    biaya = *pakaiAir * 10250;
                }
                else if (*pakaiAir > 20)
                {
                    biaya = *pakaiAir * 10550;
                }
                break;

            default:
                printf("RT - Jalan 4");
                pause();
                break;
            }
            break;

        case 5: // memiliki kios
            switch (watt)
            {
            case 1: // 450 w D5-1
                if (*pakaiAir <= 10)
                {
                    biaya = 69400;
                }
                else if (*pakaiAir > 10 && *pakaiAir <= 20)
                {
                    biaya = *pakaiAir * 10400;
                }
                else if (*pakaiAir > 20)
                {
                    biaya = *pakaiAir * 10700;
                }
                break;
            case 2: // 900 w D5-2
                if (*pakaiAir <= 10)
                {
                    biaya = 70200;
                }
                else if (*pakaiAir > 10 && *pakaiAir <= 20)
                {
                    biaya = *pakaiAir * 10550;
                }
                else if (*pakaiAir > 20)
                {
                    biaya = *pakaiAir * 10850;
                }
                break;
            case 3: // 1300 w D5-3
                if (*pakaiAir <= 10)
                {
                    biaya = 70900;
                }
                else if (*pakaiAir > 10 && *pakaiAir <= 20)
                {
                    biaya = *pakaiAir * 10700;
                }
                else if (*pakaiAir > 20)
                {
                    biaya = *pakaiAir * 11000;
                }
                break;
            case 4: // >1300 w D5-4
                if (*pakaiAir <= 10)
                {
                    biaya = 71700;
                }
                else if (*pakaiAir > 10 && *pakaiAir <= 20)
                {
                    biaya = *pakaiAir * 10850;
                }
                else if (*pakaiAir > 20)
                {
                    biaya = *pakaiAir * 11150;
                }
                break;

            default:
                printf("RT - jalan 5");
                pause();
                break;
            }
            break;

        default:
            printf("RT");
            pause();
            break;
        }
        *AirPtr = biaya;
        biaya += BPM_RT;
        biaya += ADMIN_RT;
        break;

    case 2: // usaha
        switch (jalan)
        {
        case 1: // 0 - 6.99
            switch (watt)
            {
            case 1: // 450 w E1-1
                if (*pakaiAir <= 10)
                {
                    biaya = 92000;
                }
                else if (*pakaiAir > 10 && *pakaiAir <= 20)
                {
                    biaya = *pakaiAir * 9850;
                }
                else if (*pakaiAir > 20)
                {
                    biaya = *pakaiAir * 10950;
                }
                break;
            case 2: // 900 w E1-2
                if (*pakaiAir <= 10)
                {
                    biaya = 95000;
                }
                else if (*pakaiAir > 10 && *pakaiAir <= 20)
                {
                    biaya = *pakaiAir * 10150;
                }
                else if (*pakaiAir > 20)
                {
                    biaya = *pakaiAir * 11250;
                }
                break;
            case 3: // 1300 w E1-3
                if (*pakaiAir <= 10)
                {
                    biaya = 98000;
                }
                else if (*pakaiAir > 10 && *pakaiAir <= 20)
                {
                    biaya = *pakaiAir * 10450;
                }
                else if (*pakaiAir > 20)
                {
                    biaya = *pakaiAir * 11550;
                }
                break;
            case 4: // >1300 w E1-4
                if (*pakaiAir <= 10)
                {
                    biaya = 101000;
                }
                else if (*pakaiAir > 10 && *pakaiAir <= 20)
                {
                    biaya = *pakaiAir * 10750;
                }
                else if (*pakaiAir > 20)
                {
                    biaya = *pakaiAir * 11850;
                }
                break;

            default:
                printf("Usaha - jalan 1");
                pause();
                break;
            }
            break;
        case 2: // 7 - 10
            switch (watt)
            {
            case 1: // 450 w E2-1
                if (*pakaiAir <= 10)
                {
                    biaya = 104000;
                }
                else if (*pakaiAir > 10 && *pakaiAir <= 20)
                {
                    biaya = *pakaiAir * 11050;
                }
                else if (*pakaiAir > 20)
                {
                    biaya = *pakaiAir * 12150;
                }
                break;
            case 2: // 900 w E2-2
                if (*pakaiAir <= 10)
                {
                    biaya = 107000;
                }
                else if (*pakaiAir > 10 && *pakaiAir <= 20)
                {
                    biaya = *pakaiAir * 11350;
                }
                else if (*pakaiAir > 20)
                {
                    biaya = *pakaiAir * 12550;
                }
                break;
            case 3: // 1300 w E2-3
                if (*pakaiAir <= 10)
                {
                    biaya = 110000;
                }
                else if (*pakaiAir > 10 && *pakaiAir <= 20)
                {
                    biaya = *pakaiAir * 11650;
                }
                else if (*pakaiAir > 20)
                {
                    biaya = *pakaiAir * 13150;
                }
                break;
            case 4: // >1300 w E2-4
                if (*pakaiAir <= 10)
                {
                    biaya = 113000;
                }
                else if (*pakaiAir > 10 && *pakaiAir <= 20)
                {
                    biaya = *pakaiAir * 11950;
                }
                else if (*pakaiAir > 20)
                {
                    biaya = *pakaiAir * 13950;
                }
                break;

            default:
                break;
            }
            break;
        case 3: // >10
            switch (watt)
            {
            case 1: // 450 w E3-1
                if (*pakaiAir <= 10)
                {
                    biaya = 116000;
                }
                else if (*pakaiAir > 10 && *pakaiAir <= 20)
                {
                    biaya = *pakaiAir * 12250;
                }
                else if (*pakaiAir > 20)
                {
                    biaya = *pakaiAir * 14750;
                }
                break;
            case 2: // 900 w E3-2
                if (*pakaiAir <= 10)
                {
                    biaya = 119000;
                }
                else if (*pakaiAir > 10 && *pakaiAir <= 20)
                {
                    biaya = *pakaiAir * 12550;
                }
                else if (*pakaiAir > 20)
                {
                    biaya = *pakaiAir * 15050;
                }
                break;
            case 3: // 1300 w E3-3
                if (*pakaiAir <= 10)
                {
                    biaya = 122000;
                }
                else if (*pakaiAir > 10 && *pakaiAir <= 20)
                {
                    biaya = *pakaiAir * 12850;
                }
                else if (*pakaiAir > 20)
                {
                    biaya = *pakaiAir * 15850;
                }
                break;
            case 4: // >1300 w E3-4
                if (*pakaiAir <= 10)
                {
                    biaya = 125000;
                }
                else if (*pakaiAir > 10 && *pakaiAir <= 20)
                {
                    biaya = *pakaiAir * 13150;
                }
                else if (*pakaiAir > 20)
                {
                    biaya = *pakaiAir * 16650;
                }
                break;

            default:
                printf("Usaha - jalan 3");
                pause();
                break;
            }
            break;

        default:
            printf("Usaha - Jalan");
            break;
        }
        biaya += BPM_U;
        biaya += ADMIN_U;
        break;

    default:
        printf("menu error");
        pause();
        break;
    }

    denda_tempo(dendaptr);
    biaya += *dendaptr;
    *hargaptr = biaya;
}
void denda_tempo(int *var)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    if (tm.tm_mday > 20)
    {
        *var = DENDA;
    }
    else
    {
        *var = 0;
    }
}

void struk(float *AirPtr, int menu, int jalan, int watt, float harga, int denda, float air, char *namaptr)
{
    int temp;
    
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    intro();
    printf("\t||============================================||\n"); ///////;
    printf("\t||                                            ||\n");
    printf("\t||            \e[1mSTRUK PEMBAYARAN AIR\e[m            ||\n");
    printf("\t||                                            ||\n");
    printf("\t================================================\n"); ///////;
    printf("\t   Nama Pelanggan       : %s \n", namaptr);
    printf("\t   Tanggal Pembayaran   : %02d-%02d-%04d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    printf("\t   Waktu Pembayaran     : %02d:%02d:%02d\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
    printf("\n");

    printf("\t   Golongan             : ");
    if (menu == 1)
        printf("D%d-%d", jalan, watt);
    else if (menu == 2)
        printf("E%d-%d", jalan, watt);
    printf("\n");

    printf("\t   Pemakaian Air        : %0.2f M^3\n", air);
    printf("\n");
    printf("\t   Biaya Air            : Rp. %0.2f\n", *AirPtr);
    printf("\t   Denda                : Rp. %d \n", denda);

    printf("\t   BPM                  : Rp. ");
    if (menu == 1)
        temp = BPM_RT;
    else if (menu == 2)
        temp = BPM_U;
    printf("%d", temp);
    printf("\n");

    printf("\t   Biaya Administrasi   : Rp. ");

    if (menu == 1)
        temp = ADMIN_RT;
    else if (menu == 2)
        temp = ADMIN_U;
    printf("%d", temp);
    printf("\n");

    printf("\t================================================\n"); ///////;
    printf("\t   Total Harga          : Rp. %0.2f\n", harga);
    pause();

}
void File_struck(float AirPtr, int menu, int jalan, int watt, float harga, int denda, float air, char *namaptr){
    int temp;
    FILE *Fp;
    Fp = fopen("Struk_pelanggan.txt","w");

    
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    fprintf(Fp,"\t================================================\n"); //////);
    fprintf(Fp,"\t||                 Program PDAM               ||\n");
    fprintf(Fp,"\t||            PT. Blangkon Sejahtera          ||\n");
    fprintf(Fp,"\t||============================================||\n"); ///////;
    fprintf(Fp,"\t||                                            ||\n");
    fprintf(Fp,"\t||             STRUK PEMBAYARAN AIR           ||\n");
    fprintf(Fp,"\t||                                            ||\n");
    fprintf(Fp,"\t================================================\n"); ///////;
    fprintf(Fp,"\t   Nama Pelanggan       : %s \n", namaptr);
    fprintf(Fp,"\t   Tanggal Pembayaran   : %02d-%02d-%04d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    fprintf(Fp,"\t   Waktu Pembayaran     : %02d:%02d:%02d\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
    fprintf(Fp,"\n");

    fprintf(Fp,"\t   Golongan             : ");
    if (menu == 1)
        fprintf(Fp,"D%d-%d", jalan, watt);
    else if (menu == 2)
        fprintf(Fp,"E%d-%d", jalan, watt);
    fprintf(Fp,"\n");

    fprintf(Fp,"\t   Pemakaian Air        : %0.2f M^3\n", air);
    fprintf(Fp,"\n");
    fprintf(Fp,"\t   Biaya Air            : Rp. %0.2f\n", AirPtr);
    fprintf(Fp,"\t   Denda                : Rp. %d \n", denda);

    fprintf(Fp,"\t   BPM                  : Rp. ");
    if (menu == 1)
        temp = BPM_RT;
    else if (menu == 2)
        temp = BPM_U;
    fprintf(Fp,"%d", temp);
    fprintf(Fp,"\n");

    fprintf(Fp,"\t   Biaya Administrasi   : Rp. ");

    if (menu == 1)
        temp = ADMIN_RT;
    else if (menu == 2)
        temp = ADMIN_U;
    fprintf(Fp,"%d", temp);
    fprintf(Fp,"\n");

    fprintf(Fp,"\t================================================\n"); ///////;
    fprintf(Fp,"\t   Total Harga          : Rp. %0.2f\n", harga);

    fclose(Fp);
}

void File_txt(data_pelanggan *D, int menu){
    int temp;
    FILE *Fp;
    Fp = fopen("Struk_pelanggan.txt","w");

    
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    fprintf(Fp,"\t================================================\n"); //////);
    fprintf(Fp,"\t||                 Program PDAM               ||\n");
    fprintf(Fp,"\t||            PT. Blangkon Sejahtera          ||\n");
    fprintf(Fp,"\t||============================================||\n"); ///////;
    fprintf(Fp,"\t||                                            ||\n");
    fprintf(Fp,"\t||             STRUK PEMBAYARAN AIR           ||\n");
    fprintf(Fp,"\t||                                            ||\n");
    fprintf(Fp,"\t================================================\n"); ///////;
    fprintf(Fp,"\t   Nama Pelanggan       : %s \n", D->nama);
    fprintf(Fp,"\t   Tanggal Pembayaran   : %02d-%02d-%04d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    fprintf(Fp,"\t   Waktu Pembayaran     : %02d:%02d:%02d\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
    fprintf(Fp,"\n");

    fprintf(Fp,"\t   Golongan             : ");
    if (menu == 1)
        fprintf(Fp,"D%d-%d", D->UkuranJalan, D->watt);
    else if (menu == 2)
        fprintf(Fp,"E%d-%d", D->UkuranJalan, D->watt);
    fprintf(Fp,"\n");

    fprintf(Fp,"\t   Pemakaian Air        : %0.2f M^3\n", D->PemakaianAir);
    fprintf(Fp,"\n");
    fprintf(Fp,"\t   Biaya Air            : Rp. %0.2f\n", D->BiayaAir);
    fprintf(Fp,"\t   Denda                : Rp. %d \n", D->denda);

    fprintf(Fp,"\t   BPM                  : Rp. ");
    if (menu == 1)
        temp = BPM_RT;
    else if (menu == 2)
        temp = BPM_U;
    fprintf(Fp,"%d", temp);
    fprintf(Fp,"\n");

    fprintf(Fp,"\t   Biaya Administrasi   : Rp. ");

    if (menu == 1)
        temp = ADMIN_RT;
    else if (menu == 2)
        temp = ADMIN_U;
    fprintf(Fp,"%d", temp);
    fprintf(Fp,"\n");

    fprintf(Fp,"\t================================================\n"); ///////;
    fprintf(Fp,"\t   Total Harga          : Rp. %0.2f\n", D->TotalHarga);

    fclose(Fp);
    
}
