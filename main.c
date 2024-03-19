#include <stdio.h>
#define BASE 30
#define MIDDLE 80
#define HIGH 130

int main() {
    int hour, min, sec,totalsec;
    int remainder = 0;
    float bill,tax;

    printf("Enter the hours, minutes and seconds of talk: ");
    scanf("%d %d %d", &hour, &min, &sec);

    totalsec = (hour * 3600) + (min * 60) + sec;
    printf("%d\n", totalsec);

    if (totalsec % 8 != 0) {
        remainder = totalsec % 8;
        totalsec = totalsec + (8 - remainder);
    }
    totalsec/=60;

    if (totalsec <= BASE){
        bill = BASE * 0.90;
        tax = bill*0.08;}
    else if (totalsec <= MIDDLE){
        bill = totalsec * 0.90;
        tax = (BASE*0.9)*0.08 + (totalsec-(BASE*0.9))*0.18;}
    else if (totalsec <= HIGH){
        bill = totalsec * 0.75;
        tax = (BASE*0.9)*0.08 + (totalsec-(BASE*0.9))*0.18;}
    else{
        bill = totalsec * 0.60;
        tax = (BASE*0.9)*0.08 + (totalsec-(BASE*0.9))*0.18;}

    printf("Taxes: %.2f TL\n",tax);
    printf("Total amount you need to pay is: %.2f TL\n", bill);
    printf("You need to pay in total: %.2f",tax+bill);

    return 0;
}
