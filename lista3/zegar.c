#include <stdio.h>
#include <time.h>

void Konwersja (int n)
{
    if(n/2!=0){
        Konwersja(n/2);
    }
    printf("%d",n%2);
}
void czas24h(){
    time_t t=time(NULL);
    struct tm tm =*localtime(&t);
    printf("Format 24h: %d:%d:%d \n",tm.tm_hour +1, tm.tm_min,tm.tm_sec);
}
void czas12h(){
    time_t t=time(NULL);
    struct tm tm =*localtime(&t);
    if(tm.tm_hour<12){
        printf("Format 12h: %d:%d:%d AM \n ",tm.tm_hour +1,tm.tm_min,tm.tm_sec);
    }
    else{
        printf("Format 12h: %d:%d:%d PM \n ",tm.tm_hour-12+1,tm.tm_min,tm.tm_sec);
    }
}
void czasBinarnie(){
    time_t t=time(NULL);
    struct tm tm =*localtime(&t);
    printf("Format Binary: \n");
    Konwersja(tm.tm_hour+1);
    printf(":");
    Konwersja(tm.tm_min);
    printf(":");
    Konwersja(tm.tm_sec);
}
void czasHexymalnie(){
    time_t t=time(NULL);
    struct tm tm =*localtime(&t);
    printf("Format Hex: 0x%x:0x%x:0x%x \n",tm.tm_hour +1, tm.tm_min,tm.tm_sec);
}
int main(){
    int wybor=0;
    printf("Zegar\n(1)24h\n(2)12h\n(3)Hex\n(4)Bin\n\n->");
    scanf("%d", &wybor);
    switch (wybor) {
        case 1:czas24h();break;
        case 2:czas12h();break;
        case 3:czasHexymalnie();break;
        case 4:czasBinarnie();break;
    }
       return 0;
}