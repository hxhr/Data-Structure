#include <iostream>
#include <vector>
using namespace std;

// 定义了一个反转函数，但在当前代码中被注释掉了
// 它将给定的向量从start到end的部分进行反转
//void reverse(vector<int>& nums, int start, int end) {
//    while (start < end) {
//        swap(nums[start], nums[end]);  // 交换start和end位置上的值
//        start++;  // 将start右移
//        end--;    // 将end左移
//    }
//}
 // 下面是一个被注释掉的通过反转实现数组旋转的方法
    // 使用反转方法将数组向右移动k个位置
    /*
    reverse(nums, 0, n - 1);    // 首先反转整个数组
    reverse(nums, 0, k - 1);    // 然后反转前k个元素
    reverse(nums, k, n - 1);    // 最后反转剩余的元素
    */

int main() {
    int n, k;  // n用于保存数组的长度，k用于保存右移的位置数
    cin >> n >> k;  // 从标准输入读取n和k的值

    k %= n;  // 为了确保移动的位置数不超过数组的长度，进行取余操作

    vector<int> nums(n);  // 定义一个整数向量nums，大小为n
    for (int i = 0; i < n; i++) {
        cin >> nums[i];  // 从标准输入读取n个数并保存到nums中
    }

    // 使用循环替换法进行数组旋转
    int count = 0;  // 记录已经处理的元素数量
    for (int start = 0; count < n; start++) {
        int current = start;     // 当前要处理的位置
        int prev = nums[start];  // 当前位置上的元素值
        do {
            int next = (current + k) % n;  // 计算当前元素应该移到的新位置
            swap(nums[next], prev);  // 将当前位置的元素与新位置的元素进行交换
            current = next;  // 更新当前处理的位置
            count++;  // 增加已处理的元素数量
        } while (start != current);  // 当start等于current时，一个循环完成，退出do-while循环
    }

    // 输出旋转后的数组
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";  // 输出每一个元素，之间用空格隔开
    }

    return 0;  // 程序结束，返回0
}
