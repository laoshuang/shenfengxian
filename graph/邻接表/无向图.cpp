#include"stdio.h"
#define MAXVEX 100
#include"malloc.h"


typedef char VertexName;	//顶点名类型 
typedef int Weight;		//定义权值类型 

//1.边节点
typedef struct EdgeNode{
 	int index;
 	Weight weight;
 	struct EdgeNode *next;
}EdgeNode;
//2.顶点节点
typedef struct VertexNode{
	VertexName name;
	EdgeNode *next;
}VertexNode,ARRAY[MAXVEX];
//3.图节点
typedef struct{
	ARRAY array;	//一维数组 
	int NumV,NumE;		//顶点数和边数 
}Graph; 

void CreateGraph(Graph *g);


//创建邻接表
void CreateGraph(Graph *g){
	int i,j,k;
	EdgeNode *p;
	
	puts("输入图的顶点数和边数:");
	scanf("%d",&g->NumV);
	scanf("%d",&g->NumE);
	//printf("%d,%d",g->NumV,g->NumE);
	//顶点命名并将所有顶点的指针域指向NULL 
	for(i=0;i<g->NumV;i++){
		getchar();//解决莫名其妙的bug 
		printf("请输入顶点名称:");
		scanf("%c",&g->array[i].name);
		g->array[i].next=NULL;
	}
	//for(i=0;i<g->NumV;++i)	printf("array[%d]的顶点名称是%c\n",i,g->array[i].name);		//打印顶点名称 
	//创建单链表（边表） 
	for(k=0;k<g->NumE;k++){
	puts("输入边的两个顶点下标:");
	scanf("%d",&i);getchar();scanf("%d",&j);getchar();
	//下标为i的顶点指向下标为j的邻接点 
	p=(EdgeNode *)malloc(sizeof(EdgeNode));
	p->index=j;
	p->next=g->array[i].next;
	g->array[i].next=p;
	//下标为j的顶点指向下标为i的邻接点(因为是无向图，所以两个顶点之间的边可以相互到达) 
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
//typedef char VertexName;	//顶点名类型 
//typedef int Weight;		//定义权值类型 
//
////1.边节点
//typedef struct EdgeNode{
// 	int index;
// 	Weight weight;
// 	struct EdgeNode *next;
//}EdgeNode;
////2.顶点节点
//typedef struct VertexNode{
//	VertexName name;
//	EdgeNode *next;
//}VertexNode;
////3.图节点
//typedef struct{
//	VertexNode array[MAXVEX];	//一维数组 
//	int NumV,NumE;		//顶点数和边数 
//}Graph; 
//
//void CreateGraph(Graph *g);
//
//
////创建邻接表
//void CreateGraph(Graph *g){
//	int i,j,k;
//	EdgeNode *p;
//	
//	puts("输入图的顶点数和边数:");
//	scanf("%d",&g->NumV);
//	scanf("%d",&g->NumE);
//	//printf("%d,%d",g->NumV,g->NumE);
//	//顶点命名并将所有顶点的指针域指向NULL 
//	for(i=0;i<g->NumV;i++){
//		getchar();//解决莫名其妙的bug 
//		printf("请输入顶点名称:");
//		scanf("%c",&g->array[i].name);
//		g->array[i].next=NULL;
//	}
//	//for(i=0;i<g->NumV;++i)	printf("array[%d]的顶点名称是%c\n",i,g->array[i].name);		//打印顶点名称 
//	//创建单链表（边表） 
//	for(k=0;k<g->NumE;k++){
//	puts("输入边的两个顶点下标:");
//	scanf("%d",&i);getchar();scanf("%d",&j);getchar();
//	//下标为i的顶点指向下标为j的邻接点 
//	p=(EdgeNode *)malloc(sizeof(EdgeNode));
//	p->index=j;
//	p->next=g->array[i].next;
//	g->array[i].next=p;
//	//下标为j的顶点指向下标为i的邻接点(因为是无向图，所以两个顶点之间的边可以相互到达) 
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




