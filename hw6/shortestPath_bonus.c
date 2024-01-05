#pragma warning( disable : 4996 )
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<limits.h>
struct table {
    long long int type, val;
    long long int hldv, hldt;
}dis[10000];

struct vertex {
    long long int type, from, to, time;
}way[80000];

long long int choose(long long int* s) {
    long long int index = -1, min = INT_MAX;
    for (long long int i = 0; i < 10000; ++i) {
        if (dis[i].val != 0 && *(s + i) != 1 && dis[i].val < min) {
            min = dis[i].val;
            index = i;
        }
    }
    return index;
}

long long int main() {
    long long int ans = -1;
    long long int amnt = 0, cnt;
    char tmp[6], cmd;
    while (1) {
        scanf(" %c", &cmd);
        if (cmd == 'E')
            break;
        else if (cmd == 'L') {
            scanf(" %s %lld", tmp, &cnt);
            if (isalpha(tmp[0])) { //MRT type >= 100
                way[amnt].type = (long long int)tmp[0] - 'A';
                way[amnt].type += 100;
            }
            else {
                way[amnt].type = 0;
                for (long long int i = 0; i < strlen(tmp); ++i) {
                    way[amnt].type *= 10;
                    way[amnt].type += (long long int)tmp[i] - '0';
                }
            }
            for (long long int i = 0; i < cnt; ++i) {
                scanf(" %lld %lld %lld", &way[amnt].from
                    , &way[amnt].to, &way[amnt].time);
                if (i != 0)
                    way[amnt].type = way[amnt - 1].type;
                amnt++;
            }
        }
        else { //cmd == Q
            long long int from, to;
            scanf(" %lld %lld", &from, &to);
            ans = -1;
            long long int s[10000];
            memset(s, -1, 10000 * sizeof(long long int));
            for (long long int i = 0; i < 10000; ++i) {
                dis[i].val = 0;
            }
            s[from] = 1;
            dis[from].val = 0;
            //printf("s[110]:%lld\n",s[110]);
            for (long long int i = 0; i < amnt; ++i) {
                if (way[i].from == from) {
                    if (dis[way[i].to].val == NULL
                        || dis[way[i].to].val > way[i].time) {
                        dis[way[i].to].val = way[i].time;
                        dis[way[i].to].type = way[i].type;
                    }
                }
            }
            long long int cur = choose(s);
            while (cur != -1) {
                s[cur] = 1;
                for (long long int i = 0; i < amnt; ++i) {
                    if (way[i].from == cur) {
                        long long int cmp = way[i].time;
                        if (dis[cur].type != way[i].type) {
                            if (way[i].type >= 100)
                                cmp += 10;
                            else
                                cmp += 5;
                        }
                        if (dis[way[i].to].val == NULL
                            || dis[way[i].to].val > dis[cur].val + cmp) {
                            dis[way[i].to].val = dis[cur].val + cmp;
                            dis[way[i].to].type = way[i].type;
                        }
                    }
                }
                cur = choose(s);
            }

            if (to == from)    printf("0\n");
            else if (dis[to].val != NULL || to == from)
                printf("%lld\n", dis[to].val);
            else
                printf("-1\n");

        }
    }

    return 0;
}