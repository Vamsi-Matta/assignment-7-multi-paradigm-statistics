#include <stdio.h>
#include <stdlib.h>

int compare_ints(const void *a, const void *b) {
    int x = *(const int *)a, y = *(const int *)b;
    return (x > y) - (x < y);
}

double calculate_mean(const int *numbers, int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++) sum += numbers[i];
    return (double)sum / n;
}

double calculate_median(const int *sorted, int n) {
    if (n % 2) return sorted[n / 2];
    return ((double)sorted[n / 2 - 1] + sorted[n / 2]) / 2.0;
}

void print_modes(const int *sorted, int n) {
    int highest = 0;
    for (int i = 0; i < n;) {
        int j = i + 1;
        while (j < n && sorted[j] == sorted[i]) j++;
        if (j - i > highest) highest = j - i;
        i = j;
    }
    if (highest == 1) { puts("Mode: No mode (all values occur once)"); return; }
    printf("Mode(s): ");
    for (int i = 0, first = 1; i < n;) {
        int j = i + 1;
        while (j < n && sorted[j] == sorted[i]) j++;
        if (j - i == highest) {
            printf("%s%d", first ? "" : ", ", sorted[i]);
            first = 0;
        }
        i = j;
    }
    printf(" (frequency: %d)\n", highest);
}

int main(void) {
    int n;
    printf("How many integers? ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 10000) {
        fprintf(stderr, "Enter a count between 1 and 10000.\n");
        return 1;
    }
    int *numbers = malloc((size_t)n * sizeof(*numbers));
    if (!numbers) { fprintf(stderr, "Memory allocation failed.\n"); return 1; }
    printf("Enter %d integers separated by spaces: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &numbers[i]) != 1) {
            fprintf(stderr, "Invalid integer input.\n");
            free(numbers);
            return 1;
        }
    }
    double mean = calculate_mean(numbers, n);
    qsort(numbers, (size_t)n, sizeof(*numbers), compare_ints);
    printf("Mean: %.2f\n", mean);
    printf("Median: %.2f\n", calculate_median(numbers, n));
    print_modes(numbers, n);
    free(numbers);
    return 0;
}
