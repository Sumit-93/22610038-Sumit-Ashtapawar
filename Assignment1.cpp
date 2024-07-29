#include <iostream>
#include <vector>
#include <random>
#include <numeric> 

std::vector<int> generate_random_numbers(int size, int min, int max) {
    std::vector<int> numbers(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    for (int i = 0; i < size; ++i) {
        numbers[i] = dis(gen);
    }
    return numbers;
}

bool is_even(int num) {
    return num % 2 == 0;
}


bool is_prime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= num / 2; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

unsigned long long factorial(int num) {
    if (num == 0) return 1;
    unsigned long long fact = 1;
    for (int i = 1; i <= num; ++i) {
        fact *= i;
    }
    return fact;
}

std::vector<int> prefix_sums(const std::vector<int>& numbers) {
    std::vector<int> result(numbers.size());
    std::partial_sum(numbers.begin(), numbers.end(), result.begin());
    return result;
}

double compute_average(const std::vector<int>& numbers) {
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    return static_cast<double>(sum) / numbers.size();
}

int main() {
    const int size = 100;
    const int min = 1;
    const int max = 10000;

    std::vector<int> numbers = generate_random_numbers(size, min, max);

    for (int num : numbers) {
        std::cout << "Number: " << num;
        std::cout << " | Even: " << (is_even(num) ? "Yes" : "No");
        std::cout << " | Prime: " << (is_prime(num) ? "Yes" : "No");
        std::cout << " | Factorial: " << factorial(num % 20); 
        std::cout << "\n";
    }

    std::vector<int> sums = prefix_sums(numbers);
    double average = compute_average(numbers);

    std::cout << "Prefix sums: ";
    for (int sum : sums) {
        std::cout << sum << " ";
    }
    std::cout << "\nAverage: " << average << "\n";

    return 0;
}
