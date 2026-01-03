using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (head->next == nullptr || left == right)
        {
            return head;
        }

        ListNode *current = head;
        ListNode *begin = nullptr;
        ListNode *end = nullptr;
        ListNode *previous = nullptr;
        ListNode *next = nullptr;
        int i = 1;

        while (i < left)
        {
            begin = current;
            current = current->next;
            i++;
        }

        end = current;

        while (i <= right)
        {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
            i++;
        }

        end->next = current;

        if (begin != nullptr)
        {
            begin->next = previous;
        }
        else
        {
            head = previous;
        }

        return head;
    }
};