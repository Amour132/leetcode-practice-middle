//leet-25 
//给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，
//返回移除后数组的新长度。
//不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1)
//额外空间的条件下完成。

#include <iostream>
using namespace std;

int removeDuplicates(int *arr, int n)
{
	if (n == 0)
	{
		return 0;
	}
	int i = 0;
	for (int j = 1; j < n; j++)//重复项 J 继续往后走
	{
		if (arr[i] != arr[j])//不相等 i++  并更新i的值
		{
			i++;
			arr[i] = arr[j];
		}
	}
	return i + 1;
}

int main()
{
	int arr[] = { 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 4, 5, 5, 5, 6, 6, 7, 7, 8, 8, 9 };
	int size = sizeof(arr) / sizeof(arr[0]);
	cout << removeDuplicates(arr, size) << endl;
	return 0;
}

//leetcode - 21. 合并两个有序链表
//将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定
//的两个链表的所有节点组成的。
//示例：
//输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
{
		if (l1 == NULL)//如果l1为空返回l2
		{
			return l2;
		}
		if (l2 == NULL)//如果l2为空返回l1
		{
			return l1;
		}
		ListNode *l3 = NULL;
		if (l1->val > l2->val)//比较数据域
		{
			l3 = l2;
			l3->next = mergeTwoLists(l1, l2->next);//递归进行再次比较
		}
		else
		{
			l3 = l1;
			l3->next = mergeTwoLists(l1->next, l2);
		}
		return l3;
 }
};


//leetcode-27 移除元素
//给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。
//不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
//元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
//示例 1:
//给定 nums = [3, 2, 2, 3], val = 3,
//
//函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。
//
//你不需要考虑数组中超出新长度后面的元素。
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int i = 0;
		int length = nums.size();
		for (int j = 0; j<length; j++)
		{
			if (nums[j] != val)//当数组元素不等于要删除的元素就留下来
			{
				nums[i] = nums[j];
				i++;
			}
		}
		return i;
	}
};