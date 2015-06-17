#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2;
        ListNode *head = new ListNode(-1);
        ListNode *p3 = head;
        
    
        
        int carry = 0,first,second,value;
        
        while(p1!=NULL||p2!=NULL) {
            first = p1==NULL?0:p1->val;
            second = p2==NULL?0:p2->val;
            
            value = (first+second+carry)%10;
            carry = (first+second+carry)/10;
            
            p3->next = new ListNode(value);
            p3 = p3->next;
            
            if(p1!=NULL) {
                p1 = p1->next;
            }
            if(p2!=NULL) {
                p2 = p2->next;
            }
        }
        
        if(carry==1) {
            p3->next = new ListNode(1);
        }
        
        return head->next;
    }
};


int main() {

	ListNode* test = new ListNode(2);
	test->next = new ListNode(4);
	test->next->next = new ListNode(3);
	test->next->next->next = new ListNode(1);

	ListNode* test1 = new ListNode(5);
	test1->next = new ListNode(6);
	test1->next->next = new ListNode(4);

    
    Solution s;

	ListNode* result = s.addTwoNumbers(test,test1);
	ListNode* p = result;

	while(p!=NULL) {
		cout << p->val<<endl;
		p = p->next;
	}
	 	
	return 0;
	
}
