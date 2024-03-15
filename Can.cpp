#include "Can.h"
using namespace std;


/*
WSL2でVCANによるCAN通信機能確認をするにはカーネルのビルドが必要、以下参照。
https://nikarana03.blogspot.com/2021/03/
*/


bool CCAN::CanSendMain(void)
{
    int s;
    struct sockaddr_can addr;
    struct ifreq ifr;
    struct can_frame frame;

    // ソケットを作成
    s = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    strcpy(ifr.ifr_name, "vcan0");  // 使用するCANインターフェース名
    ioctl(s, SIOCGIFINDEX, &ifr);

    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    // ソケットをCANバスにバインド
    bind(s, (struct sockaddr *)&addr, sizeof(addr));

    // CANフレームを設定
    frame.can_id = 0x123;  // メッセージID
    frame.can_dlc = 8;     // データ長

    unsigned char ucTemp = 0x01;
    for(int i=0;i<8;i++)
    {
        frame.data[i] = ucTemp;
        ucTemp += 0x01;
    }
    // ...

    // CANフレームを送信
    write(s, &frame, sizeof(struct can_frame));

    // ソケットを閉じる
    close(s);

    return true;


}

