/*************************************************************************
    > File Name: test.c
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年05月14日 星期二 23时14分28秒
 ************************************************************************/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct memory {
    int *begin;
    int *end;
};

void *sort(void *arg);

int main() {
    int N;
    scanf("%d", &N);
    int *source = malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d", source + i);
    }

    struct memory data = {source, source + N};
    pthread_t thr;
    pthread_create(&thr, NULL, sort, &data);
    pthread_join(thr, NULL);

	int tmp = source[0];
	printf("%d ",tmp);
	for(int i = 1; i < N; i++) {
		if(tmp != source[i]) {
			printf("%d ", tmp = source[i]);
		}
	}
    printf("\n");

    free(source);
    return 0;
}

void *sort(void *arg) {
    struct memory *data = (struct memory *)arg;
    int length = data->end - data->begin;
    if (length <= 1) {
        pthread_exit(NULL);
    }

    int *middle = data->begin + length / 2;
    struct memory left_data = {data->begin, middle};
    struct memory right_data = {middle, data->end};

    pthread_t thr[2];
    pthread_create(&thr[0], NULL, sort, &left_data);
    pthread_create(&thr[1], NULL, sort, &right_data);
    pthread_join(thr[0], NULL);
    pthread_join(thr[1], NULL);

    // Merge the sorted halves
    int *swp = malloc(sizeof(int) * length);
    int *left = data->begin;
    int *right = middle;
    int k = 0;

    while (left < middle && right < data->end) {
        if (*left <= *right) {
            swp[k++] = *left++;
        } else {
            swp[k++] = *right++;
        }
    }
    while (left < middle) {
        swp[k++] = *left++;
    }
    while (right < data->end) {
        swp[k++] = *right++;
    }

    memcpy(data->begin, swp, sizeof(int) * length);
    free(swp);
    pthread_exit(NULL);
}

