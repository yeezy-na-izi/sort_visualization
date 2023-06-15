#include "sortings.h"


BubbleSort::BubbleSort(std::vector<int> &array) : m_array(array) {}


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


SelectionSort::SelectionSort(std::vector<int> &array) : m_array(array) {}


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