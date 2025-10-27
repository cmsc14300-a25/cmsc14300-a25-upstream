#include <stdio.h>

enum day_of_week {SUNDAY = 1, MONDAY, TUESDAY, WEDNESDAY,
                  THURSDAY, FRIDAY, SATURDAY};

enum ABC {A = 7, B, C = 8, D};

int main() {
    printf("Sunday: %d\n", SUNDAY);
    printf("Saturday: %d\n", SATURDAY); 
    
    printf("A: %d\n", A);
    printf("B: %d\n", B);
    printf("C: %d\n", C);  
    printf("D: %d\n", D);    

}                  