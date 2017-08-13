#pragma once
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<wingdi.h>
#include<stdbool.h>
#define _CRT_SECURE_NO_WARNINGS
typedef struct Route {
	TCHAR routNum[6];//·�߱��
	TCHAR routName[20];//·������
	int hasStation;//��������վ����
	double howLong;//�ܹ�����
	double fullTime;//�ܺ�ʱ������վ��ͣ��ʱ�䣩
	TCHAR startStation[10];//��ʼվ����
	TCHAR endStation[10];//����վ����
	TCHAR chargePeople[30];//����������
	TCHAR chargeTele[8];//�����˰칫�绰
	TCHAR chargeMobile[11];//�������ƶ��绰
	TCHAR chargeEmail[50];//�����˵�������
	struct Station* headStation;//վ������
	struct Route* nextRoute;//����nextָ��

}route,*proute;
typedef struct Station {
	TCHAR belongRoute[6];//����·�߱��
	int stationCounter;//վ�����
	TCHAR stationNum[10];//վ����
	TCHAR stationName[50];//վ������
	double fromStart;//������ʼվ�����
	double fromUpper;//������һ��վ�����
	double fromUpperTime;//����һ��վ�㽻ͨ��ʱ
	double stayTime;//ͣ��ʱ��
	struct Truck *headTruck;//��������
	struct Station *nextStation;//����nextָ��
}station,*pstation;
typedef struct Truck {
	TCHAR truckNum[8];//��������
	TCHAR belongRoute[6];//ִ�е�����·�߱��
	TCHAR driverName[30];//˾������
	TCHAR driverTele[11];//˾���ƶ��绰
	TCHAR belongStation[10];//����վ����
	struct StationLoad {
		TCHAR loadName[20];//��վ����/ж������
		double loadWeight;//��վ����/ж������
	}load;
	struct Truck * nextTruck;//����nextָ��
}truck,*ptruck;
extern proute head;//ʮ�ֽ���������ͷָ��

bool getRouteData(_In_ HWND hdlg,_In_ WPARAM wParam,_Out_ proute temp);//��ȡ·������
bool getStationData(_In_ HWND hdlg,_In_ WPARAM wParam, _Out_ pstation temp);//��ȡվ������
bool getTruckData(_In_ HWND hdlg, _In_ WPARAM wParam, _Out_ ptruck temp);//��ȡ��������
bool getStationData2(_In_ HWND hdlg, _In_ WPARAM wParam, _Out_ pstation temp, TCHAR *previous);//��ȡ���վ�������
bool insertRoute(proute nowRoute);//���һ��·��
bool insertStation(pstation nowStation);//���һ��վ��
bool insertStation2(pstation nowStation, TCHAR *previous);//��previous������һ��վ��
bool insertTruck(ptruck nowTruck);//���һ������
bool changeRoute(proute nowRoute);//�޸�һ��·��
bool changeStation(pstation nowStation);//�޸�һ��վ��
bool changeTruck(ptruck nowTruck);//�޸�һ������
void copyRoute(proute rec, proute giv);//����һ��·��
void copyStation(pstation rec, pstation giv);//����һ��վ��
void copyTruck(ptruck rec, ptruck giv);//����һ������
bool findRoute(proute nowRoute);//��һ��·��
bool findStation(pstation nowStation);//��һ��վ��
bool findTruck(ptruck nowTruck);//��һ������
bool saveInFile();//���ݴ����ļ�
bool loadInFile();//���ݴ��ļ��ж�ȡ
bool deleteRoute(TCHAR rNum[]);//ɾ��·��
bool deleteStation(TCHAR sNum[]);//ɾ��վ��
bool deleteTruck(TCHAR tNum[]);//ɾ������
bool searchRouteFromStation(HWND hdlg,TCHAR s[]);//��ѯ����һ��վ������г���
bool searchLongest(HWND hwnd);//��ѯ��ʱ�����̵�·��
bool searchKiloLongest(HWND hwnd);//��ѯ�����������̵�·��
bool findStationByRoute(HWND hwnd,TCHAR s[]);//��ѯ�ƶ�·�ߵ�����
bool findStationByDriver(HWND hdlg, TCHAR s[]);//��ѯ�ƶ�˾��������·��
bool findTeleByDriver(HWND hdlg, TCHAR s[]);//��ѯָ��˾������ϵ��ʽ
bool findStationByTruck(HWND hdlg, TCHAR s[]);//��ѯָ������������·��
void getTable(HWND hdlg);//�������