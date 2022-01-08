using namespace std;

long long solution(int w, int h)
{
    long long max = (long long)w * h;
    long long sum = 0;

    for (int i = 0; i < w; i++)
    {
        long long nowH = (long long)h * i / w;
        long long nextH = (long long)h * (i + 1) / w;

        if ((long long)h * (i + 1) % w)
        {
            sum += (nextH - nowH + 1);
        }
        else
        {
            sum += (nextH - nowH);
            return max - sum * w / (i + 1);
        }
    }

    return max - sum;
}