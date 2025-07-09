#include <stdio.h>
#include <math.h>
#include "average.h"

#define EPSILON 0.01f

void test_case(const int *arr, int size, float expected, const char *description)
{
    float result = average(arr, size);
    int pass = fabsf(result - expected) < EPSILON;

    printf("=== Test: %s ===\n", description);
    printf("  Expected: %.2f\n", expected);
    printf("  Got     : %.2f\n", result);
    printf("  Result  : %s\n\n", pass ? "✅ PASS" : "❌ FAIL");
}

int main(void)
{
    // Case 1: Empty array
    int *test1 = NULL;
    test_case(test1, 0, 0.0f, "Empty array");

    // Case 2: All values within range
    int test2[] = {10, 20, 30};
    test_case(test2, 3, 20.0f, "All values in range");

    // Case 3: All values out of range (below)
    int test3[] = {-10, -5, -1};
    test_case(test3, 3, 0.0f, "All values below range");

    // Case 4: All values out of range (above)
    int test4[] = {101, 150, 999};
    test_case(test4, 3, 0.0f, "All values above range");

    // Case 5: Mixed valid and invalid values
    int test5[] = {10, -5, 50, 105, 30};
    test_case(test5, 5, 30.0f, "Mixed valid/invalid");

    // Case 6: Only one valid value
    int test6[] = {200, 100, 300};
    test_case(test6, 3, 100.0f, "One valid value (100)");

    // Case 7: Boundary values (0 and 100)
    int test7[] = {0, 50, 100};
    test_case(test7, 3, 50.0f, "Boundary values included");

    // Case 8: Large array of mixed values
    int test8[] = {1, 2, 3, 4, 5, 6, 7, 150, -10, 99, 100, 0};
    test_case(test8, 12, 22.7f, "Large array with mixed values");

    // Case 9: Array of all zeros (valid)
    int test9[] = {0, 0, 0};
    test_case(test9, 3, 0.0f, "All zero values");

    // Case 10: Negative array size (should not happen, but test for safety)
    test_case(test2, -5, 0.0f, "Negative size (invalid input)");

    return 0;
}
