
//brute force approach dp solution is easy by traversing the array from left and right

int offerings(int N, int arr[])
{
    int i = 1, left = 0, lp, top;
    int right[N];
    right[0] = 1;
    top = 1;
    while (i < N)
    {
        if (left >= top)
        {
            right[i - 1] = left + 1;
            while (arr[i] > arr[i + 1])
            {
                right[i] = right[i - 1] - 1;
                i++;
            }
            arr[i] = arr[i - 1] - 1;
        }
        if (left < top && i != 1)
        {
            int run = top - left;
            while (run)
            {
                right[i] = run;
                run--;
                i++;
            }
        }
        while (arr[i] > arr[i - 1])
        {
            right[i] = right[i - 1] + 1;
            i++;
        }
        if (arr[i] == arr[i - 1])
        {
            right[i] = 1;
            i++;
        }
        top = right[i - 1];
        left = 0;
        lp = i;
        while (arr[lp] > arr[lp + 1] && lp < N)
        {
            left++;
            lp++;
        }
        left++;
    }
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += right[i];

    }
    
    return sum;
}