using namespace std;

#include <vector>
#include <queue>

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
    struct CompareTask
    {
        bool operator()(ListNode *a, const ListNode *b)
        {
            return a->val > b->val; // Min-heap: smaller values has higher priority
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, CompareTask> minHeap;

        for (ListNode *item : lists)
        {
            if (item != nullptr)
            {
                minHeap.push(item);
            }
        }

        ListNode *resultHead = nullptr;
        ListNode *resultTail = nullptr;
        while (!minHeap.empty())
        {
            ListNode *node = minHeap.top();
            minHeap.pop();
            if (resultHead == nullptr)
            {
                resultHead = node;
                resultTail = node;
            }
            else
            {
                resultTail->next = node;
                resultTail = resultTail->next;
            }

            if (node->next != nullptr)
            {
                minHeap.push(node->next);
            }
        }

        return resultHead;
    }
};