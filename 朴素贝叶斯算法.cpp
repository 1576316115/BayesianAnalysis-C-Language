 #include "stdio.h"
#include "stdlib.h"
#include "data.h"

#define m TRAIN_NUM//m-���Ƶ�mֵ����ѵ��������

//����ѵ�������������������͸�������
//����ѵ��������
//���ѵ�������������������͸�������
void CalcPosAndNegNum(int *pPosNum,int *pNegNum){
	int i;
	//ȡ��ѵ������
	//��ʼ��Ϊ0
	*pPosNum=0;
	*pNegNum=0;
	
	for(i=0;i<TRAIN_NUM;i++){
		//trainSampleΪѵ�������׵�ַ��ÿ��ѵ����������ATTR_NUM������
		//����Ŀ�����Ե�ַ�洢��yes��noֵ������pPosNum��pNegNum
		if(trainSample[i][ATTR_NUM]==yes){
			(*pPosNum)++;
		} 
		else{
			(*pNegNum)++;
		}
	}
	return; 
} 

//���ر�Ҷ˹ѧϰ���㷨����
void NaiveBayes(void){
	
//	int newSample[]={sunny,cool,high,strong};
//	int preP[]={(float)0.333,(float)0.333,(float)0.50,(float)0.50};
	int i,j,cntY,cntN;
	//�洢ѵ������Ŀ������Ϊyes��no��������
	int posNum,negNum; 
	//�洢Ŀ��ֵyes��no�ĸ���
	float PVyes,PVno,PVyesTemp,PVnoTemp;
	//�洢Ŀ��ֵΪyesʱ������ÿ�����Եĸ���
	float PAttrYes[ATTR_NUM];
	//�洢Ŀ��ֵΪnoʱ������ÿ�����Եĸ���
	float PAttrNo[ATTR_NUM];
	//����ѵ�������������������͸�������
	CalcPosAndNegNum(&posNum,&negNum);
	
	//����Ŀ��ֵyes��no�ĸ���
	PVyes=(float)posNum/(float)TRAIN_NUM;
	PVno=(float)negNum/(float)TRAIN_NUM; 
	//printf("%f,%f\n\n",PVyes,PVno);
	for(j=0;j<ATTR_NUM;j++){
		cntY=0;
		cntN=0;
		//����ѵ����������yes��no��������Ŀ��ʵ�����Է����Ĵ��� 
		for(i=0;i<TRAIN_NUM;i++){
			//ͳ��Ŀ��ֵΪyesʱ����������������ѵ�������еĸ���
			if(trainSample[i][ATTR_NUM]==yes){
				//���ѵ��������Ŀ��������yes
				//���Ҹ�ѵ������������ֵ����Ҫ���������������ֵ��Ƚ���+1
				if(trainSample[i][j]==newSample[j]){
					cntY++;
				} 
			} 
			//ͳ��Ŀ��ֵΪnoʱ����������������ѵ�������еĸ���
			else if(trainSample[i][ATTR_NUM]==no){
				if(trainSample[i][j]==newSample[j]){
					cntN++; 
				}
			} 
		}
		//����Ŀ��ֵΪyes��noʱ�����ĸ������Եĸ��� 
		PAttrYes[j]=((float)cntY+((float)m)*preP[j])/((float)(posNum+m));
		
		PAttrNo[j]=((float)cntN+((float)m)*preP[j])/((float)(negNum+m));
		//printf("%f,%f\n",PAttrYes[j],PAttrNo[j]);
		
	} 
	printf("\n"); 
	//�ֱ������Ҫ�����������Ŀ��ֵΪyes��no�ĸ��� 
	for(i=0;i<ATTR_NUM;i++){
		PVyes=PVyes*PAttrYes[i];
		PVno=PVno*PAttrNo[i];
		//printf("%f,%f\n",PVyes,PVno);
	}
	
	//��һ������
	PVyesTemp=PVyes/(PVyes+PVno); 
	PVnoTemp=PVno/(PVyes+PVno);
	//������
	printf("���ݵ������붨����data�ļ��н��У�\n\n");
	printf("��data���ݽ��б�Ҷ˹����󣬶Ե�ǰʵ���ó����½��ۣ�\n");
	printf("ʵ������Ϊyes�ĸ��ʣ�%f\n",PVyesTemp); 
	printf("ʵ������Ϊno�ĸ��ʣ�%f\n",PVnoTemp);
	if(PVyesTemp>PVnoTemp){
		printf("ʵ��������Ϊ��yes\n");
	} 
	else if(PVyesTemp-PVnoTemp<0.1){
		printf("��ʷ������ʱ�޷��жϣ����������ѵ�����ݣ�\n");
	}
	else{
		printf("ʵ��������Ϊ��no\n");
	}
	return;	 
} 

int main(void){
	NaiveBayes();
	return 0;
}
