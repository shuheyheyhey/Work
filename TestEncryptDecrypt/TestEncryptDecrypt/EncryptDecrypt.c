//
//  EncryptDecrypt.c
//  TestEncryptDecrypt
//
//  Created by 湯川 修平 on 5/9/15.
//  Copyright (c) 2015 湯川 修平. All rights reserved.
//

#include "EncryptDecrypt.h"

long int kE = 0;
long int kD = 0;
long int kN = 0;
long int kLcm = 0;

long int kEncrypt[4096];

//最大公約数
long int gcd(long int a, long int b)
{
    long int c;
    
    //入れ替え
    if (a < b) {
        a+=b;
        b=a-b;
        a-=b;
        
    }
    
    //0になるまで繰り返す
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    
    return a;
}



double exGcd(long int a,long int b)
{
    long int x = 0;
    long int de=0;
    for(int i = 2 ; i < kLcm ;i++){
        de = i*kE;
        x = de/kLcm;
        if(de + (-x*kLcm)==1){
            x = i;
            break;
        }
    }
    return x;
}



char* itoa(long int val)
{
    char* c = malloc(255);
    sprintf(c, "%ld",val);
    return c;
}



int checkPrimeNumber(int inputNumber)
{
    int i,j;
    j=sqrt(inputNumber);
    for(i=2;i<=j;i++)
    {
        if(inputNumber%i==0)
            return 0;
    }
    return 1;
}



long int makePublicKey(long int num,long int roundLawNumber)
{
    long int e = 0;
    //公開鍵(e,n)
    if( gcd(num,roundLawNumber) == 1 ){
        e = num;
        return e;
    }
    return 0;
}



long int makeSecretKey(long int e,long int p,long int q)
{
    long int d = 0;
    d = exGcd(e, kLcm);
    
    return d;
    
}



long int modPower(long int data, long int exp, long int n)
{
    long result = 1;
    long powNumber = data;
    
    // expを2のべき乗に分解して計算
    // powNumberはnumber ^ 1, number ^ 2, number ^ 4, number ^ 8, number ^ 16, ...
    // のようにnumberの2のべき乗をとっていく
    // expの各ビットが2のべき乗の係数にあたるので、
    // ビットシフトしつつ最下位ビットの係数 > 0なら結果に乗じていく
    while (exp > 0) {
        if ((exp & 1) > 0)
            result = (result * powNumber) % n;
        powNumber = (powNumber * powNumber) % n;
        exp >>= 1;
    }
    
    return result;
}



char* returnDecyptString(char* data)
{
    long int strLength = strlen(data);
    
    char* results = malloc(4096);
    //text[i] ^ e mod pqで暗号化
    for (int i = 0; i < strLength; i++){
        long int test = modPower(kEncrypt[i], kD, kN);
        results[i] = test;
    }
    
    return results;
}



char* returnEncyptString(const char* data)
{
    long int strLength = strlen(data);
    
    char* results = malloc(4096);
    //text[i] ^ e mod pqで暗号化
    for (int i = 0; i < strLength; i++){
        long int test = modPower(data[i], kE, kN);
        kEncrypt[i] = test;
        strcat(results, itoa(test));
    }
    
    return results;
}



void start(int p,int q)
{
    kN = p * q;
    kLcm = (p - 1) * (q - 1);
    
    //公開鍵
    for (long int i = 2; i < kLcm ; i++){
        kE = makePublicKey(i,kLcm);
    }
    
    kD = makeSecretKey(kE, p, q);
}

