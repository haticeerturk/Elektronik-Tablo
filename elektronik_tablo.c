#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *matris[10][10];
int satir_sayisi;
int sutun_sayisi;

int formul_hesaplama(){
    int i,j,k,l,m,n,o,p,r,q;
    int formulSonucu = 0;
    int ilkDeger = 0;
    int ikinciDeger = 0;

    /*Formul parse islemi icin kullanilacak degiskenler*/
    char *degerler[50];
    char *degerlerTemp;
    int degerlerIndis = 0;

    int intDegerler[50];
    int intDegerlerIndis = 0;

    char temp[100];

    char *matrisTemp; //Formul olaylarinda kullanilacak. Cunku formul uzerinden parse yapilirsa ana degiskendeki(matris dizisindeki) formul bozuluyor.

    //matris[i][j][0] degeri ile elemanin formul olup olmadigi tespit edilir.
    //Eger [0] indislik karakteri '=' ise bu bir formul demektir.
    for(i=0; i<satir_sayisi; i++) {
      for(j=0; j<sutun_sayisi; j++) {
        int len = strlen(matris[i][j]); //Eleman boyutu
        if(matris[i][j][0] != '=') {//Formul degilse buraya girecek.
        }
        else { //Formul ise buraya girecek.
            memmove(&matris[i][j][0], &matris[i][j][1], strlen(matris[i][j])); //Formulun basindaki '=' karakteri silindi.
            char satirNo[2]; //1,2,3,4,5,6,7,8,9,10 olabilir.
            char sutunHarfi[2]; //A,B,C,D,E,F,G,H,I,J olabilir.
            char tempEleman[4] = ""; //A1, A2 ... B1, B6, D10 vs olabilir.
            char tempFormul[20];

            for(r=0; r<strlen(matris[i][j]); r++)
            {
                tempFormul[r] = matris[i][j][r];
            }
            tempFormul[r] = '\0';

            /*Formul icerisindeki degerler parse edilerek "degerler" dizisine alinir.*/
            matrisTemp = matris[i][j];
            degerlerTemp = strtok(matrisTemp,"-+/*");
            while(degerlerTemp!=NULL){
                degerler[degerlerIndis] = degerlerTemp;
                degerlerIndis++;
                degerlerTemp=strtok(NULL,"-+/*");
            }
            /*Formul icerisindeki degerler parse edilerek "degerler" dizisine alinir.*/
            for(l=0; l<satir_sayisi; l++) {

                if(l == 0)
                    strcpy(satirNo, "1");
                else if(l == 1)
                    strcpy(satirNo, "2");
                else if(l == 2)
                    strcpy(satirNo, "3");
                else if(l == 3)
                    strcpy(satirNo, "4");
                else if(l == 4)
                    strcpy(satirNo, "5");
                else if(l == 5)
                    strcpy(satirNo, "6");
                else if(l == 6)
                    strcpy(satirNo, "7");
                else if(l == 7)
                    strcpy(satirNo, "8");
                else if(l == 8)
                    strcpy(satirNo, "9");
                else if(l == 9)
                    strcpy(satirNo, "10");

                for(m=0; m<sutun_sayisi; m++) {
                    if(m == 0)
                        strcpy(sutunHarfi, "A");
                    else if(m == 1)
                        strcpy(sutunHarfi, "B");
                    else if(m == 2)
                        strcpy(sutunHarfi, "C");
                    else if(m == 3)
                        strcpy(sutunHarfi, "D");
                    else if(m == 4)
                        strcpy(sutunHarfi, "E");
                    else if(m == 5)
                        strcpy(sutunHarfi, "F");
                    else if(m == 6)
                        strcpy(sutunHarfi, "G");
                    else if(m == 7)
                        strcpy(sutunHarfi, "H");
                    else if(m == 8)
                        strcpy(sutunHarfi, "I");
                    else if(m == 9)
                        strcpy(sutunHarfi, "J");

                    strcpy(tempEleman, sutunHarfi);
                    strcat(tempEleman, satirNo);
                    for(n=0; n<degerlerIndis; n++)
                    {
                        if(strcmp(tempEleman, degerler[n]) == 0) {
                            intDegerler[intDegerlerIndis] = atoi(matris[l][m]);
                            intDegerlerIndis++;
                            break;
                        }
                    }
            int toplam = 0;
            int tempIndis = 0;

            for(r=0; r<strlen(tempFormul); r++) {
                    if(tempFormul[r] == '+')
                    {
                        if(tempIndis==0)
                            toplam = intDegerler[tempIndis] + intDegerler[tempIndis+1];
                        else
                            toplam += intDegerler[tempIndis+1];
                        tempIndis++;
                    }
                    else if(tempFormul[r] == '-')
                    {
                        if(tempIndis==0)
                            toplam = intDegerler[tempIndis] - intDegerler[tempIndis+1];
                        else
                            toplam -= intDegerler[tempIndis+1];
                        tempIndis++;
                    }
                    else if(tempFormul[r] == '*')
                    {
                        if(tempIndis==0)
                            toplam = intDegerler[tempIndis] * intDegerler[tempIndis+1];
                        else
                            toplam *= intDegerler[tempIndis+1];
                        tempIndis++;
                    }
                    else if(tempFormul[r] == '/')
                    {
                        if(tempIndis==0)
                            toplam = intDegerler[tempIndis] / intDegerler[tempIndis+1];
                        else
                            toplam /= intDegerler[tempIndis+1];
                        tempIndis++;
                    }
            }

                if(toplam < 688657)
                    sprintf(matris[i][j], "%d", toplam);
                toplam = 0;
                }
            }
        }

        degerlerIndis = 0;
        intDegerlerIndis = 0;
      }
    }
    printf("\n");

    printf("Formullerin hesaplandigi yeni matris:\n");
        for(i=0; i<satir_sayisi; i++) {
        for(j=0; j<sutun_sayisi; j++)
            printf("%s\t\t",matris[i][j]);
        printf("\n");
        }

    printf("Yeni bir işlem ister misiniz?(E/e/H/h) ");
    char cevap=getchar();
    scanf("%c", &cevap);

    if(cevap=='e' || cevap=='E'){
        return main();
        }
    else{
       return 0;
       }
}

int yeni_satir_ekleme() {

    if(satir_sayisi >= 10) {
        printf("Tablo 10 satira ulastigi icin daha fazla satir ekleme isleminiz sonlandirildi.\n");
        return 0;
    }

    int eklenecekSatirNumarasi = 0;
    int i,j;
    char eleman[20];
    char *yeniSatir[10];

    printf("Yeni satirin hangi satirdan sonra eklenmesini istiyorsunuz : ");
    scanf("%d", &eklenecekSatirNumarasi);
    while(eklenecekSatirNumarasi > satir_sayisi || eklenecekSatirNumarasi <= 0) {
        printf("Istediginiz satir tabloda bulunamadi, tekrar giriniz : ");
        scanf("%d", &eklenecekSatirNumarasi);
    }

    for(i=0; i<sutun_sayisi; i++) {
        printf("Yeni satir icin %d. sutunu girin: ", i+1);
        scanf("%s",eleman);
        yeniSatir[i]=strdup(eleman);
    }

    int kontrol = 0;
    for(i=0; i<satir_sayisi; i++) {
        for(j=0; j<sutun_sayisi; j++) {
            if(satir_sayisi-i == eklenecekSatirNumarasi) {
                matris[eklenecekSatirNumarasi][j] = yeniSatir[j];
                kontrol++;
            }
            else {
                matris[satir_sayisi-i][j] = matris[satir_sayisi-i-1][j];
            }
        }
        if(kontrol == sutun_sayisi)
            break;
    }

    satir_sayisi++;
    printf("Satir eklendikten sonraki yeni matris : \n");
    for(i=0; i<satir_sayisi; i++){
        for(j=0; j<sutun_sayisi; j++)
            printf("%s\t\t",matris[i][j]);
        printf("\n");
    }

    printf("Yeni bir işlem ister misiniz?(E/e/H/h) ");
    char cevap=getchar();
    scanf("%c", &cevap);

    if(cevap=='e' || cevap=='E'){
        return main();
        }
    else{
       return 0;
       }
}

int veri_filtrele() {
    int s,t,filtre;

    printf("Filtrelenmesini istediginiz veriyi girin:");
    scanf("%d",&filtre);

    for(s=0; s<satir_sayisi; s++) {
        for(t=0; t<sutun_sayisi; t++) {
            if(matris[s][t][0] != '=' && filtre >= atoi(matris[s][t]))
            {
                printf("!\t\t");
            }
            else {
                printf("%s\t\t",matris[s][t]);
            }
        }
        printf("\n");
    }

    printf("Yeni bir işlem ister misiniz?(E/e/H/h) ");
    char cevap=getchar();
    scanf("%c", &cevap);

    if(cevap=='e' || cevap=='E'){
        return main();
        }
    else{
       return 0;
       }
}

int hucre_guncelle() {
    int hucreSutunIndis = 0;
    int hucreSatirIndis = 0;
    int uygunluk = 0;
    char hucreSutun[2];
    char hucreSatir[2];
    char yeniDeger[20];

    while(uygunluk != 1)
    {
        printf("Degistirilmek istenen hucrenin sutun degerini giriniz: ");
        scanf("%s", &hucreSutun);

        if(hucreSutun[0] == 'A')
            hucreSutunIndis = 0;
        else if(hucreSutun[0] == 'B')
            hucreSutunIndis = 1;
        else if(hucreSutun[0] == 'C')
            hucreSutunIndis = 2;
        else if(hucreSutun[0] == 'D')
            hucreSutunIndis = 3;
        else if(hucreSutun[0] == 'E')
            hucreSutunIndis = 4;
        else if(hucreSutun[0] == 'F')
            hucreSutunIndis = 5;
        else if(hucreSutun[0] == 'G')
            hucreSutunIndis = 6;
        else if(hucreSutun[0] == 'H')
            hucreSutunIndis = 7;
        else if(hucreSutun[0] == 'I')
            hucreSutunIndis = 8;
        else if(hucreSutun[0] == 'J')
            hucreSutunIndis = 9;

        printf("Degistirilmek istenen hucrenin satir degerini giriniz: ");
        scanf("%s", &hucreSatir);

        if(hucreSatir[0] == '1')
            hucreSatirIndis = 0;
        else if(hucreSatir[0] == '2')
            hucreSatirIndis = 1;
        else if(hucreSatir[0] == '3')
            hucreSatirIndis = 2;
        else if(hucreSatir[0] == '4')
            hucreSatirIndis = 3;
        else if(hucreSatir[0] == '5')
            hucreSatirIndis = 4;
        else if(hucreSatir[0] == '6')
            hucreSatirIndis = 5;
        else if(hucreSatir[0] == '7')
            hucreSatirIndis = 6;
        else if(hucreSatir[0] == '8')
            hucreSatirIndis = 7;
        else if(hucreSatir[0] == '9')
            hucreSatirIndis = 8;
        else if(hucreSatir[0] == '10')
            hucreSatirIndis = 9;

        if(!(hucreSutunIndis >= 0 && hucreSutunIndis < sutun_sayisi && hucreSatirIndis < satir_sayisi && hucreSatirIndis >= 0)) {
            printf("Girdiginiz degerlerde bir hucre bulunamadi. Lutfen tekrar giriniz.\n");
            uygunluk = 0;
        }
        else {
            uygunluk = 1;
        }
    }

    printf("Hucrenin yeni degerini giriniz: ");
    scanf("%s", &yeniDeger);

    matris[hucreSatirIndis][hucreSutunIndis] = yeniDeger;

    printf("\nGuncellenen matris :\n");
    int j,i;
    for(i=0; i<satir_sayisi; i++){
    for(j=0; j<sutun_sayisi; j++)
        printf("%s\t\t",matris[i][j]);
    printf("\n");
    }

    printf("Yeni bir işlem ister misiniz?(E/e/H/h) ");
    char cevap=getchar();
    scanf("%c", &cevap);

    if(cevap=='e' || cevap=='E'){
        return main();
        }
    else{
       return 0;
       }
}


int satir_sil() {
    int silinecekSatir;
    int uygunluk = 0;

    while(uygunluk != 1) {
        printf("Silmek istediginiz satir numarasini giriniz: ");
        scanf("%d", &silinecekSatir);
        silinecekSatir -= 1; //Indis tipinde hesaplama yapilacagi icin.
        if(!(silinecekSatir >= 0 && silinecekSatir < satir_sayisi))
        {
            printf("Böyle bir satir bulunamadi. \n");
            uygunluk = 0;
        }
        else {
            uygunluk = 1;
        }
    }

    int j,i,k,l;
    for(i=0; i<satir_sayisi+1; i++){
        for(j=0; j<sutun_sayisi; j++) {
            matris[silinecekSatir][j] = matris[silinecekSatir+1][j];
        }
        silinecekSatir++;
    }

    satir_sayisi--; //Satir sayisi bir azaltilir.

    printf("\nGuncellenen matris :\n");
    for(i=0; i<satir_sayisi; i++){
    for(j=0; j<sutun_sayisi; j++)
        printf("%s\t\t",matris[i][j]);
    printf("\n");
    }

    printf("Yeni bir işlem ister misiniz?(E/e/H/h) ");
    char cevap=getchar();
    scanf("%c", &cevap);

    if(cevap=='e' || cevap=='E'){
        return main();
        }
    else{
       return 0;
       }
}

int cikis(){
    int cevap;
    do
    {
        printf("Cikis yapmak istediginize emin misiniz?(E/e/H/h) ");
        cevap=getchar();
        scanf("%c", &cevap);
    }
    while(cevap!='e' && cevap!='E' && cevap!='h' && cevap!='H');
        if(cevap=='e' || cevap=='E'){
        return 0;
        }
    else{
       return main();
       }
}

int main()
{
    char girdi[] = "4,3,10,34,37,=A1+B1+C1,40,17,34,=A2+B2+C2,=A1+A2,=B1+B2,=C1+C2,=D1+D2";
    char *temp; //virgule kadar kesilecek katari tutmak icin.
    char *parse_girdi[25]; //kesilen temp katarlarini tutacak olan dizi.
    int gS=0, i=0, j=0; //gS : girdi Sayisi.
    int secim;

    temp = strtok(girdi,",");

    while(temp!=NULL){
         parse_girdi[gS] = temp;
         gS++;
         temp=strtok(NULL,",");
    }

    //atoi() fonksiyonu ile string ifade integer ifadeye donusturulur.
    sutun_sayisi = atoi(parse_girdi[0]);
    satir_sayisi = atoi(parse_girdi[1]);

    //parse_girdi[2]-parse_girdi[3]-parse_girdi[4]-parse_girdi[5]
    //parse_girdi[6]-parse_girdi[7]-parse_girdi[8]-parse_girdi[9]
    //...
    //parse edilen girdiler yukaridaki sekilde matrise atanir. (ornek olarak 4,3 boyutlarında matris.)
    for(i=0;i<satir_sayisi;i++){
      for(j=0;j<sutun_sayisi;j++){
        matris[i][j] = parse_girdi[j+2+(i*4)];
      }
    }

    printf("********************************************\n");
    printf("Parse edilerek duzenlenen matris:\n");
    for(i=0; i<satir_sayisi; i++){
    for(j=0; j<sutun_sayisi; j++)
        printf("%s\t\t",matris[i][j]);
    printf("\n");
    }
    printf("********************************************\n\n");

    printf("Lütfen aşağıdaki menü den yapmak istediğiniz seçimi belirleyin...\n");
    printf("1. Formül Hesaplama\n");
    printf("2. Yeni Satır Ekleme\n");
    printf("3. Satır Silme\n");
    printf("4. Değer Girme Veya Güncelleme\n");
    printf("5. Veri Filtreleme\n");
    printf("6. Çıkış\n");
    printf("Yukarıdaki Seçeneklerden Hangisini Yapmak İstediğinizi Girin: ");
    scanf("%d",&secim);

    switch(secim){
        case 1:
            formul_hesaplama();
            break;
        case 2:
            yeni_satir_ekleme();
            break;
        case 3:
            satir_sil();
            break;
        case 4:
            hucre_guncelle();
            break;
        case 5:
            veri_filtrele();
            break;
        case 6:
            cikis();
            break;
    }

    return 0;
}
