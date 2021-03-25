#include <assert.h>
#include <iostream>
#include <limits>
#include <vector>

std::vector<std::uint32_t> findUnsortedSubarray(const std::vector<std::uint32_t>& arr) {
	size_t i = 0,
		   j = arr.size() - 1;

	// Случай пустого массива
	if (arr.size() == 0) {
		return {};
	}

	// Поиск индекса первого элемента, стоящего не по-возрастанию
	while ((i < arr.size() - 1) && (arr[i + 1] >= arr[i])) {
		i++;
	}

	// Если мы дошли до конца массива, значит он отсортирован
	if (i == arr.size() - 1) {
		return {};
	}

	// Поиск индекса последнего элемента, стоящего не по-возрастанию
	while (arr[j - 1] <= arr[j]) {
		j--;
	}


	std::uint32_t minUnsorted = std::numeric_limits<std::uint32_t>::max(),
				  maxUnsorted = std::numeric_limits<std::uint32_t>::min();

	/* Поиск максимального и минимального элемента на этом отрезке.
	*/
	for (; i < j + 1; i++) {
		minUnsorted = std::min(minUnsorted, arr[i]);
		maxUnsorted = std::max(maxUnsorted, arr[i]);
	}

	std::uint32_t startSubarrayIndex = 0,
				  endSubarrayIndex = arr.size() - 1;

	/* Поиск элемента, большего, чем найденный нами минимальный неотсортированный элемент. 
	* Наш элемент должен занять его место, это и будет индекс начала неотсортированного подмассива.
	*/
	while (arr[startSubarrayIndex] <= minUnsorted) {
		startSubarrayIndex++;
	}

	/* Аналогично ищем индекс первого элемента, меньшего, 
	* чем найденный нами максимальный неотсортированный элемент. */
	while (arr[endSubarrayIndex] >= maxUnsorted) {
		endSubarrayIndex--;
	}

	return { startSubarrayIndex, endSubarrayIndex };
}

bool operator==(std::vector<uint32_t>&& l, std::vector<uint32_t>&& r) {
	if (l.size() != r.size()) {
		return false;
	}

	for (size_t i = 0; i < l.size(); i++) {
		if (l[i] != r[i]) {
			return false;
		}
	}

	return true;
}

int main() {
	assert(findUnsortedSubarray(std::vector<std::uint32_t>{}) == (std::vector<std::uint32_t>{}));

	assert(findUnsortedSubarray(std::vector<std::uint32_t>{ 1, 1, 1, 1, 1, 1, 1, 1, 1 }) == (std::vector<std::uint32_t>{}));

	assert(findUnsortedSubarray(std::vector<std::uint32_t>{ 1, 2, 3, 4, 5, 6, 7, 8, 9 }) == (std::vector<std::uint32_t>{}));

	assert(findUnsortedSubarray(std::vector<std::uint32_t>{ 1, 3, 2, 4, 5 }) == (std::vector<std::uint32_t>{ 1, 2 }));

	assert(findUnsortedSubarray(std::vector<std::uint32_t>{ 1, 2, 4, 3, 5, 7, 6, 5, 1 }) == (std::vector<std::uint32_t>{ 1, 8 }));

	assert(findUnsortedSubarray(std::vector<std::uint32_t>{ 1, 2, 4, 3, 5, 7, 6, 5, 7 }) == (std::vector<std::uint32_t>{ 2, 7 }));

	assert(findUnsortedSubarray(std::vector<std::uint32_t>{ 1, 5, 5, 7, 5, 5, 7, 7, 6 }) == (std::vector<std::uint32_t>{ 3, 8 }));

	assert(findUnsortedSubarray(std::vector<std::uint32_t>{ 8, 5, 5, 7, 5, 5, 7, 7, 9 }) == (std::vector<std::uint32_t>{ 0, 7 }));

	assert(findUnsortedSubarray(std::vector<std::uint32_t>{ 1, 5, 5, 7, 5, 5, 7, 7, 9 }) == (std::vector<std::uint32_t>{ 3, 5 }));

	return 0;
}
