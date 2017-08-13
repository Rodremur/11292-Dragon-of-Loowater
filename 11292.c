/*-------------------------------------------------------
 * Tarea de Analisis de Algoritmos: 11292 - Dragon of Loowater
 * Fecha: 30-03-2016
 * Autor:
 *      A01064215 Rodrigo Reyes Murillo
 */

#include <stdio.h>

int n, m, i, h, k, sum;
int heads[20000];
int knights[20000];

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main(int argc, char const *argv[])
{
	while (scanf("%d %d", &n, &m) != EOF && (n || m)) {
			for (i = 0; i < n; i++) {
				scanf("%d", &heads[i]);
			}
			for (i = 0; i < m; i++) {
				scanf("%d", &knights[i]);
			}

			qsort(heads, n, sizeof(int), compare);
			qsort(knights, m, sizeof(int), compare);

			k = 0;
			h = 0;
			sum = 0;
			while(k < m) {
                if (h >= n) {
                    k += 1;
                } else {
                    if (knights[k] >= heads[h]) {
                        sum += knights[k];
                        k += 1;
                        h += 1;
                    } else {
                        k += 1;
                    }
                }
			}
			if (h < n) {
				printf("Loowater is doomed!\n");
			} else {
				printf("%d\n", sum);
			}
	}
    return 0;
}
