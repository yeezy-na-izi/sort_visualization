#pragma once

#include <vector>

class Sorting {
public:
    virtual std::pair<std::pair<int, int>, bool> nextStep() = 0;

    virtual bool isFinished() const = 0;
};


class BubbleSort: public Sorting {
public:
    explicit BubbleSort(std::vector<int> array);

    /// return pair of indexes of elements to swap and bool if swap was made
    std::pair<std::pair<int, int>, bool> nextStep() override;

    bool isFinished() const override;

private:
    std::vector<int> m_array;
    int m_i = 0;
    int m_j = 0;
    bool m_is_finished = false;
};

class SelectionSort: public Sorting {
public:
    explicit SelectionSort(std::vector<int> array);

    /// return pair of indexes of elements to swap and bool if swap was made
    std::pair<std::pair<int, int>, bool> nextStep() override;

    bool isFinished() const override;

private:
    std::vector<int> m_array;
    int m_i = 0;
    int m_j = 0;
    bool m_is_finished = false;
};


class QuickSort: public Sorting {
public:
    explicit QuickSort(std::vector<int> array);

    /// return all indexes of elements to swap and bool if swap was made
    std::pair<std::pair<int, int>, bool> nextStep() override;

    bool isFinished() const override;

private:
    void gen_all_steps(int left, int right);

    std::vector<int> m_array;
    int m_i = 0;
    int m_j = 0;
    bool m_is_finished = false;
    int cur_step = -1;

    std::vector<std::pair<std::pair<int, int>, bool> > m_stack;
};