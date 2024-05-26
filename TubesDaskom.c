#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char username[50], pass[50];

struct pengurus
{
    int saldo;
} pengurus;

struct pelanggan
{
    char nama[50], no[50], username[50], pass[50];
    int tb, bb, usia, saldo;
} pelanggan;

struct riwayat
{
    char namaalat[50], namapelanggan[50];
    int lama, harga;
} riwayat;

struct alat
{
    char namaalat[50];
    int hargaalat;
} alat;

// funsi pengurus start
int loginpengurus();
int menupengurus();

int datapelanggan();
int hapuspelanggan();
int riwayatsewa();
int saldopengurus();

// alat
int menualat();
int lihatalat();
int tambahalat();
int hapusalat();
// alat

// funsi pengurus end

// fungsi pelanggan start
int mainpelanggan();
int registrasipelanggan();
int loginpelanggan();

int menupelanggan();
int sewaalat();
int kalkulator();
int topupsaldo();
int saldopelanggan();
// fungsi pelanggan end

// start main
int main()
{
    system("cls");
    int i;
    printf("Selamat Datang Di NgeGYM kuy\n\npress eny key to continue...\n\n");
    getchar();

    printf("Anda adalah...\n1. Pengurus\n2. Pelanggan\n3. Keluar\n");
    printf("Pilih : ");
    scanf("%d", &i);
    getchar();

    switch (i)
    {
    case 1:
        loginpengurus();
        break;

    case 2:
        mainpelanggan();
        break;

    case 3:
        printf("Terimakasih telah menggunakan aplikasi kami...\n\n");
        exit(0);
        break;

    default:
        printf("Mohon maaf pilihan tidak ada\n\n");
        main();
        break;
    }
}

// start program pengurus
int loginpengurus()
{
    int i = 3, a;
    printf("\n\nSelamat datang...\nsilahkan login...\n\n");

    while (i > 0)
    {
        printf("Masukan Username : ");
        gets(username);
        printf("Masukan Password : ");
        gets(pass);
        // if (strcmp(username, "admin") == 0 && strcmp(pass, "123") == 0)
        if (a == 1)
        {
            menupengurus();
            break;
        }
        else
        {
            printf("username atau password salah...\n\n");
            i--;
        }
    }
    if (i <= 0)
    {
        printf("kesempatan anda telah habis...\n");
    }
}

int menupengurus()
{
    int i;

    system("cls");
    printf("Selamat datang...\n\n");
    printf("Menu Pengurus :\n1. Melihat Data Pelanggan\n2. Menghapus Data Pelanggan\n3. Daftar Alat\n4. Melihat Saldo\n5. Riwayat Penyewaan\n6. Log Out");
    printf("\nPilih Menu : ");
    scanf("%d", &i);
    getchar();

    switch (i)
    {
    case 1:
        datapelanggan();
        break;
    case 2:
        hapuspelanggan();
        break;
    case 3:
        menualat();
        break;
    case 4:
        saldopengurus();
        break;
    case 5:
        riwayatsewa();
        break;
    case 6:
        main();
        break;
    default:
        printf("Mohon maaf pilihan tidak ada");
        menupengurus();
        break;
    }
}

int datapelanggan()
{

    FILE *filePelanggan;
    filePelanggan = fopen("Pelanggan.dat", "rb");
    if (filePelanggan == NULL)
    {
        printf("Gagal membuka file...");
        return -1;
    }
    while (fread(&pelanggan, sizeof(pelanggan), 1, filePelanggan))
    {
        printf("\nNama : %s", pelanggan.nama);
        printf("\nNo Telpon : %s", pelanggan.no);
        printf("\nUsia (tahun): %d", pelanggan.usia);
        printf("\nBerat Badan (kg): %d", pelanggan.bb);
        printf("\nTinggi Badan (cm): %d", pelanggan.tb);
        printf("\nUsername : %s", pelanggan.username);
        printf("\nSaldo : %s\n", pelanggan.saldo);
    }

    fclose(filePelanggan);

    printf("\n\npress eny key to back...");
    getchar();
    menupengurus();
}

int hapuspelanggan()
{

    FILE *filePelanggan;
    FILE *filePelanggan2;
    filePelanggan = fopen("Pelanggan.dat", "rb");

    if (filePelanggan == NULL)
    {
        printf("Gagal membuka file...");
        return -1;
    }
    else
    {
        filePelanggan2 = fopen("Pelanggan2.dat", "wb");
    }

    char hapus[100];
    printf("Nama yang di hapus : ");
    gets(hapus);

    while (fread(&pelanggan, sizeof(pelanggan), 1, filePelanggan) == 1)
    {
        if (strcmp(pelanggan.nama, hapus) != 0)
        {
            fread(&pelanggan, sizeof(pelanggan), 1, filePelanggan2);
            printf("data pelanggan telah terhapus...");
            menupengurus();
            break;
        }
        else
        {
            printf("gagal menghapus...");
            menupengurus();
            break;
        }
    }
    fclose(filePelanggan);
    fclose(filePelanggan2);
    remove("Pelanggan.dat");
    rename("Pelanggan2.dat", "Pelanggan.dat");
}

int menualat()
{
    int i;
    printf("Menu alat : \n1. Tambah alat\n2. Lihat alat\n3. Hapus alat\n4.kembali\n");
    printf("Pilih : ");
    scanf("%d", &i);
    getchar();

    switch (i)
    {
    case 1:
        tambahalat();
        break;
    case 2:
        lihatalat();
        break;
    case 3:
        hapusalat();
        break;
    case 4:
        menupengurus();
        break;

    default:
        printf("pilihan tidak tersedia");
        menualat();
        break;
    }
}

int saldopengurus()
{
}

int riwayatsewa()
{
}

// alat start
int tambahalat()
{
    FILE *daftaralat;
    daftaralat = fopen("daftaralat.dat", "ab");

    printf("Nama Alat : ");
    gets(alat.namaalat);
    printf("Harga : ");
    scanf("%d", &alat.hargaalat);

    fwrite(&alat, sizeof(alat), 1, daftaralat);
    fclose(daftaralat);
}

int lihatalat() {}

int hapusalat() {}
// alat end

// end program pengurus

// ===================================================================

// start program pelanggan
int mainpelanggan()
{
    system("cls");
    int i;
    printf("\n\nSelamat datang...\n\n");

    printf("Anda ingin...\n1. Registrasi\n2. Login\n");
    printf("Pilih : ");
    scanf("%d", &i);
    getchar();

    switch (i)
    {
    case 1:
        registrasipelanggan();
        break;
    case 2:
        loginpelanggan();
        break;

    default:
        printf("Mohon maaf pilihan tidak ada");
        mainpelanggan();
        break;
    }
}

int registrasipelanggan()
{
    FILE *filePelanggan;
    filePelanggan = fopen("Pelanggan.dat", "ab");

    printf("Nama : ");
    gets(pelanggan.nama);

    printf("Telp : ");
    gets(pelanggan.no);

    printf("Usia (tahun): ");
    scanf("%d", &pelanggan.usia);
    printf("Berat badan (kg): ");
    scanf("%d", &pelanggan.bb);
    printf("Tinggi badan (cm): ");
    scanf("%d", &pelanggan.tb);
    getchar();

    printf("Username : ");
    gets(pelanggan.username);

    printf("Password : ");
    gets(pelanggan.pass);

    fwrite(&pelanggan, sizeof(pelanggan), 1, filePelanggan);
    fclose(filePelanggan);

    loginpelanggan();
}

int loginpelanggan()
{
    FILE *filePelanggan;
    filePelanggan = fopen("Pelanggan.dat", "rb");

    int i = 3;
    printf("\n\nSelamat datang...\nsilahkan login...\n\n");

    while (fread(&pelanggan, sizeof(pelanggan), 1, filePelanggan))
    {
        while (i > 0)
        {
            printf("Masukan Username : ");
            gets(username);
            printf("Masukan Password : ");
            gets(pass);
            if (strcmp(username, pelanggan.username) == 0 && strcmp(pass, pelanggan.pass) == 0)
            {
                menupelanggan();
                break;
            }
            else
            {
                printf("\nusername atau password salah...\n\n");
            }
            i--;
            if (i <= 0)
            {
                printf("kesempatan anda telah habis...\n");
                main();
                break;
            }
        }
    }
    fclose(filePelanggan);
}

int menupelanggan()
{
    printf("\nSelamat datang...\n=== %s ===\n\n", pelanggan.nama);

    int i;
    printf("\nMenu pelanggan :\n1. Melihat alat\n2. Menyewa alat\n3. Kalkulator BIM\n4. Top Up saldo\n5. Lihat saldo\n6. Keluar");
    printf("\nPilih : ");
    scanf("%d", &i);

    switch (i)
    {
    case 1:
        lihatalat();
        break;
    case 2:
        sewaalat();
        break;

    case 3:
        kalkulator();
        break;

    case 4:
        topupsaldo();
        break;
    case 5:
        saldopelanggan();
        break;
    case 6:
        exit(0);
        break;
    default:
        printf("PIlihan tidak tersedia");
        menupelanggan();
        break;
    }
}

int sewaalat() {}

int kalkulator() {}

int topupsaldo()
{
    
}

int saldopelanggan() {}
// end program pelanggan
