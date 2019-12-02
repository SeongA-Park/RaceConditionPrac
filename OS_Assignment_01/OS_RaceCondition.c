#include <stdio.h>
#include <windows.h>


// shared data
DWORD Supplies;
boolean flag[2];
int turn;
int count = 0;


// A가 발주를 넣는 함수
DWORD WINAPI Buy() {

	
	while (1) {
		flag[0] = TRUE;
		turn = 1;
		while (flag[1] && turn == 1) {
			// wait 
		}
		if (Supplies < 5) {
		
			Supplies++;
			
			printf("발주를 넣은 후의 사무용품의 수: %d\n", Supplies);
			count++;
		}

		if (count == 100) {
			break;
		}
	}
	flag[0] = FALSE;
		
     return 0;
}

// B가 사무용품을 사무실로 옮기는 함수 
DWORD WINAPI Use() {

	while (1) {
		flag[1] = TRUE;
		turn = 0;
		while (flag[0] && turn == 0) {
			// wait 
		}
		if (Supplies == 5) {
			
				Supplies -= 5;

				printf("사무실로 옮긴 후의 사무용품의 수: %d\n", Supplies);
			
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
	HANDLE ThreadHandle_buy; // 스레드 접근하기 위해 사용 
	HANDLE ThreadHandle_use;

	flag[0] = TRUE;
	flag[1] = FALSE;

		// 발주를 넣음
		ThreadHandle_buy = CreateThread(NULL, 0, Buy, NULL, 0, &Thread_buyId);

		// 사무실로 옮김
		ThreadHandle_use = CreateThread(NULL, 0, Use, NULL, 0, &Thread_useId);
		WaitForSingleObject(ThreadHandle_buy, INFINITE);
		WaitForSingleObject(ThreadHandle_use, INFINITE);
	
		CloseHandle(ThreadHandle_buy);
		CloseHandle(ThreadHandle_use);
		
		printf("남은 사무용품의 수: %d\n", Supplies);
	

	
	return 0;

}