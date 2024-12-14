#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592653589793

typedef struct {
    double real, imag;
} Complex;

Complex complex_add(Complex a, Complex b) {
    Complex result = {a.real + b.real, a.imag + b.imag};
    return result;
}

Complex complex_sub(Complex a, Complex b) {
    Complex result = {a.real - b.real, a.imag - b.imag};
    return result;
}

Complex complex_mul(Complex a, Complex b) {
    Complex result = {a.real * b.real - a.imag * b.imag, a.real * b.imag + a.imag * b.real};
    return result;
}

void fft(Complex *a, int n, int inv) {
    if (n <= 1) return;

    Complex *a0 = (Complex*)malloc(n / 2 * sizeof(Complex));
    Complex *a1 = (Complex*)malloc(n / 2 * sizeof(Complex));

    for (int i = 0; i < n / 2; i++) {
        a0[i] = a[i * 2];
        a1[i] = a[i * 2 + 1];
    }

    fft(a0, n / 2, inv);
    fft(a1, n / 2, inv);

    double angle = 2 * PI / n * (inv ? -1 : 1);
    Complex w = {1.0, 0.0};
    Complex wn = {cos(angle), sin(angle)};

    for (int i = 0; i < n / 2; i++) {
        Complex t = complex_mul(w, a1[i]);
        a[i] = complex_add(a0[i], t);
        a[i + n / 2] = complex_sub(a0[i], t);
        w = complex_mul(w, wn);
    }

    free(a0);
    free(a1);

    if (inv) {
        for (int i = 0; i < n; i++) {
            a[i].real /= n;
            a[i].imag /= n;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int size = 1 << n;  // 2^n
    Complex *f = (Complex*)malloc(size * sizeof(Complex));
    for (int i = 0; i < size; ++i) {
        scanf("%lf", &f[i].real);
        f[i].imag = 0.0;
    }

    fft(f, size, 0);

    Complex z = {0.0, 0.0};
    for (int k = 0; k < size; ++k) {
        double cos_k = cos(k);
        Complex term = {cos_k * f[k].real, cos_k * f[k].imag};
        z = complex_add(z, term);
    }

    printf("%.2lf %.2lf\n", z.real, z.imag);

    free(f);

    return 0;
}