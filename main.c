#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_POINTS 10   // Veri noktas� say�s�
#define BANDWIDTH 3     // �ekirdek bant geni�li�i

// Veri noktas�n� temsil eden yap�
typedef struct {
    float x;  // x koordinat�
    float y; // y koordinat�
} Point;

// �ki nokta aras�ndaki �klid uzakl���n� hesaplayan fonksiyon
float okliduzaklik(Point p1, Point p2) {
    float dx = p1.x - p2.x;
    float dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

// Ortalama kayd�rmal� k�meleme algoritmas�
void meanShift(Point* points) {
    int i, j;   
    float uzaklik, weightSum; // weightSum de�i�keni �evredeki noktalar�n a��rl�klar�n toplam�n� tutar
    Point shift, shiftedPoint;

    // K�me merkezi hesaplamalar�
    for (i = 0; i < NUM_POINTS; i++) {
        shift.x = 0;
        shift.y = 0;
        weightSum = 0;

        // �evredeki noktalar�n a��rl�kl� ortalamas�n� hesapla
        for (j = 0; j < NUM_POINTS; j++) {
            uzaklik = okliduzaklik(points[i], points[j]);
            
            // Noktalar�n �ekirdek bant geni�li�i i�erisinde olup olmad���n� kontrol et
            if (uzaklik <= BANDWIDTH) {
             // Noktan�n �evredeki noktalar taraf�ndan al�nan a��rl��� hesapla
                float weight = exp(-(uzaklik*uzaklik) / (2*BANDWIDTH*BANDWIDTH));
                  // A��rl�kland�r�lm�� noktan�n koordinatlar�n� topla
			    shift.x += points[j].x * weight;
                shift.y += points[j].y * weight;
           // A��rl�k toplam�n� g�ncelle
                weightSum += weight;
            }
        }

        // Kayd�r�lm�� nokta hesapla
        shiftedPoint.x = shift.x / weightSum;
        shiftedPoint.y = shift.y / weightSum;
        
        points[i] = shiftedPoint; // Yeni konumu g�ncelle
    }
}

int main() {
    int i;
    // Kullan�lcak koordinatlar tan�mlan�r
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

    meanShift(points);   // Fonksiyon �al��t�r�l�r

    printf("Kumeleme sonrasi noktalar:\n");
    for (i = 0; i < NUM_POINTS; i++) {
        printf("(%.2f, %.2f) ", points[i].x, points[i].y);
    }
    printf("\n");

    return 0;
}

