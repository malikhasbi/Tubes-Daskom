#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char username[50], pass[50];

struct
{
    int saldo;
} pengurus;

struct
{
    char nama[50], no[50], username[50], pass[50];
    int tb, bb, usia, saldo, lama, alat;
} pelanggan;

struct
{
    char namaalat[50], namapelanggan[50];
    int lama, harga;
} riwayat;

struct
{
    char namaalat[100];
    int hargaalat;
} alat;

// funsi pengurus start
int loginpengurus();
int menupengurus();
int daftaralat();
int lihatsaldo();
int riwayatsewa();
int datapelanggan();
int hapuspelanggan();
int tambahalat();
int hapusalat();
int editalat();
// funsi pengurus end

// fungsi pelanggan start
int mainpelanggan();
int registrasipelanggan();
int loginpelanggan();
int menupelanggan();
int lihatalat();
int sewaalat();
int kalkulator();
int topupsaldo();
int lihatsaldo2();
int riwayatsewa2();
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
    int i = 3, a = 1;
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
        daftaralat();
        break;
    case 4:
        lihatsaldo();
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

    FILE *daftarpelanggan;
    daftarpelanggan = fopen("daftarpelanggan.dat", "rb");
    if (daftarpelanggan == NULL)
    {
        printf("Gagal membuka file.");
        menupengurus();
        return -1;
    }
    if (fread(&pelanggan, sizeof(pelanggan), 1, daftarpelanggan) == 0)
    {
        printf("\ndata tidak tersedia...");
    }
    else
    {
        while (fread(&pelanggan, sizeof(pelanggan), 1, daftarpelanggan))
        {
            printf("\nNama : %s", pelanggan.nama);
            printf("\nNo Telpon : %s", pelanggan.no);
            printf("\nUsia (tahun): %d", pelanggan.usia);
            printf("\nBerat Badan (kg): %d", pelanggan.bb);
            printf("\nTinggi Badan (cm): %d", pelanggan.tb);
            printf("\nUsername : %s", pelanggan.username);
        }
        fclose(daftarpelanggan);
    }
    printf("\n\npress eny key to back...");
    getchar();
    menupengurus();
}

int hapuspelanggan()
{

    FILE *daftarpelanggan;
    FILE *daftarpelanggan2;
    daftarpelanggan = fopen("daftarpelanggan.dat", "rb");
    daftarpelanggan2 = fopen("daftarpelanggan2.dat", "wb");

    if (fread(&pelanggan, sizeof(pelanggan), 1, daftarpelanggan) == 0)
    {
        printf("\nTidak ada data yanng bisa dihapus...");
        printf("\n\npress eny key to back...");
        getchar();
        menupengurus();
    }
    else
    {
        char hapus[100];
        printf("Nama yang di hapus : ");
        gets(hapus);

        while (fread(&pelanggan, sizeof(pelanggan), 1, daftarpelanggan) == 1)
        {
            if (strcmp(pelanggan.nama, hapus) != 0)
            {
                fread(&pelanggan, sizeof(pelanggan), 1, daftarpelanggan2);
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
        fclose(daftarpelanggan);
        fclose(daftarpelanggan2);
        remove("daftarpelanggan.dat");
        rename("daftarpelanggan2.dat", "daftarpelanggan.dat");
    }
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
    printf("Alat telah ditambah...");
    menualat();
}

int hapusalat()
{
    FILE *daftaralat;
    FILE *daftaralat2;
    daftaralat = fopen("daftaralat.dat", "rb");
    daftaralat2 = fopen("daftaralat2.dat", "wb");

    if (fread(&alat, sizeof(alat), 1, daftaralat) == 0)
    {
        printf("\ndata tidak tersedia...");
    }

    char hapus[100];
    printf("Nama alat yang di hapus : ");
    gets(hapus);

    while (fread(&alat, sizeof(alat), 1, daftaralat))
    {
        if (strcmp(alat.namaalat, hapus) != 0)
        {
            fread(&alat, sizeof(alat), 1, daftaralat2);
            printf("data alat telah terhapus...");
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
    fclose(daftaralat);
    fclose(daftaralat2);
    remove("daftaralat.dat");
    rename("daftaralat2.dat", "daftaralat.dat");
}

int lihatsaldo()
{
    FILE *saldo;
    saldo = fopen("saldo.dat", "rb");
    if (saldo == NULL)
    {
        printf("Gagal membuka file.");
        menupengurus();
        return -1;
    }
    if (fread(&pengurus, sizeof(pengurus), 1, saldo) == 0)
    {
        printf("\ndata tidak tersedia...");
    }
    else
    {
        while (fread(&pengurus, sizeof(pengurus), 1, saldo))
        {

            printf("\nSaldo : %d", pengurus.saldo);
        }
        fclose(saldo);
    }
    printf("\n\npress eny key to back...");
    getchar();
    menupengurus();
}

int riwayatsewa()
{
    FILE *daftarriwayat;
    daftarriwayat = fopen("daftarriwayat.dat", "rb");
    if (daftarriwayat == NULL && daftaralat == NULL)
    {
        printf("Gagal membuka file.");
        menupengurus();
        return -1;
    }
    if (fread(&riwayat, sizeof(riwayat), 1, daftarriwayat) == 0)
    {
        printf("\ndata tidak tersedia...");
    }
    else
    {
        while (fread(&riwayat, sizeof(riwayat), 1, daftarriwayat))
        {
            printf("\nNama Pelanggan : %s", riwayat.namapelanggan);
            printf("\nNama alat : %s", riwayat.namaalat);
            printf("\nLama sewa : %d", riwayat.lama);
            printf("\nHarga %d: ", riwayat.harga);
        }
        fclose(daftarriwayat);
    }
    printf("\n\npress eny key to back...");
    getchar();
    menupengurus();
}

int editalat()
{
    FILE *daftaralat;
    FILE *daftaralat2;
    daftaralat = fopen("daftaralat.dat", "rb");
    daftaralat2 = fopen("daftaralat2.dat", "wb");

    if (fread(&alat, sizeof(alat), 1, daftaralat) == 0)
    {
        printf("\ndata tidak tersedia...");
    }

    int ketemu = 0, e;
    char edit[100];
    printf("Nama alat yang di edit : ");
    gets(edit);

    while (fread(&alat, sizeof(alat), 1, daftaralat) == 1)
    {
        if (strcmp(alat.namaalat, edit) == 0)
        {
            printf("Nama Alat : %s\n", alat.namaalat);
            printf("Harga: %s\n", alat.hargaalat);

            printf("\n\nEDIT MODE\nHarga : ");
            scanf("%d", &alat.hargaalat);
            ketemu = 1;

            printf("Yakin edit?\n1. YA");
            scanf("%d", &e);

            switch (e)
            {
            case 1:
                fread(&alat, sizeof(alat), 1, daftaralat2);
                printf("data alat telah teredit...");
                break;

            default:
                printf("pilihan tidak ada");
                menupengurus();
                break;
            }
            menupengurus();
            break;
        }
        else
        {
            printf("gagal mengedit...");
            menupengurus();
            break;
        }
    }
    fclose(daftaralat);
    fclose(daftaralat2);
    remove("daftaralat.dat");
    rename("daftaralat2.dat", "daftaralat.dat");
}
// end program pengurus

// start program pelanggan
int mainpelanggan()
{
    int i;
    printf("\n\n\nSelamat datang...\n\n");

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
    FILE *daftarpelanggan;
    daftarpelanggan = fopen("daftarPelanggan.dat", "ab");

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
    pelanggan.saldo = 0;

    printf("Username : ");
    gets(pelanggan.username);

    printf("Password : ");
    gets(pelanggan.pass);

    fwrite(&pelanggan, sizeof(pelanggan), 1, daftarpelanggan);
    fclose(daftarpelanggan);

    loginpelanggan();
}

int loginpelanggan()
{
    FILE *daftarpelanggan;
    daftarpelanggan = fopen("daftarPelanggan.dat", "rb");

    int i = 3;
    printf("\n\nSelamat datang...\nsilahkan login...\n\n");

    while (fread(&pelanggan, sizeof(pelanggan), 1, daftarpelanggan))
    {
        while (i > 0)
        {
            printf("Masukan Username : ");
            gets(username);
            printf("Masukan Password : ");
            gets(pass);
            if (strcmp(username, pelanggan.username) == 0 && strcmp(pass, pelanggan.pass) == 0)
            {
                printf("\nSelamat datang...\n\n");
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
}

int menupelanggan()
{
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
        lihatsaldo2();
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

int lihatalat()
{
    FILE *daftaralat;
    daftaralat = fopen("daftaralat.dat", "rb");
    if (daftaralat == NULL)
    {
        printf("Gagal membuka file.");
        return -1;
    }
    if (fread(&alat, sizeof(alat), 1, daftaralat) == 0)
    {
        printf("\ndata tidak tersedia...");
    }
    while (fread(&alat, sizeof(alat), 1, daftaralat))
    {
        printf("\nNama Alat : %s", alat.namaalat);
        printf("\nHarga Alat : %s", alat.hargaalat);
    }
    fclose(daftaralat);

    printf("\n\npress eny key to back...");
    getchar();
    menupelanggan();
}

int sewaalat()
{
    FILE *daftarriwayat;
    FILE *daftaralat;
    daftarriwayat = fopen("daftaralat.dat", "rb");
    daftarriwayat = fopen("daftarriwayat.dat", "ab");

    printf("Nama Alat : ");
    gets(riwayat.namaalat);
    printf("Waktu sewa : ");
    scanf("%d", &riwayat.lama);

    fwrite(&riwayat, sizeof(riwayat), 1, daftaralat);
    fclose(daftaralat);

    printf("\n\npress eny key to back...");
    getchar();
    menupelanggan();
}

int kalkulator(){
    
}
int lihatsaldo2(){
    FILE *saldo2;
    saldo2 = fopen("saldo2.dat", "rb");
    if (saldo2 == NULL)
    {
        printf("Gagal membuka file.");
        menupelanggan();
        return -1;
    }
    if (fread(&pelanggan, sizeof(pelanggan), 1, saldo2) == 0)
    {
        printf("\ndata tidak tersedia...");
    }
    else
    {
        while (fread(&pelanggan, sizeof(pelanggan), 1, saldo2))
        {

            printf("\nSaldo : %d", pelanggan.saldo);
        }
        fclose(saldo2);
    }
    printf("\n\npress eny key to back...");
    getchar();
    menupelanggan();
}
// end program pelanggan
