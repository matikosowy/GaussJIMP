#include "gauss.h"

/**
 * Zwraca 0 - eliminacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b) {
    // Sprawdzenie poprawności rozmiarów macierzy
    if (mat->r != mat->c || mat->r != b->r) {
        return 2;
    }

    int i, j, k;
    int n = mat->r;

    for (k = 0; k < n - 1; k++) {
        int max_index = k;
        for (i = k + 1; i < n; i++) {
            if (fabs(mat->data[i][k]) > fabs(mat->data[max_index][k])) {
                max_index = i;
            }
        }

        if (max_index != k) {
            for (j = k; j < n; j++) {
                double temp = mat->data[k][j];
                mat->data[k][j] = mat->data[max_index][j];
                mat->data[max_index][j] = temp;
            }
            double temp_b = b->data[k][0];
            b->data[k][0] = b->data[max_index][0];
            b->data[max_index][0] = temp_b;
        }

        if (mat->data[k][k] == 0) {
            return 1;
        }

        for (i = k + 1; i < n; i++) {
            double factor = mat->data[i][k] / mat->data[k][k];
            for (j = k; j < n; j++) {
                mat->data[i][j] -= factor * mat->data[k][j];
            }
            b->data[i][0] -= factor * b->data[k][0];
        }
    }

    return 0;
}
