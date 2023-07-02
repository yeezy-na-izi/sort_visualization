#include "sortings.h"

#include <utility>


BubbleSort::BubbleSort(std::vector<int> array) : m_array(std::move(array)) {}


bool BubbleSort::isFinished() const {
    return m_is_finished;
}


std::pair<std::pair<int, int>, bool> BubbleSort::nextStep() {
    if (m_is_finished) {
        return {{-1, -1}, false};
    }

    if (m_j == m_array.size() - m_i - 1) {
        m_i++;
        m_j = 0;
    }

    if (m_i == m_array.size() - 1) {
        m_is_finished = true;
        return {{-1, -1}, false};
    }

    if (m_array[m_j] > m_array[m_j + 1]) {
        std::swap(m_array[m_j], m_array[m_j + 1]);
        return {{m_j, m_j + 1}, true};
    }

    m_j++;
    return {{m_j - 1, m_j}, false};
}


SelectionSort::SelectionSort(std::vector<int> array) : m_array(std::move(array)) {}


bool SelectionSort::isFinished() const {
    return m_is_finished;
}


std::pair<std::pair<int, int>, bool> SelectionSort::nextStep() {
    if (m_is_finished) {
        return {{-1, -1}, false};
    }

    if (m_j == m_array.size()) {
        m_i++;
        m_j = m_i;
    }

    if (m_i == m_array.size() - 1) {
        m_is_finished = true;
        return {{-1, -1}, false};
    }

    if (m_array[m_j] < m_array[m_i]) {
        std::swap(m_array[m_j], m_array[m_i]);
        return {{m_j, m_i}, true};
    }

    m_j++;
    return {{m_j - 1, m_i}, false};
}


QuickSort::QuickSort(std::vector<int> array) : m_array(std::move(array)) {}


bool QuickSort::isFinished() const {
    return m_is_finished;
}


std::pair<std::pair<int, int>, bool> QuickSort::nextStep() {
    if (cur_step == -1) {
        gen_all_steps(0, m_array.size() - 1);
    }
    cur_step += 1;
    if (cur_step == m_stack.size()) {
        m_is_finished = true;
        return {{-1, -1}, false};
    }
    return m_stack[cur_step];
}


void QuickSort::gen_all_steps(int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = (left + right) / 2;
    int pivot = m_array[mid];
    int i = left;
    int j = right;
    while (i <= j) {
        while (m_array[i] < pivot) {
            m_stack.emplace_back(std::make_pair(i, mid), false);
            i++;
        }
        while (m_array[j] > pivot) {
            m_stack.emplace_back(std::make_pair(j, mid), false);
            j--;
        }
        if (i <= j) {
            std::swap(m_array[i], m_array[j]);
            m_stack.emplace_back(std::make_pair(i, j), true);
            i++;
            j--;
        }
    }
    gen_all_steps(left, j);
    gen_all_steps(i, right);

}
