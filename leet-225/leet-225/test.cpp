//leet-25 
//����һ���������飬����Ҫ��ԭ��ɾ���ظ����ֵ�Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Σ�
//�����Ƴ���������³��ȡ�
//��Ҫʹ�ö��������ռ䣬�������ԭ���޸��������鲢��ʹ�� O(1)
//����ռ����������ɡ�

#include <iostream>
using namespace std;

int removeDuplicates(int *arr, int n)
{
	if (n == 0)
	{
		return 0;
	}
	int i = 0;
	for (int j = 1; j < n; j++)//�ظ��� J ����������
	{
		if (arr[i] != arr[j])//����� i++  ������i��ֵ
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

//leetcode - 21. �ϲ�������������
//��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ���
//��������������нڵ���ɵġ�
//ʾ����
//���룺1->2->4, 1->3->4
//�����1->1->2->3->4->4
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
		if (l1 == NULL)//���l1Ϊ�շ���l2
		{
			return l2;
		}
		if (l2 == NULL)//���l2Ϊ�շ���l1
		{
			return l1;
		}
		ListNode *l3 = NULL;
		if (l1->val > l2->val)//�Ƚ�������
		{
			l3 = l2;
			l3->next = mergeTwoLists(l1, l2->next);//�ݹ�����ٴαȽ�
		}
		else
		{
			l3 = l1;
			l3->next = mergeTwoLists(l1->next, l2);
		}
		return l3;
 }
};


//leetcode-27 �Ƴ�Ԫ��
//����һ������ nums ��һ��ֵ val������Ҫԭ���Ƴ�������ֵ���� val ��Ԫ�أ������Ƴ���������³��ȡ�
//��Ҫʹ�ö��������ռ䣬�������ԭ���޸��������鲢��ʹ�� O(1) ����ռ����������ɡ�
//Ԫ�ص�˳����Ըı䡣�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
//ʾ�� 1:
//���� nums = [3, 2, 2, 3], val = 3,
//
//����Ӧ�÷����µĳ��� 2, ���� nums �е�ǰ����Ԫ�ؾ�Ϊ 2��
//
//�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int i = 0;
		int length = nums.size();
		for (int j = 0; j<length; j++)
		{
			if (nums[j] != val)//������Ԫ�ز�����Ҫɾ����Ԫ�ؾ�������
			{
				nums[i] = nums[j];
				i++;
			}
		}
		return i;
	}
};