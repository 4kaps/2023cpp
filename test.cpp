#include <iostream>
#include <string>

int find_kth_digit(int k) {
    int current_number = 1;
    int current_digit = 1;
    while (k > 0) {
        // 현재 자리수의 숫자의 자릿수 계산
        int num_digits = 0;
        int temp = current_number;
        while (temp > 0) {
            temp /= 10;
            num_digits++;
        }

        // K번째 자리수에 도달한 경우, 해당 자리수의 숫자 반환
        if (current_digit + num_digits - 1 >= k) {
            int remaining_digits = k - current_digit;
            int target_number = current_number;
            for (int i = 0; i < num_digits - remaining_digits - 1; i++) {
                target_number /= 10;
            }
            return target_number % 10;
        }

        // 다음 숫자와 자리수 업데이트
        k -= num_digits;
        current_digit += num_digits;
        current_number++;
    }

    return -1;  // 예외 처리: 유효하지 않은 입력일 경우 -1 반환
}

int main() {
    int k;
    std::cout << "K번째 자리수를 계산할 숫자 K 입력: ";
    std::cin >> k;

    int kth_digit = find_kth_digit(k);
    if (kth_digit != -1) {
        std::cout << k << "번째 자리수: " << kth_digit << std::endl;
    } else {
        std::cout << "유효하지 않은 입력입니다." << std::endl;
    }

    return 0;
}
