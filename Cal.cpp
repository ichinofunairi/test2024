#include "Cal.h"
using namespace std;


//subの方でこちらをmergeする




/*testest*/



//testes
// 新しい位置情報をリストに追加する関数
void CCAL::addPosition(double x, double y) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "メモリ割り当てエラー\n");
        exit(1);
    }

    newNode->position.x = x;
    newNode->position.y = y;
    newNode->next = head;
    head = newNode;
}

// リスト内の位置情報を表示する関数
void CCAL::printPositions() 
{
	CTOOL cTool;
    Node* current = head;
    while (current != NULL)
	{
		char sLog[64] = {0};
        // printf("X: %lf, Y: %lf\n", current->position.x, current->position.y);
		sprintf(sLog,"X: %lf, Y: %lf\n", current->position.x, current->position.y);
		cTool.OutputLog(sLog);
        current = current->next;
    }


}



bool CCAL::CalTest(int i)
{
	char sLog[64] = {0};
	int CalIO[2] = {0};

	CalIO[0] = i;
	CalIO[1] = i * 2;

	if(CalIO[1]%20 == 0)
	{
        CTOOL cTool;
		sprintf(sLog,"input = %d, output = %d",CalIO[0],CalIO[1]);
		cTool.OutputLog(sLog);
		sleep(1);
	}
	else
	{
		;
	}

	return true;
}


bool CCAL::CalTestMain(void)
{
	CTOOL cTool;

	time_t start_time, end_time;
	start_time = time(NULL);

	//calculation test
	for(int i=0;i<30;i++)
	{
//		CCAL::CalTest(i);
	}

	end_time = time(NULL);

	char sLog[64] = {0};
	sprintf(sLog,"Cal time is %ld sec",end_time - start_time);
	cTool.OutputLog(sLog);


	//リスト構造のテスト------------------
    // 位置情報を追加
    addPosition(10.0, 20.0);
    addPosition(15.0, 25.0);
    addPosition(20.0, 30.0);

    // 位置情報を表示
    printPositions();

    // メモリの解放（必要に応じて）
    while (head != NULL)
	{
        Node* temp = head;
        head = head->next;
        free(temp);
    }
	//リスト構造のテストここまで------------------





	return true;
}

// void* CCAL::Caladd(void *arg)
// {
//     int i;
//     ST_THREAD_DATA *data = (ST_THREAD_DATA*)arg;;

//    	CCAL* pDc = (CCAL*)arg;
// 	pthread_mutex_t *pMutex = &pDc->mutex;
//     long long *pmSum = &pDc->mSum;
 

//     /* addNum回 sum = sum + 1 を実行 */
//     for(i = 0; i < data->addNum; i++)
// 	{
//         pthread_mutex_lock(pMutex);
//         pmSum = pmSum + 1;
//         pthread_mutex_unlock(pMutex);
//     }

//     return NULL;
// }

// bool CCAL::CalMultiThreadTest(void* pParam)
// {
//     pthread_t thread[NUM_THREAD];
//     ST_THREAD_DATA data[NUM_THREAD];
//     int i;

//     /* Mutexオブジェクトの初期化 */
//     pthread_mutex_init(&mutex, NULL);

//     for(i = 0; i < NUM_THREAD; i++)
// 	{
//         /* ADD_NUMはNUM_THREADで割り切れることを前提としている */
//         data[i].addNum = ADD_NUM / NUM_THREAD;
//     }

//     /* スレッドの開始 */
//     for(i = 0; i < NUM_THREAD; i++)
// 	{
//         pthread_create(&thread[i], NULL, CCAL::Caladd, &data[i]);
//     }

//     /* スレッドの終了待ち */
//     for(i = 0; i < NUM_THREAD; i++)
// 	{
//         pthread_join(thread[i], NULL);
//     }

//     /* Mutexオブジェクトの破棄 */
//     pthread_mutex_destroy(&mutex);

//     /* 計算結果の表示 */
//     printf("sum = %lld\n", mSum);

//     return 0;
// }