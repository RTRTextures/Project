#include <stdlib.h>
#include <math.h>
#include "Perlin.h"

static int p[B + B + 2];
static double g3[B + B + 2][3];
static double g2[B + B + 2][2];
static double g1[B + B + 2];
static int start = 1;

void normalize2(double v[2])
{
    double s;

    s = sqrt(v[0] * v[0] + v[1] * v[1]);
    v[0] = v[0] / s;
    v[1] = v[1] / s;
}

void normalize3(double v[3])
{
    double s;

    s = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
    v[0] = v[0] / s;
    v[1] = v[1] / s;
    v[2] = v[2] / s;
}

void init(void)
{
    int i, j, k;

    for (i = 0; i < B; i++) {
        p[i] = i;
        g1[i] = (double)((rand() % (B + B)) - B) / B;

        for (j = 0; j < 2; j++)
            g2[i][j] = (double)((rand() % (B + B)) - B) / B;
        normalize2(g2[i]);

        for (j = 0; j < 3; j++)
            g3[i][j] = (double)((rand() % (B + B)) - B) / B;
        normalize3(g3[i]);
    }

    while (--i) {
        k = p[i];
        p[i] = p[j = rand() % B];
        p[j] = k;
    }

    for (i = 0; i < B + 2; i++) {
        p[B + i] = p[i];
        g1[B + i] = g1[i];
        for (j = 0; j < 2; j++)
            g2[B + i][j] = g2[i][j];
        for (j = 0; j < 3; j++)
            g3[B + i][j] = g3[i][j];
    }
}

double noise3(double vec[3])
{
    int bx0, bx1, by0, by1, bz0, bz1, b00, b10, b01, b11;
    double rx0, rx1, ry0, ry1, rz0, rz1, *q, sy, sz, a, b, c, d, t, u, v;
    int i, j;

    if (start) {
        start = 0;
        init();
    }

    setup(0, bx0, bx1, rx0, rx1);
    setup(1, by0, by1, ry0, ry1);
    setup(2, bz0, bz1, rz0, rz1);

    i = p[bx0];
    j = p[bx1];

    b00 = p[i + by0];
    b10 = p[j + by0];
    b01 = p[i + by1];
    b11 = p[j + by1];

    t = s_curve(rx0);
    sy = s_curve(ry0);
    sz = s_curve(rz0);

    q = g3[b00 + bz0]; u = at3(rx0, ry0, rz0);
    q = g3[b10 + bz0]; v = at3(rx1, ry0, rz0);
    a = lerp(t, u, v);

    q = g3[b01 + bz0]; u = at3(rx0, ry1, rz0);
    q = g3[b11 + bz0]; v = at3(rx1, ry1, rz0);
    b = lerp(t, u, v);

    c = lerp(sy, a, b);

    q = g3[b00 + bz1]; u = at3(rx0, ry0, rz1);
    q = g3[b10 + bz1]; v = at3(rx1, ry0, rz1);
    a = lerp(t, u, v);

    q = g3[b01 + bz1]; u = at3(rx0, ry1, rz1);
    q = g3[b11 + bz1]; v = at3(rx1, ry1, rz1);
    b = lerp(t, u, v);

    d = lerp(sy, a, b);

    return lerp(sz, c, d);
}