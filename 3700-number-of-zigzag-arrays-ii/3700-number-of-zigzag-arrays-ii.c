#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int SZ;

long long **matMul(long long **A,long long **B) {
    long long **C=malloc(SZ*sizeof(long long*));
    for(int i=0;i<SZ;i++) {
        C[i]=calloc(SZ,sizeof(long long));
        for(int k=0;k<SZ;k++) {
            if(!A[i][k]) continue;
            for(int j=0;j<SZ;j++) {
                C[i][j]=(C[i][j]+A[i][k]*B[k][j])%MOD;
            }
        }
    }
    return C;
}

long long **matPow(long long **base,long long exp) {
    long long **res=malloc(SZ*sizeof(long long*));
    for(int i=0;i<SZ;i++) {
        res[i]=calloc(SZ,sizeof(long long));
        res[i][i]=1;
    }
    while(exp>0) {
        if(exp&1) res=matMul(res,base);
        base=matMul(base,base);
        exp>>=1;
    }
    return res;
}

int zigZagArrays(int n,int l,int r) {
    int m=r-l+1;
    SZ=2*m;
    long long **T=malloc(SZ*sizeof(long long*));
    for(int i=0;i<SZ;i++) T[i]=calloc(SZ,sizeof(long long));
    for(int val=0;val<m;val++) {
        int up=val, down=val+m;
        for(int nxt=0;nxt<m;nxt++) {
            if(nxt<val) T[nxt+m][up]=(T[nxt+m][up]+1)%MOD;
            if(nxt>val) T[nxt][down]=(T[nxt][down]+1)%MOD;
        }
    }
    long long *dp=calloc(SZ,sizeof(long long));
    for(int a=0;a<m;a++) {
        for(int b=0;b<m;b++) {
            if(a==b) continue;
            if(a<b) dp[b]= (dp[b]+1)%MOD;
            else dp[b+m]= (dp[b+m]+1)%MOD;
        }
    }
    if(n==2) {
        long long ans=0;
        for(int i=0;i<SZ;i++) ans=(ans+dp[i])%MOD;
        return (int)ans;
    }
    long long **Texp=matPow(T,n-2);
    long long *final=calloc(SZ,sizeof(long long));
    for(int i=0;i<SZ;i++) {
        for(int j=0;j<SZ;j++) {
            final[i]=(final[i]+Texp[i][j]*dp[j])%MOD;
        }
    }
    long long ans=0;
    for(int i=0;i<SZ;i++) ans=(ans+final[i])%MOD;
    return (int)ans;
}
