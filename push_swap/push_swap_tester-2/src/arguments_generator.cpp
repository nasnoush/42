//
// Created by Simon Cros on 12/01/2025.
//

#include "arguments_generator.hpp"

#include <iostream>

#include "thread_safe_random.hpp"

ArgumentsGenerator::ArgumentsGenerator(const size_t numbersCount) : m_numbersCount(numbersCount)
{
    if (numbersCount > 1000000)
        throw std::invalid_argument("The maximum number count is 1'000'000");

    m_numbers.reserve(numbersCount);
    m_buffer = new char[m_numbersCount * lengthPerNumber];
}

ArgumentsGenerator::~ArgumentsGenerator()
{
    delete[] m_buffer;
}

auto ArgumentsGenerator::generate(ThreadSafeRandom& random, const int min, const int max) -> ArgumentsIterator
{
    m_numbers.clear();

    std::mt19937 generator(random());
    std::uniform_int_distribution<int> dist(min, max); // Uniform distribution in range [min, max]
    while (m_numbers.size() < m_numbersCount)
    {
        const int number = dist(generator);

        // Try to insert the number. If insertion succeeded, add it to the buffer
        if (m_numbers.insert(number).second)
        {
            const size_t index = (m_numbers.size() - 1) * lengthPerNumber;
            snprintf(m_buffer + index, lengthPerNumber, "%d", number);
        }
    }

    return {m_buffer, m_buffer + (m_numbersCount * lengthPerNumber), lengthPerNumber};
}
