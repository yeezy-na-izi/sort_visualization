#pragma once

#include <vector>


class BubbleSort {
public:
    BubbleSort(std::vector<int> &array);

    /// return pair of indexes of elements to swap and bool if swap was made
    std::pair<std::pair<int, int>,bool> nextStep();

    bool isFinished() const;

private:
    std::vector<int> &m_array;
    int m_i = 0;
    int m_j = 0;
    bool m_is_finished = false;
};
