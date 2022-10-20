    #include<iostream>
    using namespace std;

    int FindMax(int N, int BeforeL[])
    {
        int max = BeforeL[0];

        for(int i = 0; i < N; i++)
        {
            if(BeforeL[i] > max)
            max = BeforeL[i];
        }
        return max;
    }

    long long int CutTree(int N, int C, int W, int BeforeL[])
    {
        int L = 0; // 자르고 나서의 나무 길이
        int treecount = 0; // 자른 후의 나무 개수
        int cutcount = 0; // 자른 횟수
        int temp = 0; // 현재 금액
        long long int total = 0;
        long long int max = 0;
        int findmax = 0; // 입력받은 나무들 중 최대 길이
        
        findmax = FindMax(N, BeforeL);
        for(L = 1; L <= findmax; L++) //나올 수 있는 길이는 1 ~ 최소 나무 길이
        {
            total = 0, treecount = 0, cutcount = 0, temp = 0;
            for(int i = 0; i < N; i++)
            {
                if(BeforeL[i] >= L)
                {
                    treecount = BeforeL[i] / L ;
                    if(BeforeL[i] % L == 0) // 나누어 떨어지면
                        cutcount = treecount - 1;
                    else cutcount = treecount;

                    temp = (treecount * L * W) - (cutcount * C); // 수익 - 자른 금액
                    if(temp > 0)
                        total = total + temp;
                }
            }
            if(total > max)
                max = total; 
        }
        return max;
    }


    int main(void)
    {
        int N; // 나무의 개수
        int C; // 나무를 자를 때 드는 비용
        int W; // 나무를 한 단위의 가격
        int BeforeL[51]; // 나무 자르기 전 길이
        int totalmax = 0; // 총 최대 금액

        cin >> N >> C >> W;

        for(int i = 0; i < N; i++)
        {
            cin >> BeforeL[i];
        }
        cout << CutTree(N, C, W, BeforeL);

        return 0;
    }