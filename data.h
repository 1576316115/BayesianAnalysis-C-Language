//ѵ������:�������ݵĲɼ��󣬸��������趨��Ӧ��������������ֵ 

/**************���Զ�����***************/

//�趨ѵ����������
#define TRAIN_NUM  20
//�趨���������� 
#define ATTR_NUM 5

//��������

// A:��ʱ���� 
typedef enum A{ 
	A1,//���� 
	A2,//���� 
	A3,//���� 
	NUM_A=3
}A;

//B:������˯ʱ�䣨11��-�賿2�㣩 
typedef enum B{
	B1,//11��00-12��00 
	B2,//12��00-1��00 
	B3,//1��00-2��00 
	B4,//2��00-3��00 
	NUM_B=4
}B;

//C:�����Ͽ�ʱ��(���������) 
typedef enum C{
	C1,//1-2
	C2,//3-4
	NUM_C=2
}C;

//D:ʵ����ʱ�� 
typedef enum D{
	D1,//7��00-7��30 
	D2,//7��30-8:00 
	D3,//8��00-8��30 
	D4,//8��30-9: 00 
	NUM_D=4
}D;

//E:��Ӧ�Ŀγ� 
typedef enum E{
	E1,//��������ԭ�� 
	E2,//���������ϵͳ 
	E3,//���� 
	E4,//Ӣ�� 
	E5,//ë�� 
	NUM_E=5
}E;

//��Ӧ�����µľ��� 
typedef enum _targetAttribute{
	yes,
	no
}_targetAttribute;

//m-���Ƶ�ÿ�����Զ�Ӧ���������
float preP[ATTR_NUM]={1/(float)NUM_A,1/(float)NUM_B,1/(float)NUM_C,1/(float)NUM_D,1/(float)NUM_E};




/**************������������ ********************/ 

//���ѵ�������Ķ�ά���� 
int trainSample[][ATTR_NUM+1]={
	{A1,B1,C1,D2,E4,no},
	{A3,B2,C2,D4,E5,no},
	{A1,B3,C1,D3,E1,no},
	{A2,B1,C1,D2,E4,no},
	{A3,B3,C2,D4,E5,yes},
	{A1,B3,C2,D3,E1,yes},
	{A1,B1,C1,D3,E4,no},
	{A3,B2,C2,D4,E1,yes},
	{A1,B3,C1,D3,E1,no},
	{A1,B1,C1,D2,E5,no},
	{A3,B2,C2,D3,E5,yes},
	{A1,B3,C2,D3,E1,yes},
	{A1,B2,C1,D2,E4,no},
	{A2,B2,C2,D4,E5,yes},
	{A1,B1,C1,D3,E1,yes},
	{A1,B1,C2,D2,E4,no},
	{A3,B2,C2,D1,E5,yes},
	{A1,B3,C1,D3,E2,yes},
	{A1,B1,C1,D2,E4,yes},
	{A3,B2,C2,D4,E1,yes},
}; 
 
 
 

/******************������ʵ��*******************/

int newSample[ATTR_NUM]={A2,B3,C1,D4,E2};

