#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_POINTS 10   // Veri noktasý sayýsý
#define BANDWIDTH 3     // Çekirdek bant geniþliði

// Veri noktasýný temsil eden yapý
typedef struct {
    float x;  // x koordinatý
    float y; // y koordinatý
} Point;

// Ýki nokta arasýndaki öklid uzaklýðýný hesaplayan fonksiyon
float okliduzaklik(Point p1, Point p2) {
    float dx = p1.x - p2.x;
    float dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

// Ortalama kaydýrmalý kümeleme algoritmasý
void meanShift(Point* points) {
    int i, j;   
    float uzaklik, weightSum; // weightSum deðiþkeni çevredeki noktalarýn aðýrlýklarýn toplamýný tutar
    Point shift, shiftedPoint;

    // Küme merkezi hesaplamalarý
    for (i = 0; i < NUM_POINTS; i++) {
        shift.x = 0;
        shift.y = 0;
        weightSum = 0;

        // Çevredeki noktalarýn aðýrlýklý ortalamasýný hesapla
        for (j = 0; j < NUM_POINTS; j++) {
            uzaklik = okliduzaklik(points[i], points[j]);
            
            // Noktalarýn çekirdek bant geniþliði içerisinde olup olmadýðýný kontrol et
            if (uzaklik <= BANDWIDTH) {
             // Noktanýn çevredeki noktalar tarafýndan alýnan aðýrlýðý hesapla
                float weight = exp(-(uzaklik*uzaklik) / (2*BANDWIDTH*BANDWIDTH));
                  // Aðýrlýklandýrýlmýþ noktanýn koordinatlarýný topla
			    shift.x += points[j].x * weight;
                shift.y += points[j].y * weight;
           // Aðýrlýk toplamýný güncelle
                weightSum += weight;
            }
        }

        // Kaydýrýlmýþ nokta hesapla
        shiftedPoint.x = shift.x / weightSum;
        shiftedPoint.y = shift.y / weightSum;
        
        points[i] = shiftedPoint; // Yeni konumu güncelle
    }
}

int main() {
    int i;
    // Kullanýlcak koordinatlar tanýmlanýr
    Point points[NUM_POINTS] = {
        {1.0, 1.5},
        {2.0, 1.8},
        {2.5, 2.0},
        {3.5, 3.0},
        {4.0, 3.5},
        {5.0, 4.0},
        {5.5, 4.5},
        {6.0, 5.0},
        {6.5, 5.5},
        {7.0, 6.0}
    };

    printf("Baslangic noktalari:\n");
    for (i = 0; i < NUM_POINTS; i++) {
        printf("(%.2f, %.2f) ", points[i].x, points[i].y);
    }
    printf("\n");

    meanShift(points);   // Fonksiyon çalýþtýrýlýr

    printf("Kumeleme sonrasi noktalar:\n");
    for (i = 0; i < NUM_POINTS; i++) {
        printf("(%.2f, %.2f) ", points[i].x, points[i].y);
    }
    printf("\n");

    return 0;
}

