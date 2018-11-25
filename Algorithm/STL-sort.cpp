#include <iostream>
#include <algorithm>

const int MAX = 100;
int a[MAX] = {0}, n;

int main()
{
    std::cin >> n;
    for(int i = 1;i <= n;i++) std::cin >> a[i];

    std::sort(a+1,a+n+1); // 因为[i,j)，不包含j，所以n+1
    //降序 std::sort(a+1,a+n+1,std::greater<int>());

    for(int i = 1;i <= n;i++) std::cout << a[i] <<" ";
    return 0;
}
