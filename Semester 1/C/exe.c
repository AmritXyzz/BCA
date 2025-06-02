-----FCFS-----


#include <stdio.h>

int main() {
    int n, i, j;
    printf("No. of procs: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], wt[n], tat[n];
    
    for(i = 0; i < n; i++) {
        pid[i] = i+1;
        printf("AT & BT of P%d: ", pid[i]);
        scanf("%d%d", &at[i], &bt[i]);
    }

    // Sort by arrival time
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(at[i] > at[j]) {
                int t;
                t = at[i]; at[i] = at[j]; at[j] = t;
                t = bt[i]; bt[i] = bt[j]; bt[j] = t;
                t = pid[i]; pid[i] = pid[j]; pid[j] = t;
            }
        }
    }

    int time = 0;
    float sum_wt = 0, sum_tat = 0;

    for(i = 0; i < n; i++) {
        if(time < at[i]) time = at[i];
        wt[i] = time - at[i];
        time += bt[i];
        tat[i] = wt[i] + bt[i];

        sum_wt += wt[i];
        sum_tat += tat[i];
    }

    printf("\nPID\tAT\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], wt[i], tat[i]);

    printf("\nAvg WT: %.2f", sum_wt/n);
    printf("\nAvg TAT: %.2f\n", sum_tat/n);

    return 0;
}



-----SJF-----


#include <stdio.h>

int main() {
    int n, i, j;
    printf("No. of procs: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], wt[n], tat[n], done[n];
    for(i = 0; i < n; i++) {
        pid[i] = i+1;
        printf("AT & BT of P%d: ", pid[i]);
        scanf("%d%d", &at[i], &bt[i]);
        done[i] = 0;
    }

    int time = 0, cnt = 0;
    float sum_wt = 0, sum_tat = 0;

    while(cnt < n) {
        int idx = -1, min_bt = 9999;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && !done[i] && bt[i] < min_bt) {
                min_bt = bt[i];
                idx = i;
            }
        }

        if(idx == -1) {
            time++;
            continue;
        }

        wt[idx] = time - at[idx];
        time += bt[idx];
        tat[idx] = wt[idx] + bt[idx];
        done[idx] = 1;
        cnt++;

        sum_wt += wt[idx];
        sum_tat += tat[idx];
    }

    printf("\nPID\tAT\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], wt[i], tat[i]);

    printf("\nAvg WT: %.2f", sum_wt/n);
    printf("\nAvg TAT: %.2f\n", sum_tat/n);

    return 0;
}



-----SRTF-----


#include <stdio.h>

int main() {
    int n, i;
    printf("No. of procs: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], rt[n], ct[n], wt[n], tat[n];
    for(i = 0; i < n; i++) {
        pid[i] = i+1;
        printf("AT & BT of P%d: ", pid[i]);
        scanf("%d%d", &at[i], &bt[i]);
        rt[i] = bt[i]; // Remaining time
    }

    int done = 0, time = 0, min_rt, idx;
    float sum_wt = 0, sum_tat = 0;

    while(done < n) {
        idx = -1;
        min_rt = 9999;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0 && rt[i] < min_rt) {
                min_rt = rt[i];
                idx = i;
            }
        }

        if(idx != -1) {
            rt[idx]--;
            if(rt[idx] == 0) {
                done++;
                ct[idx] = time + 1;
                tat[idx] = ct[idx] - at[idx];
                wt[idx] = tat[idx] - bt[idx];
                sum_wt += wt[idx];
                sum_tat += tat[idx];
            }
        }

        time++;
    }

    printf("\nPID\tAT\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], wt[i], tat[i]);

    printf("\nAvg WT: %.2f", sum_wt/n);
    printf("\nAvg TAT: %.2f\n", sum_tat/n);

    return 0;
}



-----PRIORITY-----



#include <stdio.h>

int main() {
    int n, i, j;
    printf("No. of procs: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], pr[n], wt[n], tat[n], done[n];
    for(i = 0; i < n; i++) {
        pid[i] = i+1;
        printf("AT BT PR of P%d: ", pid[i]);
        scanf("%d%d%d", &at[i], &bt[i], &pr[i]);
        done[i] = 0;
    }

    int time = 0, cnt = 0;
    float sum_wt = 0, sum_tat = 0;

    while(cnt < n) {
        int idx = -1, high = 9999;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && !done[i] && pr[i] < high) {
                high = pr[i];
                idx = i;
            }
        }

        if(idx == -1) {
            time++;
            continue;
        }

        wt[idx] = time - at[idx];
        time += bt[idx];
        tat[idx] = wt[idx] + bt[idx];
        done[idx] = 1;
        cnt++;

        sum_wt += wt[idx];
        sum_tat += tat[idx];
    }

    printf("\nPID\tAT\tBT\tPR\tWT\tTAT\n");
    for(i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], pr[i], wt[i], tat[i]);

    printf("\nAvg WT: %.2f", sum_wt/n);
    printf("\nAvg TAT: %.2f\n", sum_tat/n);

    return 0;
}



-----ROUND ROBIN-----


#include <stdio.h>

int main() {
    int n, tq, i;
    printf("No. of procs: ");
    scanf("%d", &n);
    printf("Time Quantum: ");
    scanf("%d", &tq);

    int pid[n], at[n], bt[n], rt[n], wt[n], tat[n], done[n];
    for(i = 0; i < n; i++) {
        pid[i] = i+1;
        printf("AT & BT of P%d: ", pid[i]);
        scanf("%d%d", &at[i], &bt[i]);
        rt[i] = bt[i];
        done[i] = 0;
    }

    int time = 0, cnt = 0;
    float sum_wt = 0, sum_tat = 0;

    while(cnt < n) {
        int flag = 0;
        for(i = 0; i < n; i++) {
            if(rt[i] > 0 && at[i] <= time) {
                flag = 1;
                int run = rt[i] < tq ? rt[i] : tq;
                rt[i] -= run;
                time += run;

                if(rt[i] == 0) {
                    done[i] = 1;
                    cnt++;
                    tat[i] = time - at[i];
                    wt[i] = tat[i] - bt[i];
                    sum_wt += wt[i];
                    sum_tat += tat[i];
                }
            }
        }
        if(!flag) time++; // CPU idle
    }

    printf("\nPID\tAT\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], wt[i], tat[i]);

    printf("\nAvg WT: %.2f", sum_wt/n);
    printf("\nAvg TAT: %.2f\n", sum_tat/n);

    return 0;
}



-----BANKER'S-----



#include <stdio.h>

int main() {
    int n, m, i, j, k;
    printf("No. of processes: ");
    scanf("%d", &n);
    printf("No. of resources: ");
    scanf("%d", &m);

    int alloc[n][m], max[n][m], need[n][m], avail[m];
    int f[n], ans[n], ind = 0;

    printf("Enter Allocation matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Max matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter Available resources:\n");
    for (i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    for (i = 0; i < n; i++) {
        f[i] = 0;
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }

    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    for (j = 0; j < m; j++)
                        avail[j] += alloc[i][j];
                    ans[ind++] = i;
                    f[i] = 1;
                }
            }
        }
    }

    int safe = 1;
    for (i = 0; i < n; i++)
        if (f[i] == 0)
            safe = 0;

    if (safe) {
        printf("Safe Seq: ");
        for (i = 0; i < n; i++)
            printf("P%d ", ans[i]);
    } else {
        printf("No Safe Sequence Found.");
    }

    return 0;
}



-----FIFO PR-----


#include <stdio.h>

int main() {
    int f, n, i, j, pg[50], frm[10], idx = 0, hit = 0, flg;

    printf("Enter no. of frames: ");
    scanf("%d", &f);
    printf("Enter no. of pages: ");
    scanf("%d", &n);
    printf("Enter page ref str: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pg[i]);

    for(i = 0; i < f; i++) frm[i] = -1;

    for(i = 0; i < n; i++) {
        flg = 0;
        for(j = 0; j < f; j++) {
            if(frm[j] == pg[i]) {
                hit++;
                flg = 1;
                break;
            }
        }
        if(flg == 0) {
            frm[idx] = pg[i];
            idx = (idx + 1) % f;
        }

        // Show current frame content
        printf("Frm: ");
        for(j = 0; j < f; j++) {
            if(frm[j] != -1)
                printf("%d ", frm[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("Total hits: %d\n", hit);
    printf("Total faults: %d\n", n - hit);

    return 0;
}



-----LRU PR-----


#include <stdio.h>

int main() {
    int f, n, i, j, k, pg[50], frm[10], used[10], hit = 0, min, pos;

    printf("Enter no. of frames: ");
    scanf("%d", &f);
    printf("Enter no. of pages: ");
    scanf("%d", &n);
    printf("Enter page ref str: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pg[i]);

    for(i = 0; i < f; i++) frm[i] = -1;

    for(i = 0; i < n; i++) {
        int flg = 0;
        for(j = 0; j < f; j++) {
            if(frm[j] == pg[i]) {
                hit++;
                flg = 1;
                break;
            }
        }
        if(flg == 0) {
            if(i < f)
                frm[i] = pg[i];
            else {
                for(j = 0; j < f; j++) {
                    used[j] = 0;
                    for(k = i - 1; k >= 0; k--) {
                        if(pg[k] == frm[j]) {
                            used[j] = i - k;
                            break;
                        }
                    }
                }
                min = used[0];
                pos = 0;
                for(j = 1; j < f; j++) {
                    if(used[j] > min) {
                        min = used[j];
                        pos = j;
                    }
                }
                frm[pos] = pg[i];
            }
        }

        // Show current frame content
        printf("Frm: ");
        for(j = 0; j < f; j++) {
            if(frm[j] != -1)
                printf("%d ", frm[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("Total hits: %d\n", hit);
    printf("Total faults: %d\n", n - hit);

    return 0;
}
