	#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace  std;

#define MaxLength 100
struct SV{
	char Hoten[50];
	char Lop[7];
	int SBD;
	float DiemTB;
};
typedef SV ElementType;
typedef struct Node
{
	ElementType Element; 
	Node *Next;  
} ;
typedef Node *PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode List;

void Makenull_List(List &L);
int IsEmpty_List(List L);
Position Header(List L);
int IsLast(List P);
Position First(List L);
Position Advance(Position P);
Position FindPrevious(ElementType X,List L);
void Insert_List(ElementType X,Position P,List L);
void Read_ds(List L);
void Print_ds(List L);
void Delete_List(List L);
void Sort_List(List L);
Position Sort_Class(const char *lp ,List L);
void Print_Lop(List L);

int main()
{
	List dssv;
	Makenull_List(dssv);
	Read_ds(dssv);
	Print_ds(dssv);
	printf("\n\ndanh sach sau khi xoa sinh vien co diem duoi 5 \n");
	Delete_List(dssv);
	Print_ds(dssv);
	printf("\n\ndanh sach sau khi sap xep \n");
	Sort_List(dssv);
	Print_ds(dssv);
	printf("\n\n in danh sach theo lop\n");
	Print_Lop(dssv);
	getch();
	return 1;
} 

void Makenull_List(List &L)
{
	L=new Node;
	L->Next =NULL;
}
int IsEmpty_List(List L)
{
	return L->Next==NULL;
}
Position Header(List L)
{
	return L;
}
int IsLast(List P)
{
	return P->Next==NULL;
}
Position First(List L)
{
	return L->Next;
}
Position Advance(Position P)
{
	return P->Next;
}

Position FindPrevious(float X,List L)
{
	Position P;
	P=L;
	while(P->Next!= NULL && P->Next->Element.DiemTB > X)
	P=P->Next;
	
	return P;
}
void Insert_List(ElementType X,Position P,List L)
{
	Position TmpCell;
	TmpCell = new Node;
	if(TmpCell==NULL)printf("Out Of space!!!");
	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next=TmpCell;
}

void Read_ds(List L)
{
	Position P = Header(L);
	ElementType Tmp;
	int n;
	printf("Nhap So luong sinh vien:");
	scanf("%d",&n);
	for (int i =1; i<=n;i++)
	{
		printf("Nhap thong tin cua sinh vien\n");
		fflush(stdin);
		printf("Nhap ho ten:");
		gets(Tmp.Hoten);
		printf("Nhap lop:");
		fflush(stdin);
		gets(Tmp.Lop);
		printf("Nhap so bao danh: ");
		fflush(stdin);
		scanf("%d",&Tmp.SBD);
		printf("Nhap diem Trung binh:");
		scanf("%f",&Tmp.DiemTB);
		Insert_List(Tmp,P,L);
		P = P->Next;	
	}
}

void Print_ds(List L)
{
if(IsEmpty_List(L))
{
	printf("danh sach rong!!");
}
else
{
	Position P;
	printf("Danh sach sinh vien \n");
	for (P = First(L);P!=NULL;P=P->Next)
	{
		printf("THong tin sinh vien\n");
		printf("Ho Ten: %s \n",P->Element.Hoten);
		printf("so bao danh: %d\n",P->Element.SBD);
		printf("Lop: %s\n",P->Element.Lop);
		printf("Diem TB:%f\n",P->Element.DiemTB);
		printf("----------------------------------\n");
	}
	}
}

void Delete_List(List L)
{
	float X=5;
	Position P,tmp,TmpCell;
	tmp = First(L);
	while(!IsLast(tmp)){
	P=FindPrevious(X,L);
	if(!IsLast(P))
	{
		TmpCell = P->Next;
		P->Next=TmpCell->Next;
		free( TmpCell);
	}
	tmp = tmp->Next;
	}
}

void Sort_List(List L)
{
	Position i,j;
	for (i = First(L);i!=NULL;i=i->Next)
	{
		for (j=i->Next;j!=NULL;j=j->Next)
		{
			if(strcmp(i->Element.Hoten,j->Element.Hoten)==1)
			{
				ElementType t;
				t = i->Element;
				i->Element = j->Element;
				j->Element = t;
			}
		}
	}
}

Position Sort_Class(const char *lp ,List L)
{
	Position P;
	P=L->Next;
	while(P!=NULL&&strstr(P->Element.Lop,lp)==NULL)
		P=P->Next;
	return P;
}
void Print_Lop(List L)
{
	Position P,Q;
	ElementType Temp;
	if(!IsEmpty_List(L))
	{
		P=First(L);
		while(P!=NULL)
		{
			Q=P->Next;
			while(Q!=NULL)
			{
				if(strcmp(P->Element.Lop,Q->Element.Lop)>0)
			
				{
				Temp=P->Element;
				P->Element=Q->Element;
				Q->Element=Temp;
				}
				Q=Q->Next;
			}
			P=P->Next;
		}
	}
	Print_ds(L);
}	
<<<<<<< HEAD
//k co sua gi ca time  4:07
=======
//k co sua gi ca time  4:10
//thay doi lan thu N+1 time 4h21
//test lan cuoi time 4h23

>>>>>>> 54a11b8a371b15fdbb1ede59fc4af3e5b50332a3
