#include <stdio.h>
#include <windows.h>


// shared data
DWORD Supplies;
boolean flag[2];
int turn;
int count = 0;


// A�� ���ָ� �ִ� �Լ�
DWORD WINAPI Buy() {

	
	while (1) {
		flag[0] = TRUE;
		turn = 1;
		while (flag[1] && turn == 1) {
			// wait 
		}
		if (Supplies < 5) {
		
			Supplies++;
			
			printf("���ָ� ���� ���� �繫��ǰ�� ��: %d\n", Supplies);
			count++;
		}

		if (count == 100) {
			break;
		}
	}
	flag[0] = FALSE;
		
     return 0;
}

// B�� �繫��ǰ�� �繫�Ƿ� �ű�� �Լ� 
DWORD WINAPI Use() {

	while (1) {
		flag[1] = TRUE;
		turn = 0;
		while (flag[0] && turn == 0) {
			// wait 
		}
		if (Supplies == 5) {
			
				Supplies -= 5;

				printf("�繫�Ƿ� �ű� ���� �繫��ǰ�� ��: %d\n", Supplies);
			
				if (count == 100) {
					break;
				}
		} 
		}
	
		
	
	return 0; 
}


int main() {
	
	DWORD Thread_useId;
	DWORD Thread_buyId;
	HANDLE ThreadHandle_buy; // ������ �����ϱ� ���� ��� 
	HANDLE ThreadHandle_use;

	flag[0] = TRUE;
	flag[1] = FALSE;

		// ���ָ� ����
		ThreadHandle_buy = CreateThread(NULL, 0, Buy, NULL, 0, &Thread_buyId);

		// �繫�Ƿ� �ű�
		ThreadHandle_use = CreateThread(NULL, 0, Use, NULL, 0, &Thread_useId);
		WaitForSingleObject(ThreadHandle_buy, INFINITE);
		WaitForSingleObject(ThreadHandle_use, INFINITE);
	
		CloseHandle(ThreadHandle_buy);
		CloseHandle(ThreadHandle_use);
		
		printf("���� �繫��ǰ�� ��: %d\n", Supplies);
	

	
	return 0;

}