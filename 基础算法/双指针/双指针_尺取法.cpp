// luogu P1147
#include <bits/stdc++.h>

int main(){
    // left,right代表区间左右端点
    int s, sum = 3, left = 1, right = 2;;
    scanf("%d",&s);

    while(left < right){
        if(sum == s) {
            printf("%d %d\n", left, right);
            sum -= left;
            left += 1;
        } else if(sum < s){   // 区间内数小于m，右端点前移
            right += 1;
            sum += right;
        }else{               // 区间内数大于m，左端点右移动
            sum -= left;
            left++;
        }
    }
    return 0;



}

