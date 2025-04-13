#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#ifdef _WIN32
#include <windows.h>
#endif

int pesel, numer_tel, nr_domu;
char imie[40], nazwisko[40], adres[100], obywatelstwo[50], data_urodzenia[100], ulica[30];

void pasek(int moment) {
    const int dlugosc_paska = 50;
    int pos = (moment * dlugosc_paska) / 100;

    printf("\r[");
    for (int i = 0; i < dlugosc_paska; i++) {
        if (i < pos) {
            printf("=");
        } else if (i == pos) {
            printf(">");
        } else {
            printf(" ");
        }
    }
    printf("] %3d%%", moment);
    fflush(stdout);
}


void clear() {
    system("clear");
}

void dodaj_klienta() {
    FILE *dane;
    dane = fopen("panel.txt", "a");

    if (dane == NULL) {
        printf("Błąd!\n");
        exit(0);
    }
    // - - - - - - - - - - - - - - - - - - - - - - - >
    printf("Podaj imię: ");
    scanf("%s", imie);

    printf("Podaj nazwisko: ");
    scanf("%s", nazwisko);

    printf("Podaj ulicę zamieszkania: ");
    scanf("%s", ulica);

    printf("Podaj numer domu: ");
    scanf("%d", &nr_domu);

    printf("Podaj pesel: ");
    scanf("%d", &pesel);

    printf("Podaj datę urodzenia (np. 07/04/2000): ");
    scanf("%s", data_urodzenia);

    printf("Podaj numer telefonu: ");
    scanf("%d", &numer_tel);

    printf("Podaj obywatelstwo: ");
    scanf("%s", obywatelstwo);
    // - - - - - - - - - - - - - - - - - - - - - - - >

    fprintf(dane, "- - - - - - - - - - - - - - - - - - - - - -\n");
    fprintf(dane, "Imię: %s\n", imie);
    fprintf(dane, "Nazwisko: %s\n", nazwisko);
    fprintf(dane, "Ulica: %s\n", ulica);
    fprintf(dane, "Numer domu: %d\n", nr_domu);
    fprintf(dane, "Pesel: %d\n", pesel);
    fprintf(dane, "Data urodzenia: %s\n", data_urodzenia);
    fprintf(dane, "Numer telefonu: %d\n", numer_tel);
    fprintf(dane, "Obywatelstwo: %s\n", obywatelstwo);
    fprintf(dane, "- - - - - - - - - - - - - - - - - - - - - -\n\n");
    
    fclose(dane);

    // - - - - - - - - - - - - - - - - - - - - - - - >
    FILE *excel;
    excel = fopen("msexcel.txt", "a");

    if (excel == NULL) {
        printf("Błąd!\n");
        exit(0);
    }

    fprintf(excel, "%s; ", imie);
    fprintf(excel, "%s; ", nazwisko);
    fprintf(excel, "%s; ", ulica);
    fprintf(excel, "%d; ", nr_domu);
    fprintf(excel, "%d; ", pesel);
    fprintf(excel, "%s; ", data_urodzenia);
    fprintf(excel, "%d; ", numer_tel);
    fprintf(excel, "%s;\n", obywatelstwo);

    fclose(excel);
    
    // - - - - - - - - - - - - - - - - - - - - - - - >

    printf("Klient został dodany! Powracam do menu...\n");
    #ifdef _WIN32
    Sleep(470); // 100 ms
    #else
    usleep(470000); // 100000 us = 100 ms
    #endif

}

void klienci() {
    clear();
    FILE *wyswietlanie;

    wyswietlanie = fopen("panel.txt", "r");
    if (wyswietlanie == NULL) {
        printf("Błąd!\n");
    }

    char c;
    while((c = fgetc(wyswietlanie)) != EOF) {
        putchar(c);
    }
    fclose(wyswietlanie);
    printf("Kliknij losowy przycisk aby wrócić do menu!");
    getchar();
    getchar();
}

int main() {
    while(1) {
        #ifdef _WIN32
        system("chcp 65001");
        #endif
        clear();
        // - - - - - - - - >
        FILE *glowny;
        glowny = fopen("panel.txt", "a");

        if (glowny == NULL) {
            printf("Błąd!");
            return 1;
        } else {
            fclose(glowny);
        }

        FILE *export;
        export = fopen("msexcel.txt", "a");

        if (export == NULL) {
            printf("Błąd!");
            return 1;
        } else {
            fclose(export);
        }

        for(int i = 0; i < 100; i++) {
            pasek(i);
            
            #ifdef _WIN32
            Sleep(7); 
            #else
            usleep(7000);
            #endif
        }
        printf("\nŁadowanie zakończone!\n");
        #ifdef _WIN32
        Sleep(470); // 100 ms
        #else
        usleep(470000); // 100000 us = 100 ms
        #endif

        // - - - - - - - - >
        clear();
        printf("Baza klientów banku safara!\n\n");

        printf("1. Dodaj klienta\n");
        printf("2. Zobacz klientów\n");
        printf("3. Wyjście\n\n");

        int wybor;
        printf("Wybierz opcje (1 / 2 / 3): ");
        scanf("%d", &wybor);
        
        switch (wybor) {
            case 1:
                clear();
                dodaj_klienta();
                break;
            case 2:
                clear();
                klienci();
                break;
            case 3:
                printf("Zakończono program. Do widzenia!\n");
                exit(0);
                break;
            default:
                printf("Nieprawidłowy wybór! Spróbuj ponownie.\n");
                clear();
                break;
        }
    }
}