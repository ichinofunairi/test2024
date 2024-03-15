#ifndef _CAL_H_
#define _CAL_H_

#include "Tool.h"
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_THREAD 4
#define ADD_NUM 1000


class CCAL
{

// private:

public:

/* 共有データ */
long long mSum;

/* Mutexオブジェクト */
pthread_mutex_t mutex;

/* スレッドに渡すデータ */
typedef struct _ST_THREAD_DATA_ 
{
    int addNum;
}ST_THREAD_DATA;


// 物体の位置情報を表す構造体
typedef struct 
{
    double x;  // X座標
    double y;  // Y座標
} ObjectPosition;

// リストノードを表す構造体
typedef struct Node 
{
    ObjectPosition position;
    struct Node* next;
} Node;

// リストの先頭ポインタ
Node* head = NULL;



public:
bool CalTest(int i);
bool CalTestMain(void);
// static void* Caladd(void *arg);
// bool CalMultiThreadTest(void* pParam);

void addPosition(double x, double y);
void printPositions();


};

#endif