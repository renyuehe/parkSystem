#ifndef CONFIG_H
#define CONFIG_H

#include <QtWidgets>
#define LOCAL_IP    QHostAddress::LocalHost
#define SERVER_IP   "192.168.2.27"
#define UDP_PORT        9999


#define A9_SERVER_IP "192.168.43.43"
#define TCP_PORT        6666

/* 数据库查询结构体
 * type 查询的表名
 * column 查询的字段
 * values 查询的字段
 *
 * */
struct select{
    char table_name[16];
    char column[16];
    char values[16];
};

struct ctlMsg{
    unsigned char type;/* type: 0x0 控制类 0xf 传送数据 */
    unsigned char instruct;/* 0x0001 抬起杆 ......等等 */
    unsigned char data[1024];
};

/* UDP报头 报尾 */
struct __attribute__ ((__packed__)) info{
     //long long size;
     long size;
     int type;
     int count;
};

#define TRAN_SIZE 1024;
struct picHeadMsg {
    int funCode;                        //!功能码
    unsigned int uTransFrameHeadSize;    //!sizeof(WIFI_FRAME_HEADER)
    unsigned int uTransFrameSize;       //!sizeof(WIFI_FRAME_HEADER) + Data Size

    //数据帧变量
    unsigned int uDataFrameSize;        //数据帧的总大小
    unsigned int uDataFrameTotal;       //一帧数据被分成传输帧的个数
    unsigned int uDataFrameCurr;        //数据帧当前的帧号
    unsigned int uDataInFrameOffset;    //数据帧在整帧的偏移
};


#endif // CONFIG_H
