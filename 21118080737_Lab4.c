//Created by ilkay Samet ÖZTÜRK/ 21118080737
#include<stdio.h>
#include<locale.h>

// Odev fonksiyonu parametre olarak ödevler dizisini ve ödev sayısını alır.
void odev(float odevler[], int odevSayisi){
    //Kullanıcıdan ödev sayısı kez input istenir ve bunlar ödevler dizisine atanır.
    for(int i  = 0 ; i< odevSayisi ; i++){
        float odevNot;
        printf("Öğrencinin %d. ödev notunu giriniz: ",i+1);
        scanf("%f",&odevNot);
        while(odevNot<0 || odevNot>100){
            // Ödev notlarının 0 ile 100 arasında olma kontrolü yapılır.
            printf("Girilen not 0-100 arasında olmalıdır: ");
            scanf("%f",&odevNot);
        }
        odevler[i] = odevNot;
    }
    
}

// Hesapla fonksiyonu öğrenci numarasını ve ödev sayısını alır.
float calculate(char student_no[], int odevSayisi){
    
    //Ogrencileri bir yapıda tutmak için oluşturuldu.
    struct Ogrenci{
        float vizeNot ;
        float finalNot;
        float odevNotlari[odevSayisi];
        float odevOrtalama;
        float genelortalama;
    } ogrenci;
    
    
    
    // Burada ödevler dizisi, büyüklüğü ödev sayısı olacak şekilde başlatılır.
    float odevler[odevSayisi];
    float odevW = 0.3;
    float finalW;
    float midtermW;

    // Ödev sayısı 0'a eşitse sadece vize ve finalin ağırlıkları alınır.
    if(odevSayisi==0){
        midtermW=0.6;
        finalW= 0.4;
    }
    else{
        midtermW = 0.3;
        finalW = 0.4;
    }
    
    
    int midterm_grade;
    int final_grade;
    // Öğrencinin vize ve final notu kullanıcı doğru şekilde girene kadar sorulur.
    printf("%s numaralı Öğrenincinin vize notu:  ",student_no);
    scanf("%d",&midterm_grade);
    while((midterm_grade<0) || (midterm_grade>100)){
            printf("Girilen not 0-100 arasında olmalıdır: ");
            scanf("%d",&midterm_grade);
        }
    printf ("%s numaralı öğrencinin final notu: ",student_no);
    scanf("%d",&final_grade);
    while((final_grade<0) || (final_grade>100)){
            printf("Girilen not 0-100 arasında olmalıdır: ");
            scanf("%d",&final_grade);
        }
        
    ogrenci.vizeNot = midterm_grade;
    ogrenci.finalNot = final_grade;
    // Odev fonksiyonu çağılır ve ödevler kullanıcıdan istenerek ödevler dizisine atama yapılır.
    odev(odevler,odevSayisi);    
    float odevToplamNot = 0;
    for(int i  = 0 ; i  < odevSayisi ; i++){
        ogrenci.odevNotlari[i] = odevler[i];
        odevToplamNot+= odevler[i];
    }
    
    
    //Eğer ödev varsa veya yoksa farklı bir şekilde agırlık hesaplamak için.
    if(odevSayisi > 0 ){
        float odevOrtalama = odevToplamNot/odevSayisi;
        ogrenci.odevOrtalama = odevOrtalama;
        ogrenci.genelortalama = final_grade*finalW + midterm_grade * midtermW + odevOrtalama*odevW;
        
    }
    else{
        ogrenci.genelortalama = final_grade*finalW + midterm_grade* midtermW;  
    }
    
    
    if(odevSayisi>0){
        printf("%s numaralı öğrenci için ödev not ortalaması: %.2f",student_no,ogrenci.odevOrtalama);
        printf("\n");
        return ogrenci.genelortalama;
    }
    else{
        printf("\n");
        return ogrenci.genelortalama;
    }
    
}


int main() {
    setlocale(LC_ALL, "Turkish"); //  I used these settings for using Turkish characters.

    
    printf("**********************************\n");
    printf("NOT ORTALAMASI HESAPLAMA\n\n");

    float enYuksekOrtalama = 0 ;
    float enDusukOrtalama = 100;
    float toplamNot = 0;
    int ogrenciSayisi  = 0 ;
    
    int rakamlar[10] = {'0','1','2','3','4','5','6','7','8','9'};
    
    char student_no [9];
    char choice = '1';
    

    
    int odevSayisi = 0;
    printf("Lütfen dersin ödev sayısını giriniz: ");
    scanf("%d",&odevSayisi);
    
    //Odev sayisinin 0 ile 10 arasında olmasını kontrol eder.
    while(odevSayisi<0 || odevSayisi > 10 ){
        printf("Ödev sayisi 0 ile 10 arasında olmalıdır: ");
        scanf("%d",&odevSayisi);
    }

    while(choice!='0'){

    
        printf("Öğrencinin numarasını giriniz: ");
        scanf("%s",student_no);
        
        while(1){
            int counter = 0 ;
            for(int i = 0 ;student_no[i] != '\0'; i++){
                counter++;
            }
            if(counter!=9){
                printf("Öğrenci numarası 9 haneli olmalı : ");
                scanf("%s",student_no);
                continue;
            }
            for(int i = 0 ; student_no[i] != '\0' ; i++){
                int eslesme = 0;
                for(int j = 0 ; j < 10 ; j++){
                    if(student_no[i] == rakamlar[j]){
                        eslesme = 1;
                    }
                }
                if(eslesme == 0){
                    printf("Öğrenci numarası rakamlardan oluşmalı : ");
                    scanf("%s",student_no);
                    continue;
                }
            }
            break;
        }
        
        

        float ortalama = calculate(student_no,odevSayisi);
        ogrenciSayisi++;
        toplamNot += ortalama;
        
        // Yeni girilen öğrencinin notları diğer öğrencilere göre kontrol edilir.
        if(ortalama > enYuksekOrtalama){
            enYuksekOrtalama = ortalama;
        }
        if(ortalama < enDusukOrtalama){
            enDusukOrtalama = ortalama;
        }
        
        
        printf("%s numaralı öğrenciye ait genel not ortalaması:%.2f",student_no,ortalama);
        printf("\n\n");
        
        printf("Tekrar hesaplamak için 1, çıkmak için 0'a basınız:");

        
        // Hatalı karakter girişi kontrolü         
        while(1){
            char gecici[1000];
            scanf("%s",gecici);
        
            int counter = 0 ;
            for(int i = 0 ;gecici[i]!= '\0';i++){
                counter++;
            }
            
            if(counter==1 && (gecici[0] == '1' || gecici[0] == '0')){
                choice = gecici[0];
                break;
            }
            printf("Hatalı tuşlama yaptınız, tekrar deneyiniz: ");
            
        }
        
    }
    
    //Sınıf ortalaması toplam ortalamaların, öğrenci sayısına bölünmesiyle bulunur.
    float sinifOrtalamasi = toplamNot / ogrenciSayisi ;
    
    // Sınıftaki en yüksek not, en düşük not ve sınıf ortalaması yazdırılır.
    printf("Dersi alan %d öğrenci için en düşük not: %.2f\n",ogrenciSayisi,enDusukOrtalama);
    printf("Dersi alan %d öğrenci için en yüksek not: %.2f\n",ogrenciSayisi,enYuksekOrtalama);
    printf("Dersi alan %d öğrenci için sınıf ortalaması: %.2f\n", ogrenciSayisi,sinifOrtalamasi);
    
    printf("Programdan çıkılıyor...");

    return 0;
}



