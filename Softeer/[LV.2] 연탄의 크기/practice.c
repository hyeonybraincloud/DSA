#include <stdio.h>
#include <stdlib.h>

#define n_MAX 100

typedef struct __Radius {
    int r;
    int cnt;
} Radius;

// ���� Ž�� (�迭�� ũ�� �����Ƿ� �� ����� �� ����)
int find_index(Radius rr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (rr[i].r == target) return i;
    }
    return -1;
}

// �� �Լ� (ī��Ʈ ���� �������� ����)
int compare(const void* a, const void* b) {
    return ((Radius*)b)->cnt - ((Radius*)a)->cnt;
}

int heater[n_MAX];
Radius radius[n_MAX];

int main(void) {
    int n;
    int count = 0;  // radius �迭�� ���� ��� ũ��

    scanf("%d", &n);

    for (int idx = 0; idx < n; idx++)
        scanf("%d", &heater[idx]);

    // ������ ������ ���� �м�
    for (int idx = 0; idx < n; idx++) {
        for (int i = 2; i <= heater[idx]; i++) {
            if (heater[idx] % i == 0) {
                int where = find_index(radius, count, i);

                if (where == -1) {  // ���ο� ���̸� �߰�
                    radius[count].r = i;
                    radius[count].cnt = 1;  // �ݵ�� 1�� �ʱ�ȭ
                    count++;
                }
                else {
                    radius[where].cnt++;  // ���� ���̸� ���� ����
                }
            }
        }
    }

    // ���� (���� ���� ������ �������� �ֿ켱)
    qsort(radius, count, sizeof(Radius), compare);

    // ��� ���
    printf("%d\n", radius[0].cnt);

    return 0;
}
