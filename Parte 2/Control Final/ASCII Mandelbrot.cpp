#include <cstdio>

int main() {
	int t, i;
	char s[16];
	double mini, maxi, preci, minr, maxr, precr;
	if (scanf("%d", &t) != 1) return 0;
	while (t--) {
		scanf(" \"%[^\"]\" %lf %lf %lf %lf %lf %lf", s, &mini, &maxi, &preci, &minr, &maxr, &precr);
		s[12] = ' ';
		for (double a = mini; a <= maxi + 1e-8; a += preci, putchar('\n'))
			for (double b = minr; b <= maxr + 1e-8; b += precr) {
				float za = 0, zb = 0, ta;
				for (i = 0; i < 12 && (ta = za * za - zb * zb + b, zb = 2 * za * zb + a, za = ta, za * za + zb * zb <= 4); i++);
				putchar(s[i]);
		}
			if (t) putchar('\n');
	}
}
