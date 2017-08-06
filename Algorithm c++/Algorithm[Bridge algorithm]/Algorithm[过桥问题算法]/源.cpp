#include "head.h"


#define N 5
#define SIZE 64

int Position[N];
int Index,TmpScheme[SIZE],Scheme[SIZE];
int MinTime = 100,Time[N] = {1,3,6,8,12};


void Find(int Remnant, int CurTime, int Direction)
{
	if(Remnant == 0)
	{
	    MinTime = CurTime;
		for(int i = 0; i < SIZE && TmpScheme[i] >= 0; i++)
			Scheme[i] = TmpScheme[i];
	}
	else if(Direction == 1)
	{
	    for(int i = 0; i < N; i++)
			if(Position[i] == 0 && CurTime + Time[i] < MinTime)
			{
			    TmpScheme[Index++] = i;
				Position[i] = 1;
				for(int j = 0; j < N; j++)
				{
				    int TmpMax = (Time[i] > Time[j] ? Time[i] : Time[j]);
					if(Position[j] == 0 && CurTime + Time[j] < MinTime)
					{
					    TmpScheme[Index++] = j;
						Position[j] = 1;
						Find(Remnant - 2, CurTime + TmpMax,!Direction);
						Position[j] = 0;
						TmpScheme[--Index] = -1;
					}
				}
				Position[i] = 0;
				TmpScheme[--Index] = -1;
			}
	}
	else
	{
	    for(int j = 0; j < N; j++)
		{
		    if(Position[j] == 1&&CurTime + Time[j] < MinTime)
			{
			    TmpScheme[Index++] = j;
				Position[j] = 0;
				Find(Remnant + 1, CurTime + Time[j],!Direction);
				Position[j] = 1;
				TmpScheme[--Index] = -1;
			}
		}
	}
}



int main()
{
	for(int i = 0; i < SIZE; i++)
	{
	    Scheme[i] = TmpScheme[i] = - 1;
	}

	Find(N,0,1);
	cout << "MinTime = " << MinTime << endl;
	for(int i = 0 ; i < SIZE && Scheme[i] >= 0 ; i += 3)
		cout << Scheme[i] << "-" << Scheme[i + 1] << " " << Scheme[i + 2] << endl;
	cout << "\b\b";
}