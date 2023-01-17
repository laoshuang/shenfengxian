#include"stdio.h"
#define MAXVEX 100
#include"malloc.h"


typedef char VertexName;	//���������� 
typedef int Weight;		//����Ȩֵ���� 

//1.�߽ڵ�
typedef struct EdgeNode{
 	int index;
 	Weight weight;
 	struct EdgeNode *next;
}EdgeNode;
//2.����ڵ�
typedef struct VertexNode{
	VertexName name;
	EdgeNode *next;
}VertexNode,ARRAY[MAXVEX];
//3.ͼ�ڵ�
typedef struct{
	ARRAY array;	//һά���� 
	int NumV,NumE;		//�������ͱ��� 
}Graph; 

void CreateGraph(Graph *g);


//�����ڽӱ�
void CreateGraph(Graph *g){
	int i,j,k;
	EdgeNode *p;
	
	puts("����ͼ�Ķ������ͱ���:");
	scanf("%d",&g->NumV);
	scanf("%d",&g->NumE);
	//printf("%d,%d",g->NumV,g->NumE);
	//���������������ж����ָ����ָ��NULL 
	for(i=0;i<g->NumV;i++){
		getchar();//���Ī�������bug 
		printf("�����붥������:");
		scanf("%c",&g->array[i].name);
		g->array[i].next=NULL;
	}
	//for(i=0;i<g->NumV;++i)	printf("array[%d]�Ķ���������%c\n",i,g->array[i].name);		//��ӡ�������� 
	//�����������߱� 
	for(k=0;k<g->NumE;k++){
	puts("����ߵ����������±�:");
	scanf("%d",&i);getchar();scanf("%d",&j);getchar();
	//�±�Ϊi�Ķ���ָ���±�Ϊj���ڽӵ� 
	p=(EdgeNode *)malloc(sizeof(EdgeNode));
	p->index=j;
	p->next=g->array[i].next;
	g->array[i].next=p;
	//�±�Ϊj�Ķ���ָ���±�Ϊi���ڽӵ�(��Ϊ������ͼ��������������֮��ı߿����໥����) 
	p=(EdgeNode *)malloc(sizeof(EdgeNode));
	p->index=i;
	p->next=g->array[j].next;
	g->array[j].next=p;
	}
} 


int main()
{
	Graph g;
	CreateGraph(&g);
	
}




//the method two
//#include"stdio.h"
//#define MAXVEX 100
//#include"malloc.h"
//
//
//typedef char VertexName;	//���������� 
//typedef int Weight;		//����Ȩֵ���� 
//
////1.�߽ڵ�
//typedef struct EdgeNode{
// 	int index;
// 	Weight weight;
// 	struct EdgeNode *next;
//}EdgeNode;
////2.����ڵ�
//typedef struct VertexNode{
//	VertexName name;
//	EdgeNode *next;
//}VertexNode;
////3.ͼ�ڵ�
//typedef struct{
//	VertexNode array[MAXVEX];	//һά���� 
//	int NumV,NumE;		//�������ͱ��� 
//}Graph; 
//
//void CreateGraph(Graph *g);
//
//
////�����ڽӱ�
//void CreateGraph(Graph *g){
//	int i,j,k;
//	EdgeNode *p;
//	
//	puts("����ͼ�Ķ������ͱ���:");
//	scanf("%d",&g->NumV);
//	scanf("%d",&g->NumE);
//	//printf("%d,%d",g->NumV,g->NumE);
//	//���������������ж����ָ����ָ��NULL 
//	for(i=0;i<g->NumV;i++){
//		getchar();//���Ī�������bug 
//		printf("�����붥������:");
//		scanf("%c",&g->array[i].name);
//		g->array[i].next=NULL;
//	}
//	//for(i=0;i<g->NumV;++i)	printf("array[%d]�Ķ���������%c\n",i,g->array[i].name);		//��ӡ�������� 
//	//�����������߱� 
//	for(k=0;k<g->NumE;k++){
//	puts("����ߵ����������±�:");
//	scanf("%d",&i);getchar();scanf("%d",&j);getchar();
//	//�±�Ϊi�Ķ���ָ���±�Ϊj���ڽӵ� 
//	p=(EdgeNode *)malloc(sizeof(EdgeNode));
//	p->index=j;
//	p->next=g->array[i].next;
//	g->array[i].next=p;
//	//�±�Ϊj�Ķ���ָ���±�Ϊi���ڽӵ�(��Ϊ������ͼ��������������֮��ı߿����໥����) 
//	p=(EdgeNode *)malloc(sizeof(EdgeNode));
//	p->index=i;
//	p->next=g->array[j].next;
//	g->array[j].next=p;
//	}
//} 
//
//
//int main()
//{
//	Graph g;
//	CreateGraph(&g);
//	
//}




