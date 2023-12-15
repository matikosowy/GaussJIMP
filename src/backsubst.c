#include "backsubst.h"

/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int backsubst(Matrix *x, Matrix *mat, Matrix *b) {
    if (mat->r != mat->c || mat->r != b->r || x->r != b->r || x->c != 1) {
        return 2;
    }
    int i, j;
    for (i = mat->r - 1; i >= 0; i--) {
        if (mat->data[i][i] == 0) {
            return 1;
        }
        x->data[i][0] = b->data[i][0] / mat->data[i][i];

        for (j = i - 1; j >= 0; j--) {
            b->data[j][0] -= mat->data[j][i] * x->data[i][0];
        }
    }
    return 0;
}


