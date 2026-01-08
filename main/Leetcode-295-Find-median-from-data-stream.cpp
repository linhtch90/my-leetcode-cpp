//
// Created by boris on 1/8/26.
//

#include <queue>
#include <vector>

class MedianFinder
{
public:
  MedianFinder()
  {
  }

  void addNum(int num)
  {
    if (maxHeap.empty() || num <= maxHeap.top())
    {
      maxHeap.push(num);
    }
    else
    {
      minHeap.push(num);
    }

    if (maxHeap.size() > minHeap.size() + 1)
    {
      minHeap.push(maxHeap.top());
      maxHeap.pop();
    }
    if (minHeap.size() > maxHeap.size())
    {
      maxHeap.push(minHeap.top());
      minHeap.pop();
    }
  }

  double findMedian()
  {
    if (minHeap.size() == maxHeap.size())
    {
      return static_cast<double>(minHeap.top() + maxHeap.top()) / 2.0;
    }
    return maxHeap.top();
  }

private:
  std::priority_queue<int> maxHeap;
  std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
};
