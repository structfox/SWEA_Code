#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

// get hex from string part
int getDec(std::string s, int len)
{
    int total = 0;
    int tmp;

    // convert char to hex
    for (int i = 0; i < len; ++i)
    {
        if (s.at(i) == 'F')
            tmp = 15;
        else if (s.at(i) == 'E')
            tmp = 14;
        else if (s.at(i) == 'D')
            tmp = 13;
        else if (s.at(i) == 'C')
            tmp = 12;
        else if (s.at(i) == 'B')
            tmp = 11;
        else if (s.at(i) == 'A')
            tmp = 10;
        else if (s.at(i) == '9')
            tmp = 9;
        else if (s.at(i) == '8')
            tmp = 8;
        else if (s.at(i) == '7')
            tmp = 7;
        else if (s.at(i) == '6')
            tmp = 6;
        else if (s.at(i) == '5')
            tmp = 5;
        else if (s.at(i) == '4')
            tmp = 4;
        else if (s.at(i) == '3')
            tmp = 3;
        else if (s.at(i) == '2')
            tmp = 2;
        else if (s.at(i) == '1')
            tmp = 1;
        else if (s.at(i) == '0')
            tmp = 0;

        // get hex total
        total += tmp * pow(16, len - i - 1);
    }
    return total;
}

int main()
{
    int T, N, K;
    int cycle, len;
    int tmp;
    std::string num;
    
    std::cin >> T;

    for (int i = 0; i < T; ++i)
    {
        std::cin >> N >> K;
        std::cin >> num;
        std::vector<int> all_num;
        len = N / 4;

        // N/4번의 회전 동안 나오는 4변의 모든 16진수를 변환하여 배열에 저장
        // 총 N번의 연산 수행
        for (int j = 0; j < len; ++j)
        {
            cycle = 0;
            for (int k = 0; k < 4; ++k)
            {
                all_num.push_back(getDec(num.substr(cycle, len), len));
                cycle += len;
            }
            num.append(&num.at(0));
            num.erase(0, 1);
        }

        // 16진수 값을 가진 배열을 정렬
        std::sort(all_num.begin(), all_num.end());

        // 중복 확인을 위한 변수
        tmp = all_num[N];
        int k = 1;
        int counter = 1;
        // 정렬 된 배열을 뒤에서부터 탐색, K번째 크기의 인덱스 찾기
        for (int j = N; j > 0; --j)
        {
            if (k == K)
                break;
            else if (all_num[j-1] != tmp)
            {
                k++;
                tmp = all_num[j-1];
            }
            counter++;
        }

        std::cout << "#" << i + 1 << " " << all_num[N - counter] << std::endl;
    }

    return 0;
}
