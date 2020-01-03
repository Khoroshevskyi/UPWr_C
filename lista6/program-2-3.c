#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 20

typedef struct data {
    int age;
    char* name;
} data;

void print_struct(data arr[]){
    int i;
    for(i=0;i<SIZE;++i) {
        printf("%i %s\n",arr[i].age,arr[i].name);
    }
}
int sort_by_age(const void * a, const void * b) {
    return ( (const data*)a)-> age - ((const data*)b) -> age;
}

int sort_by_name(const void * a, const void * b) {
    return ((const data *) a)->name[0] - ((const data *) b)->name[0];
}

int compare_string_to_dict(const void *s, const void *d) {
    return strncmp(s, ((const data *) d)-> name, sizeof(((data *)0)-> name));
}

int main() {
    char* names[20] = {"Sophia", "Liam" , "Olivia", "Jackson", "Emma",	"Noah",
                        "Ava", "Aiden", "Aria",	"Grayson", "Isabella",	"Caden",
                        "Amelia", "Lucas", "Mia", "Elijah", "Riley", "Oliver",
                        "Aaliyah", "Muhammad"};
    data table[SIZE];
    int i;
    srand(time(NULL));

    for(i=0;i < SIZE;++i) {
        table[i].age =( rand() % 101);
        table[i].name = names[(rand() % 20)];
    }

    printf("Before sorting: \n");
    print_struct(table);
    qsort(table, SIZE, sizeof(data), sort_by_age);
    printf("\n Sort by age:\n");
    print_struct(table);
    qsort(table, SIZE, sizeof(data), sort_by_name);
    printf("\n Sort by name:\n");
    print_struct(table);

    data* result;
    char target[30] = "Oliver";

    result = bsearch(target, table, SIZE, sizeof(data), compare_string_to_dict);

    printf("\nPierwsze Imie z wiekiem o podanym wieku\n");
    printf("%i %s\n",result[0].age, result[0].name);

    return 0;
}
