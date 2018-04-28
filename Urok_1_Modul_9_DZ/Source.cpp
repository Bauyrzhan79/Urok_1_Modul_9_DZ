#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>

#define k 6
#define l 4

void main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	int nz;

	do
	{
		printf("������� ����� ������� ��� 0 ��� ������: ");
		scanf("%d", &nz);

		/*1.	��� ��������� ������ ����� �����
		a.	������������ ���������� ������, ������ ������� �������� �����
		����������� �� ������ �������� ���������������� ������� ���������� �������
		b.	������������ ���������� ������, ������ ������� �������� �����
		����������� �� ������ �������� ��������������� ������ ���������� �������
		*/
		if (nz == 1)
		{
			int ARR[k][l] = { 0 };

			for (int i = 0; i < k; i++)
			{
				for (int j = 0; j < l; j++)
				{
					ARR[i][j] = -10 + rand() % 20;
					printf("%d\t", ARR[i][j]);
				}
				printf("\n");
			}

			int *arr1 = (int *)malloc(l * sizeof(int));
			int *arr2 = (int *)malloc(k * sizeof(int));

			if ((arr1 == NULL) && (arr2 == NULL))
			{
				printf("������ ��������� ������!\n");
				system("pause");
				exit(1);
			}

			printf("���������� ������, ������ ������� �������� ����� ����������� �� ������ �������� ���������������� ������� ���������� �������:\n");

			for (int i = 0; i < l; i++)
			{
				int max = abs(ARR[0][i]);
				for (int j = 1; j < k; j++)
				{
					if (abs(ARR[j][i])>max)
						max = abs(ARR[j][i]);
				}
				*(arr1 + i) = max;
			}

			for (size_t i = 0; i < l; i++)
				printf("%d\t", *(arr1 + i));

			printf("\n");

			printf("���������� ������, ������ ������� �������� ����� ����������� �� ������ �������� ��������������� ������ ���������� �������:\n");

			for (int i = 0; i < k; i++)
			{
				int max = abs(ARR[i][0]);
				for (int j = 1; j < l; j++)
				{
					if (abs(ARR[i][j])>max)
						max = abs(ARR[i][j]);
				}
				*(arr2 + i) = max;
			}

			for (size_t i = 0; i < k; i++)
				printf("%d\t", *(arr2 + i));

			printf("\n\n");

			free(arr1);
			free(arr2);
		}

		//

		//5.	������ ����� �����. ������� �� ��� ������. ��������� ����� ������ ��������� �������
		else if (nz == 5)
		{
			int n, sum = 0;

			printf("������� ������ ����������� �������: ");
			scanf("%d", &n);

			int *arr = (int *)malloc(n * sizeof(int));

			if (arr == NULL)
			{
				printf("������ ��������� ������!\n");
				system("pause");
				exit(1);
			}

			for (size_t i = 0; i < n; i++)
			{
				*(arr + i) = rand() % 25;
				printf("%d\t", *(arr + i));
			}

			printf("\n");

			for (int i = 1; i < n; i += 2)
			{
				sum += *(arr + i);
			}

			printf("����a ������ ��������� ������� = %d\n\n", sum);
			free(arr);
		}

		//6.	������ ����� ����� N � ������ �� N ������������ �����. 
		//���������� ���������� ������������� ��������� �������
		else if (nz == 6)
		{
			int n, count = 0;

			printf("������� ������ ����������� �������: ");
			scanf("%d", &n);

			float *arr = (float *)malloc((float)n * sizeof(float));

			if (arr == NULL)
			{
				printf("������ ��������� ������!\n");
				system("pause");
				exit(1);
			}

			for (size_t i = 0; i < n; i++)
			{
				float temp1 = (float)(rand() % 90) / 100;
				float temp2 = (float)(rand() % 50) / 100;
				*(arr + i) = (float)(-10 + rand() % 25 + temp1 - temp2);
				printf("%f\t", *(arr + i));
			}

			printf("\n");

			for (int i = 0; i < n; i++)
			{
				if (*(arr + i) < 0)
					count++;
			}

			if (count != 0)
				printf("���������� ������������� ��������� ������� = %d\n\n", count);
			else
				printf("� ������� ����������� ������������ �����!!!\n\n");

			free(arr);
		}

		//7.	������ ����� ����� N. ������� ������ �� N ������������ �����. 
		//��������� ������������ ���������, ������ ������� ������ 7.
		else if (nz == 7)
		{
			int n;
			float mult = 1;

			printf("������� ������ ����������� �������: ");
			scanf("%d", &n);

			float *arr = (float *)malloc((float)n * sizeof(float));

			if (arr == NULL)
			{
				printf("������ ��������� ������!\n");
				system("pause");
				exit(1);
			}

			for (size_t i = 0; i < n; i++)
			{
				float temp1 = (float)(rand() % 90) / 100;
				float temp2 = (float)(rand() % 50) / 100;
				*(arr + i) = (float)(-10 + rand() % 25 + temp1 - temp2);
				printf("%f\t", *(arr + i));
			}

			printf("\n");

			for (int i = 0; i < n; i++)
			{
				if (fabs(*(arr + i)) < 7)
					mult *= *(arr + i);
			}
			if (mult != 1)
				printf("������������ ���������, ������ ������� ������ 7 = %f\n\n", mult);
			else
				printf("� ������� ��� ���������, ������ ������� ������ 7\n\n");

			free(arr);
		}

		//8.	������ ������������ �����. ������� �� ��� ������ ���������� ���������� ������� �������
		else if (nz == 8)
		{
			int n;

			printf("������� ������ ����������� �������: ");
			scanf("%d", &n);

			float *arr = (float *)malloc((float)n * sizeof(float));

			if (arr == NULL)
			{
				printf("������ ��������� ������!\n");
				system("pause");
				exit(1);
			}

			for (size_t i = 0; i < n; i++)
			{
				float temp1 = (float)(rand() % 90) / 100;
				float temp2 = (float)(rand() % 50) / 100;
				*(arr + i) = (float)(-10 + rand() % 25 + temp1 - temp2);
				printf("%f\t", *(arr + i));
			}

			printf("\n");

			float *max = arr;

			for (size_t i = 0; i < n; i++)
			{
				if (*(arr + i) > *max)
					max = arr + i;
			}

			printf("Max = %f\n\n", *max);

			free(arr);
		}

		//9.	������ ����� ����� N � ������ �� N ����� �����. 
		//���������� ���������� ������� �������
		else if (nz == 9)
		{
			int n;

			printf("������� ������ ����������� �������: ");
			scanf("%d", &n);

			int *arr = (int *)malloc(n * sizeof(int));

			if (arr == NULL)
			{
				printf("������ ��������� ������!\n");
				system("pause");
				exit(1);
			}

			for (size_t i = 0; i < n; i++)
			{
				*(arr + i) = rand() % 25;
				printf("%d\t", *(arr + i));
			}

			printf("\n");

			int min = *arr;
			for (int i = 0; i < n; i++)
			{
				if (*(arr + i) < min)
					min = *(arr + i);
			}

			printf("���������� ������� ������� = %d\n", min);

			free(arr);
		}

		//10.	������ ������������ �����. ������� �� ��� ������. 
		//���������� ������� �������������� ��������� �������.
		else if (nz == 10)
		{
			int n;
			float sum = 0;

			printf("������� ������ ����������� �������: ");
			scanf("%d", &n);

			float *arr = (float *)malloc((float)n * sizeof(float));

			if (arr == NULL)
			{
				printf("������ ��������� ������!\n");
				system("pause");
				exit(1);
			}

			for (size_t i = 0; i < n; i++)
			{
				float temp1 = (float)(rand() % 90) / 100;
				float temp2 = (float)(rand() % 50) / 100;
				*(arr + i) = (float)(1 + rand() % 25 + temp1 - temp2);
				printf("%f\t", *(arr + i));
				sum += *(arr + i);
			}

			printf("\n");
			printf("������� �������������� ��������� ������� = %f\n", sum / n);

			free(arr);
		}

		//11.	������ ������������ �����. ������� �� ��� ������. 
		//���������� ���������� ��������������� ��������� �������
		else if (nz == 11)
		{
			int n, count = 0;

			printf("������� ������ ����������� �������: ");
			scanf("%d", &n);

			float *arr = (float *)malloc((float)n * sizeof(float));

			if (arr == NULL)
			{
				printf("������ ��������� ������!\n");
				system("pause");
				exit(1);
			}

			for (size_t i = 0; i < n; i++)
			{
				float temp1 = (float)(rand() % 90) / 100;
				float temp2 = (float)(rand() % 50) / 100;
				*(arr + i) = (float)(-10 + rand() % 25 + temp1 - temp2);
				printf("%f\t", *(arr + i));
			}

			printf("\n");

			for (int i = 0; i < n; i++)
			{
				if (*(arr + i) > 0)
					count++;
			}

			if (count != 0)
				printf("���������� ��������������� ��������� ������� = %d\n", count);
			else
				printf("� ������� ����������� ������������� �����!!!\n");

			free(arr);
		}

		//12.	������ ����� ����� N � ������ �� N ������������ �����. 
		//���������� ������ ���������� �������������� �������� �������
		else if (nz == 12)
		{
			int n, poz = 0;

			printf("������� ������ ����������� �������: ");
			scanf("%d", &n);

			float *arr = (float *)malloc((float)n * sizeof(float));

			if (arr == NULL)
			{
				printf("������ ��������� ������!\n");
				system("pause");
				exit(1);
			}

			for (size_t i = 0; i < n; i++)
			{
				float temp1 = (float)(rand() % 90) / 100;
				float temp2 = (float)(rand() % 50) / 100;
				*(arr + i) = (float)(-10 + rand() % 25 + temp1 - temp2);
				printf("%f\t", *(arr + i));
			}

			printf("\n");

			/*for (size_t i = n-1; i >= 0; i--)
			{
			if (*(arr + i) < 0)
			{
			poz = i+1;
			break;
			}
			}*/

			for (size_t i = 0; i < n; i++)
			{
				if (*(arr + i) < 0)
					poz = i + 1;
			}

			if (poz != 0)
				printf("������ ���������� �������������� �������� ������� = %d\n", poz);
			else
				printf("� ������� ����������� ������������� �����!!!\n");

			free(arr);
		}

		//13.	������ ����� ����� N. ������� ������ �� N ������������ �����. 
		//��������� ����� ������������ � ������������� ���������.
		else if (nz == 13)
		{
			int n;

			printf("������� ������ ����������� �������: ");
			scanf("%d", &n);

			float *arr = (float *)malloc((float)n * sizeof(float));

			if (arr == NULL)
			{
				printf("������ ��������� ������!\n");
				system("pause");
				exit(1);
			}

			for (size_t i = 0; i < n; i++)
			{
				float temp1 = (float)(rand() % 90) / 100;
				float temp2 = (float)(rand() % 50) / 100;
				*(arr + i) = (float)(-10 + rand() % 25 + temp1 - temp2);
				printf("%f\t", *(arr + i));
			}

			printf("\n");

			float *max = arr, *min = arr;

			for (size_t i = 0; i < n; i++)
			{
				if (*(arr + i) > *max)
					max = arr + i;
				if (*(arr + i) < *min)
					min = arr + i;
			}

			printf("Max = %f, Min = %f. ����� ������������ � ������������� ��������� = %f\n", *max, *min, (*max) + (*min));

			free(arr);
		}

		//14.	������ ������������ �����. ������� �� ��� ������. 
		//��������� ������������ ������������ � ������������� ���������.
		else if (nz == 14)
		{
			int n;

			printf("������� ������ ����������� �������: ");
			scanf("%d", &n);

			float *arr = (float *)malloc((float)n * sizeof(float));

			if (arr == NULL)
			{
				printf("������ ��������� ������!\n");
				system("pause");
				exit(1);
			}

			for (size_t i = 0; i < n; i++)
			{
				float temp1 = (float)(rand() % 90) / 100;
				float temp2 = (float)(rand() % 50) / 100;
				*(arr + i) = (float)(-10 + rand() % 25 + temp1 - temp2);
				printf("%f\t", *(arr + i));
			}

			printf("\n");

			float *max = arr, *min = arr;

			for (size_t i = 0; i < n; i++)
			{
				if (*(arr + i) > *max)
					max = arr + i;
				if (*(arr + i) < *min)
					min = arr + i;
			}

			printf("Max = %f, Min = %f. ������������ ������������ � ������������� ��������� = %f\n", *max, *min, (*max)*(*min));

			free(arr);
		}

		//15.	������ ����� ����� N � ������ �� N ����� �����. 
		//����������, ���� �� � ������� ����� 20.
		else if (nz == 15)
		{

			int n;

			printf("������� ������ ����������� �������: ");
			scanf("%d", &n);

			int *arr = (int *)malloc(n * sizeof(int));

			if (arr == NULL)
			{
				printf("������ ��������� ������!\n");
				system("pause");
				exit(1);
			}

			int f = 0;

			for (size_t i = 0; i < n; i++)
			{
				*(arr + i) = 1 + rand() % 25;
				printf("%d\t", *(arr + i));
				if (*(arr + i) == 20)
					f = 1;
			}

			printf("\n");

			if (f == 1)
				printf("� ������� ���� ����� 20!\n");
			else
				printf("� ������� ��� ����� 20!\n");

			free(arr);
		}

		//system("pause");
		//system("cls");

	} while (nz != 0);

}